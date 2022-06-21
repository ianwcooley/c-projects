#include <stdio.h>

/* Input: text file */
/* Output: prints text file with characters like newline and tab replaced
with their escape sequence */

#define MAX 1000

void escape(void);

int main() {
    escape();
    return 0;
}

void escape(void) {
    char s[2*MAX];
    int i = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (i >= 2*MAX - 1)
            printf("ERROR: File size too large.\n");
        switch (c) {
        case '\a':
            s[i++] = '\\';
            s[i++] =  'a';
            break;
        case '\b':
            s[i++] = '\\';
            s[i++] =  'b';
            break;
        case '\f':
            s[i++] = '\\';
            s[i++] =  'f';
            break;
        case '\n':
            s[i++] = '\\';
            s[i++] =  'n';
            break;
        case '\r':
            s[i++] = '\\';
            s[i++] =  'r';
            break;
        case '\t':
            s[i++] = '\\';
            s[i++] =  't';
            break;
        case '\v':
            s[i++] = '\\';
            s[i++] =  'v';
            break;
        case '\\':
            s[i++] = '\\';
            s[i++] =  '\\';
            break;
        default:
            s[i++] = c;
            break;
        }    
    }
    s[i] = '\0';
    printf("%s", s);
}