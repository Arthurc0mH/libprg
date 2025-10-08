#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

void criar_lista_encadeada(ListaEncadeada* l) {
    l->inicio = NULL; // Uma lista vazia não aponta para nenhum nó
    l->tamanho = 0;
}

// Insere um novo elemento NO INÍCIO da lista
void inserir_inicio_lista_encadeada(ListaEncadeada* l, int valor) {
    // 1. Aloca memória para o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        return;
    }

    // 2. Define os valores do novo nó
    novo_no->valor = valor;
    novo_no->proximo = l->inicio; // O novo nó aponta para o antigo início

    // 3. Atualiza o início da lista para ser o novo nó
    l->inicio = novo_no;
    l->tamanho++;
}

// Remove um elemento DO INÍCIO da lista
int remover_inicio_lista_encadeada(ListaEncadeada* l, int* valor_removido) {
    if (l->inicio == NULL) {
        return 0; // Falha, lista está vazia
    }

    // 1. Guarda o nó a ser removido
    No* no_a_remover = l->inicio;
    *valor_removido = no_a_remover->valor;

    // 2. Atualiza o início da lista para o próximo nó
    l->inicio = no_a_remover->proximo;

    // 3. Libera a memória do nó que foi removido
    free(no_a_remover);
    l->tamanho--;

    return 1; // Sucesso
}

// Libera a memória de TODOS os nós da lista
void destruir_lista_encadeada(ListaEncadeada* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* proximo_no = atual->proximo; // Guarda o próximo antes de apagar o atual
        free(atual);                     // Libera a memória do nó atual
        atual = proximo_no;              // Move para o próximo
    }
    // Reseta a lista para o estado inicial
    l->inicio = NULL;
    l->tamanho = 0;
}

int tamanho_lista_encadeada(ListaEncadeada* l) {
    return l->tamanho;
}

int obter_primeiro_lista_encadeada(ListaEncadeada* l, int* valor) {
    if (l->inicio == NULL) {
        return 0; // Lista vazia
    }
    *valor = l->inicio->valor;
    return 1; // Sucesso
}

void imprimir_lista_encadeada(ListaEncadeada* l) {
    if (l->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: [ ");
    No* atual = l->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}