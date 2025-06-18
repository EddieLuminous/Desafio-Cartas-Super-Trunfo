#include <stdio.h>

int main() {
    printf("\n*** SIMULADOR DE MOVIMENTOS DE XADREZ ***\n");

    // 1. Movimento da Torre (5 casinhas para a direita) usando FOR
    printf("Movimento da Torre (5 casas para a direita):\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // 2. Movimento do Bispo (5 casas na diagonal para a superior direita) usando WHILE
    printf("\nMovimento do Bispo (5 casas na diagonal superior direita):\n");
    int casas_bispo = 1;
    while (casas_bispo <= 5) {
        printf("Cima, Direita\n");
        casas_bispo++;
    }

    // 3. Movimento da Rainha (8 casas para a esquerda) usando DO-WHILE
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");
    int casas_rainha = 1;
    do {
        printf("Esquerda\n");
        casas_rainha++;
    } while (casas_rainha <= 8);

    // 4. Movimento do Cavalo (2 casas para baixo e 1 para esquerda) ultilizando loops aninhados
    printf("\nMovimento do Cavalo (2 casas para baixo e 1 para esquerda):\n");
    
    // Loop externo (for) para controlar as partes do movimento em L
    for (int parte_l = 1; parte_l <= 2; parte_l++) {
        
        if (parte_l == 1) {
            // Primeira parte do L: movimento vertical (2 casasinhas para baixo)
            int casas_baixo = 1;
            while (casas_baixo <= 2) {  // Loop while para as 2 casas para baixo
                printf("Baixo\n");
                casas_baixo++;
            }
        } else {
            // Segunda parte do L: movimento horizontal (1 casa para esquerda)
            printf("Esquerda\n");
        }
    }

    printf("\n=== FIM DA SIMULAÇÃO ===\n");
    return 0;
}