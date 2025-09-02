#include "libprg/libprg.h"

void criar_pilha(Pilha *p) {
    p->topo = -1;
}
int pilha_vazia(Pilha *p) {
    if (p->topo == -1) {
        return 1; //se for verdadeiro, ela tá vazia
    }
    return 0; //falso ela não está vazia
}

