#include <stdio.h>

// Vetores com estruturas de repetição
int main(){
    int vetor[5]; // Declaração do vetor

    // Inicialização do vetor usando uma estrutura de repetição for
    for (int i = 0; i < 5; i++){
        vetor[i] = i * 2; // Atribuindo valores ao vetor
        printf("Vetor: [%d] = %d\n", i, vetor[i]); // Exibindo os elementos do vetor
    }
    
    return 0;
}