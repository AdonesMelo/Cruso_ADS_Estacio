#include <stdio.h>

int main(){
    int num = 0;
    int resto;

    resto = num % 2;

    if (resto == 0) {
        printf("O número é par");
    } else {
        printf(" O número é ímpar");
    }

    return 0;
}