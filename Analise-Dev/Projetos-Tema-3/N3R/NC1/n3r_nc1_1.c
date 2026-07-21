#include <stdio.h>

int main() {
    int idade;
    int resultado;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    resultado = idade >= 18 ? 1 : 0;

    if (resultado == 1) {
        printf("Maior de idade\n");
    } else {
        printf("Menor de idade\n");
    }

    return 0;
}