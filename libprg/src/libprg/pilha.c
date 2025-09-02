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

int pilha_cheia(Pilha *p) {
    if (p->topo == MAX_PILHA - 1) {
        return 1; //se for verdadeiro, ela tá cheia
    }
    return 0; // falso, não está cheia
}

int empilhar(Pilha *p, int valor) {
    if (pilha_cheia(p)) {
        return 0; //overflow da pilha
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1; //sucesso na operação
}
