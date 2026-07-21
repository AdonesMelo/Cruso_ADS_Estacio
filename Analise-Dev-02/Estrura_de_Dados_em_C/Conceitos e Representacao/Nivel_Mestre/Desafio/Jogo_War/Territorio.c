#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
#define MAX_TER 2
#define TOTAL_MISSOES 5

// --- Vetor de missões ---
char *missoes[TOTAL_MISSOES] = {
    "Conquistar todos os territórios.",
    "Eliminar todas as tropas da cor Vermelha.",
    "Manter pelo menos 5 tropas em cada território.",
    "Conquistar 3 territórios seguidos.",
    "Defender com sucesso 2 ataques consecutivos."
};

// --- Estrutura de dados ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Protótipos ---
void limparBufferEntrada();
void atacar(struct Territorio* atacante, struct Territorio* defensor);
void cadastrarExercito(struct Territorio *territorios);
void atualizarMapa(struct Territorio *territorios);
void menuAtacar(int *opcao);
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho);
void exibirMissao(char* missao);
void liberarMemoria(struct Territorio *territorios, char *missaoJogador);

// --- Função principal ---
int main() {
    srand(time(NULL)); // inicializa gerador de números aleatórios

    // Alocação dinâmica dos territórios
    struct Territorio *territorios = (struct Territorio*) calloc(MAX_TER, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return 1;
    }

    // Alocação dinâmica da missão
    char *missaoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador, missoes, TOTAL_MISSOES);
    exibirMissao(missaoJogador); // missão exibida apenas uma vez

    cadastrarExercito(territorios);

    int opcao;
    do {
        atualizarMapa(territorios);
        menuAtacar(&opcao);

        if (opcao == 0) {
            printf("\nSaindo do Sistema...\n");
            break;
        }

        if (opcao < 1 || opcao > MAX_TER) {
            printf("\nOpção inválida! Digite entre 1 e %d ou 0 para sair.\n", MAX_TER);
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

        // Validação: só pode atacar inimigos
        if (strcmp(territorios[atacante].cor, territorios[defensor].cor) == 0) {
            printf("\nVocê não pode atacar um território aliado!\n");
            continue;
        }

        // Executa a batalha
        atacar(&territorios[atacante], &territorios[defensor]);

        // Verificação silenciosa da missão
        if (verificarMissao(missaoJogador, territorios, MAX_TER)) {
            printf("\nO jogador do exército %s cumpriu sua missão e venceu o jogo!\n", territorios[atacante].cor);
            break;
        }

    } while (opcao != 0);

    liberarMemoria(territorios, missaoJogador);
    printf("\nFim do programa.\n");
    return 0;
}

// --- Implementações ---

// Limpa o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastro inicial dos territórios
void cadastrarExercito(struct Territorio *territorios) {
    printf("\n###########################################################\n");
    printf("    WAR ESTRUTURADO - CADASTRO INICIAL");
    printf("\n###########################################################\n");

    for (int i = 0; i < MAX_TER; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada();
    }
}

// Função de ataque
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("Atacante %s tirou: %d\n", atacante->nome, dadoA);
    printf("Defensor %s tirou: %d\n", defensor->nome, dadoD);

    if (dadoA > dadoD) {
        defensor->tropas--;
        printf("Vitória do ataque! O defensor perdeu 1 tropa.\n");

        if (defensor->tropas <= 0) {
            printf("%s foi conquistado pelo exército %s!\n", defensor->nome, atacante->cor);
            strcpy(defensor->cor, atacante->cor);

            int tropasTransferidas = atacante->tropas / 2;
            defensor->tropas = tropasTransferidas;
            atacante->tropas -= tropasTransferidas;
        }
    } else {
        atacante->tropas--;
        printf("Defesa resistiu! O atacante perdeu 1 tropa.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

// Exibe o mapa atual
void atualizarMapa(struct Territorio *territorios) {
    // Exibe o mapa atualizado
    printf("\n###########################################################\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("###########################################################\n");
    
    for (int i = 0; i < MAX_TER; i++) {
        printf("%d. %s (Exército %s, Tropas: %d)\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

// Menu de ataque
void menuAtacar(int *opcao) {
    printf("\n--- FASE DE ATAQUE ---\n");
    printf("Escolha o território atacante (1 a %d, ou 0 para sair): ", MAX_TER);
    scanf("%d", opcao);
    limparBufferEntrada();
}

// Sorteia uma missão
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Verifica se a missão foi cumprida
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho) {
    if (strcmp(missao, "Conquistar todos os territórios.") == 0) {
        for (int i = 1; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, mapa[0].cor) != 0) return 0;
        }
        return 1;
    }
    if (strcmp(missao, "Eliminar todas as tropas da cor Vermelha.") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelha") == 0 && mapa[i].tropas > 0) return 0;
        }
        return 1;
    }
    if (strcmp(missao, "Manter pelo menos 5 tropas em cada território.") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas < 5) return 0;
        }
        return 1;
    }
    return 0;
}

// Exibe missão ao jogador
void exibirMissao(char* missao) {
    printf("\n>>> Sua missão secreta: %s\n", missao);
}

