
typedef struct CELULA_TAG *PONT;

typedef struct{
    int chave;
}ITEM;

typedef struct CELULA_TAG{
    ITEM item;
    PONT prox;
}CELULA;

typedef struct{
    PONT primeira, ultima;
}FILA;

typedef struct{
    PONT topo, fundo;
    int tamanho;
}PILHA;

void criarFila(FILA *fila);
int enfileirar(FILA *fila, ITEM x);
int desenfileira(FILA *fila, ITEM *item);
int filaVazia(FILA fila);
int pilhaVazia(PILHA pilha);
void imprimeFila(FILA fila);
int look(FILA *fila, ITEM *item);
void criarPilha(PILHA *pilha);
int empilhar(PILHA *pilha, ITEM x);
int desempilha(PILHA *pilha, ITEM *x);
void imprimePilha(PILHA pilha);