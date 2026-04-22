#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define MAX_PILHA 100

#include <stdbool.h>

/*
 *(VOU APAGAR ISSO ANTES DA PROVA, APENAS UM RESUMO PARA EU ESTUDAR)
 *_____________________________________________________________________________________-
 *|texto | binário | descrição                             | existir     | não existir |
 *|------------------------------------------------------------------------------------|
 *|r     | rb      |abre p/ leitura                        | abre        | erro        |
 *|w     | wb      |abre p/ escrita no começo              |sobreescreve | cria        |
 *|a     | ab      |abre p/ escrita no fim                 |abre         | cria        |
 *|r+    | rb+     |abre p/ leitura e escrita              |abre         | cria        |
 *|w+    | wb+     |cria um arquivo p leitura e escrita    |sobreescreve | cria        |
 *|a+    | ab+     |abre p escrita no fim do file e leitura|abre         | cria        |
 *--------------------------------------------------------------------------------------
 *
 *--funções para escrita--
 *
 *int fputc(int, FILE *) escreve um caractere no arquivo
 *int fputs(char*, FILE*) escreve uma string no arquivo
 *int fprintf(FILE *, char *, ...) Semelhante ao printf
 *int fwrite(void *, int, int, FILE *) Escreve bytes em arquivo binário
 *
 *--funções para leitura--
 *
 *int fgetc(FILE *) lê um caractere do arquivo
 *int fgets(char *, int, FILE*) lê string de tamanho fixo
 *int fscanf(FILE *, char *, ...) Semelhante ao scanf
 *int fread(void *, size_t, size_t, FILE *) Lê uma quantidade específica de bytes de arquivo binário
 *
 *--outras funções para trabalhar com arquivos--
 *FILE *fopen(char *, char *) Abre um arquivo
 *int fclose(FILE *) Fecha um arquivo
 *int fseek(FILE *, long, int) Posiciona o arquivo em um byte específico
 *long ftell(FILE *) Retorna a posição atual do cursor no arquivo
 *int feof(FILE *) Retorna verdadeiro se o fim do arquivo for atingido
 *int ferror(FILE *) Retorna verdadeiro se ocorreu algum erro
 *int remove(char *) Exclui um arquivo
 *int fflush(FILE *) Descarrega dados do buffer no arquivo
 *
*/

// typedef struct {
//     int dados[MAX_PILHA];
//     int topo;
// } Pilha;
//
// void criar_pilha(Pilha *p);
// int pilha_vazia(Pilha *p); //retorna 1 se a pilha tiver vazia
// int pilha_cheia(Pilha *p); //retorna 1 se a pilha tiver cheia
// int empilhar(Pilha *p, int valor); //retorna 1 se a deu certo, retorna 0 se der overflow
// int desempilhar(Pilha *p, int *valor_removido); //retorna 1 se deu certo, retorna 0 se der underflow
// int consultar_topo(Pilha *p, int *valor_topo); //retorna 1 der certo, 0 se vazia
// int tamanho_pilha(Pilha *p); //da return na quantidade de itens na pilha
// int valor_topo(Pilha *p); //retorna o valor do topo da pilha
// char valor_topo_char(Pilha *p); //retorna o valor do topo da pilha em char
//
// result_t sub(double a, double b);
// result_t sum(double a, double b);
// result_t compute(double a, double b, operation_t op);

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


// #define MAX_FILA 100
//
// typedef struct {
//     int dados[MAX_FILA];
//     int dados_char[MAX_FILA];
//     int inicio;
//     int fim;
//     int tamanho;
// } Fila;
//
// void criar_fila(Fila *f);
// int fila_vazia(Fila *f);
// int fila_cheia(Fila *f);
// int enfileirar(Fila *f, int valor);
// int desenfileirar(Fila *f, int *valor_removido);
// int consultar_frente(Fila *f, int *valor_frente);
// int tamanho_fila(Fila *f);
// int enfileirar2(Fila *f, char valor);
// int desinfileirar2(Fila *f, char *valor_removido);
// int editar_frente(Fila *f, char valor);
// int consultar_final(Fila *f, int *valor_final);


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

// #define MAX_LISTA 100
//
// typedef struct {
//     int dados[MAX_LISTA];
//     int tamanho;
// } Lista;
//
// void criar_lista(Lista *l);
// int inserir_fim_lista(Lista *l, int valor);
// int remover_fim_lista(Lista *l, int *valor_removido);
// int obter_elemento_lista(Lista *l, int pos, int *valor);
// int lista_vazia(Lista *l);
// int lista_cheia(Lista *l);
// int tamanho_lista(Lista *l);
// void imprimir_lista(Lista *l);
// int busca_linear_lista(Lista *l, int valor);
// int busca_binaria_lista(Lista *l, int valor); // Requer que a lista esteja ordenada
// int remover_elemento_lista(Lista *l, int valor); // Usa busca linear para encontrar e remover
// void ordenar_lista(Lista *l); // Função auxiliar para a busca binária

typedef struct lista_linear{
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t* criar_lista(bool ordenada);

typedef struct No {
    int valor;
    struct No* proximo;
    struct No *esquerda;
    struct No *direita;
} No;

//Estrutura da Lista Encadeada.
//Contém um ponteiro para o primeiro nó ('inicio') e o tamanho da lista.

typedef struct {
    No* inicio;
    int tamanho;
} ListaEncadeada;

void criar_lista_encadeada(ListaEncadeada* l);
void destruir_lista_encadeada(ListaEncadeada* l);
void inserir_inicio_lista_encadeada(ListaEncadeada* l, int valor);
int remover_inicio_lista_encadeada(ListaEncadeada* l, int* valor_removido);
int tamanho_lista_encadeada(ListaEncadeada* l);
int obter_primeiro_lista_encadeada(ListaEncadeada* l, int* valor);
void imprimir_lista_encadeada(ListaEncadeada* l);

//Estruturas de ordenação

void bubble_sort(int vetor[], int tamanho);
void insertion_sort(int vetor[], int tamanho);
void selection_sort(int vetor[], int tamanho);
void merge(int vetor[], int inicio, int meio, int fim);

void merge_sort(int vetor[], int inicio, int fim);
void troca(int *a, int *b);
int particiona(int vetor[], int inicio, int fim);
void quick_sort(int vetor[], int inicio, int fim);

No *criar_no(int valor);
void destruir_no(No *no);
No *inserir_valor(No *raiz, int valor);
No *busca(No *raiz, int valor);
No *remover_valor(No *raiz, int valor);
int maior_valor(No *raiz);
int menor_valor(No *raiz);
int altura_arvore(No *raiz);

typedef struct no_avl
{
    int valor;
    int altura;
    struct no_avl *esquerda;
    struct no_avl *direita;
}no_avl_t;


int altura(no_avl_t *v);
int fator_balanceamento(no_avl_t *v);
no_avl_t *rotacao_esquerda(no_avl_t *v);
no_avl_t *rotacao_direita(no_avl_t *v);
no_avl_t *rotacao_dupla_esquerda(no_avl_t *v);
no_avl_t *rotacao_dupla_direita(no_avl_t *v);
no_avl_t *balancear(no_avl_t *v);
no_avl_t *inserir_no_avl(no_avl_t *v, int valor);
no_avl_t *buscar_no_minimo_avl(no_avl_t *v);
no_avl_t *remover_no_avl(no_avl_t *v, int valor);

#endif