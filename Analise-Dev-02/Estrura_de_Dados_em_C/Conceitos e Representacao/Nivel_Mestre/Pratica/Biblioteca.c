// ############################################################################
// PRÁTICA: SISTEMA DE BIBLIOTECA  - PARTE 3
//
// OBJETIVO DESSA PARTE:
// Modularizar o codigo com funções especializadas, aplicado boas praticas.
//  - Passagem por valor (para exibição) e por referência (para modificação).
//  - Funções para cada fucionalidade principal do sistema.
//  - A função main() se torna um 'orquestrador', chamando as outras.
// ############################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn(), um biblioteca para manipular string

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 // Capacidade para empréstimos.

// --- Definir a estrutura (STRUCT) ---
// Adicionar Struct Livro um novo campo 'disponivel' para controlar o status.
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editor[TAM_STRING];
    int edicao;
    int disponivel; // usar 1 para sim e 0 para não.
};

// Nova struct para armazenar irformações de empréstimos.
struct Emprestimo {
    int indeceLivro; // Para sabre qual livro do array 'biblioteca' foi empréstado.
    char nomeUsuario[TAM_STRING];
};

// Declara as funções, permitem que o 'main' chame antes de suas definições
void limparBufferEntrada();
void menu(struct Livro *biblioteca, struct Emprestimo *emprestimos);
void cadastrarLivros(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimo(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void limparMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);



// --- Função principal (main) ---
int main() {
    // 1. ALOCAÇÃO DINÂMICA NA MEMÓRIA
    // Agora, em vez arrays esáticos, usamos ponteiros
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos; 

    // Usar calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento).
    // Vantangem: Inicializar toda memória com zeros. Isso significa que o 'disponivel' já começa com o valor de 0.
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usar malloc para o array de emprestimos. malloc(tamanho_total_em_bytes).
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // Verificação: é crucial verificar se alocação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: falha ao locar memória.\n");
        return 1; // retornar 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    // --- Laço principal do Menu ---
    do{
        menu(biblioteca, emprestimos);

        // Lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // limpar o '\n' deixado pelo scanf.

        // --- Processamento da opção
        switch (opcao) {
            case 1: // Cadastro de livros
                cadastrarLivros(biblioteca, &totalLivros);
                break;

            case 2: // LISTAGEM DE LIVROS
                listarLivros(biblioteca, totalLivros);
                break;

            case 3: // REALIZAR EMPRÉSTIMO
                realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
                break;

            case 4: // Lista de Empréstimos
                listarEmprestimo(biblioteca, emprestimos, totalEmprestimos);
                break;

            case 0: // Sair
                printf("\nSaindo do Sistema...\n");
                break;
            
            default: // Opção Inválida
                printf("\nOpção Inválida! Tente novamente.");
                printf("\nPressione Enter para continuar...");
                getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
                break;
        }
    } while (opcao !=0);

    // 2. Liberação da Memória
    //  - Antes de terminar, é essencial liberar a memória que foi alocada dinâmicamente.
    //  - Isso evita "memory leaks" (vazamento de memória).
    limparMemoria(biblioteca, emprestimos);


    return 0; // Fim do progama!
}

// Implementações das funções

// --- Função para limpar buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibir o menu de opções
void menu(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
    printf("####################################\n");
    printf("    BIBLIOTECA - PARTE 3\n");
    printf("####################################\n");
    printf("1 - Cadastrar um novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar um empréstimo\n");
    printf("4 - Listar empréstimos\n");
    printf("0 - Sair\n");
    printf("**************************************\n");
    printf("Escolha uma opção: ");
}

// Cadastrar livros
void cadastrarLivros(struct Livro *biblioteca, int *totalLivros) {
    printf("--- Cadastro de um Novo Livro ---\n\n");

    if (*totalLivros < MAX_LIVROS) {
        int indice = *totalLivros; // Usar o valor apontado  pelo ponteiro para o índice
        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);

        printf("Digite o nome do autor: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);

        printf("Digite o nome da editora: ");
        fgets(biblioteca[indice].editor, TAM_STRING, stdin);

        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editor[strcspn(biblioteca[indice].editor, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d", &biblioteca[indice].edicao);
        limparBufferEntrada();

        biblioteca[indice].disponivel = 1; // marca como disponível

        (*totalLivros)++; // Contador de livros, incrementar o valor da variavel original na main.
        // totalLivros = totalLivros+

        printf("\nLivro cadastrado com sucesso!\n");

    } else {
        printf("Biblioteca está cheia! Não é posivel cadastra mais livros.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
}

// Listar os livros que foram cadastrados
// 'biblioteca' é array (ponteiro constante, apenas para leitura)
void listarLivros(const struct Livro *biblioteca, int totalLivros) {
    printf("--- Listar livros cadastrados ---\n");

    if (totalLivros == 0) {
        printf("Nenhum livro casdatrado ainda!\n");
    } else {
        for (int i = 0; i < totalLivros; i++) {
            printf("*****************************************\n");
            printf("Livro: %d\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            // Mostar o status de disponibilidade.
            printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Empréstado");
        }
        printf("*****************************************\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
}

// Pegar um livro emprestado na biblioteca
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
    printf("--- Realizar Empréstimos ---\n\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de empréstimos atingido!");
    } else {
        printf("Livros disponiveis:\n");
        int disponiveis = 0;
        for (int i = 0; i < totalLivros; i++) {
            if (biblioteca[i].disponivel) {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }     
        }

        if (disponiveis == 0) {
            printf("Nenhum livro disponivel para empréstimo!\n");
        } else {
            printf("\nDigite o número do livro que deseja emprestar: ");
            int numLivro;
            scanf("%d", &numLivro);
            limparBufferEntrada();

            int indice = numLivro - 1; // Converter para o indice do array (0 a N-1)

            // Validação da escolhar do usúario.
            if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                printf("Digite o nome do usúario que está pegando o livro: ");
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';

                // Registra empréstimo
                emprestimos[*totalEmprestimos].indeceLivro = indice;

                // Atualizar o status do livro para indisponivel
                biblioteca[indice].disponivel = 0;

                (*totalEmprestimos)++;
                printf("\nEmpréstimo realizado com sucesso!\n");
            } else {
                printf("\nNúmero de livro invalido ou livro indisponivel!\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
}

// Listar livros que foram emprestados
// 'biblioteca' é array (ponteiro constante, apenas para leitura)
// 'emprestimos' é array (ponteiro constante, apenas para leitura)
void listarEmprestimo(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos) {
    printf("--- Lista de Empréstimos ---\n\n");
    if (totalEmprestimos == 0) {
        printf("Nenhum empréstimos realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++) {
            // Usar o indice armazenado no empréstimos para busca o nome do livro
            int indiceLivro = emprestimos[i].indeceLivro;
            printf("***************************************\n");
            printf("EMPRÉSTIMO %d\n", i +1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usúario: %s\n", emprestimos[i].nomeUsuario);
        }
        printf("***************************************\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar(); // Uma pausa para o usuário ler a messagem, antes de voltar ao menu
}
    
// liberar a memória
void limparMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
    free(biblioteca);
    free(emprestimos);

    printf("Memória liberada com sucesso!\n");
}