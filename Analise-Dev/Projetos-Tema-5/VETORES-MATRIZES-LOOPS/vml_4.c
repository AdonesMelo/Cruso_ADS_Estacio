#include <stdio.h>

// Soma de matrizes
int main(){
    int matriz_1[2][2] = {{1, 2}, {3, 4}};
    int matriz_2[2][2] = {{5, 6}, {7, 8}};
    int soma_matriz[2][2];

    // soma das matrizes
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            soma_matriz[i][j] = matriz_1[i][j] + matriz_2[i][j];
            printf("soma_matriz[%d][%d] = %d\n", i, j, soma_matriz[i][j]);
        }
    }

    return 0;
}