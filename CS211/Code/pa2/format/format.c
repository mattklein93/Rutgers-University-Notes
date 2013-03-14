#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN_SIGNBIT 1
#define LEN_EXPONENT 8
#define LEN_SIGNIFICAND 23
#define INDEX_SIGN 0
#define INDEX_EXPONENT 1
#define INDEX_SIGNIFICAND 9
#define STRING_LENGTH 32
#define ALL_ZERO 100
#define ALL_ONE 10
#define PRECISION 7

char * substr(const char *, int, int);
int getsign(const char *);
int getexp(const char *);
int getsignif(const char *);
int chartoint(char);
int toDec(const char *);
char * fromDec(int n, int neg);
float toFloat(int, int, int);
char * strrepeat(const char * toR, int num);
char * strrev(char *str) ;

char * substr(const char *str, int start, int len) {
    if (!str || !strlen(str) || len < 0 || len > (strlen(str) - start)) {
        return 0;
    }
 
    char *out = (char *) malloc(len);
    strncpy(out, str + start, len);
    out[len] = '\0';
    return out;
}

int getsign(const char *bin) {
    char *sb = substr(bin, INDEX_SIGN, LEN_SIGNBIT);
    return chartoint(*sb);
}
 
int getexp(const char *bin) {
    char *exponent = substr(bin, INDEX_EXPONENT, LEN_EXPONENT);
    if (!strcmp(exponent, strrepeat("0", LEN_EXPONENT)))
            return ALL_ZERO;
    else if (!strcmp(exponent, strrepeat("1", LEN_EXPONENT)))
            return ALL_ONE;

    return toDec(exponent);
}
 
int getsignif(const char *bin) {
    char *significand = substr(bin, INDEX_SIGNIFICAND, LEN_SIGNIFICAND);
    if (!strcmp(significand, strrepeat("0", LEN_SIGNIFICAND)))
            return ALL_ZERO;
    else if (!strcmp(significand, strrepeat("1", LEN_SIGNIFICAND)))
            return ALL_ONE;

    return toDec(significand);
}

char * strrev(char *str) {
    char *rever = (char *)calloc(1, strlen(str));
    int i;
    for (i = 0; i < strlen(str); i++) {
        rever[i] = str[strlen(str)-1-i];
    }
    return rever;
}

char tochar(int n) {
    return n - 208;
}

int chartoint(char c) {
    return c - '0';
}

char * fromDec(int n, int neg) {
    if (neg == -1) {
        n = (~n)+1;
    }

    int base = 10;

    char *result = (char *) calloc(1, sizeof(char));
    char *digit = (char *) calloc(1, sizeof(char));
    int remainder;


    while (n) {
        remainder = abs(n % base);

        digit[0] = tochar(remainder);

        strcat(result, digit);
        n /= base;
    }
    if (neg == -1)
        printf("%s","-");
    return strrev(result);
}


int toDec(const char *in) {
    int base = 2;
    int result = 0;
    int power = 0;
    int i;
    for (i = strlen(in) - 1; i >= 0; i--) {
        int x;
        x = in[i] - '0';

        result += x * (pow(base, power++));
    }

    return result;
}

char * strrepeat(const char * toR, int num) {
    char *ret = (char*)malloc(sizeof(char)*num);
    int i = 0;
    for (; i < num; i++)
        strcat(ret,toR);

    return ret;
}

float toFloat(int sign, int man, int exp) {
    int decodedexp = exp - 127;
 
    float decoded = (pow(-1, sign) * (1 + (man * pow(2, -23))) * pow(2, decodedexp));
    return decoded;
}

void tostring(float f) {
    float temp = f;
    char *out = (char*)malloc(sizeof(char)*100);
    char *toAdd = (char*)malloc(sizeof(char));
    char *exp = (char*)malloc(sizeof(char));
    strcat(exp,"e");
    int nec = 0;

    if (f < 1) {
        nec++;
        strcat(exp,"-");
    }

    int exponent = abs((int)log10(f))+nec;
    *toAdd = (exponent-208);
    if (nec == 1) {
        double power = 1;
        while (power < exponent) {
            f *= 10;
            power++;
        }
        f *= 10;
        temp = f;
    }

    strcat(exp,toAdd);


    while (temp > 1) {
        int add = (int)temp%10;
        *toAdd = (add-208);
        temp = temp/10;
        strcat(out,toAdd);
    }

    out = strrev(out);
    strcat(out,".");
    temp = f*10;
    
    int i;
    for (i = 0; i < PRECISION; i++) {
        int add = (int)temp%10;
        *toAdd = (add-208);

        strcat(out,toAdd);

        temp = temp*10;
    }

    printf("%s%s\n", out, exp);

}

int main(int argv, char *argc[]) {
    char *set = (char *)malloc(strlen(argc[1]));
    strcpy(set,argc[1]);
    char *type = (char *)malloc(strlen(argc[2]));
    strcpy(type, argc[2]);
    char *ans = (char*)malloc(sizeof(char)*4);
    int temp = 0;

    if (strcmp(type,"int") == 0) {
        int neg = 1;
        if (set[0] == '1')
            neg = -1;
        temp = toDec(set);
        ans = fromDec(temp, neg);
        printf("%s\n", ans);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(type,"float") == 0) {
        int signNum = getsign(set);
        int exponent = getexp(set);
        int significand = getsignif(set);

        if (significand == ALL_ZERO) {
            if (exponent == ALL_ZERO) {
                if (signNum = 1) {
                    puts("negative zero");
                    exit(EXIT_SUCCESS);
                }
                else {
                    puts("negative zero");
                    exit(EXIT_SUCCESS);
                }
            } else if (exponent == ALL_ONE) {
                if (signNum = 1) {
                    puts("ninf");
                    exit(EXIT_SUCCESS);
                } else {
                    puts("pinf");
                    exit(EXIT_SUCCESS);
                }
            }
        } else {
            if (exponent == ALL_ONE) {
                puts("NaN");
                exit(EXIT_SUCCESS);
            }
        }
    }
    int signNum = getsign(set);
    int exponent = getexp(set);
    int significand = getsignif(set);  


    float answ = toFloat(signNum, significand, exponent);

    tostring(answ);

    free(set);
    free(type);
    free(ans);

    return 0;
}
