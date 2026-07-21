/*
    Programa: Implementação de Árvore Binária em C
    ------------------------------------------------------------
    Este programa demonstra como construir uma árvore binária simples
    utilizando alocação dinâmica de memória em C. Ele permite:
    - Inserir elementos na árvore binária (alocação dinâmica)
    - Percorrer e exibir os elementos usando:
        * Pré-ordem
        * Em ordem
        * Pós-ordem

    [PONTO DE ATENCAO #1] Estrutura básica do nó da árvore binária  
    [PONTO DE ATENCAO #2] Função responsável por criar um novo nó  
    [PONTO DE ATENCAO #3] Função de inserção: posiciona o novo valor na árvore  
    [PONTO DE ATENCAO #4A] Percurso pré-ordem: raiz, esquerda, direita  
    [PONTO DE ATENCAO #4B] Percurso em ordem: esquerda, raiz, direita  
    [PONTO DE ATENCAO #4C] Percurso pós-ordem: esquerda, direita, raiz  
    [PONTO DE ATENCAO #5] Liberação de toda a memória usada pela árvore  
    [PONTO DE ATENCAO #6] Execução do programa: montagem da árvore e demais operações 
    [PONTO DE ATENCAO #6A] Inserção dos valores iniciais  
    [PONTO DE ATENCAO #6B] Exibição em pré-ordem  
    [PONTO DE ATENCAO #6C] Exibição em ordem  
    [PONTO DE ATENCAO #6D] Exibição em pós-ordem  
    [PONTO DE ATENCAO #6E] Liberação da árvore
*/

#include <stdio.h>      // Biblioteca padrão de entrada/saída
#include <stdlib.h>     // Para malloc() e free()
#include <string.h>     // Para manipulação de strings

// Definição da estrutura do nó da árvore binária
// [PONTO DE ATENCAO #1] Estrutura básica do nó da árvore binária
typedef struct No {
    char valor[50];         // Valor armazenado no nó (aqui, string)
    struct No* esquerda;    // Ponteiro para o filho esquerdo
    struct No* direita;     // Ponteiro para o filho direito
} No;

/*
    Função: criarNo
    ---------------------------------
    Aloca dinamicamente um novo nó, define o valor
    e inicializa os ponteiros dos filhos como NULL.
*/
// [PONTO DE ATENCAO #2] Função responsável por criar um novo nó
No* criarNo(const char* valor) {
    No* novo = (No*)malloc(sizeof(No));    // Alocação dinâmica de memória
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);    // Encerra o programa em caso de erro de memória
    }
    strcpy(novo->valor, valor);    // Copia a string valor para o campo do nó
    novo->esquerda = NULL;         // Inicializa filho esquerdo como NULL
    novo->direita = NULL;          // Inicializa filho direito como NULL
    return novo;
}

/*
    Função: inserir
    --------------------------------------------------
    Insere um novo valor na árvore binária de forma recursiva.
    Aqui, usamos ordem alfabética para organizar os nós.
    - Se valor < nó atual → vai para a subárvore esquerda
    - Se valor >= nó atual → vai para a subárvore direita
*/
// [PONTO DE ATENCAO #3] Função de inserção: posiciona o novo valor na árvore 
No* inserir(No* raiz, const char* valor) {
    if (raiz == NULL) {
        // Se a árvore (ou subárvore) está vazia, cria um novo nó
        return criarNo(valor);
    }
    if (strcmp(valor, raiz->valor) < 0) {
        // Insere na subárvore esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        // Insere na subárvore direita
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

/*
Função: preOrdem
---------------------------------------------
Percorre e imprime a árvore em pré-ordem (raiz, esquerda, direita)
*/
// [PONTO DE ATENCAO #4A] Percurso pré-ordem: raiz, esquerda, direita
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor);        // Visita o nó atual (raiz)
        preOrdem(raiz->esquerda);          // Visita a subárvore esquerda
        preOrdem(raiz->direita);           // Visita a subárvore direita
    }
}

/*
Função: emOrdem
--------------------------------------------
Percorre e imprime a árvore em ordem (esquerda, raiz, direita)
Ideal para exibir valores em ordem alfabética.
*/
// [PONTO DE ATENCAO #4B] Percurso em ordem: esquerda, raiz, direita
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);      // Esquerda primeiro
        printf("%s ", raiz->valor);   // Depois a raiz
        emOrdem(raiz->direita);       // Depois a direita
    }
}

/*
Função: posOrdem
-----------------
Percorre e imprime a árvore em pós-ordem (esquerda, direita, raiz)
Útil para liberar memória ou avaliar expressões.
*/

// [PONTO DE ATENCAO #4C] Percurso pós-ordem: esquerda, direita, raiz
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);   // Esquerda
        posOrdem(raiz->direita);    // Direita
        printf("%s ", raiz->valor); // Raiz por último
    }
}

/*
Função: liberar
--------------------------------------------------
Libera recursivamente toda a memória alocada para a árvore.
*/
// [PONTO DE ATENCAO #5] Liberação de toda a memória usada pela árvore
void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz); // Libera o nó atual
    }
}

/*
Função principal: main
-------------------------------------
Monta uma árvore binária simples, insere alguns valores,
e demonstra os três percursos fundamentais.
*/
// [PONTO DE ATENCAO #6] Execução do programa: montagem da árvore e demonstração dos percursos
int main() {
    No* raiz = NULL;  // Inicializa a árvore como vazia

    // Insere elementos na árvore (valores de exemplo)
    raiz = inserir(raiz, "Hall de Entrada");
    raiz = inserir(raiz, "Sala de Estar");
    raiz = inserir(raiz, "Biblioteca");
    raiz = inserir(raiz, "Quarto");

    // Exibe os elementos da árvore em cada tipo de percurso
    printf("Pré-ordem: ");
    preOrdem(raiz);
    // [PONTO DE ATENCAO #6B] Exibição em pré-ordem
    printf("\n");

    printf("Em ordem: ");
    emOrdem(raiz);
    // [PONTO DE ATENCAO #6C] Exibição em ordem
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);

    // [PONTO DE ATENCAO #6C] Exibição em ordem
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    // [PONTO DE ATENCAO #6D] Exibição em pós-ordem
    printf("\n");

    // Libera toda a memória alocada para a árvore
    liberar(raiz);
    // [PONTO DE ATENCAO #6E] Liberação da árvore

    return 0;
}

