#include <stdio.h>
#include <string.h> // Para strcspn(), uma biblioteca para manipular strings

// --- Constantes Globais ---
#define MAX_TER 5 // Número máximo de territórios a cadastrar

// --- Estrutura de dados (STRUCT) ---
// Representa um território com nome, cor do exército e número de tropas.
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --- Função para limpar buffer de entrada ---
// Evita que o '\n' deixado pelo scanf interfira nas próximas leituras.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal ---
int main() {
    Territorio territorios[MAX_TER]; // Vetor de structs para armazenar os territórios

    printf("###########################################################\n");
    printf("Vamos cadastrar %d territórios iniciais para nosso mundo.\n", MAX_TER);
    
    // --- Cadastro dos territórios ---
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
    
    // --- Exibir os dados cadastrados ---
    printf("\n###########################################################\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("###########################################################\n");

    for (int i = 0; i < MAX_TER; i++) {
        printf("\nTERRITÓRIO %d:\n", i + 1);
        printf("    - Nome: %s\n", territorios[i].nome);
        printf("    - Dominado por: Exército %s\n", territorios[i].cor);
        printf("    - Tropas: %d\n", territorios[i].tropas);
    }

    printf("\nPressione Enter para encerra...");
    getchar(); // Uma pausa para o usuário ler a messagem, antes de encerra o app

    printf("\nFim do programa.\n");
    return 0;
}