#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {     // Imprime a tabulação inicial para cada linha
            printf("%d x %d = %d\n",i, j, i * j);
            //printf("%4d", i * j);
        }
        printf("\n");
    }
    
    return 0;
}