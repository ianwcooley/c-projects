#include <stdio.h>

/* Input: c code */
/* Output: prints c code with comments removed */

char c, bc; // bc = the character before c
int inOneLineComment = 0;
int inMultiLineComment = 0;

int main() {

    while ((c = getchar()) != EOF) {
        // if haven't entered comment yet
        if (!inOneLineComment && !inMultiLineComment) {
            // conditions to enter one line comment
            if (c == '/' && bc == '/') {
                inOneLineComment = 1;
                bc = 0;
            // conditions to enter multi-line comment
            } else if (c == '*' && bc == '/') {
                inMultiLineComment = 1;
                bc = 0;
            // if see a slash, set it to bc and keep going
            } else if (c =='/') {
                bc = '/';
            // if bc is slash but conditions for comment are not met,
            // print bc and c.
            } else if (bc == '/') {
                printf("%c", bc);
                printf("%c", c);
                bc = 0;
            // else, print c
            } else {
                printf("%c", c);
            }
        // if in one line comment, keep going without printing
        // until end of line.
        } else if (inOneLineComment) {
            while ((c = getchar()) != EOF && c != '\n')
                ;
            if (c == EOF) 
                return 0;
            else {
                printf("\n");
                inOneLineComment = 0;
            }
        // if in multi-line comment, keep going without printing
        // until conditions are met for end of comment.
        } else if (inMultiLineComment) {
            while ((c = getchar()) != EOF) {
                if (bc == '*') {
                    if (c == '/') {
                        bc = 0;
                        inMultiLineComment = 0;
                        break;
                    } else {
                        bc = 0;
                    }
                }
                else if (c == '*')
                    bc = '*';
                
            }
            if (c == EOF) 
                return 0;
        }
    }
    
    return 0;
}