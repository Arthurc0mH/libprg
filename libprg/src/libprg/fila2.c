#include <stdlib.h>

#include "libprg/libprg.h"

fila_t* criar_fila(int capacidade) {
    fila_t* fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}

void enfileirar(fila_t* fila, int valor) {

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar() {

}

// int incio() {
//
// }
//
// int fim() {
//
// }
//
// int vazia() {
//
// }
//
// int cheia() {
//
// }

int destruir_fila(fila_t* fila) {
    free (fila->elementos);
    free(fila);
    return 0;
}