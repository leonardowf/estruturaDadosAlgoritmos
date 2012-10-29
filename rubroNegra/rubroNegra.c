#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubroNegra.h"

/*
 Uma árvore rubro negra é uma árvore binária que satisfaz as seguintes propriedades:
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

void rotacaoEsquerda(RubroNegra arvore, Nodo x) {
        Nodo y;
        y = x->direita;
        x->direita = y->esquerda;
        if (y->esquerda != nodoNull) y->esquerda->pai = x;
        y->pai = x->pai;
        if (x->pai == nodoNull) arvore->raiz = y;
        else if (x == x->pai->esquerda) x->pai->esquerda = y;
        else
                x->pai->direita = y;
        y->esquerda = x;
        x->pai = y;
}

void rotacaoDireita(RubroNegra arvore, Nodo x) {
        Nodo y;
        y = x->esquerda;
        x->esquerda = y->direita;
        if (y->direita != nodoNull) y->direita->pai = x;
        y->pai = x->pai;
        if (x->pai == nodoNull) arvore->raiz = y;
        else if (x == x->pai->direita) x->pai->direita = y;
        else
                x->pai->esquerda = y;
        y->direita = x;
        x->pai = y;
}

void imprimeArvore(Nodo x) {
        if (x == nodoNull) return;
        imprimeArvore(x->esquerda);
        printf("cor: %d, chave: %d\n", x->cor, x->chave);
        imprimeArvore(x->direita);

}

int remover(RubroNegra arvore, int chave) {
        Nodo z = buscarNodo(arvore->raiz, chave);
        Nodo justInCase = z;
        if (z == nodoNull) return 1;
        else
                removerRubroNegra(arvore, z);
        free(justInCase->conteudo);
        free(justInCase);
        return 0;
}

Nodo buscarNodo(Nodo x, int chave) {

        if (x == nodoNull || x->chave == chave) return x;
        if (chave < x->chave) buscarNodo(x->esquerda, chave);
        else
                buscarNodo(x->direita, chave);

}

void removerRubroNegra(RubroNegra T, Nodo z) {
        Nodo x, y = z;
        puts("removendo");

        int yCorOriginal = y->cor;

        if (z->esquerda == nodoNull) {
                x = z->direita;
                transplanteRubroNegra(T, z, z->direita);

        } else if (z->direita == nodoNull) {
                x = z->esquerda;
                transplanteRubroNegra(T, z, z->esquerda);
        } else {
                y = arvoreMinima(z->direita);
                yCorOriginal = y->cor;
                x = y->direita;
                if (y->pai == z) x->pai = y;
                else {
                        transplanteRubroNegra(T, y, y->direita);
                        y->direita = z->direita;
                        y->direita->pai = y;
                }
                transplanteRubroNegra(T, z, y);
                y->esquerda = z->esquerda;
                y->esquerda->pai = y;
        }
        if (yCorOriginal == PRETO) arrumarRubroNegraRemocao(T, x);

}

void arrumarRubroNegraRemocao(RubroNegra T, Nodo x) {
        Nodo w;
        while (x != T->raiz && x->cor == PRETO) {
                if (x == x->pai->esquerda) {
                        w = x->pai->direita;
                        if (w->cor == VERMELHO) {
                                w->cor = PRETO;
                                x->pai->cor = VERMELHO;
                                rotacaoEsquerda(T, x->pai);
                                w = x->pai->direita;
                        }
                        if (w->esquerda->cor == PRETO && w->direita->cor == PRETO) {
                                w->cor = VERMELHO;
                                x = x->pai;
                        } else {
                                if (w->direita->cor == PRETO) {
                                        w->esquerda->cor = PRETO;
                                        w->cor = VERMELHO;
                                        rotacaoDireita(T, w);
                                        w = x->pai->direita;
                                }
                                w->cor = x->pai->cor;
                                x->pai->cor = PRETO;
                                w->direita->cor = PRETO;
                                rotacaoEsquerda(T, x->pai);
                                x = T->raiz;

                        }
                } else {

                        w = x->pai->esquerda;
                        if (w->cor == VERMELHO) {
                                w->cor = PRETO;
                                x->pai->cor = VERMELHO;
                                rotacaoDireita(T, x->pai);
                                w = x->pai->esquerda;
                        }
                        if (w->direita->cor == PRETO && w->esquerda->cor == PRETO) {
                                w->cor = VERMELHO;
                                x = x->pai;
                        } else {
                                if (w->esquerda->cor == PRETO) {
                                        w->direita->cor = PRETO;
                                        w->cor = VERMELHO;
                                        rotacaoEsquerda(T, w);
                                        w = x->pai->esquerda;
                                }
                                w->cor = x->pai->cor;
                                x->pai->cor = PRETO;
                                w->esquerda->cor = PRETO;
                                rotacaoDireita(T, x->pai);
                                x = T->raiz;

                        }
                }
        }
        x->cor = PRETO;
}

void transplanteRubroNegra(RubroNegra T, Nodo u, Nodo v) {
        if (u->pai == nodoNull) T->raiz = v;
        else if (u == u->pai->esquerda) u->pai->esquerda = v;
        else
                u->pai->direita = v;
        v->pai = u->pai;
}

Nodo arvoreMinima(Nodo x) {
        Nodo y = x;
        while (y->esquerda != nodoNull)
                y = y->esquerda;
        return y;

}

