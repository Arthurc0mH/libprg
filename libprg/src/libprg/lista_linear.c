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

int busca_linear_lista(Lista *l, int valor) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i] == valor) {
            return i; // Retorna o índice onde o valor foi encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// IMPORTANTE: Esta função assume que a lista JÁ ESTÁ ORDENADA.
int busca_binaria_lista(Lista *l, int valor) {
    int inicio = 0;
    int fim = l->tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (l->dados[meio] == valor) {
            return meio; // Encontrado
        }
        if (l->dados[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrado
}

int remover_elemento_lista(Lista *l, int valor) {
    int pos = busca_linear_lista(l, valor);
    if (pos == -1) {
        return 0; // Valor não encontrado, nada para remover
    }

    // "Puxa" todos os elementos da direita para a esquerda para cobrir o buraco
    for (int i = pos; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--; // Diminui o tamanho da lista
    return 1; // Sucesso
}

// Usaremos um algoritmo simples de ordenação (Selection Sort) como auxiliar.
void ordenar_lista(Lista *l) {
    for (int i = 0; i < l->tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < l->tamanho; j++) {
            if (l->dados[j] < l->dados[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento atual
        int temp = l->dados[min_idx];
        l->dados[min_idx] = l->dados[i];
        l->dados[i] = temp;
    }
}