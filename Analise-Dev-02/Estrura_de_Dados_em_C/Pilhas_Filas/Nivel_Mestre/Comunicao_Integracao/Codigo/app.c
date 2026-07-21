//----------------------------------------------------------------
// Projeto: Comunicação e Integração entre Estruturas de Dados
// Descrição: Este programa demonstra a comunicação e integração entre uma fila e uma pilha. Ele define as estruturas de dados para a fila e a pilha,
// e inclui funções para inserir, remover, empilhar e desempilhar elementos. O programa exibe as pessoas com idade superior a 60 anos, utilizando a pilha para armazenar essas pessoas enquanto percorre a fila.
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
 
Pessoa peek(Pilha *p) {
    return p->dados[p->topo];
}
 
void exibirPilha(Pilha p) {
    while (p.topo >= 0) {
        Pessoa atual = pop(&p);
        printf("Nome: %-10s | Idade: %2d\n", atual.nome, atual.idade);
    }
}
 
int main() {
    Fila fila;
    Pilha pilhaPrioridade;
 
    inicializarFila(&fila);
    inicializarPilha(&pilhaPrioridade);
 
    Pessoa pessoas[] = {
        {"Carlos", 45},
        {"Joana", 62}, 
        {"Lucas", 30},
        {"Maria", 75},
        {"Pedro", 55},
        {"Ana", 68 }
    };
 
    for (int i = 0; i < 6; i++) {
        inserir(&fila, pessoas[i]);
    }
 
    while (fila.inicio < fila.fim) {
        Pessoa atual = remover(&fila);
        if (atual.idade > 60) {
            push(&pilhaPrioridade, atual);
        }
    }
 
    printf("Pessoas com prioridade:\n");
    exibirPilha(pilhaPrioridade);
 
    return 0;
}