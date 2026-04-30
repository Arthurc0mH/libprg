#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int dado;
    no_t* proximo;
}no_t;

typedef struct nod {
    int dado;
    nod_t* proximo;
    nod_t* anterior;
}nod_t; //no duplo

no_t* criar_encadeada(int dado) {
    no_t* no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;
}

void inserir_encadeada(no_t** inicio, int dado) {
    no_t* novo = criar_encadeada(dado);
    novo->proximo = *inicio;
    *inicio = novo;
}

no_t* buscar(no_t** inicio, int dado) {
    no_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

bool remover_encadeada(no_t** inicio, int dado) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) *inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            return true;
        }
    }

    anterior = atual;
    atual = atual->proximo;
}

void destruir_encadeada(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}