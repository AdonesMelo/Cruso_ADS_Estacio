#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x; // o ponteiro 'p' recebi o valor de 'x'

    // Mundando o valor de x usando o ponteiro 
    //*p = 20;

    printf("O valor de x: %d\n", x);
    printf("O ederenço de x: %p\n", &x);
    printf("O conteudo de p (o endereço): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}