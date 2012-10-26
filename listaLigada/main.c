        /*
         * Leonardo Wistuba de França <leonardowistuba@gmail.com>
         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaLigada.h"

int main(int argc, char** argv) {
        ListaLigada l;
        void* resultadoBusca;
        int chave = 0;
        char op;

        l = novaListaLigada();
        while (42) {
                scanf("%c %d", &op, &chave);
                switch (op) {
                case 'i':
                        // terceiro parâmetro é um ponteiro para o conteúdo, um void*, pode ser qualquer coisa,
                        // um inteiro, array, outra lista, etc, só utilizar os devidos casts na busca.
                        if (l->inserir(l, chave, (void*) chave)) {
                                printf("já existe, num elementos: %d\n", l->numeroNodos);
                        } else {
                                printf("inserido\n");
                        }

                        break;
                case 'r':
                        if (l->remover(l, chave)) {
                                printf("nao removido, num elementos: %d\n", l->numeroNodos);
                        } else {
                                printf("removido\n");
                        }
                        break;
                case 'p':
                        l->imprimir(l);
                        break;
                case 'b': {
                        resultadoBusca = l->buscar(l, chave);

                        if (resultadoBusca == NULL) {
                                printf("não encontrado\n");

                        } else {
                                printf("resultado: %d\n", (int) resultadoBusca); // tratando como int, por exemplo

                        }
                        break;
                }

                default:
                        break;
                }

        }

        return EXIT_SUCCESS;
}
