#include <stdio.h>

int main() {
    int num1, num2;
    int maior;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    num1 > num2 ? (maior = num1) : (maior = num2);

    if (num1 > num2) {
        printf("O primeiro número e maior\n");
    } else if (num1 < num2) {
        printf("O segundo número e maior\n");
    } else {
        printf("Os números sao iguais\n");
    }

    printf("O maior número e: %d\n", maior);

    return 0;
}