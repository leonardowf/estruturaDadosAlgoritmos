/*
 * Leonardo Wistuba de França <leonardowistuba@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quickSort.h"

int main(int argc, char** argv) {
        int tamArray = 0, i = 0;
        int* array;

        scanf("%d", &tamArray);

        array = calloc(tamArray, sizeof(int));
        if (array == 0x0) {
                printf("erro na alocação\n");
                exit(1);
        }

        for (i = 0; i < tamArray; i++)
                scanf("%d", &array[i]);

        quickSort(array, &tamArray);

        for (i = 0; i < tamArray; i++)
                printf("%d\n", array[i]);

        return 0;
}
