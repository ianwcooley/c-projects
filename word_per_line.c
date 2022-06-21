#include <stdio.h>

/* Input: text file */
/* Output: text file printed one word per line */

int main() {

    int c, state;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            while((c = getchar()) == ' ' || c == '\n' || c == '\t')
                ;
            putchar('\n');
            if (c != EOF)
                putchar(c);
        } else {
            putchar(c);
        }
    }

    
    return 0;
}