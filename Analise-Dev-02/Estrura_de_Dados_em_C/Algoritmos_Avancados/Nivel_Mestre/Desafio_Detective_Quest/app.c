#include <stdio.h>      // Biblioteca padrão de entrada/saída
#include <stdlib.h>     // Para malloc() e free()
#include <string.h>     // Para manipulação de strings

#define MAX_NOME 50
#define TAMANHO_HASH 20

// --------------------------------------------------------------
// Estrutura da Sala (nó da árvore binária)
// Cada sala possui um nome e até dois caminhos (esquerda/direita).
// Cada sala também possui uma pista associada.
// --------------------------------------------------------------
typedef struct Sala {
    char nome[MAX_NOME];
    char pista[MAX_NOME]; // Pista associada a este cômodo
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// --------------------------------------------------------------
// Estrutura da BST de Pistas
// Cada nó guarda uma pista e aponta para subárvores esquerda/direita.
// O objetivo é armazenar todas as pistas encontradas durante a jornada.
// --------------------------------------------------------------
typedef struct NoPista {
    char pista[MAX_NOME];
    struct NoPista* esquerda;
    struct NoPista* direita;
} NoPista;

// --------------------------------------------------------------
// Estrutura de entrada para tabela hash
// Cada posição da tabela guarda um número de ocupado ou livre
// e o nome da pista que está associada a ela.
// --------------------------------------------------------------
typedef struct {
    char pista[MAX_NOME];
    char suspeito[MAX_NOME];
    int ocupado; // 0 = livre, 1 = ocupado
} EntradaHash;

// tabela hash: vetor de ponteiros para o início da lista
EntradaHash tabela_hash[TAMANHO_HASH];

// --------------------------------------------------------------
// Protótipos das funções auxiliares
// --------------------------------------------------------------

// Árvore binária
Sala* criarSala(const char* nome);
// void preOrdem(Sala* raiz);
// void emOrdem(Sala* raiz);
// void posOrdem(Sala* raiz);
void explorarSalasComPistas(Sala* raiz, NoPista** arvorePistas);
void liberar(Sala* raiz);

// Árvore BST
NoPista* criarNoBST(const char* pista);
NoPista* inserirPista(NoPista* raiz, const char* pista);
const char* buscarSuspeito(const char* pista);
void exibirPistas(NoPista* raiz);
void liberarBST(NoPista* raiz);

// Tabela hash
int hash_pista(const char* pista);
void inserirHash(const char* pista, const char* suspeito);
int verificarAcusacao(const char* suspeito);

// --------------------------------------------------------------
// Função: main
// Monta o mapa inicial da mansão e inicia o menu de exploração.
// --------------------------------------------------------------
int main() {
    printf("------------------------------------------------\n");
    printf("    Detective Quest - Desafio do Mestre\n");
    printf("------------------------------------------------\n");

    // Inicialização da tabela hash
    for (int i = 0; i < TAMANHO_HASH; i++) {
    tabela_hash[i].ocupado = 0;
    }


    // Criação automática da mansão
    Sala* raiz = criarSala("Hall de Entrada");
    raiz->esquerda = criarSala("Sala de Estar");
    raiz->direita = criarSala("Cozinha");

    raiz->esquerda->esquerda = criarSala("Biblioteca");
    raiz->esquerda->direita = criarSala("Jardim");

    raiz->direita->esquerda = criarSala("Despensa");
    raiz->direita->direita = criarSala("Quarto Secreto");

    raiz->esquerda->esquerda->esquerda = criarSala("Escritório");

    // Associação das pistas aos cômodos
    strcpy(raiz->pista, "Pegadas de lama");
    strcpy(raiz->esquerda->pista, "Chave perdida");
    strcpy(raiz->direita->pista, "Lençol manchado");
    strcpy(raiz->esquerda->esquerda->pista, "Livro com página faltando");
    strcpy(raiz->esquerda->direita->pista, "Gaveta aberta");
    strcpy(raiz->direita->esquerda->pista, "Frasco quebrado");
    strcpy(raiz->direita->direita->pista, "Bilhete misterioso");
    strcpy(raiz->esquerda->esquerda->esquerda->pista, "Fotografia rasgada");

    // Associação pista → suspeito
    inserirHash("Pegadas de lama", "Carlos");
    inserirHash("Chave perdida", "Ana");
    inserirHash("Lençol manchado", "Joana");
    inserirHash("Livro com página faltando", "Bruno");
    inserirHash("Gaveta aberta", "Marina");
    inserirHash("Frasco quebrado", "Paulo");
    inserirHash("Bilhete misterioso", "Clara");
    inserirHash("Fotografia rasgada", "Ana");
    
    NoPista* raizPistas = NULL; // Inicializando a árvore de pistas
    int opcao;
    // Loop de menu para explorarSalasComPistas a mansão e mostrar os percursos
    do {
        printf("\n--- MENU ---\n");
        printf("1. Explorar a mansão\n");
        printf("2. Mostrar pistas coletadas\n");
        printf("3. Ajuda\n");
        printf("4. Acusar um suspeito\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                explorarSalasComPistas(raiz, &raizPistas);
                printf("\n--- Pistas coletadas ---\n");
                exibirPistas(raizPistas);
                break;
            case 2:
                printf("\n--- Pistas coletadas até agora ---\n");
                if (raizPistas == NULL)
                    printf("Nenhuma pista coletada ainda.\n");
                else
                    exibirPistas(raizPistas);
                break;
            case 3:
                printf("\n--- AJUDA ---\n");
                printf("1. Explorar a mansão: percorra os cômodos e colete pistas.\n");
                printf("2. Mostrar pistas coletadas: veja todas as pistas encontradas.\n");
                printf("0. Sair: encerra o jogo.\n");
                break;
            case 4:
                char acusado[MAX_NOME];
                printf("\nDigite o nome do suspeito que deseja acusar: ");
                scanf(" %[^\n]", acusado);

                int pistas = verificarAcusacao(acusado);

                // Feedback detalhado
                printf("Foram encontradas %d pistas contra %s.\n", pistas, acusado);

                if (pistas >= 2)
                    printf("Acusação bem-sucedida! %s é o culpado.\n", acusado);
                else
                    printf("Acusação falhou. Não há pistas suficientes contra %s.\n", acusado);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        } 
    } while (opcao != 0);

    liberarBST(raizPistas); // Libera toda a memória alocada para a árvore de pistas
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
// void preOrdem(Sala* raiz) {
//     if (raiz != NULL) {
//         printf("%s ", raiz->nome);
//         preOrdem(raiz->esquerda);
//         preOrdem(raiz->direita);
//     }
// }

// Função para percurso em ordem
// void emOrdem(Sala* raiz) {
//     if (raiz != NULL) {
//         emOrdem(raiz->esquerda);
//         printf("%s ", raiz->nome);
//         emOrdem(raiz->direita);
//     }
// }

// Função para percurso pós-ordem
// void posOrdem(Sala* raiz) {
//     if (raiz != NULL) {
//         posOrdem(raiz->esquerda);
//         posOrdem(raiz->direita);
//         printf("%s ", raiz->nome);
//     }
// }

// --------------------------------------------------------------
// Função: explorarSalasComPistas (com coleta de pistas)
// Permite a navegação pela mansão e coleta automática das pistas.
// --------------------------------------------------------------
void explorarSalasComPistas(Sala* raiz, NoPista** arvorePistas) {
    Sala* atual = raiz;
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se o cômodo tiver uma pista, coleta automaticamente
        if (strlen(atual->pista) > 0) {
            printf("Pista encontrada: \"%s\"\n", atual->pista);
            *arvorePistas = inserirPista(*arvorePistas, atual->pista);
        } else {
            printf("Nenhuma pista neste cômodo.\n");
        }

        // Se não há caminhos, fim da exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim da exploração! Você chegou a um cômodo sem saída.\n");
            break;
        }

        printf("Escolha caminho (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Exploração encerrada.\n");
            break;
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

// ========== Função auxiliar: BST ==========

// --------------------------------------------------------------
// Função: criarNoBST
// Cria um novo nó da BST com a pista informada.
// --------------------------------------------------------------
NoPista* criarNoBST(const char* pista) {
    NoPista* novo = (NoPista*)malloc(sizeof(NoPista));
    if (novo == NULL) {
        printf("Erro ao alocar memória para pista!\n");
        exit(1);
    }
    strncpy(novo->pista, pista, MAX_NOME);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// --------------------------------------------------------------
// Função: inserirPista
// Insere uma pista na BST em ordem alfabética.
// Se a pista já existir, não insere novamente.
// --------------------------------------------------------------
NoPista* inserirPista(NoPista* raiz, const char* pista) {
    if (raiz == NULL)
        return criarNoBST(pista);

    int cmp = strcmp(pista, raiz->pista);
    if (cmp < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (cmp > 0)
        raiz->direita = inserirPista(raiz->direita, pista);
    // Se cmp == 0, significa que a pista já existe → não insere novamente

    return raiz;
}


// Função auxiliar para buscar suspeito pela pista
const char* buscarSuspeito(const char* pista) {
    int indice = hash_pista(pista);
    for (int i = 0; i < TAMANHO_HASH; i++) {
        int pos = (indice + i) % TAMANHO_HASH;
        if (tabela_hash[pos].ocupado == 1 && strcmp(tabela_hash[pos].pista, pista) == 0) {
            return tabela_hash[pos].suspeito;
        }
    }
    return "Desconhecido";
}

// Exibe todas as pistas em ordem alfabética junto com o suspeito
void exibirPistas(NoPista* raiz) {
    if (raiz != NULL) {
        exibirPistas(raiz->esquerda);
        const char* suspeito = buscarSuspeito(raiz->pista);
        printf("- %s (suspeito: %s)\n", raiz->pista, suspeito);
        exibirPistas(raiz->direita);
    }
}

// --------------------------------------------------------------
// Função: liberarBST
// Libera toda a memória alocada para a árvore de pistas.
// --------------------------------------------------------------
void liberarBST(NoPista* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esquerda);
        liberarBST(raiz->direita);
        free(raiz);
    }
}

// ========== Função auxiliar: Tabela Hash ==========

// --------------------------------------------------------------
// Função: hash_pista
// Função hash simples: soma os valores ASCII e módulo pelo tamanho da tabela
// --------------------------------------------------------------
int hash_pista(const char* pista) {
    int soma = 0;
    for (int i = 0; pista[i] != '\0'; i++)
        soma += pista[i];
    return soma % TAMANHO_HASH;
}

// --------------------------------------------------------------
// Função: inserirHash
// Insere uma pista na tabela hash
// -------------------------------------------------------------- 
void inserirHash(const char* pista, const char* suspeito) {
    int indice = hash_pista(pista);
    for (int i = 0; i < TAMANHO_HASH; i++) {
        int pos = (indice + i) % TAMANHO_HASH;
        if (tabela_hash[pos].ocupado == 0) {
            strcpy(tabela_hash[pos].pista, pista);
            strcpy(tabela_hash[pos].suspeito, suspeito);
            tabela_hash[pos].ocupado = 1;
            return;
        }
    }
    printf("Tabela hash cheia! Não foi possível inserir pista.\n");
}

// --------------------------------------------------------------
// Função: verificarAcusacao
// Verifica se a pista está presente na tabela hash
// --------------------------------------------------------------
int verificarAcusacao(const char* suspeito) {
    int contador = 0;
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela_hash[i].ocupado == 1 && strcmp(tabela_hash[i].suspeito, suspeito) == 0) {
            contador++;
        }
    }
    return contador;
}