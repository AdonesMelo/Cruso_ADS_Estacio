#include <stdio.h>

// Substituir condicionais de elementos
int main(){
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8,9}};
    int alvo = 5, achei_ou_nao = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] == alvo){
                printf("Elemento %d encontrado na posição (%d, %d)\n", alvo, i, j);
                achei_ou_nao = 1;
                break;
            }
        }
        if (achei_ou_nao) break;
    }
    if (! achei_ou_nao){
        printf("Elemeno %d encontrado na matriz\n", alvo);
    }

    return 0;
}