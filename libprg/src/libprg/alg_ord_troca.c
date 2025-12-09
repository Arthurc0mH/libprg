#include <stdio.h>
#include "libprg/libprg.h"

void bubble_sort(int vetor[], int tamanho){

    int i, j, aux;
    int trocou;

   for (i = 0; i < tamanho - 1; i++){
       trocou = 0;
       for (j = 0; j < tamanho - i - 1; j++){
           if (vetor[j] > vetor[j + 1]){
               aux = vetor[j];
               vetor[j] = vetor[j + 1];
               vetor[j + 1] = aux;
               trocou = 1;
           }
       }
       if (!trocou) break;
   }
}

void insertion_sort(int vetor[], int tamanho){

    int i, j, chave;
    for (i = 1; i < tamanho; i++){
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void selection_sort(int vetor[], int tamanho){

    int i, j, menor, aux;

    for (i = 0; i < tamanho - 1; i++){
        menor = i;
        for (j = i + 1; j < tamanho; j++){
            if (vetor[j] < vetor[menor]){
                menor = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}