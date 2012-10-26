/*
 * Leonardo Wistuba de França <leonardowistuba@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quickSort.h"

/*
 * O Quicksort é o algoritmo mais eficiente para uma grande variedade de situações.
 * Entretanto, é um método bastante frágil no sentido de que qualquer erro de implementação pode ser difícil de ser detectado.
 * O algoritmo é recursivo, o que demanda uma pequena quantidade de memória adicional.
 * Além disso, seu desempenho é da ordem de O(n²) operações no pior caso.
 *
 * Retirado do livro Projeto de Algoritmos do Nivio Ziviani
 */

void particionar(int esquerda, int direita, int* i, int* j, int* A) {
        int x, w;
        *i = esquerda;
        *j = direita;
        x = A[(*i + *j) / 2]; // obtém o pivô x
        do {
                while (x > A[*i])
                        (*i)++;
                while (x < A[*j])
                        (*j)--;
                if (*i <= *j) {
                        w = A[*i];
                        A[*i] = A[*j];
                        A[*j] = w;
                        (*i)++;
                        (*j)--;
                }
        } while (*i <= *j);

}

void ordenar(int esquerda, int direita, int* A) {
        int i, j;
        particionar(esquerda, direita, &i, &j, A);
        if (esquerda < j) ordenar(esquerda, j, A);
        if (i < direita) ordenar(i, direita, A);
}

void quickSort(int* A, int* n) {
        ordenar(0, *n - 1, A);

}
