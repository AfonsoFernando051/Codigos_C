/*
 ============================================================================
 Name        : project.c
 Author      : fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_funcionarios, i;
    float *salarios, salario_atual, soma_salarios = 0.0, maior_salario = 0.0;
    int *pecas, qtd_pecas;

    // Solicita a quantidade de funcionários e valida se é positiva
    do {
        printf("Digite a quantidade de funcionarios: ");
        scanf("%d", &num_funcionarios);
    } while (num_funcionarios <= 0);

    // Aloca os vetores dinamicamente
    salarios = (float*) malloc(num_funcionarios * sizeof(float));
    pecas = (int*) malloc(num_funcionarios * sizeof(int));

    // Preenche o vetor de peças produzidas
    printf("\nQuantidade de pecas produzidas por cada funcionario:\n");
    for (i = 0; i < num_funcionarios; i++) {
        do {
            printf("Funcionario %d: ", i+1);
            scanf("%d", &qtd_pecas);
        } while (qtd_pecas < 0);
        pecas[i] = qtd_pecas;
    }

    // Calcula os salários finais e armazena no vetor de salários
    for (i = 0; i < num_funcionarios; i++) {
        qtd_pecas = pecas[i];
        if (qtd_pecas <= 200) {
            salario_atual = qtd_pecas * 2.0;
        } else if (qtd_pecas <= 400) {
            salario_atual = qtd_pecas * 2.3;
        } else {
            salario_atual = qtd_pecas * 2.5;
        }
        salarios[i] = salario_atual;
        soma_salarios += salario_atual;
        if (salario_atual > maior_salario) {
            maior_salario = salario_atual;
            qtd_pecas = pecas[i];
        }
    }

    // Exibe os valores calculados
    printf("\nSalarios:\n");
    for (i = 0; i < num_funcionarios; i++) {
        printf("Funcionario %d: R$ %.2f\n", i+1, salarios[i]);
    }
    printf("Soma dos salarios: R$ %.2f\n", soma_salarios);
    printf("Maior salario: R$ %.2f (produziu %d pecas)\n", maior_salario, qtd_pecas);

    // Libera a memória alocada
    free(salarios);
    free(pecas);

    return 0;
}
