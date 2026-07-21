#include <stdio.h>

int main(){
    int nota = 50;

    if(nota > 50){
        printf("Parabéns! você foi aprovado\n");
    }
    else{
        if(nota < 50){
            printf("Infelizmente você reprovou\n");
        }
        else{
            printf("Você ficou de recuperação!\n");
        }
    }

    return 0;
}