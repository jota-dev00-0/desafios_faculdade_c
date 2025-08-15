#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// Definições de tamanho
#define SKILL_SIZE 5   // Tamanho das matrizes de habilidades
#define BOARD_SIZE 10  // Tamanho do tabuleiro

// Função para gerar matriz em formato de cone (triângulo apontando para baixo)
void generateCone(int matrix[SKILL_SIZE][SKILL_SIZE]) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Verifica se está dentro do triângulo
            if (j >= i && j < SKILL_SIZE - i) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

// Função para gerar matriz em formato de cruz (+)
void generateCross(int matrix[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Linha central ou coluna central
            if (i == center || j == center) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

// Função para gerar matriz em formato de octaedro (losango)
void generateOctahedron(int matrix[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Verifica se está dentro do losango
            int distance = abs(i - center) + abs(j - center);
            if (distance <= center) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

// Função para aplicar uma habilidade no tabuleiro
void applySkillToBoard(int board[BOARD_SIZE][BOARD_SIZE], 
                      int skill[SKILL_SIZE][SKILL_SIZE], 
                      int center_row, int center_col) {
    // Calcula o ponto de partida no tabuleiro (centralizando a habilidade)
    int start_row = center_row - SKILL_SIZE/2;
    int start_col = center_col - SKILL_SIZE/2;
    
    // Percorre a matriz da habilidade
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Calcula a posição no tabuleiro
            int board_row = start_row + i;
            int board_col = start_col + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (board_row >= 0 && board_row < BOARD_SIZE && 
                board_col >= 0 && board_col < BOARD_SIZE) {
                
                // Se a habilidade afeta esta posição, marca com 5
                if (skill[i][j] == 1) {
                    board[board_row][board_col] = 5;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro com símbolos visuais
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nTabuleiro 10x10:\n");
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col); // Cabeçalho das colunas
    }
    printf("\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i); // Cabeçalho das linhas
        
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Usa símbolos visuais para representar os elementos
            switch (board[i][j]) {
                case 0: // Água
                    printf(" ~ ");
                    break;
                case 3: // Navio
                    printf(" \u25B6 "); // Símbolo de navio (triângulo)
                    break;
                case 5: // Área afetada
                    printf(" \u25A0 "); // Símbolo de quadrado cheio
                    break;
                default:
                    printf(" ? ");
            }
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf(" ~  = Água\n");
    printf(" \u25B6  = Navio\n");
    printf(" \u25A0  = Área afetada pela habilidade\n\n");
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    
    // Adiciona navios (3) em posições específicas
    board[2][3] = 3;
    board[5][7] = 3;
    board[8][1] = 3;
    board[9][4] = 3;
    board[4][5] = 3;
    board[1][8] = 3;
    
    // Gera as matrizes de habilidades
    int cone[SKILL_SIZE][SKILL_SIZE];
    int cross[SKILL_SIZE][SKILL_SIZE];
    int octahedron[SKILL_SIZE][SKILL_SIZE];
    
    generateCone(cone);
    generateCross(cross);
    generateOctahedron(octahedron);
    
    // Define pontos de origem para cada habilidade (linha, coluna)
    int cone_origin[] = {3, 3};       // Centro em (3,3)
    int cross_origin[] = {7, 2};      // Centro em (7,2)
    int octahedron_origin[] = {5, 8}; // Centro em (5,8)
    
    // Aplica as habilidades no tabuleiro
    applySkillToBoard(board, cone, cone_origin[0], cone_origin[1]);
    applySkillToBoard(board, cross, cross_origin[0], cross_origin[1]);
    applySkillToBoard(board, octahedron, octahedron_origin[0], octahedron_origin[1]);
    
    // Imprime o tabuleiro final
    printBoard(board);
    
    return 0;
}