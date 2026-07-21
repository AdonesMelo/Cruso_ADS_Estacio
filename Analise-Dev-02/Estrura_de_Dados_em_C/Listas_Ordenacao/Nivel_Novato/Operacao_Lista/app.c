#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};

void inserirNoInicio(struct No** inicio, int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
} 

void removerDoInicio(struct No** inicio) {
    if (*inicio != NULL) {
        struct No* temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    }
} 

void listar(struct No* inicio) {
    struct No* atual = inicio;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
} 

int main(){
    struct No* inicio = NULL;

    inserirNoInicio(&inicio, 10);
    inserirNoInicio(&inicio, 20);
    inserirNoInicio(&inicio, 30);

    printf("Lista atual:\n");
    listar(inicio);

    removerDoInicio(&inicio);
    printf("\nApós remover do início:\n");
    listar(inicio);

    while (inicio != NULL) {
        removerDoInicio(&inicio);
    }

    return 0;
}