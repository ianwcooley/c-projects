#include <stdio.h>
#include "getnum.h"

int n;
double array[SIZE] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};

int main() {

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    

    for (n = 0; n < SIZE; n++)
        printf("%d %g\n", n, array[n]);

    return 0;
}