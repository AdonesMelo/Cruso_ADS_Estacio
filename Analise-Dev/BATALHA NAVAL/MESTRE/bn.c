#include <stdio.h>


#define LINHA_H 3 // Posição do navio na horizontal
#define INICIAL_NAVIO_H 3 // Posisão da coluna inicial do navio na horizontal

#define COLUNA_V 8    // Posição do navio na vertical
#define INICIAL_NAVIO_V 5 // Posisão  da coluna inicial do navio na vertical

#define TAM_NAVIO_D 3 // Tamanho do navio na diagonal

#define VALOR_NAVIO 3 // Valor que representa o navio na matriz

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int tamanho_navio_h = INICIAL_NAVIO_H + 2;
    int tamanho_navio_v = INICIAL_NAVIO_V + 2;

    // Valores posição do navio na diagonal esquerda para direita de cima para baixo
    int linha_inicio_diagonal_ed = 4; // índice 4 = linha 3, "ed" = esquerda para direita
    int coluna_inicio_diagonal_ed = 4; // índice 4 = coluna D, "ed" = esquerda para direita

    // Valores posição do navio na diagonal direita para esquerda de cima para baixo
    int linha_inicial_diagonal_de = 7; // índice 7 = linha 8, "de" = direita para esquerda
    int coluna_inicial_diagonal_de = 2; // índice 2 = coluna C, "de" = direita para esquerda

    // Posiciona o número 3 na linha 3 (índice 2) nas colunas D, E, F (índices 3, 4, 5)
    // Posição horizontal
    for (int i = INICIAL_NAVIO_H; i <= tamanho_navio_h; i++)
        tabuleiro[LINHA_H - 1][i] = VALOR_NAVIO;

    // Posiciona o número 3 na coluna H (índice 7) nas linhas 6, 7, 8 (índices 5, 6, 7)
    // Pocição vertical
    for (int j = INICIAL_NAVIO_V; j <= tamanho_navio_v; j++)
        tabuleiro[j][COLUNA_V - 1] = VALOR_NAVIO;

    // Diagonal esquerda -> direita de cima para baixo
    for (int i = 0; i < TAM_NAVIO_D; i++){
        tabuleiro[linha_inicio_diagonal_ed + i][coluna_inicio_diagonal_ed + i] = VALOR_NAVIO;
    }

    // Diagonal direita -> esquerda de cima para baixo
    for (int j = 0; j < TAM_NAVIO_D; j++){
        tabuleiro[linha_inicial_diagonal_de + j][coluna_inicial_diagonal_de - j] = VALOR_NAVIO;  
    }
    
    printf("##### Jogo de Batalha Naval #####\n");
    printf("\n");

    // Imprime cabeçalho com letras
    printf("   "); // Espaço para alinhar com os números da coluna
    for (int i = 0; i < 10; i++){
        printf(" %c ", 'A' + i);
    }

    printf("\n");

    // imprime cada linha com número e os valores da matriz
    for (int j = 0; j < 10; j++) {
        printf("%2d ", 1 + j); // Imprime número da linha
        for (int i = 0; i < 10; i++) {
            printf(" %d ",tabuleiro[j][i] == 0 ? 0 : tabuleiro[j][i]); // Operador ternário
        }
        printf("\n");
    }

    return 0;
}
