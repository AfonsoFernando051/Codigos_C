/*
 * func.c
 *
 *  Created on: 25 de jun. de 2023
 *      Author: fernando
 */
#include <stdio.h>
#include <stdlib.h>
#include "lyb.h"

menu(){
	char op;
	int qtd;
	listaSimples * lista = NULL;
	do{
		printf("\nDigite para escolher: \n"
				"\nA - para insercao por inicio\n"
				"\nB - para inserir por fim\n"
				"\nD - para imprimir\n"
				"\nF - para sair\n");
		scanf(" %c", &op);

		op = toupper(op);
		switch(op){
		case 'A':
			quantidade(&qtd);
			for(int i = 0; i<qtd; i++){
				lista = inserirInicio(lista);
			}
			break;
		case 'B':
			quantidade(&qtd);
			for(int i = 0; i<qtd; i++){
				lista = inserirFim(lista);
			}
			break;
		case 'D':
			imprimir(lista);
			break;
		default:
			printf("\nSaindo...\n");
		}

	}while(op != 'F');
}

void quantidade(int *qtd){
	printf("\nDigite a quantidade a ser inserida\n");
	scanf(" %d", qtd);
}

listaSimples * inserirInicio(listaSimples * lista){
	listaSimples * novo = (listaSimples*)malloc(sizeof(listaSimples));
	novo->codigo = RANDOM(100);
	novo->prox = lista;
	novo->ant = NULL;
	if(!lista){
		lista = novo;
		novo->prox = NULL;
	}
	if(lista){
		lista->ant = novo;
	}

	return novo;
}

listaSimples * inserirFim(listaSimples * lista){
	listaSimples * novo = (listaSimples*)malloc(sizeof(listaSimples));
	novo->codigo = RANDOM(100);
	novo->ant = lista;
	novo->prox = NULL;

	if(lista){
		listaSimples * tmp = lista;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = lista;
		return lista;
	}else{

		return novo;
	}

}

void imprimir(listaSimples * lista){
	if(lista){
		printf("\n %d - codigo, Anterior - %p, Endereco - %p, Proximo - %p\n", lista->codigo, lista->ant, lista, lista->prox);
		imprimir(lista->prox);
	}
}
