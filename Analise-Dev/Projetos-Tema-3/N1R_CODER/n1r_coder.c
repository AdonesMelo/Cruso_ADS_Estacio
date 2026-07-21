#include <stdio.h>

int main(){
    float temperatura, umidade;
    unsigned int estoque, estoque_min=1000;

    printf("Entre com a temperatura: \n");
    scanf("%f", &temperatura);
    printf("Entre com a umidade: \n");
    scanf("%f", &umidade);
    printf("Entre com o estoque: \n");
    scanf("%u", &estoque);

    if (temperatura > 30) {
        printf("Temperatura está alta!\n");
    } else {
        printf("Temperatura dentro dos parâmetros.\n");
    }

    if (umidade > 50) {
        printf("Umidade elevada!\n");
    } else {
        printf("Umidade dentro dos parâmetros.\n");
    }

    if (estoque < estoque_min) {
        printf("Estoque abaixo do minimo!\n");
    } else {
        printf("Estoque normal.\n");
    }
    
    return 0;
}