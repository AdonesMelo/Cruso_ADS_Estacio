#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Funções de string(strcpy e strcmg)

// Definir a constante para o comprimento maximo de texto que ele deve ter
#define MAX_STR_LEN 50 // Tamanha maximo da string/texto

//--------------------------------------------------------------------------
// Parte 1: LISTA ESTÁTICA(VETOR DE STRINGS)
// Uma lista estática é uma estrutura de dados de tamanho fixo.
// Emplementado um vetor(ou array).
// Todo memória necessária é alocada de uma só vez, quando a variavel é declarada.
//--------------------------------------------------------------------------

// Definir a constante para o número maximo de itens que ele deve conter
#define TAM_MAX 10 //Definir o tamanho maximo de itens na lista estática.

// Estrutura que representa a lista estática

typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas(itens), 50 colunas(caracteres por item)
    int quantidade; // Este é o contador de controle. Ele informa quantos itens realmente estão armazenado na lista
}ListaEstatica;

// Funções da Lista Estática

// Esta função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como 0, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variável original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);


// ---------------------------------------------------------------
// PARTE 2: LISTA ENCADEADA (DE STRINGS)
// Uma lista encadeada é uma estrutura de dados de tamanho dinâmico.
// Ela é composta por "nós" separados na memória,
// onde cada nó contém um dado e um ponteiro que "aponta" para o próximo nó da sequência.
// ---------------------------------------------------------------

// Estrutura do nó (cada elemento da lista)
// - char* dado: Este é um ponteiro. Ele não armazena o texto em si, mas sim o endereço
// de memória onde o texto está guardado.
// Isso é muito flexível, pois cada texto pode ter um tamanho diferente, e alocamos apenas
// a memória necessária para cada um.
// - struct No *proximo: Este é o ponteiro que cria a "ligação". Ele armazena o endereço do próximo nó na lista.
// O último nó da lista terá este ponteiro apontando para NULL.
typedef struct No {
    char* dado; // Ponteiro para string(alocado dinamicamente)
    struct No *proximo; 
}No;

// Isso é um atalho. Em vez de escrever No* sempre que quisermos nos referir à nossa lista, podemos simplesmente usar
// A "lista" em si é apenas um ponteiro para o primeiro nó (a "cabeça" da lista).
typedef No* ListaEncadeada;

// Funções da Lista Encadeada

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerListaEncadeada(ListaEncadeada *lista, const char* texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista); // Função nova para limpar a memória

//------------------------------------------------------------------------------------
//  --- FUNÇÃO PRINCIPAL(main) E MENUS
//------------------------------------------------------------------------------------

void menuListaEstatica();
void menuListaEncadeada();

