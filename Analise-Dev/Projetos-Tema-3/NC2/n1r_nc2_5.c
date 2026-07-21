#include <stdio.h>

int main(){
    int idade_1 = 35;
    int idade_2 = 25;

    if(idade_1 > idade_2){
        printf("A pessoa 1 é mais venha que pessoa 2\n");
    }
    else{
        if(idade_1 < idade_2){
            printf("A pessoa 1 é mais nova que a pessoa 2\n");
        }
        else{
            printf("As pessoas têm as mesma idade\n");
        }
    }

    return 0;
}