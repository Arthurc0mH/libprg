#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

No *criar_no(int valor){
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void destruir_no(No *no){
    if (no != NULL){
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

No *inserir_valor(No *raiz, int valor){
    if (raiz == NULL){
        return criar_no(valor);
    }else if (valor < raiz->valor){
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    }else if (valor > raiz->valor){
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

No *busca(No *raiz, int valor){ //vou usar int mesmo, 0 e 1 pra false e true
    if (raiz == NULL){
        return 0;
    }
    if (valor == raiz->valor){
        return 1;
    }
    if (valor < raiz->valor){
        return busca(raiz->esquerda, valor);
    }else{
        return busca(raiz->direita, valor);
    }
}

No *remover_valor(No *raiz, int valor){
    if (raiz == NULL){
        return raiz;
    }
    if (valor < raiz->valor){
        raiz->esquerda = remover_valor(raiz->esquerda, valor);
    }else if (valor > raiz->valor){
        raiz->direita = remover_valor(raiz->direita, valor);
    }else{
        if (raiz->esquerda == NULL){
            No *no_aux = raiz->direita;
            free(raiz);
            return no_aux;
        }else if (raiz->direita == NULL){}
    }
}

int maior_valor(No *raiz){
    if (raiz == NULL){
        printf("a árvore está vazia\n");
        return 1;
    }
    No *atual = raiz;
    while (atual->direita != NULL){
        atual = atual->direita;
    }
    return atual->valor;
}

int menor_valor(No *raiz){
    if (raiz == NULL){
        printf("a árvore está vazia\n");
        return 1;
    }
    No *atual = raiz;
    while (atual->esquerda != NULL){
        atual = atual->esquerda;
    }
    return atual->valor;
}

int altura_arvore(No *raiz){
    if (raiz == NULL){
        return 1;
    }
    int altura_esquerda = altura_arvore(raiz->esquerda);
    int altura_direita = altura_arvore(raiz->direita);
    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}

// árvore avl

#define max(a,b) (((a) > (b)) ? (a) : (b))

no_avl_t *criar_no_avl(int valor){
    no_avl_t *no = (no_avl_t *) malloc(sizeof(no_avl_t));
    if (!no) return NULL;
    no->valor = valor;
    no->altura = 1;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

int altura(no_avl_t *v){
    if (v == NULL){
        return 0;
    }else{
        return v->altura;
    }
}

int fator_balanceamento(no_avl_t *v){
    if (v == NULL){
        return 0;
    }else{
        return altura(v->esquerda) - altura(v->direita);
    }
}

no_avl_t *rotacao_esquerda(no_avl_t *v){
    no_avl_t *u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
    return u;
}

no_avl_t *rotacao_direita(no_avl_t *v){
    no_avl_t *u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
    return u;
}

no_avl_t *rotacao_dupla_esquerda(no_avl_t *v){ //rotação direita no filho, dps esquerda no pai
    v->direita = rotacao_direita(v->direita);
    return rotacao_esquerda(v);
}

no_avl_t *rotacao_dupla_direita(no_avl_t *v){ //rotção esquerda no filho, dps direita no pai
    v->esquerda = rotacao_esquerda(v->esquerda);
    return rotacao_direita(v);

}

no_avl_t *balancear(no_avl_t *v){
    if (!v) return NULL;

    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;

    int fator = fator_balanceamento(v);

    if (fator > 1){
        if (fator_balanceamento(v->esquerda) >= 0){
            return rotacao_direita(v);
        }else{
            return rotacao_dupla_direita(v);
        }
    }
    if (fator < -1){
        if (fator_balanceamento(v->direita) <= 0){
            return rotacao_esquerda(v);
        }else{
            return rotacao_dupla_esquerda(v);
        }
    }
    return v;
}

no_avl_t *inserir_no_avl(no_avl_t *v, int valor){
    if (!v) return criar_no_avl(valor);

    if (valor < v->valor){
        v->esquerda = inserir_no_avl(v->esquerda, valor); //insere na subarvore esquerda
    }else if (valor > v->valor){
        v->direita = inserir_no_avl(v->direita, valor); //insere na subarvore direita
    }else{
        return v;
    }
    return balancear(v);
}

no_avl_t *buscar_no_minimo_avl(no_avl_t *v){
    no_avl_t *atual = v;

    while (atual->esquerda){
        atual = atual->esquerda;
    }
    return atual;
}

no_avl_t *remover_no_avl(no_avl_t *v, int valor){
    if (!v) return NULL;
    if (valor < v->valor){
        v->esquerda = remover_no_avl(v->esquerda, valor);
    }else if (valor > v->valor){
        v->direita = remover_no_avl(v->direita, valor);
    }else{
        if (!v->esquerda || !v->direita){
            no_avl_t *aux = v->esquerda ? v->esquerda : v->direita;
            if (!aux){
                free(v);
                return NULL;
            }
            v->valor = aux->valor;
            v->direita = aux->direita;
            v->esquerda = aux->esquerda;
            free(aux);
        }else{
            no_avl_t *aux = buscar_no_minimo_avl(v->direita);
            v->valor = aux->valor;
            v->direita = remover_no_avl(v->direita, aux->valor);
        }
    }
    return balancear(v);
}

void pre_ordem(no_avl_t *v){
    if (v){
        printf("%d ", v->valor);
        pre_ordem(v->esquerda);
        pre_ordem(v->direita);
    }
}

void em_ordem(no_avl_t *v){
    if (v){
        em_ordem(v->esquerda);
        printf("%d ", v->valor);
        em_ordem(v->direita);
    }
}

void pos_ordem(no_avl_t *v){
    if (v){
        pos_ordem(v->esquerda);
        pos_ordem(v->direita);
        printf("%d ", v->valor);
    }
}

void em_largura(no_avl_t *v){
    if (!v) return;

    int capacidade = 100;
    no_avl_t **fila = (no_avl_t **) malloc(capacidade * sizeof(no_avl_t *));
    int inicio = 0, fim = 0;

    fila[fim++] = v;

    while (inicio < fim){
        no_avl_t *atual = fila[inicio++];
        printf("%d ", atual->valor);
        if (atual->esquerda) fila[fim++] = atual->esquerda;
        if (atual->direita) fila[fim++] = atual->direita;
    }
    free(fila);
}