#include "lib1.h"

listaSimples* inserirInicio(listaSimples *inicioLista){
	//Alocar dinamicamente o novo endereço
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));

	//Preencher dados básicos
	novo->codigo = RANDON(1000);

	//Conectar esse registro à lista
	novo->proximo = inicioLista;

	//Retornar o novo para atualizar a lista
	return novo;
}

listaSimples* inserirFim(listaSimples *inicioLista){
	//Alocar o novo elemento
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));

	//Preencher dados básicos
	novo->codigo = RANDON(100);

	//O novo aponta para o inicio
	novo->proximo = NULL;

	//Conectar o registro à lista
	//Ele não é o primeiro a ser inserido
	if (inicioLista != NULL) { //if (inicioLista){
		//Procurar o último registro
		listaSimples *tmp = inicioLista;
		while (tmp->proximo != NULL) { //while (tmp->proximo) {
			tmp = tmp->proximo;
		}

		//Fazer o último apontar para o novo registro
		tmp->proximo = novo;
		return inicioLista;
	} else {//Ele é o primeiro a ser inserido
		return novo;
	}
}

void inserirFimUltimo(listaSimples **ultimoLista){
	//Alocar o novo elemento
	listaSimples *novo = (listaSimples*) malloc (sizeof(listaSimples));

	//Preencher dados básicos
	novo->codigo = RANDON(100);

	//O novo aponta para o inicio
	novo->proximo = NULL;

	//Conectar o registro à lista
	if ((*ultimoLista) != NULL) { //if ((*ultimo)){
		(*ultimoLista)->proximo = novo;
	}
	(*ultimoLista) = novo;

}

listaSimples * remover(listaSimples *inicioLista, int codigo){

	listaSimples *tmp = inicioLista;
	listaSimples *tmp2 = NULL;

	while (tmp != NULL) { //while (tmp->proximo) {
		if(tmp->codigo != codigo){
			tmp2 = tmp;
			tmp = tmp->proximo;

		}else{
			if(tmp2 == NULL){
				tmp2 = tmp->proximo;
			}
			tmp2->proximo = tmp->proximo;
			free(tmp);
			return inicioLista;
		}
	}
	printf("Retorno nao encontrado");
	return inicioLista;
}

void impressao(listaSimples *lista){
	if (lista != NULL) { //if (lista) {
		printf("\nEndereço %p - Código %d - Próximo %p\n",
				lista, lista->codigo, lista->proximo);
		impressao(lista->proximo);
	}
}
