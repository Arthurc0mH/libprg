#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define INT_MAX 1000000

#include <stdbool.h>

//=== PILHA ===
typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
}pilha_t;

pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int tamanho(pilha_t* pilha);
bool vazia(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);

//=== FILA ===

typedef struct fila{
    int *elementos;
    int capacidade;
    int inicio;
    int fim;
    int tamanho; //(Quantidade de elementos na fila)
}fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t* fila);
int inicio(fila_t* fila);
int fim(fila_t* fila);
bool fila_vazia(fila_t* fila);
bool fila_cheia(fila_t* fila);
void destruir_fila(fila_t* fila);

//=== LISTA LINEAR ===

typedef struct lista_linear{
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t* criar_lista(bool ordenada, int capacidade);
void inserir_lista(lista_linear_t* lista, int valor);
int busca_linear(lista_linear_t* lista, int valor);
int busca_binaria(lista_linear_t* lista, int valor);
int buscar(lista_linear_t* lista, int valor);
int remover_lista(lista_linear_t* lista, int valor);
bool lista_cheia(lista_linear_t* lista);
bool lista_vazia(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);


//=== LISTA ENCADEADA ===

typedef struct no no_t;
typedef struct no {
    int dado;
    no_t* proximo;
}no_t;
typedef struct lista_encadeada {
    no_t* inicio;
    bool ordenada;
}lista_encadeada_t;

no_t* criar_encadeada(int dado);
void inserir_encadeada(lista_encadeada_t* lista, int dado);
no_t* buscar_encadeada(lista_encadeada_t* lista, int dado);
bool remover_encadeada(lista_encadeada_t* lista, int dado);
void destruir_encadeada(lista_encadeada_t* inicio);
lista_encadeada_t* criar_lista_encadeada(bool ordenada);

//=== LISTA ENCADEADA DUPLA ===
typedef struct nod nod_t;

nod_t* criar_lista_cadeada_dupla(int dado);
void inserir_encadeada_dupla(nod_t** inicio, int dado);
nod_t* buscar_encadeada_dupla(nod_t** inicio, int dado);
void destruir_encadeada_dupla(nod_t** inicio);
bool remover_encadeada_dupla(nod_t** inicio, int dado);

//=== ORDENAÇÃO ===

int* bubble_sort(int* vetor, int tamanho);
int* merge_sort(int* vetor, int esquerda, int direita);
int* insertion_sort(int *vetor, int tamanho);
int* selection_sort(int *vetor, int tamanho);
int partition(int* vetor, int inicio, int fim);
int* quick_sort(int* vetor, int inicio, int fim);

// === Hash ===

typedef struct noh noh_t;
typedef struct dicionario {
    int tamanho;
    noh_t** vetor;
}dicionario_t;
dicionario_t* criar_dicionario(int m);
int hash(char* chave, int m);
int inserir_hash(dicionario_t* d, char* chave, long valor);
int buscar_hash(dicionario_t* d, char* chave, long* valor);
int remover_hash(dicionario_t* d, char* chave);
void destruir_dicionario(dicionario_t* d);
void imprimir_dicionario(dicionario_t* d);

// === Árvore binária ===

typedef struct noa noa_t;
noa_t* criar_noa(int dado);
noa_t* adicionar_noa(noa_t* raiz, int dado);
noa_t* remover_noa(int dado, noa_t* no);
void travessia_emordem(noa_t* raiz);
void travessia_preordem(noa_t* raiz);
void travessia_posordem(noa_t* raiz);
void destrur_arvore(noa_t* raiz);

// == Árvore AVL ==
typedef struct noavl noavl_t;
noavl_t* criar_noavl(int dado);
int altura_avl(noavl_t* raiz);
int fator_balanceamento(noavl_t* raiz);
noavl_t* adicionar_noavl(noavl_t* raiz, int dado);
noavl_t* rotacao_esquerda(noavl_t* v);
noavl_t* rotacao_direita(noavl_t* v);
noavl_t* rotacao_dupla_direita(noavl_t* v);
noavl_t* rotacao_dupla_esquerda(noavl_t* v);
noavl_t* balancear(noavl_t* v) ;
noavl_t* remover_noavl(int dado, noavl_t* raiz);

#endif