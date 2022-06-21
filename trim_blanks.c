#include <stdio.h>

/* Input: text file */
/* Output: text with multiple consecutive blanks replaced by 1 blank */

int main() {

    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        // printf("%c", c);
        if (c == ' ') {
            while((c = getchar()) == ' ')
                ;
            if (c != EOF)
                printf("%c", c);
        }
    }
    
    return 0;
}