#ifndef BIBLIOLISTASIMPLES_H_
#define BIBLIOLISTASIMPLES_H_

#include <stdio.h>
#include <stdlib.h>

//Macro
#define RANDON(x) rand() % (x)

//Estrutura
typedef struct dados listaSimples;
struct dados{
	//Dados b�sicos
	int codigo;

	//Ponteiros
	listaSimples *proximo;
};

//Fun��es
listaSimples* inserirInicio(listaSimples *inicioLista);
void inserirFimUltimo(listaSimples **ultimo);
listaSimples* inserirFim(listaSimples *inicioLista);
listaSimples * remover(listaSimples *inicioLista, int codigo);


void impressao(listaSimples *lista);
#endif /* BIBLIOLISTASIMPLES_H_ */
