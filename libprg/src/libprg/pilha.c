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

int desempilhar(Pilha *p, int *valor_removido) {
    if (pilha_vazia(p)) {
        return 0; //underflow da pilha
    }
    *valor_removido = p->dados[p->topo];
    p->topo--;
    return 1; //sucesso na operação
}

int consultar_topo(Pilha *p, int *valor_topo) {
    if (pilha_vazia(p)) {
        return 0; //não tem o que consultar
    }
    *valor_topo = p->dados[p->topo];
    return 1; //sucesso
}

int tamanho_pilha(Pilha *p) {
    return p->topo + 1;
}