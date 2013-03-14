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

char * substr(const char *, int, int);
int getsign(const char *);
int getexp(const char *);
int getsignif(const char *);
int chartoint(char);
int toDec(const char *);
char * fromDec(int n, int neg);
float toFloat(int sign, int exp, int man);
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
    char *rever = (char *)calloc(strlen(str));
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
    printf("%d\n", n);
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
	float decoded = pow(-1, sign) * (1 + (man * pow(2, -23))) * pow(2, decodedexp);
	
    return decoded;
}

void tostring(float f) {
    printf("%f", f);
    char fstr[80];
    float num = f;
    int m = log10(num);
    int digit;
    float tolerance = .0001f;
    int i = 0;
    while (num > 0 + tolerance)
    {
        float weight = pow(10.0f, m);
        digit = floor(num / weight);
        num -= (digit*weight);
        *(fstr[i++]) = '0' + digit;
        if (m == 0)
            *(fstr[i++]) = '.';
        m--;
    }
    *(fstr) = '\0';

    printf("%s\n", fstr);
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
                puts("zero");
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


    float answ = toFloat(signNum, exponent, significand);
//    tostring(answ);

    printf("%.7e\n", answ);

    free(set);
    free(type);
    free(ans);

    return 0;
}
