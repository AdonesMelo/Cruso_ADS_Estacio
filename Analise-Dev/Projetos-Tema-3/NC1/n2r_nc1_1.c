#include <stdio.h>

int main(){
    int a = -1, b = 5;

    //AND
    printf("\nOperador AND(&&)\n");
    if (a >= 0 && b >= 0) {
        printf("Os números são positivos\n");
    } else {
        printf("Pelo menos uns dos números são negativo!\n");
    }

    // OR
    printf("\nOperador OR(||)\n");
    if (a >= 0 || b >= 0) {
        printf("Pelo menos uns dos números são positivos!\n");
    } else {
        printf("Os números são negativos!\n");
    }

    // NOT
    printf("\nOperador NOT'!'\n");
    if (!a) {
        printf("A variavel é zero.\n");
    } else {
        printf("A variavel é diferente de zero.!\n");
    }

    printf("\nOperador NOT'!': Se o número é positivo ou negativo?\n");
    if (!(a >= 0)) {
        printf("A variavel é negativa.\n");
    } else {
        printf("A variavel é positiva.\n");
    }


    return 0;
}