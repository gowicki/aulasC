#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
    struct aluno *prox;
};

struct aluno *cria(void);
void imprime(struct aluno *lista);

int main(void) {
    struct aluno *lista;
    lista = cria();               // lista vazia (só a cabeça)

    /* --- monta 3 nós na mão, ligados à cabeça (como no Dia 3) --- */
    struct aluno *n1 = malloc(sizeof(struct aluno));
    strcpy(n1->nome, "Ana");   n1->idade = 20; n1->nota = 8.5;
    struct aluno *n2 = malloc(sizeof(struct aluno));
    strcpy(n2->nome, "Bruno"); n2->idade = 22; n2->nota = 7.0;
    struct aluno *n3 = malloc(sizeof(struct aluno));
    strcpy(n3->nome, "Caio");  n3->idade = 19; n3->nota = 9.2;

    lista->prox = n1;   /* cabeça -> n1 */
    n1->prox = n2;      /* n1 -> n2 */
    n2->prox = n3;      /* n2 -> n3 */
    n3->prox = NULL;    /* fim */
    /* ----------------------------------------------------------- */

    imprime(lista);     /* deve sair Ana, Bruno e Caio */

    return 0;
}

struct aluno *cria(void) {
    struct aluno *cabeca = malloc(sizeof(struct aluno));
    cabeca->prox = NULL;     // lista vazia
    return cabeca;
}

void imprime(struct aluno *lista) {
    struct aluno *p = lista->prox;   // começa no 1o nó REAL (pula a cabeça)
    while (p != NULL) {              // enquanto não chegou no fim
        printf("Nome: %s\n", p->nome);
        p = p->prox;                 // anda pro próximo
    }
}
