#include <stdio.h>
#include <stdlib.h>

struct numero {
    int valor;
    struct numero *prox;
};

struct numero *cria(void);
void insere_ordenado(struct numero *lista, int valor);
void imprime(struct numero *lista);

int main(void) {
    struct numero *lista;
    lista = cria();

    insere_ordenado(lista, 50);
    insere_ordenado(lista, 20);
    insere_ordenado(lista, 80);
    insere_ordenado(lista, 10);
    insere_ordenado(lista, 60);

    imprime(lista);   /* gabarito: 10 20 50 60 80 */

    return 0;
}

struct numero *cria(void) {
    struct numero *cabeca = malloc(sizeof(struct numero));
    cabeca->prox = NULL;
    return cabeca;
}

void insere_ordenado(struct numero *lista, int valor) {
    /* SUA TAREFA — o roteiro:
       FASE 0 — nasce o nó (Dia 5):
         1. malloc
         2. novo->valor = valor

       FASE 1 — PROCURA (pergunta 1, 2 e 3):
         3. os dois dedos partem: ant da cabeça, p do primeiro real
         4. while com DUAS condições (&&, ordem importa!)
         5. dentro: o passo duplo (ant pisa, p avança)

       FASE 2 — COSTURA (pergunta 4, diagrama passos ? e ?):
         6. seta do novo primeiro
         7. seta do ant depois
    */
    struct numero *novo = malloc(sizeof(struct numero));
    novo->valor = valor;
    
    struct numero *ant = lista;
    struct numero *p = lista->prox;
    while (p != NULL && p->valor < valor) {
    	ant = p;
    	p = p->prox;
	}
	
	novo->prox = p;
	ant->prox = novo;
    
	}
    


void imprime(struct numero *lista) {
    struct numero *p = lista->prox;
    while (p != NULL) {
        printf("%d\n", p->valor);
        p = p->prox;
    }
}
