#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int add(int x, int y) {
    return x +y;
}

int compute_fib(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return add(compute_fib(n-1),compute_fib(n-2));
}

int main (int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "ERROR. Too many arguments! Syntax: ./mystery <pos_int>\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 1) {
        fprintf(stderr, "ERROR. No Argument Provided! Syntax: ./mystery <pos_int>\n");
        exit(EXIT_FAILURE);
    }

    int num = atoi(argv[1]);

    if (num < 0) {
        fprintf(stderr, "ERROR. Negative Integer! Syntax: ./mystery <pos_int>\n");
        exit(EXIT_FAILURE);
    }

    if (num > 46) {
        fprintf(stderr, "ERROR. Integer too large! Syntax: ./mystery <pos_int>\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", "Value: ");
    printf("%d\n", compute_fib(num));

    exit(EXIT_SUCCESS);
}
