/*
 * calc.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mattklein
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIN_BASE 2
#define HEX_LEN 4
#define OCT_LEN 3
#define OCT_BASE 8
#define DEC_BASE 10
#define HEX_BASE 16

char tochar(int);

int hexCharToInt(char);

typedef struct LLBin {
    int num;
    struct LLbin *next;
} LLBin, in1, in2;

void print(LLBin **list, char *form) {
    int b;
    char *ans = (char *) malloc(sizeof(char));
    int ret;
    if (strcmp(form, "b")) {
        while (*list) {
            printf("%c", tochar((*list)->num));
            (*list) = (*list)->next;
        }
        return;
    }
    else if (strcmp(form, "x"))
        b = HEX_BASE;
    else if (strcmp(form, "o"))
        b = OCT_BASE;
    else if (strcmp(form, "d"))
        b = DEC_BASE;

    while (list) {
        ret += pow((*list)->num,b);
    }
    printf("%c", tochar(ret));
}

char tochar(int n) {
    return n - 208;
}

void toBin(int n, char form, LLBin **list) {
    int base = 2;
    LLBin *temp = *list;

    while (temp)
        temp = temp->next;

    int r;
    int count = 0;
    while (n) {
        r = n % base;

        temp->num = r;

        n /= base;
        count++;
    }
    int base_ret;

    if (form == 'o')
        base_ret = 3;
    else if (form == 'x')
        base_ret = 4;

    while (count != base_ret) {
        temp->num = 0;
        temp = temp->next;
        count++;
    }
}

void toDec(char *in, char form, int base, LLBin **list) {
    int i;

    for (i = strlen(in) - 1; i >= 0; i--) {
        int x = 0;

        /* Convert A-Fa-f to 10-15. */
        if (base == HEX_BASE && !isdigit(in[i])) {
            x = hexCharToInt(in[i]);
        } else {
            x = in[i] - '0';
        }

        toBin(x, form, list);
    }
}

LLBin * add(LLBin **list1, LLBin **list2) {
    LLBin *out = (LLBin *) malloc(sizeof(LLBin));
    LLBin *t1 = *list1;
    LLBin *t2 = *list2;
    /*Right to left, add each. carry+l1[x]+l2[x]*/
    int carry = 0;
    while (t1 && t2) {
        int tmp = carry+((t1->num)+(t2->num));
        carry = 0;
        if (tmp > 1) {
            tmp = tmp%BIN_BASE;
            carry = 1;
        }
        out->num = tmp;
        out = out->next;
        t1 = t1->next;
        t2 = t2->next;
    }
    /*If t1 is empty from 1st loop but t2 isnt*/
    while (t2 != NULL) {
        int tmp = carry+(t2->num);
        carry = 0;
        if (tmp == 2) {
            tmp = tmp%BIN_BASE;
            carry = 1;
        }
        out->num = tmp;
        t2 = t2->next;
    }
    /*If t2 is empty from 1st loop but t1 isnt*/
    while (t1 != NULL) {
        int tmp = carry+((*t1)->num);
        carry = 0;
        if (tmp == 2) {
            tmp = tmp%BIN_BASE;
            carry = 1;
        }
        out->num = tmp;
        t1 = t1->next;
    }
    /*Excess 1 from last guy*/
    if (carry == 1) {
        out->num = carry;
    }
    return out;
}

