/*
 * funcoes.c
 *
 *  Created on: 24 de ago. de 2023
 *      Author: 3A226866341
 */
#include <stdio.h>
#include <stdlib.h>
#include "lyb.h"

void cria(PILHA* pilha){
	pilha->topo = (PONT)malloc(sizeof(CELULA));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int vazia(PILHA pilha){
	return(pilha.topo == pilha.fundo);
}

int push (ITEM x, PILHA * pilha){
	PONT aux;

	aux = (PONT)malloc(sizeof(CELULA));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
	return 0;
}

//int pop(ITEM x, PILHA * pilha){
//
//}
