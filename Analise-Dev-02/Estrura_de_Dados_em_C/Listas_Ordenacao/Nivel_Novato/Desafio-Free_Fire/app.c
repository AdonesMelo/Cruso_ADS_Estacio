#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10 // Capacidade máxima da mochila

// --------------------------------------------------------------
// Estrutura que representa um item da mochila do jogador.
// Contém nome, tipo e quantidade.
// --------------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// --------------------------------------------------------------
// Estrutura da mochila (lista sequencial).
// Armazena até MAX_ITENS itens e controla a quantidade atual.
// --------------------------------------------------------------
typedef struct {
    Item itens[MAX_ITENS];
    int quantidade;
} Mochila;

// Funções
void inicializarMochila(Mochila *mochila);
void cadastrarItem(Mochila *mochila);
void removerItem(Mochila *mochila);
void listarItens(const Mochila *mochila) ;
void buscarItem(const Mochila *mochila);
void menuTorre();

// --------------------------------------------------------------
// Função principal: inicia o sistema
// --------------------------------------------------------------
int main() {
    menuTorre();
    return 0;
}

// --------------------------------------------------------------
// Inicializa a mochila, definindo quantidade como 0.
// --------------------------------------------------------------
void inicializarMochila(Mochila *mochila) {
    mochila->quantidade = 0;
    printf("Mochila inicializada!\n");
}

// --------------------------------------------------------------
// Cadastra um novo item na mochila.
// Verifica se há espaço disponível antes de inserir.
// --------------------------------------------------------------
void cadastrarItem(Mochila *mochila) {
    if (mochila->quantidade == MAX_ITENS) {
        printf("Erro: Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Cadastro de Item ---\n");
    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo do item (arma, municao, cura, ferramenta): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // limpa o buffer

    mochila->itens[mochila->quantidade] = novo;
    mochila->quantidade++;

    printf("Item \"%s\" cadastrado com sucesso!\n", novo.nome);
}

// --------------------------------------------------------------
// Remove um item da mochila com base no nome informado.
// --------------------------------------------------------------
void removerItem(Mochila *mochila) {
    char nome[30];
    int pos = -1;

    printf("\n--- Remocao de Item ---\n");
    printf("Digite o nome do item para remover: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < mochila->quantidade; i++) {
        if (strcmp(mochila->itens[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Item \"%s\" nao encontrado na mochila.\n", nome);
        return;
    }

    for (int i = pos; i < mochila->quantidade - 1; i++) {
        mochila->itens[i] = mochila->itens[i + 1];
    }

    mochila->quantidade--;
    printf("Item \"%s\" removido com sucesso!\n", nome);
}

// --------------------------------------------------------------
// Lista todos os itens atualmente armazenados na mochila.
// --------------------------------------------------------------
void listarItens(const Mochila *mochila) {
    if (mochila->quantidade == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < mochila->quantidade; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1,
               mochila->itens[i].nome,
               mochila->itens[i].tipo,
               mochila->itens[i].quantidade);
    }
}

// --------------------------------------------------------------
// Busca sequencial por um item com base no nome informado.
// Exibe os dados do item encontrado.
// --------------------------------------------------------------
void buscarItem(const Mochila *mochila) {
    char nome[30];
    printf("\n--- Busca de Item ---\n");
    printf("Digite o nome do item para buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < mochila->quantidade; i++) {
        if (strcmp(mochila->itens[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila->itens[i].nome,
                   mochila->itens[i].tipo,
                   mochila->itens[i].quantidade);
            return;
        }
    }

    printf("Item \"%s\" nao encontrado na mochila.\n", nome);
}

// --------------------------------------------------------------
// Menu principal do sistema de inventário.
// Permite ao jogador cadastrar, remover, listar e buscar itens.
// --------------------------------------------------------------
void menuTorre() {
    Mochila mochila;
    inicializarMochila(&mochila);
    int opcao;
    printf("\n=================================================================================\n");
    printf("        MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
    printf("=================================================================================\n");

    do {
        printf("\n=== MENU MOCHILA ===\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                cadastrarItem(&mochila);
                listarItens(&mochila);
                break;
            case 2:
                removerItem(&mochila);
                listarItens(&mochila);
                break;
            case 3:
                listarItens(&mochila);
                break;
            case 4:
                buscarItem(&mochila);
                break;
            case 0:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}