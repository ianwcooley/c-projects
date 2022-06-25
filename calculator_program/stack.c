#include <stdio.h>
#include "calc.h"

#define MAXVAL 100    /* maximum depth of val stack */

static int sp = 0;           /* next free stack position */
static double val[MAXVAL];   /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* clearStack:  clears stack and returns stack position to 0 */
void clearStack(void) {
    for (int i = 0; i <= sp; i++)
        val[i] = 0;
    sp = 0;
}

/* printTop: prints top element of stack without popping */
void printTop(void) {
    printf("%g", val[sp - 1]);
}

/* duplicateTop: duplicates top element of stack 
and increments stack position */
void duplicateTop(void) {
    if (sp < MAXVAL) {
        val[sp] = val[sp - 1];
        // When I tried to increment sp in the line above I got
        // a "warning: unsequenced modification and access to 'sp' [-Wunsequenced]"
        // not sure why this is a problem.
        sp++;
    } else {
        printf("error: stack full, can't duplicate top element.\n");
    }
}

/* swapTop: swaps top two elements of stack */
void swapTop(void) {
    double tempVal = val[sp - 1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tempVal;
}



