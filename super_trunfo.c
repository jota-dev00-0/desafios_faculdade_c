#include "stdio.h"
#include <math.h>

typedef struct {
    char nome[50];
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib; 
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta ;

typedef struct {
    const char *nome;
    float valor_c1;
    float valor_c2;
    int menorVence; 
} Comparacao;


void cadastrarCarta(Carta *c){
    printf("Digite o Nome do País: ");
    scanf_s(" %[^\n]", c->nome);
    printf("Digite o Código ISO (ex: BRA): ");
    scanf_s(" %s", c->codigo);
    printf("Digite a População: ");
    scanf_s("%lu", &c->populacao);
    printf("Digite a Área (km²): ");
    scanf_s("%f", &c->area);
    printf("Digite o PIB (em trilhões de dólares): ");
    scanf_s("%f", &c->pib);
    printf("Digite o número de Pontos Turísticos famosos: ");
    scanf_s("%d", &c->pontos_turisticos);

   
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = (c->pib * 1e12) / c->populacao; 
}

void calcularSuperPoder(Carta *c){
    c->super_poder =
    (float) c->populacao +
    (float) c -> pontos_turisticos +
    c->area +
    c->pib +
    c->pib_per_capita +
    (1.0f / c->densidade_populacional);
}

void compararCartas(Carta c1, Carta c2) {
    Comparacao comps[] = {
        {"População", (float)c1.populacao, (float)c2.populacao, 0},
        {"Área", c1.area, c2.area, 0},
        {"PIB", c1.pib, c2.pib, 0},
        {"Pontos Turísticos", (float)c1.pontos_turisticos, (float)c2.pontos_turisticos, 0},
        {"Densidade Populacional", c1.densidade_populacional, c2.densidade_populacional, 1},
        {"PIB per Capita", c1.pib_per_capita, c2.pib_per_capita, 0},
        {"Super Poder", c1.super_poder, c2.super_poder, 0}
    };

    int total = sizeof(comps) / sizeof(comps[0]);

    printf("\n=== Comparação de Cartas ===\n");
    printf("%-25s %-15s %-15s Resultado\n", "Atributo", "Carta 1", "Carta 2");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        int venceu;
        if (comps[i].menorVence)
            venceu = comps[i].valor_c1 < comps[i].valor_c2 ? 1 : 0;
        else
            venceu = comps[i].valor_c1 > comps[i].valor_c2 ? 1 : 0;

        printf("%-25s %-15.2f %-15.2f Carta %d venceu (%d)\n",
               comps[i].nome,
               comps[i].valor_c1,
               comps[i].valor_c2,
               venceu ? 1 : 2,
               venceu);
    }
}



int main(){
    Carta c1, c2;
    printf("cadastro da primeira carta\n");
    cadastrarCarta(&c1);
    printf("Cadastro da primeira carta\n");
    cadastrarCarta(&c2);

    calcularSuperPoder(&c1);
    calcularSuperPoder(&c2);

    compararCartas(c1, c2);

    return 0;

}