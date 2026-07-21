#include <stdio.h>

int main(){
    int idade = 25;
    float altura = 1.71;

    // idade >= 18 V
    // idade <= 30 V
    // V && V => V
    // V && altura >= 1.70 => V
    // V && V => V

    if (idade >= 18 && idade <= 30 && altura >= 1.70) {
        printf("Você está na faixa etaria e tem a altura adequada.\n");
    } else {
        printf("Você não tem os critérios.\n");
    }
    

    return 0;
}