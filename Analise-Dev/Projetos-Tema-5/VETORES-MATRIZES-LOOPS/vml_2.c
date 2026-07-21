#include <stdio.h>

// Matrizes com estruturas de repetição
int main(){
    int matriz[3][3]; // Declara uma matriz 3x3

    // Inicialização da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j] = i + j; // Atribuindo valores à matriz
            printf("Matrizes [%d][%d] = %d\n", i, j, matriz[i][j]); // Exibindo os elementos da matriz
        }
    }

    return 0;
}