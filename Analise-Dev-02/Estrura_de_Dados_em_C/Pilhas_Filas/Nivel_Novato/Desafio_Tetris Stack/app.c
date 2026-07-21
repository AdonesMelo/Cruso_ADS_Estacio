#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_MAX_FILA 5

// Definição da estrutura para representar uma peça do Tetris
typedef struct {
    char tipo; // Tipo da peça ('I', 'O', 'T', 'L')
    int id;  // Identificador único da peça
} Peca;

// Definição da estrutura para representar a fila de peças do Tetris
typedef struct {
    Peca itens[TAM_MAX_FILA];
    int inicio;
    int fim;
    int total;
} FilaPecas;

// Protótipos das funções
void inicializarFila(FilaPecas *f);
int filaCheia(FilaPecas *f);
int filaVazia(FilaPecas *f);
void gerarPeca(Peca *p);
void inserir(FilaPecas *f, Peca p);
void remover(FilaPecas *f, Peca *p);
void mostrarFila(FilaPecas *f);
void menu();

// Função principal para testar a implementação da fila de peças do Tetris
int main() {
    srand(time(NULL));
    menu();

    return 0;
}

//----------------------------------------
// Implementação das funções da fila de peças do Tetris
//----------------------------------------
void inicializarFila(FilaPecas *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Função para verificar se a fila está cheia
int filaCheia(FilaPecas *f) {
    return f->total == TAM_MAX_FILA;
}

// Função para verificar se a fila está vazia
int filaVazia(FilaPecas *f) {
    return f->total == 0;
}

// Função para gerar uma peça aleatória do Tetris
int contadorID = 0;
void gerarPeca(Peca *p) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    p->tipo = tipos[rand() % 4];
    p->id = ++contadorID; // Atribui um ID único para cada peça gerada
}

// Função para adicionar uma peça à fila
void inserir(FilaPecas *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir a peça.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % TAM_MAX_FILA;
    f->total++;
}

// Função para remover uma peça da fila
void remover(FilaPecas *f, Peca *p) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não há peças para remover.\n");
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX_FILA;
    f->total--;
}

// Função para exibir as peças na fila
void mostrarFila(FilaPecas *f) {
    printf("\nFila de Peças:\n");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % TAM_MAX_FILA) {
        printf("[%c %d] ", f->itens[idx].tipo, f->itens[idx].id);
    }
    printf("\n");
}

// Função para exibir o menu de opções
void menu() {
    FilaPecas fila;
    Peca p;
    inicializarFila(&fila);
    for (int i = 0; i < TAM_MAX_FILA; i++) {
        gerarPeca(&p);
        inserir(&fila, p);
    }
    printf("\n================================================\n");
    printf("        JOGO DO TETRIS STACK\n");
    printf("=================================================\n");
    printf("Fila inicializada com %d peças!\n", TAM_MAX_FILA);
    mostrarFila(&fila);

    int opcao;

    do {
        printf("\n================================================\n");
        printf("        JOGO DO TETRIS STACK\n");
        printf("=================================================\n");
        printf("\n===   MENU DE OPÇÕES   ===\n\n");
        printf("1. Jogar peça (dequeue)\n");
        printf("2. Inserir nova peça (enqueue)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                // Lógica para jogar peça (remover da fila)
                remover(&fila, &p);
                printf("Peça jogada: [%c %d]\n", p.tipo, p.id);
                mostrarFila(&fila);
                break;
            case 2:
                // Lógica para inserir nova peça na fila
                gerarPeca(&p); // Gerar uma nova peça para inserir
                inserir(&fila, p);
                printf("Nova peça inserida: [%c %d]\n", p.tipo, p.id);
                mostrarFila(&fila);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}