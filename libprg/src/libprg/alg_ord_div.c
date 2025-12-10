#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

void merge(int vetor[], int inicio, int meio, int fim){

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = (int *) malloc(n1 * sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = vetor[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }

    free (L);
    free (R);
}

void merge_sort(int vetor[], int inicio, int fim){

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int inicio, int fim){
    int pivo = vetor[fim];
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quick_sort(int vetor[], int inicio, int fim){

    if (inicio < fim) {
        int p = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, p - 1);
        quick_sort(vetor, p + 1, fim);
    }
}