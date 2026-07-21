#include <stdio.h>

int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor) {
    if (inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor)
        return meio;
    else if (vetor[meio] < valor)
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
    else
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
}

int main() {
    int numeros[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int valor;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);

    // chamada da função recursiva
    int posicao = buscaBinariaRecursiva(numeros, 0, tamanho - 1, valor);

    if (posicao != -1)
        printf("Valor %d encontrado na posicao %d.\n", valor, posicao);
    else
        printf("Valor %d nao encontrado.\n", valor);

    return 0;
}