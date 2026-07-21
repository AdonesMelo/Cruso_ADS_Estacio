# include <stdio.h>

int main(){
    /*
    incremento (++)
    pré-incremento a++
    descremento (--)
    pré-descremento a--
    pós-descremento --a
    */

    int num = 1, resultado;
    printf("Antes incremento: %d\n", num);

    num++;
    printf("Depois do incremento: %d\n", num);

    num--;
    printf("Depois do descremento: %d\n", num);

    resultado = num++;
    printf("Apos o Pós-incremento - Num 1: %d - Resultado: %d\n", num, resultado);

    resultado = ++num;
    printf("Apos o Pré-incremento - Num 1: %d - Resultado: %d\n", num, resultado);

    resultado = num--;
    printf("Apos o Pós-decremento - Num 1: %d - Resultado: %d\n", num, resultado);

    resultado = --num;
    printf("Apos o Pré-decremento - Num 1: %d - Resultado: %d\n", num, resultado);
}