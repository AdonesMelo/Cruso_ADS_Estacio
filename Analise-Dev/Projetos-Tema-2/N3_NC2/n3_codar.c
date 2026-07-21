#include <stdio.h>

int main(){
    // Declara as variaveis Produtos, u i estoque, double valor unitario
    // u i quantidade minima
    char produto_a[30] = "A";
    char produto_b[30] = "B";

    unsigned int estoque_a = 1000;
    unsigned int estoque_b = 1000;

    float valor_a = 10.50;
    float valor_b = 20.40;

    unsigned int estoque_minimo_a = 500;
    unsigned int estoque_minimo_b = 2500;

    double valor_total_a;
    double valor_total_b;

    // Vai armazenar o valor de comparação
    int resultado_a, resultado_b;

    // exibir as informações do produto
    printf("O produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produto_a, estoque_a, valor_a);
    printf("O produto %s tem estoque %u e o valor unitario é  R$ %.2f\n", produto_b, estoque_b, valor_b);

    // comparação com o valor minimmo de estoque
    resultado_a = estoque_a > estoque_minimo_a;
    resultado_b = estoque_b > estoque_minimo_b;

    printf("\nSe o estoque é maior que o estoque minimo\n");
    printf("O produto %s tem estoque minimo de '%d' ('0' para false e '1' para true)\n", produto_a, resultado_a);
    printf("O produto %s tem estoque minimo de '%d' ('0' para false e '1' para true)\n", produto_b, resultado_b);

    // comparação entres os valores totais dos produtos
    printf("\nSe o valor total de A (R$ %.2f) é maior que o valor total de B (R$ %.2f)? \n'%d' ('0' para false e '1' para true)\n", estoque_a * valor_a, estoque_b * valor_b, (estoque_a * valor_a) > (estoque_b * valor_b));

    return 0;
}