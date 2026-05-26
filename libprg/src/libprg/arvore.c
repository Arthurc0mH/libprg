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

void remover_noa(int dado, noa_t* no) {

}

void travessia_emordem(noa_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem(raiz->direita);
    }
}

//destruir
//travessia_preordem
//travessia_emordem
//travessia_posordem