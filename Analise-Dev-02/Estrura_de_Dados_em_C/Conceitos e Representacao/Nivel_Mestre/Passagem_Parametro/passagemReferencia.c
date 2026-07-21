# include <stdio.h>

// A função recebe um ENDEREÇO (ponteiro para int)
void dobraValor(int* x) {
    // acessando o valor do ENDEREÇO e o modificando
    *x = (*x) *2;
    
    // Valor do ENDEREÇO
    printf("Dentro da função o valor do ENDEREÇO é: %d\n", x);
}

int main() {
    int numero = 5;

    printf("Antes de chamar a função o valor é: %d\n", numero);

    // Passando o ENDEREÇO de 'numero' com operador '&'
    dobraValor(&numero);

    printf("depois de chamar a função o valor é: %d\n", numero);

    return 0;
}