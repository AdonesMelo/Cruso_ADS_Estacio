#include <stdio.h>

int main(){
    int num_1;
    int num_2;

    num_1 = 50;
    num_2 = 50;

    if(num_1 > num_2){
        printf("O número 1 é maior que o número 2");
    }
    else{
        if(num_1 < num_2){
            printf("O número 1 é menor que o número 2");
        }
        else{
            printf("Os números são iguais");
        }
        
    }

    return 0;
}