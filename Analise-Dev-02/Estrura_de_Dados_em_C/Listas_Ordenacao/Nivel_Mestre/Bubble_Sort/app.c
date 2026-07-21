#include <stdio.h>
#include <stdlib.h>

// Funções
void trocar(int* a, int* b);
void bubbleSort(int vetor[], int tamanho);
void imprimirVetor(int vetor[], int tamanho);

int main() {
    int vetor[5] = {5, 1, 4, 2, 8};

    printf("Antes: ");
    imprimirVetor(vetor, 5);

    bubbleSort(vetor, 5);

    printf("Depois: ");
    imprimirVetor(vetor, 5);

    return 0;
}

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
} 

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}