int main() {
    int opcao;
    do {
        printf("\n--- MANIPULACAO DE LISTAS (TEXTO) ---\n");
        printf("1. Lista Estatica\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaEncadeada();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// ---------------------------------------------------------------
// IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ESTÁTICA
// ---------------------------------------------------------------

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto) {
    // Primeiro, ela verifica se lista->quantidade já atingiu TAM_MAX.
    // Se sim, a lista está cheia e a função retorna.
    if (lista->quantidade == TAM_MAX) {
        printf("Erro: Lista cheia! Nao e possivel inserir.\n");
        return;
    }
    // A inserção ocorre na primeira "linha" livre da matriz.
    // Para strings, não podemos fazer "lista->dados[i] = texto;", porque em C não se pode atribuir vetores/strings com "=".
    // Precisamos copiar o conteúdo da string para a posição correta na nossa matriz dados.
    strcpy(lista->dados[lista->quantidade], texto);
    // Após a cópia, lista->quantidade é incrementado, pois agora temos mais um item na lista.
    lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}


void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int i, pos = -1;
    // Para comparar strings, usamos strcmp(). Retorna 0 se forem iguais.
    // A função percorre os itens em uso na lista (de 0 até quantidade).
    // Para comparar strings, usamos strcmp(string1, string2).
    // Essa função retorna 0 se as strings forem idênticas. Se encontrar, guarda a posição (pos) e para o loop.
    for (i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->dados[i], texto) == 0) {
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: Se o loop terminar e pos continuar -1, o item não foi encontrado.
    if (pos == -1) {
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    // Fechar a Lacuna: Se removemos um item do meio da lista, criamos um "buraco".
    // Para preenchê-lo, movemos todos os itens subsequentes uma posição para a esquerda.
    // O loop for começa na posição do item removido e copia cada item i+1 para a posição i.
    // Deslocar os elementos posteriores para a esquerda usando strcpy.
    for (i = pos; i < lista->quantidade - 1; i++) {
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    // Atualização do Contador: Finalmente, quantidade é decrementado para refletir que a lista tem um item a menos.
    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
    if (lista->quantidade == 0) {
        printf("A lista estatica esta vazia.\n");
        return;
    }
    printf("Itens da Lista Estatica: [ ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\"%s\" ", lista->dados[i]); // Usar %s para imprimir strings
    }
    printf("]\n");
}

// --------------------------------------------------------------
// IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ENCADEADA
// --------------------------------------------------------------

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto) {
    // 1. Alocar memória para o NOVO NÓ
    // Alocação do Nó: malloc(sizeof(No)) pede ao sistema operacional memória suficiente para um nó.
    // novoNo agora aponta para essa memória.
    No* novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {
        printf("Erro: Falha na alocacao de memoria para o no.\n");
        return;
    }

    // 2. Alocar memória para a STRING DENTRO DO NÓ
    // strlen(texto) + 1 para incluir o caractere nulo '\0' no final
    // Alocação da String: malloc(strlen(texto) + 1) aloca memória para o texto.
    // strlen conta os caracteres, e o +1 é vital para o caractere nulo (\0) que finaliza toda string em C.
    // novoNo->dado agora aponta para este espaço.
    novoNo->dado = (char*) malloc(strlen(texto) + 1);

    if (novoNo->dado == NULL) {
        printf("Erro: Falha na alocacao de memoria para o texto.\n");
        free(novoNo); // Libera o nó que já foi alocado
        return;
    }

    // 3. Copiar o texto para a memória recém-alocada
    // Cópia do texto: strcpy copia o texto de entrada para a área de memória recém-alocada apontada por novoNo->dado.
    strcpy(novoNo->dado, texto);

    // 4. Ligar o novo nó à lista
    // O ponteiro proximo do novo nó passa a apontar para o que era o antigo primeiro nó da lista.
    novoNo->proximo = *lista;
    // A cabeça da lista (*lista) é atualizada para apontar para o novoNo. O novoNo é agora o primeiro item.
    *lista = novoNo;

    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto) {
    // Usamos dois ponteiros, atual e anterior, para percorrer a lista. atual avança, e anterior o segue.
    // Paramos quando atual aponta para o nó a ser removido.
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && strcmp(atual->dado, texto) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    // Se o nó a ser removido for o primeiro (anterior == NULL), a cabeça da lista (*lista) passa a ser o segundo (atual->proximo).
    // Se estiver no meio/fim, o ponteiro proximo do nó anterior "pula" o atual e aponta para atual->proximo.
    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    // Liberação de Memória (Muito Importante): Para evitar vazamento de memória (memory leak), precisamos devolver ao sistema a memória que foi alocada.
    // Primeiro, free(atual->dado): Libera a memória que foi usada para guardar o texto.
    // Depois, free(atual): Libera a memória do próprio nó. Se fizéssemos o contrário, perderíamos a referência para o dado dentro do nó.

    // ANTES de liberar o nó, precisamos liberar a string DENTRO dele.
    free(atual->dado);
    // AGORA podemos liberar o nó.
    free(atual);

    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista) {
    No *temp = lista;
    if (temp == NULL) {
        printf("A lista encadeada esta vazia.\n");
        return;
    }

    printf("Itens da Lista Encadeada: [ ");
    while (temp != NULL) {
        printf("\"%s\" ", temp->dado); // Usar %s para imprimir
        temp = temp->proximo;
    }
    printf("]\n");
}

// Função para liberar toda a memória da lista encadeada no final
// Ela percorre todos os nós da lista, um por um, e aplica a mesma lógica de liberação dupla (free(dado)
// e depois free(nó)) para cada um deles, garantindo que nenhuma memória alocada seja deixada para trás quando o programa terminar.
void liberarListaEncadeada(ListaEncadeada *lista) {
    No *atual = *lista;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->dado);     // Libera a string
        free(atual);           // Libera o nó
        atual = proximo;       // Avança para o próximo nó
    }

    // Após liberar todos os nós, definimos o ponteiro principal como NULL
    *lista = NULL;
    printf("Memória da lista encadeada liberada com sucesso.\n");
}

// ---------------------------------------------------------------
// MENUS DE INTERAÇÃO
// ---------------------------------------------------------------

void menuListaEstatica() {
    ListaEstatica lista;
    inicializarListaEstatica(&lista);
    int opcao;
    char texto[MAX_STR_LEN];

    do {
        printf("\n--- MENU LISTA ESTATICA ---\n");
        printf("1. Inserir texto\n");
        printf("2. Remover texto\n");
        printf("3. Listar textos\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite o texto para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0'; // remove o \n
                inserirListaEstatica(&lista, texto);
                break;
            case 2:
                printf("Digite o texto para remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0';
                removerListaEstatica(&lista, texto);
                break;
            case 3:
                listarListaEstatica(&lista);
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuListaEncadeada() {
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    int opcao;
    char texto[MAX_STR_LEN];

    do {
        printf("\n--- MENU LISTA ENCADEADA ---\n");
        printf("1. Inserir texto\n");
        printf("2. Remover texto\n");
        printf("3. Listar textos\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite o texto para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0';
                inserirListaEncadeada(&lista, texto);
                break;
            case 2:
                printf("Digite o texto para remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0';
                removerListaEncadeada(&lista, texto);
                break;
            case 3:
                listarListaEncadeada(lista);
                break;
            case 0:
                liberarListaEncadeada(&lista);
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
