/*
 ============================================================================
 Name        : listaLigada.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Lista;
typedef struct nodoEstrutura* Nodo;
typedef struct NodoEstrutura {
        Nodo proximo;
        void* conteudo;
} NodoEstrutura;

int criaNodo(void* conteudo);

int main(int arcg, char** argv) {

        char* valor;
        valor = calloc(1, sizeof(int));
        valor = "fuck";

        if (!criaNodo(valor)) {
                printf("acerto");

        } else {
                printf("erro"); // comment2
        }
        return EXIT_SUCCESS;

}

int criaNodo(void* conteudo) {
        printf("%s\n", (char*)conteudo);
        // comment

        return 0;
}
