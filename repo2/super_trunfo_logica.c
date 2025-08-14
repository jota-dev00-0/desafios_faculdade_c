#include <stdio.h>


// Estrutura para representar um país
typedef struct {
    char nome[50];
    float populacao;      // em milhões
    float area;           // em km²
    float pib;            // em bilhões de dólares
    int pontosTuristicos; // quantidade
} Pais;

// Função para exibir atributos de um país
void exibirPais(Pais p) {
    printf("\n=== %s ===\n", p.nome);
    printf("1 - População: %.2f milhões\n", p.populacao);
    printf("2 - Área: %.2f km²\n", p.area);
    printf("3 - PIB: %.2f bilhões US$\n", p.pib);
    printf("4 - Pontos Turísticos: %d\n", p.pontosTuristicos);
}

// Função para comparar dois atributos e retornar pontos
int compararAtributo(Pais p1, Pais p2, int opcao) {
    switch (opcao) {
        case 1:
            return (p1.populacao > p2.populacao) ? 1 : (p1.populacao < p2.populacao ? -1 : 0);
        case 2:
            return (p1.area > p2.area) ? 1 : (p1.area < p2.area ? -1 : 0);
        case 3:
            return (p1.pib > p2.pib) ? 1 : (p1.pib < p2.pib ? -1 : 0);
        case 4:
            return (p1.pontosTuristicos > p2.pontosTuristicos) ? 1 : (p1.pontosTuristicos < p2.pontosTuristicos ? -1 : 0);
        default:
            printf("\n⚠️ Opção inválida!\n");
            return 0;
    }
}

int main() {
    Pais pais1, pais2;
    int atributo1, atributo2;
    int pontosJogador1 = 0, pontosJogador2 = 0;

    // Cadastro das cartas
    printf("=== Cadastro do País 1 ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", pais1.nome);
    printf("População (milhões): ");
    scanf("%f", &pais1.populacao);
    printf("Área (km²): ");
    scanf("%f", &pais1.area);
    printf("PIB (bilhões US$): ");
    scanf("%f", &pais1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &pais1.pontosTuristicos);

    printf("\n=== Cadastro do País 2 ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", pais2.nome);
    printf("População (milhões): ");
    scanf("%f", &pais2.populacao);
    printf("Área (km²): ");
    scanf("%f", &pais2.area);
    printf("PIB (bilhões US$): ");
    scanf("%f", &pais2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &pais2.pontosTuristicos);

    // Exibir cartas cadastradas
    exibirPais(pais1);
    exibirPais(pais2);

    // Escolha dos atributos
    printf("\nEscolha o PRIMEIRO atributo para comparar (1-4): ");
    scanf("%d", &atributo1);

    printf("Escolha o SEGUNDO atributo para comparar (1-4): ");
    scanf("%d", &atributo2);

    // Comparação do primeiro atributo
    int resultado = compararAtributo(pais1, pais2, atributo1);
    if (resultado == 1) pontosJogador1++;
    else if (resultado == -1) pontosJogador2++;

    // Comparação do segundo atributo
    resultado = compararAtributo(pais1, pais2, atributo2);
    if (resultado == 1) pontosJogador1++;
    else if (resultado == -1) pontosJogador2++;

    // Resultado final
    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s: %d pontos\n", pais1.nome, pontosJogador1);
    printf("%s: %d pontos\n", pais2.nome, pontosJogador2);

    if (pontosJogador1 > pontosJogador2)
        printf("🏆 %s venceu!\n", pais1.nome);
    else if (pontosJogador2 > pontosJogador1)
        printf("🏆 %s venceu!\n", pais2.nome);
    else
        printf("🤝 Empate!\n");

    return 0;
}
