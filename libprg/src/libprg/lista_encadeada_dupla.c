#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct nod {
    int dado;
    nod_t* proximo;
    nod_t* anterior;
}nod_t; //no duplo

nod_t* criar_lista_cadeada_dupla(int dado) {
    nod_t* no = malloc(sizeof(nod_t));
    no->dado = dado;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}

void inserir_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t* novo = criar_lista_cadeada_dupla(dado);
    novo->proximo = *inicio;
    (*inicio)->anterior = novo;
    *inicio = novo;

}

nod_t* buscar_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void destruir_encadeada_dupla(nod_t** inicio) {
    nod_t* atual = *inicio;
    while (atual != NULL) {
        nod_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

bool remover_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (atual->anterior == NULL) *inicio = atual->proximo;
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return true;
        }
        atual = atual->proximo;
    }
}