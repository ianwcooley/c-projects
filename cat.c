#include <stdio.h>

/* Input: a text file */
/* Output: the contents of the text file */

int main() {

    int c;
    while((c = getchar()) != EOF)
        printf("%c", c);
    
    return 0;
}