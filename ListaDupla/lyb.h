/*
 * lyb.h
 *
 *  Created on: 25 de jun. de 2023
 *      Author: fernando
 */

#ifndef LYB_H_
#define LYB_H_
#define RANDOM(x) rand() % (x)

typedef struct lista listaSimples;

struct lista{
	int codigo;
	listaSimples * prox;
	listaSimples * ant;
};
void menu();
void quantidade();
listaSimples * inserirInicio(listaSimples * lista);
listaSimples * inserirFim(listaSimples * lista);
void imprimir();

#endif /* LYB_H_ */
