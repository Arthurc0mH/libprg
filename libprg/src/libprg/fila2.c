#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

fila_t* criar_fila(int capacidade){
    fila_t* fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}
void enfileirar(fila_t* fila, int valor){
    if (fila->tamanho >= fila->capacidade){
        exit(EXIT_FAILURE);
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

void desenfileirar(fila_t* fila){
    if (fila->tamanho <= 0){
        exit(EXIT_FAILURE);
        }
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

int inicio(fila_t* fila){
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    return fila->elementos[fila->inicio];
}

int fim(fila_t* fila){
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    int final = fila->fim - 1;
    if (final < 0) final = fila->capacidade - 1;
    return fila->elementos[final];
}

bool fila_vazia(fila_t* fila){
    if (fila->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool fila_cheia(fila_t* fila){
    if (fila->tamanho == fila->capacidade){
        return true;
    }else{
        return false;
    }
}

void destruir_fila(fila_t* fila){
    free(fila->elementos);
    free(fila);
}