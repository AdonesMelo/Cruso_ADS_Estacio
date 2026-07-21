#include <stdio.h>

// Variavel global
int global = 10;

void mostraGlobal() {
    printf("Na função mostraGlobal: %d\n", global);
}

int main() {
    // Variavel local
    int local = 5;

    printf("Na função main(LOCAL): %d\n", local);
    printf("Na função main(GLOBAL): %d\n", global);

    mostraGlobal();

    return 0;
}