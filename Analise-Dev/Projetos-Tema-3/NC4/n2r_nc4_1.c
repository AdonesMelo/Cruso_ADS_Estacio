#include <stdio.h>

int main(){
    int variavel;
    char variavel2;

    // printf("Digite um número: \n");
    // scanf("%d", &variavel);

    printf("Digite um letra: \n");
    scanf("%c", &variavel2);

    // switch (variavel)
    // {
    // case 1:
    //     printf("codigo a ser execultado da variavel == 1\n");
    //     printf("Teste do case 1\n");
    //     break;
    // case 2:
    //     printf("codigo a ser execultado da variavel == 2\n");
    //     printf("Teste do case 2\n");
    //     break;
    // default:
    //     printf("codigo a ser execultado da variavel não for 1 ou 2\n");
    //     break;
    // }

    switch (variavel2)
    {
    case 'a':
        printf("codigo a ser execultado da variavel == a\n");
        printf("Teste do case a\n");
        break;
    case 'b':
        printf("codigo a ser execultado da variavel == b\n");
        printf("Teste do case b\n");
        break;
    default:
        printf("codigo a ser execultado da variavel não for a ou b\n");
        break;
    }

    return 0;
}