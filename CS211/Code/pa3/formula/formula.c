#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nCr.h"

#define BIT_SIZE 32
#define MAX 12

void expand(int n) {
    int i;
    int temp = 0;
    for (i = 1; i <= n; i++) {

        printf("%s", " + ");

        temp = nCr(n, i);

        int tempInt = 0;

        printf("%d%s", temp, "*x");

        if (i != 1)
            printf("%s%d", "^", i);
    }
}

void help() {
    printf("%s\n","Please input a positive number less than 32 (This program only works on 32bit integers).");
}

int main (int argv, char **argc) {
    if (argv > 2) {
        printf("%s\n", "Too many inputs!");
        exit(EXIT_FAILURE);
    }

    char *set = (char *)malloc(strlen(argc[1]));
    strcpy(set, argc[1]);

    if (strcmp(argc[1],"-h") == 0) {
        help();
        exit(EXIT_SUCCESS);
    }


    int size = atoi(set);

    if (size > BIT_SIZE) {
        printf("%s\n","This program will only accept 32 or below, due to having 32bit integer storage only");
        exit(EXIT_FAILURE);
    }

    if (size > MAX) {
        printf("%s\n","This program will only accept 12 or below, due to having 32bit integer storage only and anything larger than 12 will result in overflow. The answer you want is not the answer you will get.");
        printf("%s\n", "The program will continue anyway.");
    }

    printf("%d", 1);

    expand(size);

    puts("\n");

    free(set);
    exit(EXIT_SUCCESS);

}
