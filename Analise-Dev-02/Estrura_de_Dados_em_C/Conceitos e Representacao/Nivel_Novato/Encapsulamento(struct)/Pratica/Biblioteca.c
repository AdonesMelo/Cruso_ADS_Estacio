// ############################################################################
// PRÁTICA: SISTEMA DE BIBLIOTECA  - PARTE 1
//
// OBJETIVO DESSA PARTE:
// Implementar um cadastro e uma lista de livros usuando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.
//
//
//
//
// ############################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn(), um biblioteca para manipular string

// --- Constantes Globais
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definir a estrutura (STRUCT)
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editor[TAM_STRING];
    int edicao;
};

// --- Função para limpar buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal (main) ---
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laço principal do Menu ---
    do{
        // Exibir o menu de opções
        printf("####################################\n");
        printf("    BIBLIOTECA - PARTE 1\n");
        printf("####################################\n");
        printf("1 - Cadastrar um novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("**************************************\n");
        printf("Escolha uma opção: ");

        // Lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // limpar o '\n' deixado pelo scanf.

        // --- Processamento da opção
        switch (opcao) {
            case 1: // Cadastro de livros
                printf("--- Cadastro de um Novo Livro ---\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o nome do autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite o nome da editora: ");
                    fgets(biblioteca[totalLivros].editor, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editor[strcspn(biblioteca[totalLivros].editor, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++; // Contador de livros
                    // totalLivros = totalLivros+

                    printf("\nLivro cadastrado com sucesso!\n");

                } else {
                    printf("Biblioteca está cheia! Não é posivel cadastra mais livros.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu

                break;

            case 2: // LISTAGEM DE LIVROS
                printf("--- Listar livros cadastrados ---\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro casdatrado ainda!\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("*****************************************\n");
                        printf("Livro: %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editor);
                        printf("Edição: %d\n", biblioteca[i].edicao);
                    }
                    printf("*****************************************\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
                break;
            
            case 0: // Sair
                printf("\nSaindo do Sistema...\n ");
                break;
            
            default: // Opção Inválida
                printf("\nOpção Inválida! Tente novamente.");
                printf("\nPressione Enter para continuar...");
                getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
                break;
        }
    } while (opcao !=0);

    return 0; // Fim do progama!
}