#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c, nextC, negNum = 0;

    /* ignore all white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* do we have a negative number? */
    if (c == '-') {
        if (isdigit(nextC = getch())) {
            s[0] = '-';
            negNum = 1;
        }
        ungetch(nextC);
    }

    /* do we have something that isn't a number? */
    if (!negNum && !isdigit(c) && c != '.') {
        // is it a <math.h> function?
        if (islower(c)) {
            i = 0;
            do {
                s[i++] = c;
            } while (islower(c = getch()) || isdigit(c));
            s[i] = '\0';
            if (c != EOF)
                ungetch(c);
            return FUNCTION;
        }
        return c;       /* not a number  - hopefully an operator */
    }
    
    /* do we have a number? */
    i = 0;
    if (isdigit(c) || negNum) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}