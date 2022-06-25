#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main () {
    int type, funtype;
    double op2;
    char s[MAXOP]; // file input buffer
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        /* <math.h> functions
         (excluding frexp and modf) */
        case FUNCTION:
            if (!strcmp(s, "sin"))
                push(sin(pop()));
            else if (!strcmp(s, "cos"))
                push(cos(pop()));
            else if (!strcmp(s, "tan"))
                push(tan(pop()));
            else if (!strcmp(s, "asin"))
                push(asin(pop()));
            else if (!strcmp(s, "acos"))
                push(acos(pop()));
            else if (!strcmp(s, "atan"))
                push(atan(pop()));
            else if (!strcmp(s, "atan2"))
                push(atan2(pop(), pop()));
            else if (!strcmp(s, "sinh"))
                push(sinh(pop()));
            else if (!strcmp(s, "cosh"))
                push(cosh(pop()));
            else if (!strcmp(s, "exp"))
                push(exp(pop()));
            else if (!strcmp(s, "log"))
                push(log(pop()));
            else if (!strcmp(s, "log10"))
                push(log10(pop()));
            else if (!strcmp(s, "pow"))
                push(pow(pop(), pop()));
            else if (!strcmp(s, "sqrt"))
                push(sqrt(pop()));
            else if (!strcmp(s, "ceil"))
                push(ceil(pop()));
            else if (!strcmp(s, "floor"))
                push(floor(pop()));
            else if (!strcmp(s, "fabs"))
                push(fabs(pop()));
            else if (!strcmp(s, "ldexp"))
                push(ldexp(pop(), pop()));
            else if (!strcmp(s, "fmod"))
                push(fmod(pop(), pop()));
            else
                 printf("error: unknown function %s\n", s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((double) ((int) pop() % (int) op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}