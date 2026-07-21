#include <stdio.h>
 
int main() {
    unsigned long int numero_grande_positivo = 4000000000;
    unsigned int numero_positivo = 4000000000;
    long int numero_grande = 4000000000;
    long long int numero_grande2 = 4000000000;
    int numero = 4000000000;

    printf("Número grande positio: %lu\n", numero_grande_positivo);
    printf("Número positivo: %u\n", numero_positivo);
    printf("Número grande(lond lond): %lld\n", numero_grande2);
    printf("Número grande: %ld\n", numero_grande);
    printf("Número: %d\n", numero);
 
    return 0;
}