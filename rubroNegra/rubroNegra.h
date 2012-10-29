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
Nodo novoNodo(int chave, void* conteudo);
void rotacaoDireita(RubroNegra arvore, Nodo x);
void rotacaoEsquerda(RubroNegra arvore, Nodo x);
void arrumarRubroNegra(RubroNegra arvore, Nodo z);
int inserir(RubroNegra arvore, int chave, void* conteudo);
void imprimeArvore(Nodo x);
Nodo arvoreMinima(Nodo x);
void transplanteRubroNegra(RubroNegra T, Nodo u, Nodo v);
void arrumarRubroNegraRemocao(RubroNegra T, Nodo x);
static void removerRubroNegra(RubroNegra T, Nodo z);
Nodo buscarNodo(Nodo x, int chave);
int remover(RubroNegra arvore, int chave);
void destruir(RubroNegra arvore);
void liberaNodo(Nodo atual);
void* buscar(RubroNegra arvore, int chave);
void imprimir(RubroNegra arvore);