// Libera memória
void liberarMemoria(struct Territorio *territorios, char *missaoJogador) {
    free(territorios);
    free(missaoJogador);
    printf("Memória liberada com sucesso!\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
#define MAX_TER 2
#define TOTAL_MISSOES 5

// --- Vetor de missões ---
char *missoes[TOTAL_MISSOES] = {
    "Conquistar todos os territórios.",
    "Eliminar todas as tropas da cor Vermelha.",
    "Manter pelo menos 5 tropas em cada território.",
    "Conquistar 3 territórios seguidos.",
    "Defender com sucesso 2 ataques consecutivos."
};

// --- Estrutura de dados ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Protótipos ---
void limparBufferEntrada();
void atacar(struct Territorio* atacante, struct Territorio* defensor);
void cadastrarExercito(struct Territorio *territorios);
void atualizarMapa(struct Territorio *territorios);
void menuAtacar(int *opcao);
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho);
void exibirMissao(char* missao);
void liberarMemoria(struct Territorio *territorios, char *missaoJogador);

// --- Função principal ---
int main() {
    srand(time(NULL)); // inicializa gerador de números aleatórios

    // Alocação dinâmica dos territórios
    struct Territorio *territorios = (struct Territorio*) calloc(MAX_TER, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return 1;
    }

    // Alocação dinâmica da missão
    char *missaoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador, missoes, TOTAL_MISSOES);
    exibirMissao(missaoJogador); // missão exibida apenas uma vez

    cadastrarExercito(territorios);

    int opcao;
    do {
        atualizarMapa(territorios);
        menuAtacar(&opcao);

        if (opcao == 0) {
            printf("\nSaindo do Sistema...\n");
            break;
        }

        if (opcao < 1 || opcao > MAX_TER) {
            printf("\nOpção inválida! Digite entre 1 e %d ou 0 para sair.\n", MAX_TER);
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

        // Validação: só pode atacar inimigos
        if (strcmp(territorios[atacante].cor, territorios[defensor].cor) == 0) {
            printf("\nVocê não pode atacar um território aliado!\n");
            continue;
        }

        // Executa a batalha
        atacar(&territorios[atacante], &territorios[defensor]);

        // Verificação silenciosa da missão
        if (verificarMissao(missaoJogador, territorios, MAX_TER)) {
            printf("\nO jogador do exército %s cumpriu sua missão e venceu o jogo!\n", territorios[atacante].cor);
            break;
        }

    } while (opcao != 0);

    liberarMemoria(territorios, missaoJogador);
    printf("\nFim do programa.\n");
    return 0;
}

// --- Implementações ---

// Limpa o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastro inicial dos territórios
void cadastrarExercito(struct Territorio *territorios) {
    printf("\n###########################################################\n");
    printf("    WAR ESTRUTURADO - CADASTRO INICIAL");
    printf("\n###########################################################\n");

    for (int i = 0; i < MAX_TER; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada();
    }
}

// Função de ataque
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("Atacante %s tirou: %d\n", atacante->nome, dadoA);
    printf("Defensor %s tirou: %d\n", defensor->nome, dadoD);

    if (dadoA > dadoD) {
        defensor->tropas--;
        printf("Vitória do ataque! O defensor perdeu 1 tropa.\n");

        if (defensor->tropas <= 0) {
            printf("%s foi conquistado pelo exército %s!\n", defensor->nome, atacante->cor);
            strcpy(defensor->cor, atacante->cor);

            int tropasTransferidas = atacante->tropas / 2;
            defensor->tropas = tropasTransferidas;
            atacante->tropas -= tropasTransferidas;
        }
    } else {
        atacante->tropas--;
        printf("Defesa resistiu! O atacante perdeu 1 tropa.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

// Exibe o mapa atual
void atualizarMapa(struct Territorio *territorios) {
    // Exibe o mapa atualizado
    printf("\n###########################################################\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("###########################################################\n");
    
    for (int i = 0; i < MAX_TER; i++) {
        printf("%d. %s (Exército %s, Tropas: %d)\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

// Menu de ataque
void menuAtacar(int *opcao) {
    printf("\n--- FASE DE ATAQUE ---\n");
    printf("Escolha o território atacante (1 a %d, ou 0 para sair): ", MAX_TER);
    scanf("%d", opcao);
    limparBufferEntrada();
}

// Sorteia uma missão
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Verifica se a missão foi cumprida
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho) {
    if (strcmp(missao, "Conquistar todos os territórios.") == 0) {
        for (int i = 1; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, mapa[0].cor) != 0) return 0;
        }
        return 1;
    }
    if (strcmp(missao, "Eliminar todas as tropas da cor Vermelha.") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelha") == 0 && mapa[i].tropas > 0) return 0;
        }
        return 1;
    }
    if (strcmp(missao, "Manter pelo menos 5 tropas em cada território.") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas < 5) return 0;
        }
        return 1;
    }
    return 0;
}

// Exibe missão ao jogador
void exibirMissao(char* missao) {
    printf("\n>>> Sua missão secreta: %s\n", missao);
}

// Libera memória
void liberarMemoria(struct Territorio *territorios, char *missaoJogador) {
    free(territorios);
    free(missaoJogador);
    printf("Memória liberada com sucesso!\n");
}