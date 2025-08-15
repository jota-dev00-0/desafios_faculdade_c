#include "stdio.h" 


#define TORRE_PASSOS 5
#define BISPO_PASSOS 4
#define RAINHA_PASSOS 5
#define CAVALO_PASSOS 3


// Torre - Recursão simples (linha ou coluna)
void moverTorreCima(int passos){
    if (passos <= 0) return;
    printf("CIMA\n");
    moverTorreCima(passos - 1);
}
void moverTorreLado(int passos){
    if (passos <= 0) return;
    printf("LADO\n");
    moverTorreLado(passos - 1);
}

// Cavalo - loops complexos "L" (2 cima + 1 direita ou esquerda)
void moverCavalo(int passos){
    int movimento = 0;

    for(int up = 0; up < 2; up++){
        for(int right = 0; right < 1; right++){
            if (movimento >= CAVALO_PASSOS) {
                printf("CIMA\n");
                printf("CIMA\n");
                printf("LADO\n");
                movimento++;
            }
        }
    }
}

// Bispo - Recursão com loops aninhados
void moverBispo(int passos){
    if (passos <= 0) return;

    for (int i = 0; i < 1; i++) {
        printf("CIMA");
        for (int j = 0; j < 1; j++) {
            printf("DIAGONAL");
        }
    }

    moverBispo(passos - 1);
}

// Rainha - combina Torre e Bispo
void moverRainha(int passos){
    if (passos <= 0) return;

    printf("CIMA");


    printf("LADO");

    moverRainha(passos - 1);
}


// ===== Função Principal =====
int main(){
    printf("--- Mobimentos da Torre --- \n");
    moverTorreCima(TORRE_PASSOS);
    moverTorreLado(TORRE_PASSOS);
    printf("\n");
    printf("--- Mobimentos do Bispo --- \n");
    moverBispo(BISPO_PASSOS);
    printf("\n");
    printf("--- Mobimentos da Rainha --- \n");
    moverRainha(RAINHA_PASSOS);
    printf("\n");
    printf("--- Mobimentos do Cavalo --- \n");
    moverCavalo(CAVALO_PASSOS);
    printf("\n");
    return 0;
}