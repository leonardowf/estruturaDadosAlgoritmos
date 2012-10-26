        /*
         * Leonardo Wistuba de França <leonardowistuba@gmail.com>
         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaLigada.h"

ListaLigada novaListaLigada() {
        ListaLigada l = calloc(1, sizeof(struct _listaLigada));
        if (l == NULL) {
                printf("Falha na alocação de nova lista\n");
                exit(EXIT_FAILURE);
        }

        l->imprimir = &imprimir;
        l->inserir = &inserir;
        l->remover = &remover;
        l->buscar = &buscar;

        return l;
}

void imprimir(ListaLigada l) {
        Nodo nodoAtual;

        nodoAtual = l->cabeca;
        while (nodoAtual != NULL) {
                printf("%d->", nodoAtual->chave);
                nodoAtual = nodoAtual->proximo;
        }
        printf("\n");

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

int remover(ListaLigada l, int chave) {
        Nodo nodoAtual = l->cabeca;
        Nodo libera;

        // quem alocou o l->conteudo que de free, vai que tem mais alguma coisa apontando para lá

        if (l->cabeca == NULL) return EXIT_FAILURE;

        if (l->cabeca->chave == chave) {
                l->cabeca = l->cabeca->proximo;
                free(nodoAtual);
                l->numeroNodos--;
                return EXIT_SUCCESS;
        }
        while (nodoAtual->proximo != NULL) {
                if (nodoAtual->proximo->chave == chave) {
                        libera = nodoAtual->proximo;
                        nodoAtual->proximo = nodoAtual->proximo->proximo;
                        free(libera);
                        l->numeroNodos--;
                        return EXIT_SUCCESS;
                } else {
                        nodoAtual = nodoAtual->proximo;
                }
        }
        return EXIT_FAILURE;

}

void* buscar(ListaLigada l, int chave) {
        Nodo nodoAtual = l->cabeca;

        while (nodoAtual != NULL) {
                if (nodoAtual->chave == chave) return nodoAtual->conteudo;
                else
                        nodoAtual = nodoAtual->proximo;

        }
        return NULL;

}

