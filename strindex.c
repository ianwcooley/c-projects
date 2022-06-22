#include <stdio.h>

/* Input: string and string to search for within it*/
/* Output: */

#define MAX 1000

int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

int main() {

    char s[MAX] = {'\0'}, t[MAX] = {'\0'};

    printf("Enter string to be searched in (no spaces):\n");
    scanf("%s", s);
    printf("Enter string to be searched for (no spaces):\n");
    scanf("%s", t);

    printf("Index of first occurence of string: %d\n", strindex(s, t));
    printf("Index of first rightmost occurence of string: %d\n", strrindex(s, t));
    
    return 0;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}


/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k;
    int str_length;
    for (i = 0; s[i] != '\0'; i++)
        ;
    str_length = i - 1;
    for (i = str_length; i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
