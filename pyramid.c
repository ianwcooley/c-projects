#include <stdio.h>

/* Input: n */
/* Output: Prints a Pyramid of Stars, of height n */

void printPyramid(int n);

int main() {

    int n;
    printf("Enter a number 1-20:\n");
    scanf("%d", &n);
    printf("Your number is %d\n", n);
    printPyramid(n);

    return 0;
}

void printPyramid(int n) {
    int i, j;
    int rowLength = 1;
    int maxRowLength = 1 + 2 * (n - 1);
    int padding = maxRowLength / 2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < padding; j++)
            printf(" ");
        for (j = 0; j < rowLength; j++)
            printf("*");
        printf("\n");
        rowLength += 2;
        padding = padding - 1;
    }
}