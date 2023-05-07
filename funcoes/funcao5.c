/*
 ============================================================================
 Name        : funcoes.c
 Author      : fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int EUF(){
    int entrada;

    do{
	    printf("\nDigite o valor de entrada:  \n");
	    printf("\n1 - Calcular novo salario: \n");
	    printf("\n2 - Minha strncpy\n");
	    printf("\n3 - Finalizar\n");
        scanf("%d", &entrada);
    }while(entrada != 1 && entrada != 2 && entrada != 3);

    return entrada;

}

int inteiro(){
    int valor;
	do{
		printf("\nDigite o tamanho do array: (Ate 50)\n");
		scanf("%d", &valor);
	}while(valor>50);
	return valor;
}

float recebeSalariofloat(){
    float salario;
	do{
		printf("\nDigite o valor(real) do salario: \n");
		scanf("%f", &salario);
		if(salario<=0){
			printf("\nDigite novamente.\n");
		}
	}while(salario<=0);
    return salario;
}

float calculaSalario(float salarioAtual){
    float salarioNovo;
    if(salarioAtual <= 2500){
        salarioNovo = ((salarioAtual/100)*15)+salarioAtual;
        printf("\nAjuste de %.2f para %.2f. Aumento de 15 por cento.\n",salarioAtual, salarioNovo);
    }
    else if(salarioAtual > 2500 && salarioAtual <= 7000){
        salarioNovo = ((salarioAtual/100)*7.5)+salarioAtual;
        printf("\nAjuste de %.2f para %.2f. Aumento de 15 por cento.\n",salarioAtual, salarioNovo);

    }
     else if(salarioAtual > 7000){
        printf("\nSem aumento\n");
    }
    return salarioNovo;

}

float preencheVetor(int recebeInteiro,float vetor[]){
    //matriz = malloc(sizeof(char*) * m->linhas);
	float acumulaSalario;
    vetor = malloc(sizeof(float) * (recebeInteiro));
    for(int i = 0; i<recebeInteiro;i++){
        vetor[recebeInteiro] = recebeSalariofloat();
        float salarioAtual = vetor[recebeInteiro];
        vetor[recebeInteiro] = calculaSalario(salarioAtual);
        acumulaSalario += vetor[recebeInteiro];
    }
    free(vetor);
        printf("Acumulo :%.2f",acumulaSalario);
    return acumulaSalario;
}

float mediaSalarios(float acumulaSalario, int recebeInteiro){
    float mediaSalario;
    mediaSalario = acumulaSalario/recebeInteiro;

    printf("\nA media de salarios e: %.2f\n",mediaSalario);
    return mediaSalario;
}

void strncpy(char String2[], char String1[]){
int tamanhoCopia;
tamanhoCopia = inteiro();
char stringCopiada[50];
int itera = tamanhoCopia;
for(int i = 0; i < tamanhoCopia;i++){
		String2[i] = String1[i];
}
	for(int j = 0; j<strlen(String2);j++){
		if(itera < strlen(String2)){
			String2[itera] = " ";
			itera++;
		}

	}
printf("%s",String2);
}

int main(void) {
	setbuf(stdin,NULL);
    int entrada;
    int valor;
    int recebeInteiro;
    float salarioAtual;
    float salario;
    float acumulaSalario;

	do{
	entrada = EUF();

    if(entrada == 1){
    recebeInteiro = inteiro();

    float* vetor;

    acumulaSalario = preencheVetor(recebeInteiro, vetor);

    mediaSalarios(acumulaSalario, recebeInteiro);
    }

    if(entrada == 2){
    	char String1[50] = "teste1";
    	char String2[50] = "teste2";
    	strncpy(String2, String1);

     }
    if(entrada == 3){
    	printf("\nFinalizamos\n");
       }
	}while(entrada != 3);
}
