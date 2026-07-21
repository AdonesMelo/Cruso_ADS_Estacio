#include <stdio.h>

int main(){
    int a = 5;
    int b = 10;
    int c = 10;

    if (a > 0 && b < 0 || c == 0) {
        printf("a condição é verdadeira.\n");
    } else {
        printf("A condição é falsa.\n");
    }

    return 0;
}