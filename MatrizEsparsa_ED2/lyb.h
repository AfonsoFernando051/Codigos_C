/*
 * lyb.h
 *
 *  Created on: 24 de ago. de 2023
 *      Author: 3A226866341
 */

#ifndef LYB_H_
#define LYB_H_

typedef struct CELULA_TAG *PONT;

typedef struct{
	int i;
}ITEM;

typedef struct CELULA_TAG{
	ITEM item;
	PONT prox;
} CELULA;

typedef struct {
	PONT fundo, topo;
	int tamanho;
} PILHA;

void cria(PILHA*);
int vazia(PILHA);
int push (ITEM x, PILHA * pilha);
int pop(PILHA * pilha, ITEM *item);
int look(PILHA *pilha, ITEM *item);
int tamanho (PILHA pilha);
#endif /* LYB_H_ */
