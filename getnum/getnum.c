
/* getnum */
/* functions that convert a string of a decimal number
into the decimal number and store it in a variable*/
#include <stdio.h>
#include <ctype.h>
#include "getnum.h"


/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch())) // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        printf("why are we creating this long-running loop here??\n");
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        printf("Oh no you don't.\n");
        ungetch(c);
        return c;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/* getfloat: get next float from input into *pn */
int getfloat(double *pn) {
    int c;
    double sign, power, exp, expsign;
    while (isspace(c = getch())) // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c !='.') {
        ungetch(c);
        printf("why are we creating this long-running loop here??\n");
        return 0;
    }
    sign = (c == '-') ? -1.0 : 1.0;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        printf("Oh no you don't.\n");
        ungetch(c);
        return c;
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }

    // support for scientific notation
    if (c == 'e' || c == 'E') {
        c = getch();
        expsign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
            c = getch();
        if (!isdigit(c))
            ungetch(c);
        for (exp = 0.0; isdigit(c); c = getch())
            exp = 10.0 * exp + (c - '0');

        if (expsign == -1)
            for (int j = 0; j < exp; j++)
                *pn /= 10.0;
        else
            for (int j = 0; j < exp; j++)
                *pn *= 10.0;
    }
    

    *pn = sign * *pn / power;

    if (c != EOF)
        ungetch(c);
    return c;
}