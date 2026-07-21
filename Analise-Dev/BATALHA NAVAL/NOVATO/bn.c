#include <stdio.h>

int main(){
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tabuleiro[10][10] = {0}; // Inicializa tudo com zero

    // Posiciona o número 3 na linha 3 (índice 2) nas colunas D, E, F (índices 3, 4, 5)
    // Posição horizontal
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Posiciona o número 3 na coluna H (índice 7) nas linhas 6, 7, 8 (índices 5, 6, 7)
    // Pocição vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    printf("##### Jogo de Batalha Naval #####\n");
    printf("\n");

    // Imprime cabeçalho com letras
    printf("   "); // Espaço para alinhar com os números da coluna

    for (int i = 0; i < 10; i++){
        printf(" %c ", linha[i]);
    }

    printf("\n");

    // imprime cada linha com número e os valores da matriz
    for (int j = 0; j < 10; j++) {
        printf("%2d ", coluna[j]); // Imprime número da linha
        for (int i = 0; i < 10; i++) {
            if (tabuleiro[j][i] == 0) {
                printf(" 0 "); // Representa cada célula do tabuleiro
            } else {
                printf(" %d ", tabuleiro[j][i]);
            }
        }
        printf("\n");
    }

    return 0;
}