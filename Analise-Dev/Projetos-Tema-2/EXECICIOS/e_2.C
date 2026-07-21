#include <stdio.h>

int main() {
    char letra;
    printf("Digite uma letra:\n");
    scanf("%c", &letra);
    letra = letra + ('A' - 'a');  // Converte para maiúscula
    printf("Caractere = %c\n", letra);

    return 0;
}