#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubroNegra.h"

void usage();

int main(int argc, char** argv) {
        RubroNegra arvore;
        arvore = novaRubroNegra();

        int chave;
        char operacao;
        void* resultadoBusca;

        while (operacao != 'q') {
                usage();
                operacao = getchar();
                getchar();
                switch (operacao) {
                case 'i':
                        scanf("%d", &chave);
                        printf("Inserindo chave: [%d].\n", chave);
                        if (inserir(arvore, chave, (void*) chave)) printf("Chave [%d] já existe.\n", chave);
                        else
                                printf("Chave [%d] inserida.\n", chave);
                        getchar();

                        break;
                case 'r':
                        scanf("%d", &chave);
                        printf("Removendo chave: [%d].\n", chave);
                        if (remover(arvore, chave)) printf("Chave [%d] não encontrada.\n", chave);
                        else
                                printf("Chave [%d] removida.\n", chave);
                        getchar();
                        break;
                case 'b':
                        scanf("%d", &chave);
                        printf("Buscando chave: [%d].\n", chave);
                        resultadoBusca = buscar(arvore, chave);
                        if (resultadoBusca == NULL) printf("Chave [%d] não encontrada.\n", chave);
                        else
                                printf("Resultado da busca: [%d].\n", (int) resultadoBusca);

                        getchar();
                        break;
                case 'p':
                        printf("Imprimindo árvore.\n");
                        imprimir(arvore);

                        break;
                case 'd':
                        printf("Destruindo árvore.\n");
                        destruir(arvore);
                        printf("Árvore destruída.\n");
                        break;
                default:
                        usage();
                        break;
                }

        }

        return 0;

}

void usage() {
        printf("i valor: inserir valor.\n");
        printf("r valor: remover valor.\n");
        printf("b valor: buscar valor.\n");
        printf("p: imprimir árvore.\n");
        printf("d: destruir árvore.\n");
}
