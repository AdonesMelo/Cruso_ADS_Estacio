#include <stdio.h>

int main(){
    int idade = 20;

    if(idade >= 18){
        printf("Você é maior de idade\n");
        printf("Dentro do 'if'\n");
    }    
    
    printf("Fora do 'if'\n");

    return 0;
}