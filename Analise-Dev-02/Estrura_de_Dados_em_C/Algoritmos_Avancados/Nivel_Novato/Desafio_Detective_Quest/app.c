#include <stdio.h>      // Biblioteca padrão de entrada/saída
#include <stdlib.h>     // Para malloc() e free()
#include <string.h>     // Para manipulação de strings

#define MAX_NOME 50

// --------------------------------------------------------------
// Estrutura da Sala (nó da árvore binária)
// Cada sala possui um nome e até dois caminhos (esquerda/direita).
// --------------------------------------------------------------
typedef struct Sala {
    char nome[MAX_NOME];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// --------------------------------------------------------------
// Protótipos das funções auxiliares
// --------------------------------------------------------------
Sala* criarSala(const char* nome);
void preOrdem(Sala* raiz);
void emOrdem(Sala* raiz);
void posOrdem(Sala* raiz);
void explorarSalas(Sala* raiz);
void liberar(Sala* raiz);

// --------------------------------------------------------------
// Função: main
// Monta o mapa inicial da mansão e inicia o menu de exploração.
// --------------------------------------------------------------
int main() {
    printf("------------------------------------------------\n");
    printf("    Detective Quest - Desafio do Novato\n");
    printf("------------------------------------------------\n");

    // Criação automática da mansão
    Sala* raiz = criarSala("Hall de Entrada");
    raiz->esquerda = criarSala("Sala de Estar");
    raiz->direita = criarSala("Cozinha");

    raiz->esquerda->esquerda = criarSala("Biblioteca");
    raiz->esquerda->direita = criarSala("Jardim");

    raiz->direita->esquerda = criarSala("Despensa");
    raiz->direita->direita = criarSala("Quarto Secreto");

    int opcao;
    // Loop de menu para explorarSalas a mansão e mostrar os percursos
    do {
        printf("\n--- MENU ---\n");
        printf("1. Explorar a mansão\n");
        printf("2. Mostrar percurso em pré-ordem\n");
        printf("3. Mostrar percurso em ordem\n");
        printf("4. Mostrar percurso em pós-ordem\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                explorarSalas(raiz);
                break;
            case 2:
                printf("Percurso pré-ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Percurso em ordem: ");
                emOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Percurso pós-ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    liberar(raiz); // Libera toda a memória alocada para a árvore
    return 0;
}

// --------------------------------------------------------------
// Implementação das funções auxiliares: criarSala, inserirSala, percursos e liberar
// --------------------------------------------------------------

// --------------------------------------------------------------
// Função: criarSala
// Cria dinamicamente uma sala com o nome informado.
// --------------------------------------------------------------
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strncpy(novaSala->nome, nome, MAX_NOME);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para percurso pré-ordem
void preOrdem(Sala* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->nome);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Função para percurso em ordem
void emOrdem(Sala* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->nome);
        emOrdem(raiz->direita);
    }
}

// Função para percurso pós-ordem
void posOrdem(Sala* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->nome);
    }
}

// --------------------------------------------------------------
// Função: explorarSalas
// Permite a navegação do jogador pela árvore binária.
// O jogador escolhe esquerda (e), direita (d) ou sair (s).
// --------------------------------------------------------------
void explorarSalas(Sala* raiz) {
    Sala* atual = raiz;
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se não há caminhos, fim da exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim da exploração! Você chegou a um cômodo sem saída.\n");
            break;
        }

        printf("Escolha caminho (e = esquerda, d = direita): ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else {
            printf("Caminho inválido! Tente novamente.\n");
        }
    }
}

// --------------------------------------------------------------
// Função: liberar
// Libera recursivamente toda a memória alocada para a árvore.
// --------------------------------------------------------------
void liberar(Sala* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}