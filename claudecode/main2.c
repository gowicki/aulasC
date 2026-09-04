#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct produto {
    /* TAREFA 1: nome (texto), preco (decimal), quantidade (inteiro)
       + o ponteiro pro próximo */
    char nome [30];
    float preco;
    int qtde;
    struct produto *prox;

};

struct produto *cria(void);
void insere(struct produto *lista, char nome[], float preco, int qtde);
void imprime(struct produto *lista);

int main(void) {
    struct produto *lista;
    lista = cria();

    insere(lista, "Arroz", 25.90, 10);
    insere(lista, "Feijao", 8.50, 24);
    insere(lista, "Cafe", 18.75, 6);

    imprime(lista);   /* deve sair: Cafe, Feijao, Arroz (ordem inversa) */

    return 0;
}

struct produto *cria(void) {
    /* TAREFA 2: de memória, do Dia 4 */
    struct produto *cabeca = malloc(sizeof(struct produto));
    cabeca->prox = NULL;
    return cabeca;

}

void insere(struct produto *lista, char nome[], float preco, int qtde) {
    /* TAREFA 3 (a nova):
       1. aloca o nó
       2. preenche os 3 campos (nome com strcpy!)
       3. encaixa no começo — as DUAS setas, na ordem certa:
          primeiro a do novo nó, depois a da cabeça */
    struct produto *novo = malloc(sizeof(struct produto));      
	strcpy(novo->nome, nome);   // o nome que CHEGOU na chamada
	novo->preco = preco;        // o preço que chegou
	novo->qtde = qtde;
	
	novo->prox = lista->prox;
	lista->prox = novo;    

}

void imprime(struct produto *lista) {
    /* TAREFA 4: de memória, do Dia 4 — mostrando os 3 campos */
    struct produto *p = lista->prox;
    while (p != NULL) {
    	printf ("Nome: %s\n", p->nome);
    	p = p->prox;
	}
}
