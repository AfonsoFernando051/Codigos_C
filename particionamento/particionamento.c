/*
 ============================================================================
 Name        : particionamento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int tam){
	for(int i = 0; i < tam; i++){
		printf("%02d ", v[i]);

	}
	printf("\n");
	for(int i = 0; i < tam; i++){
			printf("%02d ", i);

	}
	printf("\n");
}

int main(void) {

	int vet[] = {1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1};
	int tam = sizeof(vet)/sizeof(int);

	int i = 0, j = tam-1;
	int pivo = 0, aux = 0;

	imprime(vet, tam);

	do{
		while(pivo > vet[i]) i++;
		while(pivo <= vet[j]) j--;
		if(i <= j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;j--;
		}
	}while(i <= j);

	imprime(vet, tam);
	printf("i = %d\n", i);
	printf("j = %d\n", j);

	return 0;
}
