#include <stdio.h>

int main(){
    float num1 = 10.2;
    int num2 = 10;

    printf("num1 > num2: %d\n", num1 > num2);
    printf("num1 == num2: %d\n", num1 == num2);

    // conversão explicita
    printf("\nConversão explicita\n");
    printf("num1 > num2: %d\n", (int) num1 > num2);
    printf("num1 == num2: %d\n", (int) num1 == num2);

    return 0;
}