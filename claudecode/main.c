#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct aluno {
    char nome[50];
    int idade;
    float nota;
    struct aluno *prox;
};
int main(void) {
        struct aluno *a1 = malloc(sizeof(struct aluno));
        strcpy(a1->nome, "Gustavo Owicki");
        a1->idade = 20;
        a1->nota = 99.90;

		struct aluno *a2 = malloc(sizeof(struct aluno));
        strcpy(a2->nome, "Gustavo Lacerda");
        a2->idade = 21;
        a2->nota = 78.90;


    printf ("Nome: %s\n", a1->nome);
    printf ("Idade: %d\n", a1->idade);
    printf ("Nota: %.2f\n", a1->nota);

    printf ("Nome: %s\n", a2->nome);
    printf ("Idade: %d\n", a2->idade);
    printf ("Nota: %.2f\n", a2->nota);
    
    free(a1);
    free(a2);

    return 0;
}


