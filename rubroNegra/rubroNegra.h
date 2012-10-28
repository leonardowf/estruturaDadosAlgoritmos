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
void DEBUG(char* descricao, int x);
Nodo novoNodo(int chave, void* conteudo);
void rotacaoDireita (RubroNegra arvore, Nodo x);
void rotacaoEsquerda (RubroNegra arvore, Nodo x);
void arrumarRubroNegra(RubroNegra arvore, Nodo z);
int inserir(RubroNegra arvore, int chave, void* conteudo);
void imprimeArvore(Nodo x);
