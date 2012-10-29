#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubroNegra.h"

int main(int argc, char** argv) {
        RubroNegra arvore;
        arvore = novaRubroNegra();

        inserir(arvore, 1, NULL);
        inserir(arvore, 2, NULL);
        inserir(arvore, 3, NULL);
        inserir(arvore, 4, NULL);
        inserir(arvore, 5, NULL);
        inserir(arvore, 6, NULL);
        inserir(arvore, 7, NULL);

        imprimeArvore(arvore->raiz);
        puts("\n");
        remover(arvore, 7);
        imprimeArvore(arvore->raiz);
        remover(arvore, 6);
        imprimeArvore(arvore->raiz);
        remover(arvore, 5);
        imprimeArvore(arvore->raiz);
        remover(arvore, 4);
        imprimeArvore(arvore->raiz);
        remover(arvore, 3);
        imprimeArvore(arvore->raiz);



        return 0;

}
