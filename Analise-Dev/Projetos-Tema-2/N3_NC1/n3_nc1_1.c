#include <stdio.h>

int main(){
    int numero_sinal = 3000000000; //esse valor excede o limite do int normal
    unsigned int numero_sem_sinal = 3000000000;

    printf("Número com sinal: %d\n", numero_sinal);
    printf("Número sem sinal: %u\n", numero_sem_sinal);
    return 0;
}