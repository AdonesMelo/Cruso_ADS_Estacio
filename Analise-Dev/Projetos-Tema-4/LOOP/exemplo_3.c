# include <stdio.h>

int main() {
    int nurero, i, resultado;

    printf("Digite um número para calcula sua tabuada: ");
    scanf("%d", &nurero);

    for (i = 0; i <= 10; i++) {
        resultado = nurero * i;
        printf("%d x %d = %d\n", nurero, i,  resultado);
    }

    return 0;
}