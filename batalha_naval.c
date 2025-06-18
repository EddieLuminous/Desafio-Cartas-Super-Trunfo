#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Valores para representar água e navios
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se o navio cabe no tabuleiro
    if (vertical) {
        if (linha + tamanho > TAMANHO_TABULEIRO) return false;
    } else {
        if (coluna + tamanho > TAMANHO_TABULEIRO) return false;
    }
    
    // Verifica se há alguma sobreposição com outros navios
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            if (tabuleiro[linha + i][coluna] != AGUA) return false;
        } else {
            if (tabuleiro[linha][coluna + i] != AGUA) return false;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro corretamente (eu acho)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, bool vertical) {
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            tabuleiro[linha + i][coluna] = NAVIO;
        } else {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j); // Imprime índices das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Imprime índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona o navio horizontal
    int linha_horizontal = 2, coluna_horizontal = 3;
    bool vertical_horizontal = false;
    
    if (posicaoValida(linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, vertical_horizontal, tabuleiro)) {
        posicionarNavio(tabuleiro, linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, vertical_horizontal);
    } else {
        printf("Posição inválida para o navio horizontal!\n");
        return 1;
    }
    
    // Posiciona o navio vertical
    int linha_vertical = 5, coluna_vertical = 7;
    bool vertical_vertical = true;
    
    if (posicaoValida(linha_vertical, coluna_vertical, TAMANHO_NAVIO, vertical_vertical, tabuleiro)) {
        posicionarNavio(tabuleiro, linha_vertical, coluna_vertical, TAMANHO_NAVIO, vertical_vertical);
    } else {
        printf("Posição inválida para o navio vertical!\n");
        return 1;
    }
    
    // Exibe o tabuleiro (yay)
    exibirTabuleiro(tabuleiro);
    
    return 0;
}