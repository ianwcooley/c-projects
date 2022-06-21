#include <stdio.h>

/* Input: text file */
/* Output: prints text file with escape sequences like \n replaced by the
real characters (in this case, a newline character) */

#define MAX 1000

void escape_rev(void);

int main() {
    escape_rev();
    return 0;
}

void escape_rev(void) {
    char s[2*MAX];
    int i = 0;
    char c;
    int escapeSeq = 0;
    while ((c = getchar()) != EOF) {
        if (i >= 2*MAX - 1)
            printf("ERROR: File size too large.\n");
        switch (c) {
        case '\\':
            if (escapeSeq) {
                s[i++] = '\\';
                escapeSeq = 0;
            } else {
                escapeSeq = 1;
            }
            break;
        case 'a':
            if (escapeSeq) {
                s[i++] = '\a';
                escapeSeq = 0;
            } else {
                s[i++] = 'a';
            }
            break;
        case 'b':
            if (escapeSeq) {
                s[i++] = '\b';
                escapeSeq = 0;
            } else {
                s[i++] = 'b';
            }
            break;
        case 'f':
            if (escapeSeq) {
                s[i++] = '\f';
                escapeSeq = 0;
            } else {
                s[i++] = 'f';
            }
            break;
        case 'n':
            if (escapeSeq) {
                s[i++] = '\n';
                escapeSeq = 0;
            } else {
                s[i++] = 'n';
            }
            break;
        case 'r':
            if (escapeSeq) {
                s[i++] = '\r';
                escapeSeq = 0;
            } else {
                s[i++] = 'r';
            }
            break;
        case 't':
            if (escapeSeq) {
                s[i++] = '\t';
                escapeSeq = 0;
            } else {
                s[i++] = 't';
            }
            break;
        case 'v':
            if (escapeSeq) {
                s[i++] = '\v';
                escapeSeq = 0;
            } else {
                s[i++] = 'v';
            }
            break;
        default:
            if (escapeSeq) {
                s[i++] = '\\';
                escapeSeq = 0;
            }
            s[i++] = c;
            break;
        }    
    }
    s[i] = '\0';
    printf("%s", s);
}