#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubroNegra.h"

/*
 A árvore rubro negra é uma árvore binária que satisfas as seguintes propriedades:
 A red-black tree is a binary tree that satisfies the following red-black properties:
 1. Todo nodo é preto ou vermelho.
 1. Every node is either red or black.
 2. A raíz é preta.
 2. The root is black.
 3. Every leaf (NIL) is black.
 3. Toda folha (NIL) is preta.
 4. If a node is red, then both its children are black.
 4. Se um nodo é vermelho, então ambos seus filhos são pretos.
 5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 5. Para cada nodo, todos os caminhos simples do nodo até as folhas descentes contém o mesmo número de nodos pretos.
 */

RubroNegra novaRubroNegra() {
        if (nodoNull == NULL) {
                nodoNull = calloc(1, sizeof(_nodo));
                nodoNull->chave = 42;
                nodoNull->conteudo = NULL;
                nodoNull->cor = PRETO;
                nodoNull->direita = nodoNull;
                nodoNull->esquerda = nodoNull;
                nodoNull->pai = nodoNull;
        }
        RubroNegra novaArvore = calloc(1, sizeof(struct _rubroNegra));
        novaArvore->raiz = nodoNull;
        return novaArvore;
}

Nodo novoNodo(int chave, void* conteudo) {
        Nodo novo = calloc(1, sizeof(_nodo));
        novo->chave = chave;
        novo->conteudo = conteudo;
        novo->cor = VERMELHO;
        novo->direita = nodoNull;
        novo->esquerda = nodoNull;
        novo->pai = nodoNull;
        return novo;

}

void DEBUG(char* descricao, int x) {
        fflush(stdout);
        fprintf(stdout, "%s: %d\n", descricao, x);
        fflush(stdout);

}

int inserir(RubroNegra arvore, int chave, void* conteudo) {

        Nodo y, x, z;
        z = novoNodo(chave, conteudo);

        y = nodoNull;
        x = arvore->raiz;
        while (x != nodoNull) {
                y = x;
                if (z->chave < x->chave) x = x->esquerda;
                else
                        x = x->direita;
        }
        z->pai = y;
        if (y == nodoNull) arvore->raiz = z;
        else if (z->chave < y->chave) y->esquerda = z;
        else
                y->direita = z;
        z->esquerda = nodoNull;
        z->direita = nodoNull;
        z->cor = VERMELHO;

        arrumarRubroNegra(arvore, z);
        return 0;

}

void arrumarRubroNegra(RubroNegra arvore, Nodo z) {
        Nodo y;
        while (z->pai->cor == VERMELHO) {
                if (z->pai == z->pai->pai->esquerda) {
                        y = z->pai->pai->direita;

                        if (y->cor == VERMELHO) {
                                z->pai->cor = PRETO;
                                y->cor = PRETO;
                                z->pai->pai->cor = VERMELHO;
                                z = z->pai->pai;
                        } else {
                                if (z == z->pai->direita) {
                                        z = z->pai;
                                        rotacaoEsquerda(arvore, z);
                                }
                                z->pai->cor = PRETO;
                                z->pai->pai->cor = VERMELHO;
                                rotacaoDireita(arvore, z->pai->pai);
                        }

                } else {

                        y = z->pai->pai->esquerda;

                        if (y->cor == VERMELHO) {
                                z->pai->cor = PRETO;
                                y->cor = PRETO;
                                z->pai->pai->cor = VERMELHO;
                                z = z->pai->pai;
                        } else {
                                if (z == z->pai->esquerda) {
                                        z = z->pai;
                                        rotacaoDireita(arvore, z);
                                }
                                z->pai->cor = PRETO;
                                z->pai->pai->cor = VERMELHO;
                                rotacaoEsquerda(arvore, z->pai->pai);
                        }

                }
        }
        arvore->raiz->cor = PRETO;

}

void rotacaoEsquerda (RubroNegra arvore, Nodo x)
{
        Nodo y;
        y = x->direita;
        x ->direita = y->esquerda;
        if (y->esquerda != nodoNull)
                y->esquerda->pai = x;
        y->pai = x->pai;
        if (x->pai == nodoNull)
                arvore->raiz = y;
        else if (x == x->pai->esquerda)
                x->pai->esquerda = y;
        else
                x->pai->direita = y;
        y->esquerda = x;
        x ->pai = y;
}

void rotacaoDireita (RubroNegra arvore, Nodo x)
{
        Nodo y;
        y = x->esquerda;
        x ->esquerda = y->direita;
        if (y->direita != nodoNull)
                y->direita->pai = x;
        y->pai = x->pai;
        if (x->pai == nodoNull)
                arvore->raiz = y;
        else if (x == x->pai->direita)
                x->pai->direita = y;
        else
                x->pai->esquerda = y;
        y->direita = x;
        x ->pai = y;
}

void imprimeArvore(Nodo x)
{
        if (x == nodoNull)
                return;
        imprimeArvore(x->esquerda);
        printf("cor: %d, chave: %d\n", x->cor, x->chave);
        imprimeArvore(x->direita);



}

