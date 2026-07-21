# include <stdio.h>

int main() {
    int i = 0;

    // Loop para imprimir números de 0 a 10
    while (i <= 10) {
        // verifica se o número é par
        if (i % 2 == 0) {
            printf("O número %d é par\n", i);
        }
        i++;
    }

    return 0;
}