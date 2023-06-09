/*
 * funcoesLista.c
 *
 *  Created on: 8 de jun. de 2023
 *      Author: fernando
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void menu(){
	char op;
	int tam = 0;
	int cod;

	listaSimples *lista = NULL, *ultimo = NULL;

	do{
		printf("\nDigite para escolher a acao:\n"
				"\nA - para criar itens na lista\n"
				"\nB - para remover\n"
				"\nC - para imprimir os itens\n"
				"\nF - para sair\n");
		scanf(" %c", &op);
		op = toupper(op);

		switch(op){
		case 'A':
			int codMenuInsercao;
			lista != NULL ? free(lista): printf("\nLista pronta para ser criada\n");
			tamanhoLista(&tam);
			menuInsercao(&codMenuInsercao);
			for(int i = 0; i < tam; i++){
				codMenuInsercao == 1 ? lista = inserirInicio(lista) : 0;
				codMenuInsercao == 2 ? lista = inserirFim(lista) : 0;
				codMenuInsercao == 3 ? inserirFimUltimo(&ultimo) : 0;
				codMenuInsercao == 4 ? printf("\nVoltando ao menu anterior\n") : 0;
			}
			break;
		case 'B':
			printf("\nDigite o codigo do produto a ser removido\n");
			scanf(" %d", &cod);
			printf("\n %d", cod);
			lista = removerLista(lista, cod);
			break;
		case 'C':
			impressao(lista, 0);
			break;
		case 'F':
			lista != NULL ? free(lista): printf("\nErro ao apagar os dados...n");
			printf("\nSaindo...\n");
			break;
		default:
			printf("Opcao invalida");
			break;
		}

	}while(op != 'F');
}

void tamanhoLista(int *tam){
	printf("\nDigite o tamanho que a lista tera\n");
	scanf(" %d", tam);
}

void menuInsercao(int * codMenuInsercao){
	printf("\nEscolha o tipo de insercao:\n"
			"\n1 - para insercao por inicio\n"
			"\n2 - para insercao por fim\n"
			"\n3 - para insercao por fim ultimon"
			"\n4 - para sair\n");
	scanf(" %d", codMenuInsercao);
}

listaSimples* inserirInicio(listaSimples *listaInicio){
	listaSimples *novo = (listaSimples*)malloc(sizeof(listaSimples));

	novo->codigo = RANDOM(1000);

	novo->proximo = listaInicio;

	return novo;
}

listaSimples * inserirFim(listaSimples * inicioLista){
	listaSimples *novo = (listaSimples*)malloc(sizeof(listaSimples));

	novo->codigo = RANDOM(1000);

	novo->proximo = NULL;

	if(inicioLista != NULL){
		listaSimples *tmp = inicioLista;
		while(tmp->proximo != NULL){
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return inicioLista;
	}else{
		return novo;
	}
}

void inserirFimUltimo(listaSimples **ultimoLista){
	listaSimples *novo = (listaSimples*)malloc(sizeof(listaSimples));

	novo->codigo = RANDOM(1000);

	novo->proximo = NULL;

	if((*ultimoLista) != NULL){
		(*ultimoLista)->proximo = novo;
	}
	(*ultimoLista) = novo;
}

listaSimples *removerLista(listaSimples *listaInicio, int codigo){

	listaSimples * temp = listaInicio;
	listaSimples * tempAnterior = NULL;

	//Tentativa com recursividade
	//	if(listaInicio != NULL){
	//		if(codigo != listaInicio->codigo){
	//			tempAnterior = temp;
	//			temp = listaInicio->proximo;
	//			removerLista(temp, temp->codigo);
	//
	//		}else if(tempAnterior == NULL)
	//		{
	//			tempAnterior = temp->proximo;
	//			free(temp);
	//		}
	//		else if(codigo == listaInicio->codigo){
	//			tempAnterior->proximo = temp->proximo;
	//			printf("\nantes: %p, depois: %p\n", tempAnterior  ,temp->proximo );
	//
	//			free(temp);
	//			return listaInicio;
	//		}
	//
	//	}

	while (temp != NULL) { //while (tmp->proximo) {
		if(temp->codigo != codigo){
			tempAnterior = temp;
			temp = temp->proximo;

		}else{
			if(tempAnterior == NULL){
				listaInicio=listaInicio->proximo;

			}else{
				tempAnterior->proximo = temp->proximo;
			}

			free(temp);
			printf("\n Apos a remocao: \n");
			impressao(listaInicio, 0);

			return listaInicio;
		}

	}

	printf("Registro nao encontrado");
	return listaInicio;
}

void impressao(listaSimples *lista, int i){

	if(lista != NULL){
		i++;
		printf("\n Lista %d - Endereco %p - Codigo %d - Proximo %p \n", i,lista, lista->codigo,lista->proximo);
		impressao(lista->proximo, i++);
	}
}
