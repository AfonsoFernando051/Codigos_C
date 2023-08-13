/*
 ============================================================================
 Name        : matrizEsparsa.c
 Author      : fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Matriz Esparsa LIL(Listas de Listas)

//Struct que contem os dados, consistem em coluna, valor(dado) e o ponteiro que aponta para o próximo.
typedef struct Data{
	int column;
	int value;
	struct Data* next;
} Data;

//Struct que tem o tipo Data e armazena a linha;
typedef struct {
	Data* row;
} MatrizEsparsa;

//Função que cria a matriz esparsa, recebe por parâmetro o número de linhas e cria uma variável do tipo matriz esparsa.
//Há uma estrutura de repetição que percorre o número de linhas passadas por parâmetro e preenche a matriz criada com o
//número de linhas igual a nulo, para definir para ser retornado.
MatrizEsparsa* criarMatrizsparsa(int rows){
	MatrizEsparsa* matriz = (MatrizEsparsa*)malloc(sizeof(MatrizEsparsa) * rows);
	for(int i = 0; i < rows; i++){
		matriz[i].row = NULL;
	}
	return matriz;
	}

//Função que insere na matriz criada os elementos. Recebe por parâmetro a matriz, a linha, a coluna, o valor e o próximo.

//Dentro da função é criada uma variável tipo Data.
//Os valores passados por parâmetro se tornam os valores estabelecidos nesta variável, inclusive o atributo próximo recebe
//a informação de que o tipo matriz que veio por parâmetro é um próximo elemento da matriz e a linha estabelecida como a
//A matriz na posição que passamos por parâmetro recebe a nova Data criada.
//
void InserirElemento(MatrizEsparsa* matriz, int row, int column, int value){
	Data* newData = (Data*)malloc(sizeof(Data));
	newData->column = column;
	newData->value = value;
	newData->next = matriz[row].row;
	matriz[row].row = newData;
}

//Esta função imprime a matriz percorrendo a quantidade de linhas e colunas definidas.
//A variável tipo Data, dataAtual recebe a matriz em todas as posições que possuem nas
//linhas com uma estrutura de repetição, ao mesmo passo que há uma estrutura de repetição
//para percorrer as colunas, e se a linha existir e a data for igual a coluna (ou seja, durante
// a repetição inteira), é printada o valor da dataAtual e a dataAtual se torna a próxima.
void printarMatrizEsparsa(MatrizEsparsa* matriz, int rows, int columns){
	for(int i = 0; i < rows; i++){
		Data* dataAtual = matriz[i].row;
		for(int j = 0; j < columns; j++){
			if(dataAtual && dataAtual->column == j){
				printf("%d ", dataAtual->value);
				dataAtual = dataAtual->next;
			}else{
				printf("0 ");
			}
		}
        printf("\n");
	}
}

int main(void) {
	int rows = 4;
	int columns = 5;

	MatrizEsparsa* matrizEsparsa = criarMatrizsparsa(rows);

	InserirElemento(matrizEsparsa, 0, 1, 5);
	InserirElemento(matrizEsparsa, 1, 2, 8);
	InserirElemento(matrizEsparsa, 2, 0, 2);
	InserirElemento(matrizEsparsa, 3, 3, 1);

	printf("Matriz Esparsa: \n");
	printarMatrizEsparsa(matrizEsparsa, rows, columns);

	return 0;

}
