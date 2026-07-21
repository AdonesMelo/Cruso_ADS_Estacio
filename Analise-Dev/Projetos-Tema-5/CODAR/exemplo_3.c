#include <stdio.h>
#define LINHA 10
#define COLUNA 10

// Substituir condicionais de elementos
int main(){
    int matriz[LINHA][COLUNA];

    int alvo = 90, achei_ou_nao = 0;
    int soma = 1;
    

    for (int i = 0; i < LINHA; i++){
        for (int j = 0; j < COLUNA; j++){
            matriz[i][j] = soma;
            soma++;
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < LINHA; i++){
        for (int j = 0; j < COLUNA; j++){
            if (matriz[i][j] == alvo){
                printf("\nO valor %d encontrado no indice (%d, %d)\n", alvo, i, j);
                achei_ou_nao = 1;
                break;
            }
        }
        if (achei_ou_nao) break;
    }

    if (! achei_ou_nao){
        printf("\nElemeno %d encontrado na matriz\n", alvo);
    }

    return 0;
}