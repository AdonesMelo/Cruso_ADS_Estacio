#include <stdio.h>

int main(){
    int estoque = 5;

    if(estoque < 5){
        printf("O estoque está baixo");
    }
    else{
        if(estoque > 5){
            printf("O estoque está alto");
        }
        else{
            printf("O estoque está no limite");
        }
    }
    
    return 0;
}