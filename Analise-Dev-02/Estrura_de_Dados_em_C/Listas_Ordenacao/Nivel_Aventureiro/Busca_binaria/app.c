#include <stdio.h>

// Função de busca binária
int buscaBinariaIterativa(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // valor não encontrado
}

int main() {
    int numeros[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int valor;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);

    // chamada da função Binaria
    int posicao = buscaBinariaIterativa(numeros, tamanho, valor);

    if (posicao != -1)
        printf("Valor %d encontrado na posicao %d.\n", valor, posicao);
    else
        printf("Valor %d nao encontrado.\n", valor);

    return 0;
}
