#include <stdlib.h>
#include "libprg/libprg.h"

lista_linear_t* criar_lista(bool ordenada, int capacidade){
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_lista(lista_linear_t* lista, int valor) {
    if (lista == NULL) {
        return;
    }

    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;

        int* novo = realloc(lista->elementos, lista->capacidade * sizeof(int));

        if (novo == NULL) {
            return;
        }

        lista->elementos = novo;
    }

    if (lista->ordenada == true) {
        int i = lista->tamanho - 1;

        while (i >= 0 && valor < lista->elementos[i]) {
            lista->elementos[i + 1] = lista->elementos[i];
            i--;
        }

        lista->elementos[i + 1] = valor;
        lista->tamanho++;
    } else {
        lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
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
    int inicio = 0; int fim = lista->tamanho  -1;
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
    if (lista->ordenada == false) {
        return busca_linear(lista, valor);
    }else {
        return busca_binaria(lista, valor);
    }
}

int remover_lista(lista_linear_t* lista, int valor) {
    if (lista->ordenada == true){
        int posicao = buscar(lista, valor);
        if (posicao == -1) return -1;
        int aux = 0;
        for (int i = posicao; i < lista->tamanho -1; i++) {
            lista->elementos[i] = lista->elementos[i+1];
        }
        lista->tamanho--;
        return 1;
    }else{
        int posicao = buscar(lista, valor);
        if (posicao == -1) return -1;
        lista->elementos[posicao] = lista->elementos[lista->tamanho -1];
        lista->tamanho--;
        return 1;
    }
}

bool lista_cheia(lista_linear_t* lista) {
    if (lista->tamanho == lista->capacidade) {
        return true;
    }else {
        return false;
    }
}

bool lista_vazia(lista_linear_t* lista) {
    if (lista->tamanho == 0) {
        return true;
    }else{
        return false;
    }
}

void destruir_lista(lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}

//alterar
//ordenar
//combinar