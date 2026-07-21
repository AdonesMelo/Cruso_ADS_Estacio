#include <stdio.h>
//#include <string.h>

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
    float  densidade1, pip_capito1;
    float  densidade2, pip_capito2;

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
    pip_capito1 = (float) (pib1 *  1000000000) / populacao1;
    pip_capito2 = (float) (pib2 *  1000000000) / populacao2;

    // cálcula o super poder
    float super_poder1 = (float)populacao1 + area1 +  pib1 + (float)num_turistico1 + pip_capito1 + (1 / densidade1);
    float super_poder2 = (float)populacao2 + area2 +  pib2 + (float)num_turistico2 + pip_capito2 + (1 / densidade2);

    printf("\nSuper poder carta 1: %.2f\n", super_poder1);
    printf("Super poder carta 2: %.2f\n", super_poder2);

    // prints carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codígo: %s\n", codigo1);
    printf("Nome da cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", num_turistico1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pip_capito1);

    // prints cartas 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codígo: %s\n", codigo2);
    printf("Nome da cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", num_turistico2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pip_capito2);

    // Comparar as cartas
    int populacao = populacao1 > populacao2;
    int area = area1 > area2;
    int pib = pib1 > pib2;
    int num_turistico = num_turistico1 > num_turistico2;
    int densidade = densidade1 < densidade2; // menor densidade é melhor
    int pip_capito = pip_capito1 > pip_capito2;
    int super_poder = super_poder1 > super_poder2;

    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", populacao ? 1 : 2, populacao);
    printf("Área: Carta %d venceu (%d)\n", area ? 1 : 2, area);
    printf("PIB: Carta %d venceu (%d)\n", pib ? 1 : 2, pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", num_turistico ? 1 : 2, num_turistico);
    printf("Densidade Populacional: Carta %d venceu(%d)\n", densidade ? 1 : 2, densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", pip_capito ? 1 : 2, pip_capito);
    printf("Super Poder: Carta %d venceu (%d)\n", super_poder ? 1 : 2, super_poder);

    return 0;
}