#include <stdio.h>
#include <stdlib.h>

// Funções
void insertionSort(int vetor[], int tamanho);
void imprimirVetor(int vetor[], int tamanho);

int main() {
    int vetor[5] = {5, 1, 4, 2, 8};

    printf("Antes: ");
    imprimirVetor(vetor, 5);

    insertionSort(vetor, 5);

    printf("Depois: ");
    imprimirVetor(vetor, 5);

    return 0;
}


void insertionSort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i]; // elemento atual a ser inserido
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        // Insere a chave na posição correta
        vetor[j + 1] = chave;
    }
} 

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}