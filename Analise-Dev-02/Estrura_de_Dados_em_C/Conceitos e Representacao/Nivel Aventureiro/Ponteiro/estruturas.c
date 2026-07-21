#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    // 'p' é um ponteiro para 'pessoa'
    Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
    // if (p == NULL) return 1;

    printf("Digite o nome: ");
    scanf("%s", p->nome); // usar a seta '->'
    printf("Digite a idade: ");
    scanf("%d", &p->idade); // usar a seta '->'

    printf("%s tem %d anos.", p->nome, p->idade); // usar a seta '->'
    free(p);
    
    return 0;
} 