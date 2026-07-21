//----------------------------------------------------------------
// Projeto: Reversão da Ordem de uma Fila usando Pilha
// Descrição: Este programa implementa a reversão da ordem de uma fila usando uma pilha auxiliar. Ele define as estruturas de dados para a fila e a pilha,
// e inclui funções para inserir, remover, empilhar e desempilhar elementos. O programa exibe a fila original e a fila invertida.
//----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 50
 
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
typedef struct {
    Pessoa dados[MAX];
    int inicio, fim;
} Fila;
 
typedef struct {
    Pessoa dados[MAX];
    int topo;
} Pilha;
 
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}
 
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}
 
void inserir(Fila *f, Pessoa p) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = p;
    }
}
 
Pessoa remover(Fila *f) {
    return f->dados[f->inicio++];
}
 
void push(Pilha *p, Pessoa pes) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = pes;
    }
}
 
Pessoa pop(Pilha *p) {
    return p->dados[p->topo--];
}
 
void exibirFila(Fila f) {
    for (int i = f.inicio; i < f.fim; i++) {
        printf("Nome: %-10s | Idade: %2d\n", f.dados[i].nome, f.dados[i].idade);
    }
}
 
int main() {
    // Declara as estruturas de dados
    Fila filaOriginal, filaInvertida;
    Pilha auxiliar;
    
    // Inicializa as estruturas de dados
    inicializarFila(&filaOriginal);
    inicializarFila(&filaInvertida);
    inicializarPilha(&auxiliar);
    
    // Adiciona pessoas à fila original
    Pessoa pessoas[] = {
        {"Carlos", 45},
        {"Joana", 62}, 
        {"Lucas", 30}, 
        {"Maria", 75},
        {"Pedro", 55},
        {"Ana", 40},
        {"Rafael", 28},
        {"Sofia", 33}
    };
 
    for (int i = 0; i < 8; i++) {
        inserir(&filaOriginal, pessoas[i]);
    }
    
    // Exibe a fila original
    printf("\nFila original:\n");
    exibirFila(filaOriginal);

    while (filaOriginal.inicio < filaOriginal.fim) {
        push(&auxiliar, remover(&filaOriginal));
    }
    
    // Inverte a fila usando a pilha
    while (auxiliar.topo >= 0) {
        inserir(&filaInvertida, pop(&auxiliar));
    }
    
    // Exibe a fila invertida
    printf("\nFila invertida:\n");
    exibirFila(filaInvertida);
 
    return 0;
}