/*
[Ponto de Atenção #1] Métodos de colisão em Tabela Hash
- Encadeamento (Chaining): Cada posição da tabela aponta para o início c
- Sondagem Linear (Linear Probing): Todos os dados ficam no próprio vet
*/
/*
Programa: Tabela Hash Simples em C com Encadeamento e Sondagem Linear
---------------------------------------------------------------
Este programa demonstra como implementar uma tabela hash para strings
explorando duas estratégias de tratamento de colisão:
    - Encadeamento (Chaining) com listas ligadas
    - Sondagem Linear (Linear Probing)
Permite inserir, buscar e remover palavras, além de visualizar a tabel
Ideal para consolidar o modelo chave-valor e as diferentes abordagens
de colisão.

[Ponto de Atenção #1] Métodos de colisão em Tabela Hash
[Ponto de Atenção #2] Definição do nó da lista ligada para encadeamento
[Ponto de Atenção #3] Função hash: transforma a palavra em índice da tabela
[Ponto de Atenção #4] Função de inserção: lógica para encadeamento
[Ponto de Atenção #5] Função de busca: busca elemento na lista ligada
[Ponto de Atenção #6] Função de remoção: remoção na lista (chaining)
[Ponto de Atenção #7] Função de visualização da tabela com encadeamento
[Ponto de Atenção #8] Fluxo principal do programa: inicialização, inserção
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10 // Tamanho fixo da tabela hash

/*******************************************************
 * Estrutura 1: Tabela Hash com Encadeamento (Chaining)
 *******************************************************/

// Nó da lista ligada usada para encadeamento
// [Ponto de Atenção #2] Definição do nó da lista ligada para encadeamento
typedef struct Nodo {
    char valor[50];
    struct Nodo* proximo;
} Nodo;

// Tabela hash: vetor de ponteiros para o início da lista
Nodo* tabela_chaining[TAMANHO_TABELA];

// Função hash simples: soma dos valores ASCII e módulo pelo tamanho da t
// [Ponto de Atenção #3] Função hash: transforma a palavra em índice da t
int funcao_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % TAMANHO_TABELA;
}

// Inserção com encadeamento
// [Ponto de Atenção #4] Função de inserção: lógica para encadeamento
void inserir_chaining(const char* valor) {
    int indice = funcao_hash(valor);
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->valor, valor);
    novo->proximo = tabela_chaining[indice]; // Insere no início da lista
    tabela_chaining[indice] = novo;
}

// Busca com encadeamento
// [Ponto de Atenção #5] Função de busca: busca elemento na lista ligada
Nodo* buscar_chaining(const char* valor) {
    int indice = funcao_hash(valor);
    Nodo* atual = tabela_chaining[indice];
    while (atual != NULL) {
        if (strcmp(atual->valor, valor) == 0)
            return atual; // Encontrado
        atual = atual->proximo;
    }
    return NULL; // Não encontrado
}

