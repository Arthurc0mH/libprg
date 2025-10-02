#include <stdio.h>
#include "libprg/libprg.h"

void criar_lista(Lista *l) {
    l->tamanho = 0;
}

int lista_vazia(Lista *l) {
    return (l->tamanho == 0);
}

int lista_cheia(Lista *l) {
    return (l->tamanho == MAX_LISTA);
}

int tamanho_lista(Lista *l) {
    return l->tamanho;
}

int inserir_fim_lista(Lista *l, int valor) {
    if (lista_cheia(l)) {
        return 0;
    }

    l->dados[l->tamanho] = valor;
    l->tamanho++;
    return 1; // Sucesso
}

int remover_fim_lista(Lista *l, int *valor_removido) {
    if (lista_vazia(l)) {
        return 0;
    }

    l->tamanho--;
    *valor_removido = l->dados[l->tamanho];
    return 1;
}

int obter_elemento_lista(Lista *l, int pos, int *valor) {

    if (pos < 0 || pos >= l->tamanho) {
        return 0;
    }
    *valor = l->dados[pos];
    return 1;
}

// Função auxiliar para imprimir a lista
void imprimir_lista(Lista *l) {
    if (lista_vazia(l)) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Elementos da lista: [ ");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("]\n");
}