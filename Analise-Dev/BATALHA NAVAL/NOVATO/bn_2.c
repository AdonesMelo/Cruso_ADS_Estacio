#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};

    // Variáveis para definir o navio
    int linha = 2;         // Linha 3 (índice 2)
    int coluna = 3;        // Coluna D (índice 3)
    int tamanho = 3;       // Tamanho do navio
    char direcao = 'D';    // 'H' para horizontal, 'V' para vertical
    int valorNavio = 3;    // Valor que representa o navio
    int linha_inicial = 1; // índice 2 = linha 3
    int coluna_inicial = 9; // índice 2 = coluna C

    // Posiciona o navio com base nas variáveis
    if (direcao == 'H') {
        for (int i = 0; i < tamanho && coluna + i < 10; i++) {
            tabuleiro[linha][coluna + i] = valorNavio;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < tamanho && linha + i < 10; i++) {
            tabuleiro[linha + i][coluna] = valorNavio;
        }
    } else if (direcao == 'D'){
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha_inicial + i][coluna_inicial + i] = valorNavio;
        }
    }
    
    // Imprime o tabuleiro
    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf(" %c ", 'A' + i);
    }
    printf("\n");

    // imprime cada linha com número e os valores da matriz
    for (int j = 0; j < 10; j++) {
        printf("%2d ", j + 1); // Imprime número da linha
        for (int i = 0; i < 10; i++) {
            printf(" %d ",tabuleiro[j][i] == 0 ? 0 : tabuleiro[j][i]); // Operador ternário
        }
        printf("\n");
    }

    return 0;
}
