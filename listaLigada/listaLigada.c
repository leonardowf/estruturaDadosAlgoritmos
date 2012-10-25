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
#include <string.h>

typedef struct _nodo* Nodo;
typedef struct _listaLigada* ListaLigada;
struct _listaLigada {
        Nodo cabeca;
        int numeroNodos;
        void (*imprimir)(ListaLigada l);
        int (*inserir)(ListaLigada, int, void*);
};
struct _nodo {
        int chave; // para remoção da lista
        Nodo proximo;
        void* conteudo;
};

ListaLigada novaListaLigada();
void imprimir();
int inserir(ListaLigada l, int chave, void* conteudo);
Nodo novoNodo(int chave, void* conteudo);

int main(int argc, char** argv) {
        ListaLigada l;
        l = novaListaLigada();

        int chave = 0;

        while (42) {
                puts("chave: ");
                scanf("%d", &chave);
                if (l->inserir(l, chave, NULL)) {
                        printf("já existe\n");
                } else {
                        puts("inserido");
                }
        }

        return EXIT_SUCCESS;
}

ListaLigada novaListaLigada() {
        ListaLigada l = calloc(1, sizeof(struct _listaLigada));
        if (l == NULL) {
                printf("Falha na alocação de nova lista\n");
                exit(EXIT_FAILURE);
        }

        l->imprimir = &imprimir;
        l->inserir = &inserir;

        return l;
}

void imprimir() {
        printf("lulz\n");

}

int inserir(ListaLigada l, int chave, void* conteudo) {
        // só pode haver um nodo com uma chave

        Nodo nodoAtual;
        nodoAtual = l->cabeca;

        if (nodoAtual == NULL) {
                l->cabeca = novoNodo(chave, conteudo);
                l->numeroNodos++;
                return EXIT_SUCCESS;
        } else {
                while (nodoAtual->chave != chave) {
                        if (nodoAtual->proximo == NULL) {
                                nodoAtual->proximo = novoNodo(chave, conteudo);
                                l->numeroNodos++;
                                return EXIT_SUCCESS;

                        } else {
                                nodoAtual = nodoAtual->proximo;
                        }

                }
                return EXIT_FAILURE;

        }

        return 0;

}

Nodo novoNodo(int chave, void* conteudo) {
        Nodo novo;
        novo = calloc(1, sizeof(struct _nodo));
        if (novo == NULL) {
                printf("erro na criação de nodo");
                exit(EXIT_FAILURE);
        }
        novo->chave = chave;
        novo->conteudo = conteudo;
        return novo;

}

