#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIN_BASE 2
#define OCT_BASE 8
#define DEC_BASE 10
#define HEX_BASE 16

/*----*/
int hexCharToInt(char ch);
int add(int x, int y);
int sub(int x, int y);
char * strrev(char *str);
int toDec(char *in, int base);
int getBase(char base);
char tochar(int n);
char toHexChar(int n);
char * fromDec(int n, char form);
char * twos (char *str, char form);
/*----*/

char * fromDec(int n, char form) {
    int base = DEC_BASE;
    if (form == 'x')
        base = HEX_BASE;
    else if (form == 'o')
        base = OCT_BASE;
    else if (form == 'b')
        base = BIN_BASE;
    
    char *result = (char *) calloc(1, sizeof(char));
    char *digit = (char *) calloc(1, sizeof(char));
    int remainder;

    char *neg = "";

    if (n < 0) {
        n = (~n)+1;
        neg = "-";
    }

    while (n) {
        remainder = n % base;
        if (base == HEX_BASE && remainder >= 10) {
            digit[0] = toHexChar(remainder);
        }
        else {
            digit[0] = tochar(remainder);
        }

        strcat(result, digit);
        n /= base;
    }
    printf("%s%c", neg, form);
    return strrev(result);
}

char toHexChar(int n) {
    char hexchars[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    return hexchars[n - 10];
}

int add(int x, int y) {
    return (x+y);
}

int sub(int x, int y)  {
    return (x-y);
}

char tochar(int n) {
    return n - 208;
}

char * strrev(char *str) {
    char *rever = (char *)malloc(strlen(str));
    int i;
    for (i = 0; i < strlen(str); i++) {
        rever[i] = str[strlen(str)-1-i];
    }
    return rever;
}

int toDec(char *in, int base) {
    int result = 0;
    int power = 0;
    int i;
    for (i = strlen(in) - 1; i >= 0; i--) {
        int x;

        /* Convert A-Fa-f to 10-15. */
        if (base == HEX_BASE && !isdigit(in[i])) {
            x = hexCharToInt(in[i]);
        } else {
            x = in[i] - '0';
        }

        result += x * (pow(base, power++));
    }

    return result;
}

int hexCharToInt(char ch) {
    switch (ch) {
        /*A/a case*/
        case 'a':
        case 'A':
            return 10;
        /*B/b case*/
        case 'b':
        case 'B':
            return 11;
        /*C/c case*/
        case 'c':
        case 'C':
            return 12;
        /*D/d case*/
        case 'd':
        case 'D':
            return 13;
        /*E/e case*/
        case 'e':
        case 'E':
            return 14;
        /*F/f case*/
        case 'f':
        case 'F':
            return 15;
        /*Else case*/
        default:
            return -1;
    }
}

int getBase(char base) {
    if (base == 'b')
        return BIN_BASE;
    else if (base == 'o')
        return OCT_BASE;
    else if (base == 'd')
        return DEC_BASE;
    else if (base == 'x')
        return HEX_BASE;
    else {
        printf("%s%c\n", "base is: ", base);
        fprintf(stderr, "Invalid base for number!\n");
        exit(EXIT_FAILURE); 
    }
}

int main(int argc, char *argv[]) {
    /*Check if argc < 5*/
    if (argc < 5) {
        fprintf(stderr, "Not enough arguments passed.\n");
        exit(EXIT_FAILURE);        
    }
    if (argc > 6) {
        fprintf(stderr, "Too many arguments passed.\n");
        exit(EXIT_FAILURE);        
    }


    char *op = (char *)malloc(strlen(argv[1]));
    strcpy(op, argv[1]);
    char *setFirst = (char *)malloc(strlen(argv[2]));
    strcpy(setFirst, argv[2]);
    char *setTwo = (char *)malloc(strlen(argv[3]));
    strcpy(setTwo, argv[3]);
    char *outForm = (char *)malloc(strlen(argv[4]));
    strcpy(outForm, argv[4]);
    char *ans = (char*)malloc(sizeof(char));

    int numO, numT, res;
    numO = 0;
    numT = 0;
    res = 0;

    int negO, negT;
    negO = 1;
    negT = 1;

    /*if (strcmp(op, "+") != 0 || strcmp(op, "-") != 0) {
        fprintf(stderr, "Invalid operation!\n");
        exit(EXIT_FAILURE);  
    }*/

    if (setFirst[0] == '-') {
        negO = -1;
        char base = setFirst[1];
        int val = getBase(base);
        char *numOne = (char *)malloc(strlen(setFirst)-2);
        numOne = strncpy(numOne, setFirst+2, strlen(setFirst));
        numO = toDec(numOne, val);
        numO *= negO;
    }
    else {
        char base = setFirst[0];
        int val = getBase(base);
        char *numOne = (char *)malloc(strlen(setFirst)-1);
        numOne = strncpy(numOne, setFirst+1, strlen(setFirst));
        numO = toDec(numOne, val);
    }

    if (setTwo[0] == '-') {
        negT = -1;
        char base = setTwo[1];
        int val = getBase(base);
        char *numTwo = (char *)malloc(strlen(setTwo)-2);
        numTwo = strncpy(numTwo, setTwo+2, strlen(setTwo));
        numT = toDec(numTwo, val);
        numT *= negT;
    }
    else {
        char base = setTwo[0];
        int val = getBase(base);
        char *numTwo = (char *)malloc(strlen(setTwo)-1);
        numTwo = strncpy(numTwo, setTwo+1, strlen(setTwo));
        numT = toDec(numTwo, val);
    }

    if (strcmp(op,"+") == 0) {
        res = add(numO,numT);
    }
    else if (strcmp(op,"-") == 0) {
        res = sub(numO,numT);
    }


    ans = fromDec(res, (*outForm));
    printf("%s\n", ans);
    
    
    return 0;
}