LLBin * twos(LLBin **list) {
    LLBin *temp = *list;
    LLBin *one = (LLBin *) malloc(sizeof(LLBin));
    one->num = 1;
    one->next = NULL;
    LLBin *ret = (LLBin *) malloc(sizeof(LLBin));
    while (temp) {
        if (temp->num == 1)
            temp->num = 0;
        else
            temp->num = 1;

        temp = temp->next;
    }
    ret = add (temp, one);
    return ret;
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

void place(LLBin **list, char *str) {
    int len = strlen(str);
    int i;
    LLBin *temp = list;
    for (i = 0; i < len; i++) {
        temp->num = str[i] - '0';
        temp = temp->next;
    }
}

char * strrev(char *str) {
    char *rever = (char *)malloc(strlen(str));
    int i;
    for (i = 0; i < strlen(str); i++) {
        rever[i] = str[strlen(str)-1-i];
    }
    return rever;
}

int main(int argc, char *argv[]) {
    /*Check if it is a '-'
     * in first, if not take the char it is form and go from +1 of that to end */
    /*Convert to binary*/
    /*Repeat for 2nd guy*/
    /*Add if add, or sub if sub(two's complement and then add)*/
    /*Output*/
    LLBin *list1 = (LLBin *)malloc(sizeof(LLBin));
    LLBin *list2 = (LLBin *)malloc(sizeof(LLBin));

    /*Check if argv < 5*/
    if (argc < 5) {
        fprintf(stderr, "Not enough arguments passed.\n");
        exit(EXIT_FAILURE);
    }
    if (argc > 6) {
        fprintf(stderr, "Too many arguments passed.\n");
        exit(EXIT_FAILURE);
    }


    char *setFirst = argv[2];
    char *setTwo = argv[3];
    char *op = argv[1];
    char *outForm = argv[4];

    if (!strcmp(op, "+") || !strcmp(op, "-")) {
        fprintf(stderr, "Invalid operation!\n");
        exit(EXIT_FAILURE);
    }

    if (!strcmp(outForm, "b")  || !strcmp(outForm, "d")  || !strcmp(outForm, "x") ||  !strcmp(outForm, "o")) {
        fprintf(stderr, "Invalid output base!\n");
        exit(EXIT_FAILURE);
    }

    if (setFirst[0] == '-') {
        char base = setFirst[1];
        strncpy(setFirst, setFirst+2, strlen(setFirst));
        if (base == 'b') {
            char *str = strrev(setFirst);
            place(list1, str);
        }
        else if (base == 'x')
            toDec(setFirst, 'x', HEX_BASE, &list1);
        else if (base == 'd')
            toDec(setFirst, 'd', DEC_BASE, &list1);
        else if (base == 'o')
            toDec(setFirst, 'o', OCT_BASE, &list1);
    }
    else {
        char base = setFirst[0];
        strncpy(setFirst, setFirst+1, strlen(setFirst));
        if (base == 'b') {
            char *str = strrev(setFirst);
            place(list1, str);
        }
        else if (base == 'x')
            toDec(setFirst, 'x', HEX_BASE, &list1);
        else if (base == 'd')
            toDec(setFirst, 'd', DEC_BASE, &list1);
        else if (base == 'o')
            toDec(setFirst, 'o', OCT_BASE, &list1);
    }

    /*Second input*/
    if (setTwo[0] == '-') {
        /*Two's! and add to list*/
        char base = setTwo[1];
        strncpy(setTwo, setTwo+2, strlen(setTwo));
        if (setTwo[1] == 'b') {
            char *str = strrev(setTwo);
            place(list2, str);
        }
        else if (base == 'x')
            toDec(setTwo, 'x', HEX_BASE, &list2);
        else if (base == 'd')
            toDec(setTwo, 'd', DEC_BASE, &list2);
        else if (base == 'o')
            toDec(setTwo, 'o', OCT_BASE, &list2);


    }
    else {
        char base = setTwo[0];
        strncpy(setTwo, setTwo+1, strlen(setTwo));
        if (base == 'b') {
            char *str = strrev(setTwo);
            place(list2, str);
        }
        else if (base == 'x')
            toDec(setTwo, 'x', HEX_BASE, &list2);
        else if (base == 'd')
            toDec(setTwo, 'd', DEC_BASE, &list2);
        else if (base == 'o')
            toDec(setTwo, 'o', OCT_BASE, &list2);


    }

    LLBin *out = (LLBin*)malloc(sizeof(LLBin));
    if (strcmp(op, "+")) {
        out = add(list1, list2);
    }
    else if (strcmp(op, "-")) {
        list2 = twos(list2);
        out = add(list1, list2);
    }
    print(out, outForm);


    return 0;
}

