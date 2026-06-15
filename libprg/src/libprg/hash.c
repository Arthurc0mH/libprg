#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libprg/libprg.h"

typedef struct noh noh_t;

typedef struct noh {
    char* chave;
    long valor;
    noh_t* proximo;
}noh_t;

dicionario_t* criar_dicionario(int m) {
    if (m < 1) return NULL;

    dicionario_t* d = malloc(sizeof(dicionario_t));
    if (d == NULL) return NULL;

    d->vetor = calloc(m, sizeof(noh_t*));
    if (d->vetor == NULL) {
        free(d);
        return NULL;
    }

    d->tamanho = m;
    return d;
}

int hash(char* chave, int m) {
   int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

int inserir_hash(dicionario_t* d, char* chave, long valor) {
    if (d == NULL || chave == NULL) return 1;

    int indice = hash(chave, d->tamanho);

    noh_t* atual = d->vetor[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            atual->valor = valor;
            return 0;
        }
        atual = atual->proximo;
    }

    noh_t* no = malloc(sizeof(noh_t));
    if (no == NULL) return 1;

    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return 1;
    }

    no->valor = valor;

    no->proximo = d->vetor[indice];
    d->vetor[indice] = no;

    return 0;
}

int buscar_hash(dicionario_t* d, char* chave, long* valor) {
    if (d == NULL || chave == NULL || valor == NULL) return 1;

    int indice = hash(chave, d->tamanho);

    noh_t* atual = d->vetor[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            *valor = atual->valor;
            return 0;
        }
        atual = atual->proximo;
    }

    return 1;
}

int remover_hash(dicionario_t* d, char* chave) {
    if (d == NULL || chave == NULL) return 1;

    int indice = hash(chave, d->tamanho);

    noh_t* atual = d->vetor[indice];
    noh_t* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                d->vetor[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual->chave);
            free(atual);

            return 0;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return 1;
}

void destruir_dicionario(dicionario_t* d) {
    if (d == NULL) return;

    for (int i = 0; i < d->tamanho; i++) {
        noh_t* atual = d->vetor[i];

        while (atual != NULL) {
            noh_t* proximo = atual->proximo;

            free(atual->chave);
            free(atual);

            atual = proximo;
        }
    }

    free(d->vetor);
    free(d);
}

void imprimir_dicionario(dicionario_t* d) {
    if (d == NULL) return;

    for (int i = 0; i < d->tamanho; i++) {
        printf("[%d]: ", i);

        noh_t* atual = d->vetor[i];

        while (atual != NULL) {
            printf("(%s, %d) -> ", atual->chave, atual->valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}