#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define MAX_PILHA 100

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

lista_linear_t* criar_lista(bool ordenada);
void inserir_lista(lista_linear_t* lista, int valor);
int busca_linear(lista_linear_t* lista, int valor);
int busca_binaria(lista_linear_t* lista, int valor);


typedef struct No {
    int valor;
    struct No* proximo;
    struct No *esquerda;
    struct No *direita;
} No;

//=== LISTA ENCADEADA ===

typedef struct no no_t;
typedef struct nod nod_t;

no_t* criar_encadeada(int dado);
void inserir_encadeada(no_t** inicio, int dado);
no_t* buscar(no_t** inicio, int dado);
bool remover_encadeada(no_t** inicio, int dado);
void destruir_encadeada(no_t** inicio);

//Estrutura da Lista Encadeada.
//Contém um ponteiro para o primeiro nó ('inicio') e o tamanho da lista.


//Estruturas de ordenação

// void bubble_sort(int vetor[], int tamanho);
// void insertion_sort(int vetor[], int tamanho);
// void selection_sort(int vetor[], int tamanho);
// void merge(int vetor[], int inicio, int meio, int fim);
//
// void merge_sort(int vetor[], int inicio, int fim);
// void troca(int *a, int *b);
// int particiona(int vetor[], int inicio, int fim);
// void quick_sort(int vetor[], int inicio, int fim);
//
// No *criar_no(int valor);
// void destruir_no(No *no);
// No *inserir_valor(No *raiz, int valor);
// No *busca(No *raiz, int valor);
// No *remover_valor(No *raiz, int valor);
// int maior_valor(No *raiz);
// int menor_valor(No *raiz);
// int altura_arvore(No *raiz);

// typedef struct no_avl
// {
//     int valor;
//     int altura;
//     struct no_avl *esquerda;
//     struct no_avl *direita;
// }no_avl_t;
//
//
// int altura(no_avl_t *v);
// int fator_balanceamento(no_avl_t *v);
// no_avl_t *rotacao_esquerda(no_avl_t *v);
// no_avl_t *rotacao_direita(no_avl_t *v);
// no_avl_t *rotacao_dupla_esquerda(no_avl_t *v);
// no_avl_t *rotacao_dupla_direita(no_avl_t *v);
// no_avl_t *balancear(no_avl_t *v);
// no_avl_t *inserir_no_avl(no_avl_t *v, int valor);
// no_avl_t *buscar_no_minimo_avl(no_avl_t *v);
// no_avl_t *remover_no_avl(no_avl_t *v, int valor);
//
// #endif