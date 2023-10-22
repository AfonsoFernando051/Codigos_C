#include <stdio.h>
#include <stdlib.h>
#include "reverselyb.h"

void criarFila(FILA *fila){
    fila->primeira = (PONT)malloc(sizeof(CELULA));
    fila->ultima = fila->primeira;
    fila->primeira->prox = NULL;
}

void criarPilha(PILHA *pilha){
	pilha->topo = (PONT)malloc(sizeof(CELULA));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int enfileirar(FILA *fila, ITEM x){
    fila->ultima->prox = (PONT)malloc(sizeof(CELULA));
    fila->ultima = fila->ultima->prox;
    fila->ultima->item = x;
    fila->ultima->prox = NULL;

    return 0;
}

int empilhar(PILHA *pilha, ITEM x){
	PONT aux;

	aux = (PONT)malloc(sizeof(CELULA));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
	return 0;
}

int filaVazia(FILA fila){
    return fila.primeira == fila.ultima;
}

int pilhaVazia(PILHA pilha){
    return pilha.topo == pilha.fundo;
}

int desenfileira(FILA *fila, ITEM *item){

    if(filaVazia(*fila)){
        printf("A fila esta vazia");
        return -1;
    }

    PONT q;
    q = fila->primeira;
    fila->primeira=q->prox;
    *item = q->prox->item;
    free(q);
    return 0;
}

int desempilha(PILHA *pilha, ITEM *item){

	PONT q;

	if(pilhaVazia(*pilha)){
		return -1;
	}

	q = pilha->topo;
	pilha->topo = q->prox;
	*item = q->prox->item;
	free(q);
	pilha->tamanho--;
	return 0;
}

void imprimeFila(FILA fila){
  
    if(filaVazia(fila)){
        printf("\nFila vazia.\n");
    }
	PONT aux;

	aux = fila.primeira->prox;
    
	while(aux != NULL){
		printf("%d ", aux->item.chave);
		aux = aux->prox;
	}
}

void imprimePilha(PILHA pilha){
  
    if(pilhaVazia(pilha)){
        printf("\nPilha vazia.\n");
    }
	PONT aux;

	aux = pilha.topo->prox;
    
	while(aux != NULL){
		printf("%d ", aux->item.chave);
		aux = aux->prox;
	}
}

int look(FILA *fila, ITEM *item){
	if(filaVazia(*fila)){
		return -1;
	}
	*item = fila->primeira->prox->item;
	return 0;
}

int main(void){
    PILHA pilha;
    FILA fila;
    ITEM item;
    criarFila(&fila);
    criarPilha(&pilha);

   // Adicionando items na fila.
    for(int i = 0; i < 10; i++){
        item.chave = i;
        if(enfileirar(&fila, item) == -1){
            printf("Erro");
        }
    }

    printf("\nItens empilhados: \n");
    imprimeFila(fila);
    printf("\n");

    while(!filaVazia(fila)){
        desenfileira(&fila, &item);
        ITEM i = item;
        empilhar(&pilha, i);
    }

    printf("\nItens empilhados: \n");
    imprimePilha(pilha);
    printf("\n");

    while(!pilhaVazia(pilha)){
        desempilha(&pilha, &item);
        ITEM i = item;
        enfileirar(&fila, i);
    }

    printf("\nItens empilhados: \n");
    imprimeFila(fila);
    printf("\n");
    
    return 0;
}