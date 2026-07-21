/*
 * Projeto: Gerenciador de Peças - Tetris Stack
 * Autor: Adones [Seu Sobrenome]
 * Data: [12/06/2026]
 * Descrição: Sistema que gerencia peças do Tetris usando fila circular e pilha linear.
 * Objetivo: Demonstrar manipulação de estruturas de dados e operações estratégicas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_MAX_FILA 5
#define TAM_MAX_PILHA 3

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

// Definição da estrutura para representar a pilha de peças do Tetris
typedef struct {
    Peca itens[TAM_MAX_PILHA];
    int topo;
} PilhaPecas;

// Protótipos das funções
void inicializarFila(FilaPecas *f);
int filaCheia(FilaPecas *f);
int filaVazia(FilaPecas *f);
void gerarPeca(Peca *p);
void inserir(FilaPecas *f, Peca p);
void remover(FilaPecas *f, Peca *p);
void mostrarFila(FilaPecas *f);

void inicializarPilha(PilhaPecas *p);
int pilhaVazia(PilhaPecas *p);  
int pilhaCheia(PilhaPecas *p);
void push(PilhaPecas *p, Peca nova);
void pop(PilhaPecas *p, Peca *removida);
void mostrarPilha(PilhaPecas *p);

void mostrarEstado(FilaPecas *fila, PilhaPecas *pilha);
void trocarAtual(FilaPecas *fila, PilhaPecas *pilha);
void trocaMultipla(FilaPecas *fila, PilhaPecas *pilha);
void menu();

//------------------------------------------------------
// VARIÁVEL GLOBAL PARA CONTROLE DE IDs ÚNICOS
//------------------------------------------------------
int contadorID = 0;

// Função principal para testar a implementação da fila de peças do Tetris
int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
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

//------------------------------------------------------
// Implementação das funções da pilha de peças do Tetris
//------------------------------------------------------

// Inicialização e verificação da pilha
void inicializarPilha(PilhaPecas *p) {
    p->topo = -1;
}

int pilhaVazia(PilhaPecas *p) {
    return p->topo == -1;
}

int pilhaCheia(PilhaPecas *p) {
    return p->topo == TAM_MAX_PILHA - 1;
}

// Implementação da função push(inserir) para a pilha
void push(PilhaPecas *p, Peca nova) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o topo
    p->itens[p->topo] = nova;  // Insere o novo elemento
}

// Implementação da função pop(remover) para a pilha 
void pop(PilhaPecas *p, Peca *removida) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há peça para remover.\n");
        return;
    }

    *removida = p->itens[p->topo];  // Copia o valor do topo
    p->topo--;               // Decrementa o topo
}

// Implementação da função peek(consulta) o elemento do topo da pilha sem removê-lo
void peek(PilhaPecas *p, Peca *visualizada) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há peça para ser visualizada.\n");
        return;
    }

    *visualizada = p->itens[p->topo];  // Copia o elemento do topo sem alterar a pilha
}

// Função para exibir as peças na pilha
void mostrarPilha(PilhaPecas *p) {
    printf("\nPilha de Peças:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->itens[i].tipo, p->itens[i].id);
    }
}

// Função para exibir o estado atual da fila e da pilha
void mostrarEstado(FilaPecas *fila, PilhaPecas *pilha) {
    printf("\n================================================\n");
    printf("        ESTADO ATUAL DO JOGO\n");
    printf("================================================\n");
    printf("\nFila de Peças\t(Frente -> Fundo): ");
    for (int i = 0, idx = fila->inicio; i < fila->total; i++, idx = (idx + 1) % TAM_MAX_FILA) {
        printf("[%c %d] ", fila->itens[idx].tipo, fila->itens[idx].id);
    }

    printf("\n");

    printf("Pilha de Reserva\t(Topo -> Base): ");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("[%c %d] ", pilha->itens[i].tipo, pilha->itens[i].id);
    }
}

// Troca a peça da frente da fila com o topo da pilha
void trocarAtual(FilaPecas *fila, PilhaPecas *pilha) {
    if (filaVazia(fila) || pilhaVazia(pilha)) {
        printf("Não é possível trocar: fila ou pilha vazia.\n");
        return;
    }

    int idxFila = fila->inicio;
    Peca temp = fila->itens[idxFila];
    fila->itens[idxFila] = pilha->itens[pilha->topo];
    pilha->itens[pilha->topo] = temp;

    printf("\nOpção escolhida: 4\n");
    printf("Ação: troca realizada entre a peça da frente da fila e o topo da pilha.\n");
    printf("\nNovo estado:\n");
    mostrarEstado(fila, pilha);
}

// Troca múltipla: 3 primeiras da fila com 3 da pilha
void trocaMultipla(FilaPecas *fila, PilhaPecas *pilha) {
    if (fila->total < 3 || pilha->topo < 2) {
        printf("Não é possível realizar a troca múltipla: faltam peças.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        int idxFila = (fila->inicio + i) % TAM_MAX_FILA;
        Peca temp = fila->itens[idxFila];
        fila->itens[idxFila] = pilha->itens[pilha->topo - i];
        pilha->itens[pilha->topo - i] = temp;
    }

    printf("\nOpção escolhida: 5\n");
    printf("Ação: troca realizada entre as 3 primeiras peças da fila e as 3 da pilha.\n");
    printf("\nNovo estado:\n");
    mostrarEstado(fila, pilha);
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

    PilhaPecas pilha;
    inicializarPilha(&pilha);
    for (int i = 0; i < TAM_MAX_PILHA; i++) {
        gerarPeca(&p);
        push(&pilha, p);
    }

    printf("\n================================================\n");
    printf("        JOGO DO TETRIS STACK\n");
    printf("=================================================\n");
    printf("Fila inicializada com %d peças!\n", TAM_MAX_FILA);
    mostrarEstado(&fila, &pilha);
    int opcao;

    do {
        printf("\n================================================\n");
        printf("        JOGO DO TETRIS STACK\n");
        printf("=================================================\n");
        printf("\n===   MENU DE OPÇÕES   ===\n\n");
        printf("1. Jogar peça\n");
        printf("2. Reservar peça\n");
        printf("3. Usar peça reservada\n");
        printf("4. Trocar peça atual (fila ↔ pilha)\n");
        printf("5. Troca múltipla (3 primeiras ↔ 3 da pilha)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                // Lógica para jogar peça (remover da fila)
                remover(&fila, &p);
                printf("Peça jogada: [%c %d]\n", p.tipo, p.id);

                // se houver peças na pilha, usar uma para reabastecer a fila
                if (!pilhaVazia(&pilha)) {
                    pop(&pilha, &p);
                    printf("Peça usada da reserva para reabastecer a fila: [%c %d]\n", p.tipo, p.id);
                } else {
                    gerarPeca(&p);
                    printf("Nova peça gerada para reabastecer a fila: [%c %d]\n", p.tipo, p.id);
                }

                inserir(&fila, p);
                mostrarEstado(&fila, &pilha);
                break;
            
            case 2:
                if (!filaVazia(&fila)) {
                    remover(&fila, &p);

                    if (!pilhaCheia(&pilha)) {
                        push(&pilha, p);
                        printf("Peça reservada: [%c %d]\n", p.tipo, p.id);
                        gerarPeca(&p);
                        printf("Nova peça gerada para reabastecer a fila: [%c %d]\n", p.tipo, p.id);
                        inserir(&fila, p);
                    } else {
                        printf("Erro: pilha cheia. Não é possível reservar.\n");
                    }

                    mostrarEstado(&fila, &pilha);
                } else {
                    printf("Fila vazia! Não há peças para reservar.\n");
                }
                break;

            case 3:
                // Lógica para usar peça reservada (pop da pilha)
                if (!pilhaVazia(&pilha)) {
                    pop(&pilha, &p);
                    printf("Peça usada da reserva: [%c %d]\n", p.tipo, p.id);
                    mostrarEstado(&fila, &pilha);
                } else {
                    printf("Pilha vazia! Não há peças reservadas para usar.\n");
                }
                break;
            
            case 4:
                trocarAtual(&fila, &pilha);
                break;

            case 5:
                trocaMultipla(&fila, &pilha);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0); // Continua até o jogador escolher sair
}