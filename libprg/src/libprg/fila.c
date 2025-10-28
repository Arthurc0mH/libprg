#include <stdio.h>
#include "libprg/libprg.h"

void criar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return (f->tamanho == 0);
}

int fila_cheia(Fila *f) {
    return (f->tamanho == MAX_FILA);
}

int enfileirar(Fila *f, int valor) {
    if (fila_cheia(f)) {
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *valor_removido) { //valor_removido pode ser uma variável de lixo
    if (fila_vazia(f)) {
        return 0;
    }
    *valor_removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    return 1;
}

int consultar_frente(Fila *f, int *valor_frente) {
    if (fila_vazia(f)) {
        return 0;
    }
    *valor_frente = f->dados[f->inicio];
    return 1;
}

int tamanho_fila(Fila *f) {
    return f->tamanho;
}

int enfileirar2(Fila *f, char valor)
{
    if (fila_cheia(f)) {
        return 0;
    }
    f->dados_char[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->tamanho++;
    return 1;
}

int desinfileirar2(Fila *f, char *valor_removido)
{
    if (fila_vazia(f)) {
        return 0;
    }
    *valor_removido = f->dados_char[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    return 1;
}