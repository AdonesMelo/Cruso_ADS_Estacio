#include <stdio.h>
 
int main() {
    int numero_preciso = 2147483647; // Valor máximo de int
    long long int numero_grande = 2147483647;
 
    printf("Número regular (int): %d\n", numero_preciso);
    printf("Número grande (long int): %ld\n", numero_grande);
 
    numero_grande = 2147483648; // Valor maior que o máximo de int
    printf("Número grande atualizado (long long int): %lld\n", numero_grande);
 
    return 0;
}