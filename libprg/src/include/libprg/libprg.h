#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define MAX_PILHA 10

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

typedef struct {
    int dados[MAX_PILHA];
    int topo;
} Pilha;

void criar_pilha(Pilha *p);
int pilha_vazia(Pilha *p); //retorna 1 se a pilha tiver vazia
int pilha_cheia(Pilha *p); //retorna 1 se a pilha tiver cheia
int empilhar(Pilha *p, int valor); //retorna 1 se a deu certo, retorna 0 se der overflow
int desempilhar(Pilha *p, int *valor_removido); //retorna 1 se deu certo, retorna 0 se der underflow
int consultar_topo(Pilha *p, int *valor_topo); //retorna 1 der certo, 0 se vazia
int tamanho_pilha(Pilha *p); //da return na quantidade de itens na pilha

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif
