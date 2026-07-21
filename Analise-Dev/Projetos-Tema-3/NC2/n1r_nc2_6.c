#include <stdio.h>

int main(){
    int num = 3, resto;

    resto = num % 2;
    printf("Resto da divisão: %d\n", resto);

    if(resto == 0){
        printf("O número é par\n");
    }
    else{
        printf("O número é impar\n");
    }

    return 0;
}