// Remoção com encadeamento
// [Ponto de Atenção #6] Função de remoção: remoção na lista (chaining)
void remover_chaining(const char* valor) {
    int indice = funcao_hash(valor);
    Nodo* atual = tabela_chaining[indice];
    Nodo* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->valor, valor) == 0) {
            if (anterior == NULL)
                tabela_chaining[indice] = atual->proximo; // Era o prime
            else
                anterior->proximo = atual->proximo;
            free(atual);
            printf("'%s' removido (chaining).\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("'%s' não encontrado para remoção (chaining).\n", valor);
}

// Visualização da tabela com encadeamento
// [Ponto de Atenção #7] Função de visualização da tabela com encadeamento
void mostrar_chaining() {
    printf("\nTabela Hash (Chaining):\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%d]: ", i);
        Nodo* atual = tabela_chaining[i];
        while (atual != NULL) {
            printf("%s -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

/******************************************************
 * Estrutura 2: Tabela Hash com Sondagem Linear
 ******************************************************/

// Estrutura de entrada para sondagem linear
typedef struct {
    char valor[50];
    int ocupado; // 0 = livre, 1 = ocupado, -1 = removido
} Entrada;

Entrada tabela_linear[TAMANHO_TABELA];

// Inserção com sondagem linear
// [Ponto de Atenção #4] Função de inserção: lógica para sondagem linear
void inserir_linear(const char* valor) {
    int indice = funcao_hash(valor);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;
        if (tabela_linear[pos].ocupado == 0 || tabela_linear[pos].ocupado == -1) {
            strcpy(tabela_linear[pos].valor, valor);
            tabela_linear[pos].ocupado = 1;
            return;
        }

    }
    printf("Tabela cheia. Não foi possível inserir '%s'.\n", valor);
}


// Busca com sondagem linear
// Função de busca: procura elemento no vetor (linear probing)
int buscar_linear(const char* valor) {
    int indice = funcao_hash(valor);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;
        if (tabela_linear[pos].ocupado == 0) {
            return -1; // Livre: não está presente
        }
        if (tabela_linear[pos].ocupado == 1 && strcmp(tabela_linear[pos].valor, valor) == 0) {
            return pos; // Encontrado
        }
        // Se ocupado == -1 (removido), continua procurando
    }
    return -1; // Não encontrado
}


// Remoção com sondagem linear
// [Ponto de Atenção #6] Função de remoção: remoção por marcação na tabela
void remover_linear(const char* valor) {
    int pos = buscar_linear(valor);
    if (pos == -1) {
        printf("'%s' não encontrado para remoção (linear).\n", valor);
        return;
    }
    tabela_linear[pos].ocupado = -1; // Marca como removido
    printf("'%s' removido (linear).\n", valor);
}

// Visualização da tabela com sondagem linear
// [Ponto de Atenção #7] Função de visualização da tabela linear
void mostrar_linear() {
    printf("\nTabela Hash (Linear Probing):\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%d]: ", i);
        if (tabela_linear[i].ocupado == 1)
            printf("%s\n", tabela_linear[i].valor);
        else if (tabela_linear[i].ocupado == -1)
            printf("<removido>\n");
        else
            printf("<livre>\n");
    }
}

/********************************************************************************************
 * Função principal: Demonstração das duas abordagens
 ********************************************************************************************/
// [Ponto de Atenção #8] Fluxo principal do programa: inicialização, ins
int main() {
    // Inicializa as tabelas
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_chaining[i] = NULL;
        tabela_linear[i].ocupado = 0;
    }

    // Palavras de exemplo
    const char* palavras[] = {
        "Ana", "Bruno", "Carlos", "Amanda", "Paulo",
        "Lucas", "Marina", "Joana", "Roberta", "Clara", "Daniel"
    };
    int n = sizeof(palavras) / sizeof(palavras[0]);

    // Inserção nas duas tabelas
    for (int i = 0; i < n; i++) {
        inserir_chaining(palavras[i]);
        inserir_linear(palavras[i]);
    }

    // Visualização das tabelas após inserção
    mostrar_chaining();
    mostrar_linear();

    // Busca por alguns nomes
    printf("\nBuscando 'Bruno' (chaining): %s\n", buscar_chaining("Bruno"));
    printf("Buscando 'Joana' (linear): %s\n", buscar_linear("Joana") != -1 ? "Encontrado" : "Não encontrado");
    printf("Buscando 'Zeca' (chaining): %s\n", buscar_chaining("Zeca") ? "Encontrado" : "Não encontrado");

    // Remoção de alguns nomes
    remover_chaining("Carlos");
    remover_linear("Carlos");
    remover_chaining("Zeca");    // Teste de não existente
    remover_linear("Zeca");      // Teste de não existente

    // Visualização final das tabelas
    mostrar_chaining();
    mostrar_linear();

    // Liberação da memória da tabela chaining
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Nodo* atual = tabela_chaining[i];
        while (atual != NULL) {
            Nodo* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    return 0; 
}
