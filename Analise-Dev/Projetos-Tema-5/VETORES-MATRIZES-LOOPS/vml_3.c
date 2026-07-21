#include <stdio.h>

// Soma dos elementos de um vetor
int main(){
    int vetor[5] = {1, 2, 3, 4, 5};
    int soma = 0;

    for (int i = 0; i <= 5; i++){
        soma += vetor[i];    
    }

    printf("A soma dos elementos do vetor é: %d", soma);

    return 0;
}