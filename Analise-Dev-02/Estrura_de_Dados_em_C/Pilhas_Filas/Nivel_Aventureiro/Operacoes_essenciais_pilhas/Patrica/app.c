#include <stdio.h>
#include <stdlib.h>

#define MAX 5
 
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

// Protótipos das funções
void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void push(Pilha *p, Pessoa nova);
void pop(Pilha *p, Pessoa *removida);
void peek(Pilha *p, Pessoa *visualizada);
void mostrarPilha(Pilha *p);

// Função main e utilização
int main() {
    Pilha p;
    inicializarPilha(&p);
 
    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};
    Pessoa d = {"João", 30};
    Pessoa e = {"Maria", 23};
 
    push(&p, a);
    push(&p, b);
    push(&p, c);
    push(&p, d);
    push(&p, e);
 
    mostrarPilha(&p);
 
    Pessoa removida;
    pop(&p, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);
 
    mostrarPilha(&p);
 
    Pessoa topo;
    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);

    pop(&p, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);

    mostrarPilha(&p);

    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);
 
    return 0;
}

// Inicialização e verificação
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Implementação da função push(inserir) para a pilha
void push(Pilha *p, Pessoa nova) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o topo
    p->itens[p->topo] = nova;  // Insere o novo elemento
}

// Implementação da função pop(remover) para a pilha 
void pop(Pilha *p, Pessoa *removida) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há pessoa para remover.\n");
        return;
    }

    *removida = p->itens[p->topo];  // Copia o valor do topo
    p->topo--;               // Decrementa o topo
    printf("\n");
}

// Implementação da função peek(consulta) o elemento do topo da pilha sem removê-lo
void peek(Pilha *p, Pessoa *visualizada) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há pessoa para ser visualizada.\n");
        return;
    }

    *visualizada = p->itens[p->topo];  // Copia o elemento do topo sem alterar a pilha
    printf("\n");
}

// Possibilita visualizar todos os elementos da pilha, do topo até a base
void mostrarPilha(Pilha *p) {
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}