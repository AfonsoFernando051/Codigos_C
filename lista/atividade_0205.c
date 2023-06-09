/*
 ============================================================================
 Name        : atividade_0205.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"


int main(void) {
	setbuf(stdout, NULL);
	listaSimples *lista = NULL,
				*ultimo = NULL;


	for (int i = 0; i < 3; i++) {
		lista = inserirInicio(lista);
		//lista = inserirFim(lista);
//		inserirFimUltimo(&ultimo);
//		if (lista == NULL) { //if (!lista) {
//			lista = ultimo;
//		}
	}
	listaSimples * remover(listaSimples *inicioLista, int codigo);
	impressao(lista);
	return EXIT_SUCCESS;
}


