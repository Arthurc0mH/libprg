#ifndef FILA_H
#define FILA_H

#define MAX_FILA 100

typedef struct {
    int dados[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void criar_fila(Fila *f);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f, int *valor_removido);
int consultar_frente(Fila *f, int *valor_frente);
int tamanho_fila(Fila *f);

#endif