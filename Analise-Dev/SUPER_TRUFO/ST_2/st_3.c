#include <stdio.h>

int main(){
    // variaveis cartas 1
    char estado1, codigo1[4], cidade1[20];
    unsigned long int populacao1;
    int num_turistico1;
    float area1, pib1;

    // variaveis cartas 2
    char estado2, codigo2[4], cidade2[20];
    unsigned long int populacao2;
    int num_turistico2;
    float area2, pib2;

    // variaveis para cálculo
    float  densidade1, pib_capito1;
    float  densidade2, pib_capito2;

    // cartas 1
    printf("Digite o estado(letra):\n");
    scanf(" %c", &estado1);

    printf("Digite o codígo:\n");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", cidade1); // permitir espaços

    printf("Digite a população:\n");
    scanf("%lu", &populacao1);

    printf("Digite a área territorial:\n");
    scanf("%f", &area1);

    printf("Digite o PIB:\n");
    scanf("%f", &pib1);

    printf("Digite a quantidades de pontos turísticos:\n");
    scanf("%d", &num_turistico1);

    // cartas 2
    printf("\nDigite o estado(letra):\n");
    scanf(" %c", &estado2);

    printf("Digite o codígo:\n");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", cidade2); // permitir espaços

    printf("Digite a população:\n");
    scanf("%lu", &populacao2);

    printf("Digite a área territorial:\n");
    scanf("%f", &area2);

    printf("Digite o PIB:\n");
    scanf("%f", &pib2);

    printf("Digite a quantidades de pontos turísticos:\n");
    scanf("%d", &num_turistico2);

    // cálculo para obter desnsidade populacional e PIB per capito
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pib_capito1 = (float) (pib1 *  1000000000) / populacao1;
    pib_capito2 = (float) (pib2 *  1000000000) / populacao2;

    // cálcula o super poder
    float super_poder1 = (float)populacao1 + area1 +  pib1 + (float)num_turistico1 + pib_capito1 + (1 / densidade1);
    float super_poder2 = (float)populacao2 + area2 +  pib2 + (float)num_turistico2 + pib_capito2 + (1 / densidade2);

    // Menu
    int menu;
    // Exibir o menu
    printf("\n### Super Trunfo ###\n");
    printf("Escolha uma opção:\n");
    printf("1: Nome da Cidade:\n");
    printf("2: Comparar Atributo População:\n");
    printf("3: Comparar Atributo Área:\n");
    printf("4: Comparar Atributo PIB:\n");
    printf("5: Comparar Atributo Número de Pontos Turísticos:\n");
    printf("6: Comparar Atributo Densidade Demográfica:\n");
    printf("7: Comparar Atributo PIB per capito:\n");
    printf("8: Comparar Atributo Super Poder:\n");
    printf("Escolha: ");
    scanf(" %d", &menu);


    switch (menu)
    {
    case 1:
        // Exibir a primeira carta
        printf("\n\n");
        printf("\n### Super Trunfo ###\n");
        printf("\nCartas 1:\n");
        printf("Estado: %c\n", estado1);
        printf("Nome da cidade: %s\n", cidade1);
        printf("População: %lu\n", populacao1);
        printf("Área: %.2f\n", area1);
        printf("PIB: %.2f\n", pib1);
        printf("Número de pontos turísticos: %d\n", num_turistico1);
        printf("Densidade demográfica: %.2f\n", densidade1);
        printf("PIB per capito: %.2f\n", pib_capito1);
        printf("Super poder: %.2f\n", super_poder1);
        printf("\n");

        // Exibir a segunda carta
        printf("\n### Super Trunfo ###\n");
        printf("\nCartas 2:\n");
        printf("Estado: %c\n", estado2);
        printf("Nome da cidade: %s\n", cidade2);
        printf("População: %lu\n", populacao2);
        printf("Área: %.2f\n", area2);
        printf("PIB: %.2f\n", pib2);
        printf("Número de pontos turísticos: %d\n", num_turistico2);
        printf("Densidade demográfica: %.2f\n", densidade2);
        printf("PIB per capito: %.2f\n", pib_capito2);
        printf("Super poder: %.2f\n", super_poder2);
        printf("\n");
        break;
    case 2:
        // Comparar população
        printf("\n### Super Trunfo ###\n");
        printf("Comparando população:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("População da carta 1: %lu\n", populacao1);
        printf("População da carta 2: %lu\n", populacao2);

        if (populacao1 > populacao2) {
            printf("A carta 1 venceu!.\n");
        } else if (populacao1 < populacao2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 3:
        // Comparar área
        printf("\n### Super Trunfo ###\n");
        printf("Comparando área:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("Área da carta 1: %.2f\n", area1);
        printf("Área da carta 2: %.2f\n", area2);
        if (area1 > area2) {
            printf("A carta 1 venceu!.\n");
        } else if (area1 < area2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 4:
        // Comparar PIB
        printf("\n### Super Trunfo ###\n");
        printf("Comparando PIB:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("PIB da carta 1: %.2f\n", pib1);
        printf("PIB da carta 2: %.2f\n", pib2);
        if (pib1 > pib2) {
            printf("A carta 1 venceu!.\n");
        } else if (pib1 < pib2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 5:
        // Comparar número de pontos turísticos
        printf("\n### Super Trunfo ###\n");
        printf("Comparando número de pontos turísticos:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("Número de pontos turísticos da carta 1: %d\n", num_turistico1);
        printf("Número de pontos turísticos da carta 2: %d\n", num_turistico2);
        if (num_turistico1 > num_turistico2) {
            printf("A carta 1 venceu!.\n");
        } else if (num_turistico1 < num_turistico2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 6:
        // Comparar densidade demográfica
        printf("\n### Super Trunfo ###\n");
        printf("Comparando densidade demográfica:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("Densidade demográfica da carta 1: %.2f\n", densidade1);
        printf("Densidade demográfica da carta 2: %.2f\n", densidade2);
        if (densidade1 < densidade2) {
            printf("A carta 1 venceu!.\n");
        } else if (densidade1 > densidade2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 7:
        // Comparar PIB per capito 
        printf("\n### Super Trunfo ###\n");
        printf("Comparando PIB per capito:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("PIB per capito da carta 1: %.2f\n", pib_capito1);
        printf("PIB per capito da carta 2: %.2f\n", pib_capito2);
        if (pib_capito1 > pib_capito2) {
            printf("A carta 1 venceu!.\n");
        } else if (pib_capito1 < pib_capito2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    case 8:
        // Comparar super poder
        printf("\n### Super Trunfo ###\n");
        printf("Comparando super poder:\n");
        printf("Carta 1 - %s ### Carta 2 - %s\n", cidade1, cidade2);
        printf("Super poder da carta 1: %.2f\n", super_poder1);
        printf("Super poder da carta 2: %.2f\n", super_poder2);
        if (super_poder1 > super_poder2) {
            printf("A carta 1 venceu!.\n");
        } else if (super_poder1 < super_poder2) {
            printf("A carta 2 venceu.\n");
        } else {
            printf("Empate!\n");
        }
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    
    return 0;
}