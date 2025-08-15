# Movimento de Peças de Xadrez

Esse programa em C simula os movimentos de 3 peças de xadrez (Torre, Bispo, Rainha e Cavalo) usando diferentes técnicas, como recursão e loops aninhados.

📋 Estrutura do Projeto

    1. Definições de constantes para o número de passos de cada peça
    2. Funções que implementam os movimentos de cada peça

♟️ Peças Implementadas
1. Torre
Movimento: Linhas retas (vertical ou horizontal)

Técnica usada: Recursão simples

Funções:
    moverTorreCima() - Move para cima
    moverTorreLado() - Move para o lado

2. Bispo
Movimento: Diagonais

Técnica usada: Recursão com loops aninhados

Função:
    moverBispo() - Move em diagonal (cima + lado)

3. Rainha
Movimento: Combina movimentos da Torre e Bispo (linhas retas e diagonais)

Técnica usada: Recursão combinando padrões

Função:
    moverRainha() - Alterna entre movimentos retos e diagonais    

4. Cavalo
Movimento: Em "L" (2 casas em uma direção + 1 casa perpendicular)

Técnica usada: Loops complexos

Função:
    moverCavalo() - Implementa o movimento característico em L

🏃 Como Executar
Compile o programa com um compilador C:
    gcc movimentos_xadrez.c -o xadrez

Execute o programa gerado:
    ./movimentos_xadrez

📝 Observações
Os movimentos estão simplificados para demonstração didática, mostrando apenas parte dos movimentos possíveis no jogo de xadrez real.

