/*
 * biblioteca.h
 *
 *  Created on: 8 de jun. de 2023
 *      Author: fernando
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define RANDOM(x) rand() % (x)

typedef struct lista listaSimples;
struct lista{
	int codigo;
	listaSimples *proximo;
};

void tamanhoLista();
void menuInsercao(int * codMenuInsercao);
listaSimples* inserirInicio(listaSimples *listaInicio);
listaSimples * inserirFim(listaSimples * inicioLista);
void inserirFimUltimo(listaSimples **ultimoLista);
void impressao(listaSimples *lista, int i);
listaSimples *removerLista(listaSimples *listaInicio, int codigo);


#endif /* BIBLIOTECA_H_ */
