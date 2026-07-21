#include <stdio.h>

void saudacao() {
    printf("Olá, mundo!\n");
}

int main() {
    // Declaração do ponteiro 'ptr' para função.
    // que não retorna nada (void) e não tem parâmetros ().
    void (*ptr)() = saudacao;

    // Chamanda da função atraveis do ponteiro
    ptr();

    return 0;
}