#include <stdio.h>

int main() {
    int idade = 12;

    printf(idade < 18 ? "Menor de idade\n" : "Maior de idade\n");
    if(idade < 18) {
        printf("Menor de idade\n");
    } else {
        printf("Maior de idade\n");
    }

    if (idade < 18) {
        printf("Menor de idade\n");
    } else if (idade >= 18) {
        printf("Maior de idade\n");
    }

    // exemplo de switch case incorreto
    // switch (idade)
    // {
    // case < 18:
    //     printf("Menor de idade\n");
    //     break;
    // case >= 18:
    //     printf("Maior de idade\n");
    //     break;
    
    // default:
    //     break;
    // }

}