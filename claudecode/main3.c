#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pessoa {
	char nome [30];
	int idade;
	float peso;
	
	struct pessoa *prox; // nao lembro se era struct pessoa->prox ou struct *prox, ou outra coisa - em uma situação eu testaria os dois
};

struct pessoa *cria (void) {
	struct pessoa *cabeca = malloc(sizeof(struct pessoa));
	cabeca->prox = NULL;
	return cabeca;
}


void imprime(struct pessoa *lista) {
	struct pessoa *p = lista->prox;
	while (p!= NULL) {
		printf ("Nome: %s \n", p->nome);
		p = p->prox;
	}
}

int main() {
	
	return 0;
}
