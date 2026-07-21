#include <stdio.h>
#include <string.h> // Para strcspn(), uma biblioteca para manipular strings
#include <stdlib.h>
#include <time.h>

// --- Constantes Globais ---
#define MAX_TER 5 // Número máximo de territórios a cadastrar

// --- Estrutura de dados (STRUCT) ---
// Representa um território com nome, cor do exército e número de tropas.
struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função para limpar buffer de entrada ---
// Evita que o '\n' deixado pelo scanf interfira nas próximas leituras.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função de ataque
// Simula uma batalha entre dois territórios usando dados (1 a 6).
// Atualiza o número de tropas e pode transferir posse do território.
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dadoA = rand() % 6 + 1; // rolagem do atacante
    int dadoD = rand() % 6 + 1; // rolagem do defensor

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, dadoA);
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, dadoD);

    if (dadoA > dadoD) {
        defensor->tropas--; // defensor perde tropa
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");

        // Se o defensor ficar sem tropas, território é conquistado
        if (defensor->tropas <= 0) {
            printf("%s foi conquistado pelo exército %s!\n", defensor->nome, atacante->cor);
            // Transferir posse: copiar cor do atacante para o defensor
            strcpy(defensor->cor, atacante->cor);
            // Opcional: mover 1 tropa para o território conquistado
            defensor->tropas = 1; // mínimo de tropas no território conquistado
            atacante->tropas--; // atacante move uma tropa para ocupar
        }
    } else {
        atacante->tropas--; // atacante perde tropa
        printf("DEFESA RESISTIU! O atacante perdeu 1 tropa.\n");
    }

    printf("\nPressione Enter para continuar para o próximo turno...");
    getchar();
}


// --- Função principal ---
int main() {
    srand(time(NULL)); // inicializa gerador de números aleatórios

    // 1. ALOCAÇÃO DINÂMICA NA MEMÓRIA
    // Agora, em vez array esático, usar ponteiro
    struct Territorio *territorios; 

    // Usar malloc para o array de emprestimos. malloc(tamanho_total_em_bytes).
    territorios = (struct Territorio *) malloc(MAX_TER * sizeof(struct Territorio));

    // Verificação: é crucial verificar se alocação de memória deu certo.
    if (territorios == NULL) {
        printf("Erro: falha ao locar memória.\n");
        return 1; // retornar 1 para indicar um erro.
    }

    // Exibir o menu de opções
    printf("\n###########################################################\n");
    printf("    WAR ESTRUTURADO - CADASTRO INICIAL");
    printf("\n###########################################################\n");

    for (int i = 0; i < MAX_TER; i++) {
            printf("\n--- Cadastro Território - %d ---\n", i + 1);

            printf("Nome do Território: ");
            fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
            territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove o '\n'

            printf("Cor do Exército (ex: Azul, Verde): ");
            fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
            territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Remove o '\n'

            printf("Número de Tropas: ");
            scanf("%d", &territorios[i].tropas);

            limparBufferEntrada(); // limpar o '\n' deixado pelo scanf.
    }

    printf("\nCadastro inicial concluído com sucesso.\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Uma pausa para o usuário ler a messagem

    int opcao;
    // --- Loop principal da fase de ataque ---
    do {
        // Exibe o mapa atualizado
        printf("\n###########################################################\n");
        printf("    MAPA DO MUNDO - ESTADO ATUAL\n");
        printf("###########################################################\n");

        for (int i = 0; i < MAX_TER; i++) {
            printf("%d. %s (Exército %s, Tropas: %d)\n",
                i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
        }

        // Escolha do atacante
        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o território atacante (1 a %d, ou 0 para sair): ", MAX_TER);
        scanf("%d", &opcao);
        limparBufferEntrada();

        if (opcao == 0) {
            printf("\nSaindo do Sistema...\n");
            break;
        }

        if (opcao < 1 || opcao > MAX_TER) {
            printf("\nOpção inválida!\n");
            continue;
        }

        int atacante = opcao - 1;

        // Validação: atacante precisa ter pelo menos 2 tropas
        if (territorios[atacante].tropas < 2) {
            printf("\nO atacante precisa ter pelo menos 2 tropas para atacar!\n");
            continue;
        }

        // Escolha do defensor
        printf("Escolha o território defensor (1 a %d): ", MAX_TER);
        int defensor;
        scanf("%d", &defensor);
        limparBufferEntrada();

        if (defensor < 1 || defensor > MAX_TER || defensor == opcao) {
            printf("\nDefensor inválido!\n");
            continue;
        }

        defensor = defensor - 1;

        // Executa a batalha
        atacar(&territorios[atacante], &territorios[defensor]);

    } while (opcao != 0);

    // Liberação da memória
    free(territorios);
    printf("\nMemória liberada com sucesso!\n");
    printf("\nFim do programa.\n");

    return 0;
}