#include <stdio.h>
#include <stdlib.h>

// Funções
void trocar(int* a, int* b);
void selectionSort(int vetor[], int tamanho);
void imprimirVetor(int vetor[], int tamanho);

int main() {
    int vetor[5] = {5, 1, 4, 2, 8};

    printf("Antes: ");
    imprimirVetor(vetor, 5);

    selectionSort(vetor, 5);

    printf("Depois: ");
    imprimirVetor(vetor, 5);

    return 0;
}

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            trocar(&vetor[i], &vetor[indiceMenor]);
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