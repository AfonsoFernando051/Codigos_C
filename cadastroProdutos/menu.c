#include <stdio.h>
#include <stdlib.h>
#include "minhaLib.h"



void menu(){
	char opcao;
	int totalProdutos;
	double mediaPrecos;
	produto *listaDeProdutos = NULL;

	//Estrutura de repeticao, enquanto o valor opcao for diferente de 3
	//o codigo continuara
	do
	{
		printf("\nMenu de opcoes, digite a letra para executar a funcionalidade: \n");
		printf("\nA - Criar estrutura para preenchimento. \n");
		printf("\nB - Preencher dados.\n");
		printf("\nC - Exibir produtos com estoque zerado. \n");
		printf("\nD - Exibir produtos cadastrados. \n");
		printf("\nE - Finalizar. \n");
		scanf(" %c", &opcao);
		opcao = toupper(opcao);

		switch (opcao){
		case 'A':
			//Case opcao == A, chama a funcao totalProdutos e posteriormente
			//aloca dinamicamente um espaco na memoria do tamanho de totalProdutos.
			//Sempre que for chamada, libera o espaco de memoria, se estiver preenchido
			//ou nao.
			free(totalProdutos);
			totalProdutos = totalDeProdutos();
			listaDeProdutos = (produto*) malloc(sizeof(produto) * totalProdutos);
			break;
		case 'B':
			//Case opcao == B, se o ponteiro listaDeProdutos, que aponta para o endereco de
			//memoria em que alocaremos os produtos tiver o valor inicial que era NULL, o valor
			//e invalido e deve passar pelo case A novamente. Caso contrario, a funcao de
			//cadastro de produtos e executada.
			listaDeProdutos!=NULL ? cadastroDeProdutos(listaDeProdutos,totalProdutos)
					: printf("\nInvalido\n");
			break;

		case 'C':
			//Assim como o case B, o case C so funciona apos o case A ser executado,
			//esta funcao exibe os produtos que tem quantidade == 0, passando por um
			//loop de repeticao que percorre todos os itens, e uma estrutura condicional
			//que procura o produto na posicao atual que tiver quantidade 0.
			listaDeProdutos!=NULL ? exibirEstoqueZerado(listaDeProdutos,totalProdutos)
					: printf("\nInvalido\n");;
			break;
		case 'D':
			//Tambem necessita de passar pelo case A, este case retorna todos os produtos e suas
			//caracteristicas, alem de retornar a media do preco dos produtos.
			listaDeProdutos!=NULL ? exibirEstoqueCompleto(listaDeProdutos,totalProdutos,&mediaPrecos)
					: printf("\nInvalido\n");;
			printf("\nMedia do preco dos produtos: %.2lf\n", mediaPrecos);
			break;
		case 'E':
			printf("\nFinalizando...\n");
			break;
		default:
			printf("\nOpcao indisponivel, digite novamente.\n");
			break;
		}

	}while(opcao != 'E');
}

//Funcao que retorna o inteiro quantidade de produtos;
int totalDeProdutos(){
	int totalProdutos;
	do
	{
		printf("Digite a quantidade total de produtos");
		scanf(" %d", &totalProdutos);
		if(totalProdutos < 0)
		{
			printf("\nQuantidade invalida, digite um numero positivo\n");
		}
	}while(totalProdutos < 0);
	return totalProdutos;
}
//Funcao que faz o cadastro de produtos, chamando outras funcoes relativas.
void cadastroDeProdutos(produto *produto,int totalProdutos)
{
	for(int i = 0; i<totalProdutos;i++)
	{
		cadastrarDescricao(produto->descricao);
		produto->codigo = RANDOM;
		cadastrarPreco(&produto->preco);
		cadastrarQuantidade(produto);
		produto++;
	}
}
//Funcao que cadastra a descricao dos produtos.
void cadastrarDescricao(char *descricao)
{
	printf("\nDigite a descricao do produto: \n");
	scanf(" %[^\n]", descricao);
}
//Funcao que cadastra o preco dos produtos.
void cadastrarPreco(double *preco)
{
	printf("\nDigite o preco do produto: \n");
	scanf("%lf", preco);
}
//Funcao que cadastra a quantidade disponivel de cada produto.
void cadastrarQuantidade(produto *listaProdutos)
{
	printf("\nDigite a quantidade disponivel do produto: \n");
	scanf("%d", &listaProdutos->quantidade);
}
//Funcao que exibe os produtos indisponiveis no estoque.
void exibirEstoqueZerado(produto *produto,int totalProdutos)
{
	printf("\n-------------------------------\n");
	printf("\nItens indisponiveis no estoque\n");
	printf("\n-------------------------------\n");
	printf("\Item Quantidade Preco\n");


	for(int i = 0; i<totalProdutos;i++){
		if(produto[i].quantidade == 0){
			printf("\n %s   %d   %.2f\n",produto[i].descricao,
					produto[i].quantidade, produto[i].preco);		}
	}
	printf("\n-------------------------------\n");
	printf("\n-------------------------------\n");
}
//Funcao que exibe o estoque completo e retorna a media de precos.
void exibirEstoqueCompleto(produto *produto,int totalProdutos, double *media)
{
	int i = 0;
	double soma = produto[i].preco;

	printf("\n-------------------------------\n");
	printf("\nItens disponiveis no estoque\n");
	printf("\n-------------------------------\n");
	printf("\Item Quantidade Preco\n");


	for(int j = 0; j<totalProdutos;j++)
	{
		printf("\n %s   %d   %.2f\n",produto[i].descricao,
				produto[i].quantidade, produto[i].preco);

		soma += produto[i].preco;
	}

	*media = soma/i;
	printf("\n-------------------------------\n");
	printf("\n-------------------------------\n");
}
