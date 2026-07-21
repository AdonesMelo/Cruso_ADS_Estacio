#include <stdio.h>

int main(){
    int opcao;
    float saldo = 1000.00;
    char banco[20];
    int agencia;
    int conta;
    float deposito;
    float saque;


    printf("\nEsconha uma opção: \n");
    printf("1: Verificar saldo: \n");
    printf("2: Fazer de depósito: \n");
    printf("3: Fazer saque: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("O seu saldo é: R$ %.2f", saldo);
        break;

    case 2:
        printf("Digite o banco que deseja fazer o depósito: \n");
        scanf("%s", &banco);
        printf("Digite o número da agência que deseja fazer o depósito: \n");
        scanf("%d", &agencia);
        printf("Digite o número da conta que deseja fazer o depósito: \n");
        scanf("%d", &conta);
        printf("Digite o valor do depósito: \n");
        scanf("%f", &deposito);

        saldo = saldo + deposito;
        printf("Saldo: R$ %.2f", saldo);
        break;
    
    case 3:
        printf("Digite o valor do saque: \n");
        scanf("%f", &saque);

        saldo = saldo - saque;
        printf("Saldo: R$ %.2f", saldo);
        break;
        
    default:
        printf("Opção inválida!\n");
        break;
    }

    return 0;
}