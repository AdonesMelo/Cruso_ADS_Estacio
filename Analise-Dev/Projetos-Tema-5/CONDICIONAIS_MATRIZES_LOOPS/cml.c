#include <stdio.h>

// Modificação condicional de uma matriz
int main(){
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8,9}};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] > 5){
                matriz[i][j] = - matriz[i][j]; // Se o valor for maior que 5 torna-se negativo!
            }
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}