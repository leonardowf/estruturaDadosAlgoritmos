/*
 * Leonardo Wistuba de França <leonardowistuba@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRETO 0
#define VERMELHO 1

typedef struct _nodo* Nodo;
typedef struct _nodo {
        int chave;
        void* conteudo;
        Nodo esquerda, direita, pai;
        int cor;
} _nodo;
typedef struct _rubroNegra* RubroNegra;
struct _rubroNegra {
        Nodo raiz;
};

static Nodo nodoNull = NULL; // sentinela para facilitar implementação

RubroNegra novaRubroNegra();
static Nodo novoNodo(int chave, void* conteudo);
static void rotacaoDireita(RubroNegra arvore, Nodo x);
static void rotacaoEsquerda(RubroNegra arvore, Nodo x);
static void arrumarRubroNegra(RubroNegra arvore, Nodo z);
int inserir(RubroNegra arvore, int chave, void* conteudo);
static void imprimeArvore(Nodo x);
static Nodo arvoreMinima(Nodo x);
static void transplanteRubroNegra(RubroNegra T, Nodo u, Nodo v);
static void arrumarRubroNegraRemocao(RubroNegra T, Nodo x);
static void removerRubroNegra(RubroNegra T, Nodo z);
static Nodo buscarNodo(Nodo x, int chave);
int remover(RubroNegra arvore, int chave);
void destruir(RubroNegra arvore);
static void liberaNodo(Nodo atual);
void* buscar(RubroNegra arvore, int chave);
void imprimir(RubroNegra arvore);

