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


char EUF(){
    char entrada;
    
    do{
	    printf("\nDigite o valor de entrada:  \n");
        scanf("%c", &entrada);
	    printf("\nA - Calcular novo salario: \n");
	    printf("\nB - Minha strncpy\n");
	    printf("\nC - Finalizar\n");
    }while(entrada != 'c');

    return entrada;

}

int inteiro(int* valor){
	do{
		printf("\nDigite o tamanho do array: \n");
		scanf("%d", *valor);
	}while(valor>51);
	return valor;
}

float recebeSalariofloat(float salario){
	do{
		printf("\nDigite o valor(real) do salario: \n");
		scanf("%f", salario);
	}while(salario<0);
    return salario;
}

float calculaSalario(float salarioAtual){
    printf("\nDigite o valor do salario para ajuste: \n");
    if(salarioAtual <= 2500){
        salarioAtual += (salarioAtual * 0,15)+salarioAtual; 
        printf("\nAumento de 15 por cento\n");
        printf("\n%fn",salarioAtual );
        return salarioAtual;
    }
    if(salarioAtual > 2500 && salarioAtual <= 7000){
        salarioAtual += (salarioAtual * 0,075)+salarioAtual; 
        printf("\nAumento de 7.5 por cento\n");
        printf("\n%fn",salarioAtual );
        return salarioAtual;
    }
     if(salarioAtual > 7000){
        printf("\nSem aumento\n");
        return salarioAtual;
    }
}

float preencheEAcumulaVetor(float caulculoDoSalario,int *valor,float vetor[]){
    //matriz = malloc(sizeof(char*) * m->linhas);
    float acumulaSalario;
    malloc(sizeof(float) * (*valor));
    for(int i = 0; i<valor;i++){
        vetor[i] = caulculoDoSalario;
        acumulaSalario += vetor[i];     
    }
    return acumulaSalario;
}

float mediaSalarios(float acumulaSalario, int recebeInteiro){
    float mediaSalario;
    mediaSalario = acumulaSalario/recebeInteiro;

    printf("\nA media de salarios e: %f\n",mediaSalario);
}

int main(void) {
    int valor;
    int recebeInteiro;
    float salarioAtual;
    float salario;
    float caulculoDoSalario;
    float acumulaSalario;

	    EUF();
	   
        recebeInteiro = inteiro(valor);

        float* vetor;

        salarioAtual = recebeSalariofloat(salario);
        caulculoDoSalario = calculaSalario(salarioAtual);

       acumulaSalario = preencheEAcumulaVetor(caulculoDoSalario, recebeInteiro, vetor);

        mediaSalarios(acumulaSalario, recebeInteiro);



}