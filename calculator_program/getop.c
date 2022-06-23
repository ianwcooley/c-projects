#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c, nextC, negNum = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '-') {
        if (isdigit(nextC = getch())) {
            s[0] = '-';
            negNum = 1;
        }
        ungetch(nextC);
    }
    if (!negNum && !isdigit(c) && c != '.')
        return c;       /* not a number */
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