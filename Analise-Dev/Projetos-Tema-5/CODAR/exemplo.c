#include <stdio.h>

int main(){
    int index;

    char * nomes_alunos[3][3] = {
        {"Aluno 0", "Pt: 30", "Mat: 90"},
        {"Aluno 1", "Pt: 60", "Mat: 60"},
        {"Aluno 2", "Pt: 90", "Mat: 30"}
    };

    printf("Digite o número do aluno quer acessar a nota...\n");
    printf("Para aluno 0, digite 0\n");
    printf("Para aluno 1, digite 1\n");
    printf("Para aluno 2, digite 2\n");
    scanf("%d", &index);

    printf("As notas do %s são: %s | %s\n", nomes_alunos[index][0], nomes_alunos[index][1], nomes_alunos[index][2]);

    return 0;
}