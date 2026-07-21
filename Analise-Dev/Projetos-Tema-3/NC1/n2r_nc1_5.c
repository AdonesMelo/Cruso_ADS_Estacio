#include <stdio.h>

int main(){
    int nota;

    printf("Digite a sua nota: \n");
    scanf("%d", &nota);

    // A vai ser maior ou igual 90
    // B vai se maior ou igual 80
    // C vai se maior ou igual 70
    // D vai se maior ou igual 60
    // E vai se maior ou igual 50
    // F

    if (nota >= 90) {
        printf("O conceito é A!\n");
    } else if (nota >= 80) {
        printf("O conceito é B!\n");
    } else if (nota >= 70) {
        printf("O conceito é C!\n");
    } else if (nota >= 60) {
        printf("O conceito é D!\n");
    } else if (nota >= 50) {
        printf("O conceito é E!\n");
    } else {
        printf("O conceito é F!\n");
    }

    return 0;
}