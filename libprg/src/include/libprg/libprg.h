#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define MAX_PILHA 100

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

typedef struct {
    int dados[MAX_PILHA];
    int topo;
} Pilha;

void criar_pilha(Pilha *p);
int pilha_vazia(Pilha *p); //retorna 1 se a pilha tiver vazia
int pilha_cheia(Pilha *p); //retorna 1 se a pilha tiver cheia
int empilhar(Pilha *p, int valor); //retorna 1 se a deu certo, retorna 0 se der overflow
int desempilhar(Pilha *p, int *valor_removido); //retorna 1 se deu certo, retorna 0 se der underflow
int consultar_topo(Pilha *p, int *valor_topo); //retorna 1 der certo, 0 se vazia
int tamanho_pilha(Pilha *p); //da return na quantidade de itens na pilha
int valor_topo(Pilha *p); //retorna o valor do topo da pilha
char valor_topo_char(Pilha *p); //retorna o valor do topo da pilha em char

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#define MAX_FILA 100

typedef struct {
    int dados[MAX_FILA];
    int dados_char[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void criar_fila(Fila *f);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f, int *valor_removido);
int consultar_frente(Fila *f, int *valor_frente);
int tamanho_fila(Fila *f);
int enfileirar2(Fila *f, char valor);
int desinfileirar2(Fila *f, char *valor_removido);
int editar_frente(Fila *f, char valor);

#define MAX_LISTA 100

typedef struct {
    int dados[MAX_LISTA];
    int tamanho;
} Lista;

void criar_lista(Lista *l);
int inserir_fim_lista(Lista *l, int valor);
int remover_fim_lista(Lista *l, int *valor_removido);
int obter_elemento_lista(Lista *l, int pos, int *valor);
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int tamanho_lista(Lista *l);
void imprimir_lista(Lista *l);
int busca_linear_lista(Lista *l, int valor);
int busca_binaria_lista(Lista *l, int valor); // Requer que a lista esteja ordenada
int remover_elemento_lista(Lista *l, int valor); // Usa busca linear para encontrar e remover
void ordenar_lista(Lista *l); // Função auxiliar para a busca binária

typedef struct No {
    int valor;
    struct No* proximo;
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

#endif
