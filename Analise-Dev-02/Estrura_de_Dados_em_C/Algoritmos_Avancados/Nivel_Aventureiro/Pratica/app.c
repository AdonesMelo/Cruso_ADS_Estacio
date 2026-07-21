/*
Programa: Implementação comparativa de BST e Trie em C
-------------------------------------------------------
Este programa demonstra como construir e utilizar duas estruturas clássicas:
 - BST (Árvore Binária de Busca)
 - Trie (Árvore de Prefixos para Strings)
O código permite inserir e buscar strings, além de visualizar percursos.
Ideal para compreender diferenças práticas e aplicações de cada estrutura.

[PONTO DE ATENCAO #1] Definição das estruturas (BST e Trie)
[PONTO DE ATENCAO #2] Criação de nós e funções básicas para cada estrutura
[PONTO DE ATENCAO #4] Normalização: padroniza a palavra antes de inserir/buscar na Trie
[PONTO DE ATENCAO #5] Inserção e busca: as palavras são inseridas nas duas estruturas
[PONTO DE ATENCAO #6] Visualização: exibe dados em ordem (BST) ou prefixos (Trie)
[PONTO DE ATENCAO #7] Liberação de memória de todas as estruturas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ========= BST: Árvore Binária de Busca ==========

// Estrutura do nó da BST
// [PONTO DE ATENCAO #1] Definição das estruturas (BST e Trie)
typedef struct NoPista {
    char valor[50];
    struct NoPista* esquerda;   // [PONTEIROS] Aponta para o nó-filho à esquerda.
    struct NoPista* direita;    // [PONTEIROS] Aponta para o nó-filho à direita.
} NoPista;

// Cria um novo nó BST
// [PONTO DE ATENCAO #2] Criação de nós e funções básicas para cada estrutura
NoPista* criarNoBST(const char* valor) {
    NoPista* novo = (NoPista*)malloc(sizeof(NoPista)); // [PONTEIROS] malloc retorna o endereço do nó criado, que será manipulado via ponteiro.
    strcpy(novo->valor, valor);
    novo->esquerda = NULL; // [PONTEIROS] Um ponteiro nulo indica "não tem filho" (folha).
    novo->direita = NULL;  // [PONTEIROS] Idem acima.
    return novo;           // [PONTEIROS] Retorna o endereço do nó criado.
}

// Insere elemento na BST (ordem alfabética)
NoPista* inserirBST(NoPista* raiz, const char* valor) {
    if (raiz == NULL)
        return criarNoBST(valor);
    if (strcmp(valor, raiz->valor) < 0)
        raiz->esquerda = inserirBST(raiz->esquerda, valor); // [PONTEIROS] Liga o campo "esquerda" para apontar para o novo subnó.
    else
        raiz->direita = inserirBST(raiz->direita, valor); // [PONTEIROS] Liga o campo "direita" para apontar para o novo subnó.
    return raiz; // [PONTEIROS] Sempre devolve o ponteiro (endereço) da raiz da árvore atualizada.
}

// Busca na BST
bool buscarBST(NoPista* raiz, const char* chave) {
    if (raiz == NULL)
        return false;
    if (strcmp(chave, raiz->valor) == 0)
        return true;
    if (strcmp(chave, raiz->valor) < 0)
        return buscarBST(raiz->esquerda, chave); // [PONTEIROS] Vai seguindo o ponteiro para a esquerda
    else
        return buscarBST(raiz->direita, chave); // [PONTEIROS] Vai seguindo o ponteiro para a direita
}

// Percurso em ordem (ordem alfabética)
// Visita a subárvore esquerda, o nó atual e depois a direita. Exibe valores em ordem alfabética (ou numérica).
void emOrdemBST(NoPista* raiz) {
    if (raiz != NULL) {
        emOrdemBST(raiz->esquerda);   // [PONTEIROS] Percorre a subárvore à esquerda
        printf("%s ", raiz->valor);
        emOrdemBST(raiz->direita);    // [PONTEIROS] Percorre a subárvore à direita
    }
}

// Libera memória da BST
void liberarBST(NoPista* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esquerda);   // [PONTEIROS] Libera toda a subárvore esquerda
        liberarBST(raiz->direita);    // [PONTEIROS] Libera toda a subárvore direita
        free(raiz);                   // [PONTEIROS] Libera o nó atual
    }
}

// ======== Trie: Árvore de Prefixos para Strings =========

#define TAMANHO_ALFABETO 26

// Estrutura do nó Trie
// [PONTO DE ATENCAO #1] Definição das estruturas (BST e Trie)
typedef struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
} NoTrie;

// Cria um novo nó Trie
// [PONTO DE ATENCAO #2] Criação de nós e funções básicas para cada estrutura
NoTrie* criarNoTrie() {
    NoTrie* novo = (NoTrie*)malloc(sizeof(NoTrie));
    novo->ehFimDePalavra = false;
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
        novo->filhos[i] = NULL;
    return novo;
}

// Normaliza string (minúsculas, sem espaços/acentos)
// [PONTO DE ATENCAO #4] Normalização: padroniza a palavra antes de inserir/buscar
void normalizar(const char* entrada, char* saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        if (c >= 'A' && c <= 'Z') c += 32; // Converte maiúscula
        if (c >= 'a' && c <= 'z') saida[j++] = c; // Apenas letras
    }
    saida[j] = '\0';
}

// Insere palavra na Trie
void inserirTrie(NoTrie* raiz, const char* palavra) {
    NoTrie* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL)
            atual->filhos[indice] = criarNoTrie();
        atual = atual->filhos[indice];
    }
    atual->ehFimDePalavra = true;
}

// Busca palavra na Trie
bool buscarTrie(NoTrie* raiz, const char* palavra) {
    NoTrie* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL)
            return false;
        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->ehFimDePalavra;
}

// Lista palavras na Trie (lexicográfica)
void listarPalavras(NoTrie* no, char* buffer, int nivel) {
    if (no->ehFimDePalavra) {
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            buffer[nivel] = 'a' + i;
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

// Libera memória da Trie
void liberarTrie(NoTrie* no) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL)
            liberarTrie(no->filhos[i]);
    }
    free(no);
}

// ========== Função principal: Demonstração ==========
// [PONTO DE ATENCAO #5] Inserção e busca: as palavras são inseridas nas duas estruturas
int main() {
    // ---------- BST ----------
    printf("\n==== BST ====\n");
    NoPista* raizBST = NULL;
    raizBST = inserirBST(raizBST, "Pegadas de Lama");
    raizBST = inserirBST(raizBST, "Chave perdida");
    raizBST = inserirBST(raizBST, "Livro com pagina faltando");
    raizBST = inserirBST(raizBST, "Lençol manchado");
    raizBST = inserirBST(raizBST, "Gaveta perdida");

    printf("Em ordem (BST): ");
    emOrdemBST(raizBST);
    printf("\nBuscar 'Lençol manchado' (BST): %s\n", buscarBST(raizBST, "Lençol manchado") ? "Encontrado" : "Não encontrado");
    printf("Buscar 'Óculos' (BST): %s\n", buscarBST(raizBST, "Óculos") ? "Encontrado" : "Não encontrado");

    // ------- Trie --------
    printf("\n==== Trie ====\n");
    NoTrie* raizTrie = criarNoTrie();
    char normalizada[100];

    // Inserção de palavras normalizadas (minúsculo, sem espaço)
    normalizar("Pegadas de Lama", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Chave perdida", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Livro com pagina faltando", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Lençol manchado", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Gaveta perdida", normalizada);
    inserirTrie(raizTrie, normalizada);

    printf("Palavras na Trie: ");
    char buffer[100];
    // [PONTO DE ATENCAO #6] Visualização: exibe dados em ordem (BST) ou prefixos (Trie)
    listarPalavras(raizTrie, buffer, 0);
    printf("\n");
    normalizar("Lencol manchado", normalizada);
    printf("Buscar 'lencolmanchado' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontrado" : "Não encontrado");
    normalizar("Oculos", normalizada);
    printf("Buscar 'oculos' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontrado" : "Não encontrado");

    // Liberação de memória
    // [PONTO DE ATENCAO #7] Liberação de memória de todas as estruturas
    liberarBST(raizBST);
    liberarTrie(raizTrie);

    return 0;
}
