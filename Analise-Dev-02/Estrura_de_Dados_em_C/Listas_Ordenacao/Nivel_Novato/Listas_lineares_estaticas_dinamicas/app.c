#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numeros = (int*) malloc(3 *sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    printf("\nNúmeros: %d, %d e %d\n", numeros[0], numeros[1], numeros[2]);

    // Realocando para 5 posições
    int* temp = numeros = realloc(numeros, 5 *sizeof(int));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        free(numeros); // libera a memória antiga
        return 1;
    }
    numeros = temp;
    numeros[3] = 40;
    numeros[4] = 50;

    printf("\nNúmeros após o 'realloc': %d, %d, %d, %d e %d\n", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4]);

    free(numeros);
    numeros =NULL;

    return 0;
}