#include <stdio.h>

// Função que simula o movimento da torre para a direita
void move_torre(int casas){
    if (casas > 0){
        printf("Direita\n");
        move_torre(casas - 1); // chamada recursiva para repetir o movimento
    }
}

// Função que simula o movimento da rainha para a esquerda
void move_rainha(int casas){
    if (casas > 0){
        move_rainha(casas - 1); // chamada recursiva
        printf("Esquerda\n");
    }

}

// Função que simula o movimento do bispo na diagonal (cima e direita)
void move_bispo(int casas){
    if (casas > 0){
        move_bispo(casas - 1); // chamada recursiva
        printf("Cima, Direita\n"); // movimento diagonal
    }
}

// Cavalo: movimento em "L" com loops aninhados e controle de fluxo
void move_cavalo(int movimento){
    int cima, direita;

    for(cima = 0; cima < movimento; cima++){
        for(direita = 0; direita < movimento; direita++){
            if (cima == 0 && direita == 1){
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                break; // movimento completo, sai do loop interno
            } else {
                continue; // ignora combinações que não formam "L"
            }
        }
        break; // sai do loop externo após o movimento em "L"
    } 
}


int main(){
    // Quantidade de movimento para cada peças
    int qtde_torre = 5;
    int qtde_rainha = 8;
    int qtde_bispo = 5;
    int movimento_cavalo = 3;
    
    // Movimentos da torre
    move_torre(qtde_torre);
    printf("A torre moveu-se %d casas à direita.\n", qtde_torre);
    printf("\n#######################################\n");
    printf("\n");

    // Movimentos da rainha
    move_rainha(qtde_rainha);
    printf("A rainha moveu-se %d casas à esquerda.\n", qtde_rainha);
    printf("\n#######################################\n");
    printf("\n");

    // Movimentos do bispo
    move_bispo(qtde_bispo);
    printf("O bispo moveu-se %d casas na diagonal(Cima, Direita).\n", qtde_bispo);
    printf("\n#######################################\n");
    printf("\n");

    // Movimento do cavalo
    move_cavalo(movimento_cavalo);
    printf("O cavalo moveu-se em L: duas casas para cima e uma para a direita.\n");

    return 0;
}