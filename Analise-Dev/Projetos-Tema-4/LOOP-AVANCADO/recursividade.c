#include <stdio.h>

void recursivo(int numero){
    if (numero > 0){
        printf("%d \n", numero); // Ordem decrescente
        recursivo(numero - 1);
        //printf("%d \n", numero); // Ordem crescente
    }
    
}

int main(){
    int quantidade = 10;

    printf("Contagem regressiva...\n");
    recursivo(quantidade);

    return 0;
}