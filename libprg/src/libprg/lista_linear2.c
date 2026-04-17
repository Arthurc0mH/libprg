#include <stdlib.h>
#include "libprg/libprg.h"

#define CAPACIDADE_INICIAL 10

lista_linear_t* criar_lista(bool ordenada){
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_lista(lista_linear_t* lista, int valor) {
    if (lista->ordenada == true) {
        int aux = 0;
        for (int i = 0; i < lista->tamanho; i++) {
            if (valor <= lista->elementos[i]) {
                aux = lista->elementos[i];
                lista->elementos[i] = valor;
                valor = aux;
            }
        }
        lista->tamanho++;
    }else {
        //ordenar
    }
}


int busca_linear(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (valor == lista->elementos[i]) {
            return i;
        }
    }
    return -1;
}

int busca_binaria(lista_linear_t* lista, int valor) {
    int inicio = 1; int fim = lista->tamanho;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->elementos[meio] == valor) {
            return meio;
        }else if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar(lista_linear_t* lista, int valor) {
    if (lista->ordenada == true) {
        return busca_linear(lista, valor);
    }else {
        return busca_binaria(lista, valor);
    }
}

int remover_lista(lista_linear_t* lista, int valor) {
    int posicao = buscar(lista, valor);
    if (posicao == -1) return -1;
    int aux = 0;
    for (int i = posicao; i < lista->tamanho; i++) {
        aux = lista->elementos[i+1];
        lista->elementos[i] = aux;
    }
    lista->tamanho--;
    return 1;
}

bool lista_cheia(lista_linear_t* lista) {
    if (lista->tamanho == lista->capacidade) {
        return true;
    }else {
        return false;
    }
}

void destruir_lista(lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}
//inserir
//remover
//buscar linear
//busca binaria
//alterar
//ordenar
//combinar
//destruir