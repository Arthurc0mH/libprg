#include <stdlib.h>
#include "libprg/libprg.h"

#define CAPACIDADE_INICIAL 10

typedef struct lista_linear{
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t* criar_lista(bool ordenada){
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}

//inserir
//remover
//buscar linear
//busca binaria
//alterar
//ordenar
//combinar
//destruir