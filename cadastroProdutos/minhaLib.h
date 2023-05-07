/*
 * lib.h
 *
 *  Created on: 7 de mai. de 2023
 *      Author: fernando
 */

#ifndef MINHALIB_H_
#define MINHALIB_H_

struct produto{
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
};

typedef struct produto produto;

#define RANDOM rand() % 50

void menu();
int totalDeProdutos();
void cadastroDeProdutos();
void cadastrarDescricao(char *descricao);
void cadastrarPreco(double *preco);
void cadastrarQuantidade(produto *listaProdutos);

#endif /* MINHALIB_H_ */
