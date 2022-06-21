#include <stdio.h>

/* Input: two matrices */
/* Output: product matrix (if legal) */

int main() {

    int i, j, k, numRows1, numCols1, numRows2, numCols2;
    
    // get first matrix
    printf("Enter size of first matrix: (#rows #columns)\n");
    scanf("%d %d", &numRows1, &numCols1);
    int a[numRows1][numCols1];
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < numRows1; i++)
        for (j = 0; j < numCols1; j++)
            scanf("%d", &a[i][j]);

    // get second matrix
    printf("Enter size of second matrix: (#rows #columns)\n");
    scanf("%d %d", &numRows2, &numCols2);
    int b[numRows2][numCols2];
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < numRows2; i++)
        for (j = 0; j < numCols2; j++)
            scanf("%d", &b[i][j]);

    // print error and return if matrices can't be multiplied
    if (numCols1 != numRows2) {
        printf("Invalid matrix sizes\n");
        return 0;
    }

    // declare product matrix
    int c[numRows1][numCols2];

    // multiply matrices
    for (i = 0; i < numRows1; i++)
        for (j = 0; j < numCols2; j++) {
            c[i][j] = 0;
            for (k = 0; k < numCols1; k++)
                c[i][j] += a[i][k]*b[k][j]; 
        }
    
    printf("---\n");

    // print first matrix
    printf("First matrix:\n"); 
    for (i = 0; i < numRows1; i++){
        for (j = 0; j < numCols1; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    // print second matrix
    printf("Second matrix:\n");
    for (i = 0; i < numRows2; i++){
        for (j = 0; j < numCols2; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    // print product matrix
    printf("Product matrix:\n");
    for (i = 0; i < numRows1; i++){
        for (j = 0; j < numCols2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    
    return 0;
}