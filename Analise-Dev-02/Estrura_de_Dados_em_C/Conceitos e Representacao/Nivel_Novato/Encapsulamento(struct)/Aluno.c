#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    // Criando e inicializado uma variavel tipo A luno
    Aluno aluno1 = {"João", 20, 8.5};

    // Acessando os dados com operadores '.'
    printf("Aluno: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.2f\n", aluno1.media);

    return 0;
}