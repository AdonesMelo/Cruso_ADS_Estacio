#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 1;
    int b = 2;

    printf("Antes: a = %d e b = %d\n", a, b);

    trocar(&a, &b);

    printf("Depois: a = %d e b = %d\n", a, b);

    return 0;
}