#include <stdio.h>
#include <string.h>

/* ~SCRATCH PAPER ~ */
/* This file is for testing things. */

int main() {

    /* Common Escape Sequences */

    // printf("Alert: \a awe\n");
    // printf("Backspace:\b awe\n");
    // printf("Formfeed:\f awe\n");
    // printf("Carriage Return: \r awe\n");
    // printf("Horizontal Tab: \t awe\n");
    // printf("Vertical Tab: \v awe\n");
    // printf("Hex Number: \x41 awe\n");
    // printf("Oct Number: %c awe\n", '\101');

    char s[20], t[11];
    for (int i = 0; i < 20; i++) {
        if (i < 10)
            s[i] = t[i] = 'a';
        else if (i == 10)
            s[i] = t[i] = '\0';
        else if (i == 19)
            s[i] = '\0';
        else     
            s[i] = 'b';
    }
    printf("%s\n%s\n", s, t);
    printf("%d\n", strcmp(s,t));
    
    return 0;
}