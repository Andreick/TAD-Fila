#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
	int info;
	struct no *prox;
} No;

struct fila {
	No *primeiro;
	No *ultimo;
};

Fila* criarFila() {
	Fila *fi = (Fila*) malloc(sizeof(Fila));

	if (fi != NULL) {
		fi->primeiro = NULL;
		fi->ultimo = NULL;
	}

	return fi;
}

int enfileirar(int num, Fila *fi) {

	if (fi == NULL)
		return 0;

	No *novo_no = (No*) malloc(sizeof(No));

	if (novo_no == NULL)
		return 0;

	novo_no->info = num;
	novo_no->prox = NULL;

	if (fi->primeiro == NULL)
		fi->primeiro = novo_no;
	else
		fi->ultimo->prox = novo_no;

	fi->ultimo = novo_no;

	return 1;
}

int desenfileirar(Fila *fi) {

	if (fi == NULL || fi->primeiro == NULL)
		return 0;

	No *aux = fi->primeiro;
	fi->primeiro = fi->primeiro->prox;

	if (fi->primeiro == NULL)
		fi->ultimo = NULL;
	
	free(aux);

	return 1;
}

void exibirFila(Fila *fi) {

	if (fi != NULL) {
		
		No *aux = fi->primeiro;
		
		while (aux != NULL) {
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
}

void excluirFila(Fila **fi) {

	if (*fi != NULL) {

		No *aux;
		
		while ((*fi)->primeiro != NULL) {
			aux = (*fi)->primeiro;
			(*fi)->primeiro = (*fi)->primeiro->prox;
			free(aux);
		}

		free(*fi);
		*fi = NULL;
	}
}

int filaVazia(Fila *fi) {

	if (fi == NULL || fi->primeiro == NULL)
		return 1;

	return 0;
}
