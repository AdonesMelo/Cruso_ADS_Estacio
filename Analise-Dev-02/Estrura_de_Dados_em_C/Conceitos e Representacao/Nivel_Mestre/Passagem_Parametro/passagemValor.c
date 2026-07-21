# include <stdio.h>

// Esssa função faz receber a copiar do valor
void dobraValor(int x) {
    x = x *2;

    printf("Dentro da função o valor da copia é: %d\n", x);
}

int main() {
    int numero = 5;

    printf("Antes de chamar a função o valor original é: %d\n", numero);

    dobraValor(numero);

    printf("depois de chamar a função o valor original é: %d\n", numero);

    return 0;
}