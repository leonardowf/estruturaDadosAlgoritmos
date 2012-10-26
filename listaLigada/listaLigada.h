        /*
         * Leonardo Wistuba de França <leonardowistuba@gmail.com>
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
        int (*remover)(ListaLigada, int);
        void* (*buscar)(ListaLigada, int);
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
int remover(ListaLigada l, int chave);
void* buscar(ListaLigada l, int chave);
