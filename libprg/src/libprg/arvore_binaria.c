#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

No *criar_no(int valor){
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void destruir_no(No *no){
    if (no != NULL){
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

No *inserir_valor(No *raiz, int valor){
    if (raiz == NULL){
        return criar_no(valor);
    }else if (valor < raiz->valor){
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    }else if (valor > raiz->valor){
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

int busca(No *raiz, int valor){ //vou usar int mesmo, 0 e 1 pra false e true
    if (raiz == NULL){
        return 0;
    }
    if (valor == raiz->valor){
        return 1;
    }
    if (valor < raiz->valor){
        return busca(raiz->esquerda, valor);
    }else{
        return busca(raiz->direita, valor);
    }
}

No *remover_valor(No *raiz, int valor){
    if (raiz == NULL){
        return raiz;
    }
    if (valor < raiz->valor){
        raiz->esquerda = remover_valor(raiz->esquerda, valor);
    }else if (valor > raiz->valor){
        raiz->direita = remover_valor(raiz->direita, valor);
    }else{
        if (raiz->esquerda == NULL){
            No *no_aux = raiz->direita;
            free(raiz);
            return no_aux;
        }else if (raiz->direita == NULL){}
    }
}