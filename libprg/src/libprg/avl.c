#include <stdlib.h>
#include "libprg/libprg.h"
#define max(a,b) (a > b) ? a : b

typedef struct noavl {
    int dado;
    noavl_t* esquerda;
    noavl_t* direita;
    int altura;
}noavl_t;

noavl_t* criar_noavl(int dado) {
    noavl_t* no = (noavl_t*) malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;
    return no;
}

int altura_avl(noavl_t* raiz) {
    if (raiz == NULL) return 0;
    return raiz->altura;
}

int fator_balanceamento(noavl_t* raiz) {
    if (raiz == NULL) return 0;

    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

noavl_t* adicionar_noavl(noavl_t* raiz, int dado) {
    if(raiz == NULL){
        return criar_noavl(dado);
    }
    if(raiz->dado < dado){
        raiz->direita = adicionar_noavl(raiz-> direita, dado);
    }
    if(raiz->dado > dado){
        raiz->esquerda = adicionar_noavl(raiz->esquerda, dado);
    }
    raiz->altura = max(altura_avl(raiz->esquerda), altura_avl(raiz->direita) + 1);
    raiz = balancear(raiz);
    return raiz;
}

noavl_t* rotacao_esquerda(noavl_t* v) {
    noavl_t* u = v->direita;
    noavl_t* T2 = u->esquerda;

    u->esquerda = v;
    v->direita = T2;

    v->altura = max(altura_avl(v->esquerda), altura_avl(v->direita) + 1);
    u->altura = max(altura_avl(u->esquerda), altura_avl(u->direita) + 1);

    return u;
}

noavl_t* rotacao_direita(noavl_t* v) {
    noavl_t* u = v->esquerda;
    noavl_t* T2 = u->direita;

    u->direita = v;
    v->esquerda = T2;

    v->altura = max(altura_avl(v->esquerda), altura_avl(v->direita) + 1);
    u->altura = max(altura_avl(u->esquerda), altura_avl(u->direita) + 1);

    return u;
}

noavl_t* rotacao_dupla_direita(noavl_t* v) {
    v->esquerda = rotacao_esquerda(v->esquerda);
    return rotacao_direita(v);
}

noavl_t* rotacao_dupla_esquerda(noavl_t* v) {
    v->direita = rotacao_direita(v->direita);
    return rotacao_esquerda(v);
}

noavl_t* balancear(noavl_t* v) {
    int fb = fator_balanceamento(v);

    if (fb > 1) {
        if (fator_balanceamento(v->esquerda) > 0) {
            return rotacao_direita(v);
        }
        return rotacao_dupla_direita(v);
    }
    if (fb < -1) {
        if (fator_balanceamento(v->direita) < 0) {
            return rotacao_esquerda(v);
        }
        return rotacao_dupla_esquerda(v);
    }
    return v;
}

noavl_t* remover_noavl(int dado, noavl_t* raiz) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado) {
        raiz->esquerda = remover_noavl(dado, raiz->esquerda);
    }else if (dado > raiz->dado) {
        raiz->direita = remover_noavl(dado, raiz->direita);
    }else {
        if (raiz->direita == NULL || raiz->esquerda == NULL) { //1 ou 0 filhos
            noavl_t* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) { //0 filhos
                free(raiz);
                return NULL;
            }
            free(raiz); //1 filho
            return temp;
        } //2 filhos
        //encontra o menor valor da subárvore da direita
        noavl_t* temp = raiz->direita;
        while (temp != NULL && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->dado = temp->dado;
        raiz->direita = remover_noavl(temp->dado, raiz->direita);
    }
    if (raiz != NULL) {
        raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
        raiz = balancear(raiz);
    }
    return raiz;
}

int avl_posordem(noavl_t* raiz) {
    if (raiz != NULL) {
        avl_posordem(raiz->esquerda);
        avl_posordem(raiz->direita);
        return raiz->dado;
    }
}
