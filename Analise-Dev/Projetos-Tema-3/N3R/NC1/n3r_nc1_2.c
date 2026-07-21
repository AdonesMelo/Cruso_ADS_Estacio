#include <stdio.h>

int main() {
    int temperatura;
    int resultado;

    printf("Digite a temperatura: ");
    scanf("%d", &temperatura);

    resultado = temperatura >= 30 ? 1 : 0;
    if (resultado == 1) {
        printf("Dia quente\n");
    } else {
        printf("Dia frio\n");
    }

    return 0;
}