#include "libprg/libprg.h"
//"Pilha *p" como parâmetro é o ponteiro para a pilha a ser verificada

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

int empilhar(Pilha *p, int valor) { //Pilha *p é a pilha que será empilhada. valor é o que vai ser empilhado
    if (pilha_cheia(p)) {
        return 0; //overflow da pilha
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1; //sucesso na operação
}

int desempilhar(Pilha *p, int *valor_removido) { //caso não seja necessário, o valor_removido pode ser uma variável de "lixo"
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

int tamanho_pilha(Pilha *p) { // a pilha começa em -1, então o tamanho é topo + 1
    return p->topo + 1;
}

int valor_topo(Pilha *p) {
    if (pilha_vazia(p)) {
        return 0; //pilha vazia
    }
    return p->dados[p->topo]; //retorna o valor do topo
}

char valor_topo_char(Pilha *p) { //para resolver a prova
    if (pilha_vazia(p)) {
        return 0; //pilha vazia
    }
    return p->dados[p->topo]; //retorna o valor do topo
}