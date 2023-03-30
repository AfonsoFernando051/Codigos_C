/*
 ============================================================================
 Name        : alura1.c
 Author      : fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main() {

	char palavrasecreta[20];
	printf("Digite a palavra da forca: ");
	fgets(palavrasecreta,20,stdin);

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	do {

		for(int i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;

			for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}

			if(achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		char chute;
		printf("Qual letra? ");
		scanf(" %c", &chute);

		chutes[tentativas] = chute;
		tentativas++;


	} while (!acertou && !enforcou);

}

