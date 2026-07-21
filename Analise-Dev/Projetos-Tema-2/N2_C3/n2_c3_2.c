# include <stdio.h>

int main(){
    /*
    Atribução simples(=)
    atribuição com soma(+=)
    atribuição com subtração(-=)
    atribuiçao com multlicação(*=)
    atribuição com divisão(/=)
    */

    int num_1 = 10, num_2, resultado;

    resultado = 10;
    printf("Resultado: %d\n", resultado);

    // mesma coisa de resultado = resultado + 20
    resultado += 20;
    printf("Resultado: %d\n", resultado);

    // mesma coisa de resultado = resultado - num_1
    resultado -= num_1;
    printf("Resultado: %d\n", resultado);

    // mesma coisa de resultado = resultado * 5
    resultado *= 5;
    printf("Resultado: %d\n", resultado);

    // mesma coisa de resultado = resultado / 2
    resultado /= 2;
    printf("Resultado: %d\n", resultado);
}