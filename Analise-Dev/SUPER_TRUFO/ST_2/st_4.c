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

    int escolhar_1, escolhar_2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;

    // menu de atributos
    printf("\n### Super Trunfo ###\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("6. PIB per capito\n");
    printf("7. Super poder\n");    
    printf("Escolha: ");
    scanf("%d", &escolhar_1);

    // menu dinamico
    printf("\n### Super Trunfo ###\n");
    printf("Escolha o segundo atributo para comparar:\n");
    switch (escolhar_1) {
        case 1:
            printf("2 - Área territorial\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade demográfica\n6 - PIB per capito\n7 - Super poder\n");
        break;
        case 2:
            printf("1 - População\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade demográfica\n6 - PIB per capito\n7 - Super poder\n");
            break;
        case 3:
            printf("1 - População\n2 - Área territorial\n4 - Número de pontos turísticos\n5 - Densidade demográfica\n6 - PIB per capito\n7 - Super poder\n");
            break;
        case 4:
            printf("1 - População\n2 - Área territorial\n3 - PIB\n5 - Densidade demográfica\n6 - PIB per capito\n7 - Super poder\n");
            break;
        case 5:
            printf("1 - População\n2 - Área territorial\n3 - PIB\n4 - Número de pontos turísticos\n6 - PIB per capito\n7 - Super poder\n");
            break;
        case 6:
            printf("1 - População\n2 - Área territorial\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade demográfica\n7 - Super poder\n");
            break;
        case 7:
            printf("1 - População\n2 - Área territorial\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade demográfica\n6 - PIB per capito\n");
            break;
    default:
        printf("Opção inválida!\n");
        return 1;
        break;
    }

    printf("Escolha: ");
    scanf("%d", &escolhar_2);
    if (escolhar_1 == escolhar_2) {
        printf("Erro: Você escolheu o mesmo atributo!\n");
        return 1;
    }

    // Função auxiliar
    float obter_valor(int escolha, int carta) {
        switch (escolha) {
            case 1: return carta == 1 ? (float)populacao1 : (float)populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? (float)num_turistico1 : (float)num_turistico2;
            case 5: return carta == 1 ? densidade1 : densidade2;
            case 6: return carta == 1 ? pib_capito1 : pib_capito2;
            case 7: return carta == 1 ? super_poder1 : super_poder2;
            default: return 0.0; // Caso inválido
        }
    }

    // Comparação
    valor1_carta1 = obter_valor(escolhar_1, 1);
    valor1_carta2 = obter_valor(escolhar_1, 2);
    valor2_carta1 = obter_valor(escolhar_2, 1);
    valor2_carta2 = obter_valor(escolhar_2, 2);

    int pontos_carta1 = 0, pontos_carta2 = 0;

    // Regras especial para densidade demográfica
    if (escolhar_1 == 5) {
        if (valor1_carta1 < valor1_carta2) {
            pontos_carta1++;
        } else if (valor1_carta1 > valor1_carta2) {
            pontos_carta2++;
        }
    } else {
        if (valor1_carta1 > valor1_carta2) {
            pontos_carta1++;
        } else if (valor1_carta1 < valor1_carta2) {
            pontos_carta2++;
        }
    }

    // soma dos atributos
    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    printf("\n### Super Trunfo ###\n");
    printf("\nResultado da rodada:\n");
    if (soma1 > soma2) {
        printf("A carta 1 venceu! Cidade: %s\n", cidade1);
        pontos_carta1++;
    } else if (soma1 < soma2) {
        printf("A carta 2 venceu! Cidade: %s\n", cidade2);
        pontos_carta2++;
    } else {
        printf("Empate!\n");
    }

    return 0;
}