#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noa {
    int dado;
    noa_t* esquerda;
    noa_t* direita;
}noa_t;

noa_t* criar_noa(int dado) {
    noa_t* no = malloc(sizeof(noa_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

noa_t* adicionar_noa(noa_t* raiz, int dado){
  if(raiz == NULL){
      return criar_noa(dado);
  }
  if(raiz->dado < dado){
      raiz->direita = adicionar_noa(raiz-> direita, dado);
  }
  if(raiz->dado > dado){
      raiz->esquerda = adicionar_noa(raiz->esquerda, dado);
  }
  return raiz;
 }

noa_t* remover_noa(int dado, noa_t* raiz) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado) {
        raiz->esquerda = remover_noa(dado, raiz->esquerda);
    }else if (dado > raiz->dado) {
        raiz->direita = remover_noa(dado, raiz->direita);
    }else {
        if (raiz->direita == NULL || raiz->esquerda == NULL) { //1 ou 0 filhos
            noa_t* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) { //0 filhos
                free(raiz);
                return NULL;
            }
            free(raiz); //1 filho
            return temp;
        } //2 filhos
        //encontra o menor valor da subárvore da direita
        noa_t* temp = raiz->direita;
        while (temp != NULL && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->dado = temp->dado;
        raiz->direita = remover_noa(temp->dado, raiz->direita);
    }
    return raiz;
}

void travessia_emordem(noa_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem(raiz->direita);
    }
}

void travessia_preordem(noa_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        travessia_preordem(raiz->esquerda);
        travessia_preordem(raiz->direita);
    }
}

void travessia_posordem(noa_t* raiz) {
    if (raiz != NULL) {
        travessia_posordem(raiz->esquerda);
        travessia_posordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}
//destruir
//travessia_preordem
//travessia_emordem
//travessia_posordem