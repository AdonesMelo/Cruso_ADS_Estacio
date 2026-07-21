#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Definição da estrutura para representar uma pessoa
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

// Definição da estrutura para representar a fila de pessoas
typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Protótipos das funções
void inicializarFila(Fila *f);
int filaCheia(Fila *f);
int filaVazia(Fila *f);
void inserir(Fila *f, Pessoa p);
void remover(Fila *f, Pessoa *p);
void mostrarFila(Fila *f);

// Função principal para testar a implementação da fila
int main() {
    Fila fila;
    Pessoa p;

    inicializarFila(&fila);

    // Adicionando pessoas à fila
    Pessoa p1 = {"João", 30};
    Pessoa p2 = {"Maria", 27};
    Pessoa p3 = {"Jose", 23};
    Pessoa p4 = {"Ana", 25};


    inserir(&fila, p1);
    inserir(&fila, p2);
    inserir(&fila, p3);
    inserir(&fila, p4);

    mostrarFila(&fila);

    // Removendo pessoas da fila
    remover(&fila, &p);
    printf("Pessoa removida: [%s, %d]\n", p.nome, p.idade);

    mostrarFila(&fila);
    
    return 0;
}

//----------------------------------------
// Implementação das funções da fila
//----------------------------------------

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Função para verificar se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Função para adicionar uma pessoa à fila
void inserir(Fila *f, Pessoa p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar mais pessoas.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

// Função para remover uma pessoa da fila
void remover(Fila *f, Pessoa *p) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não há pessoas para remover.\n");
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

// Função para exibir as pessoas na fila
void mostrarFila(Fila *f) { 
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
    }
    printf("\n");
}
