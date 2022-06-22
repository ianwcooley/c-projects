#include <stdio.h>

/* Input: string 1 with no spaces*/
/* Output: expands notation like a-z, A-Z0-9, -a-z from s1
into sequences and puts the expanded string in s2 (then prints) */

// I was too lazy to write edge case error-catching
// on this one (if resultant string > MAX)

#define MAX 10000

void expand(char s1[], char s2[]);
int expLeft(char s[], char c, int i);
int expRight(char s[], char c, int i);
int expMiddle(char s[], char c1, char c2, int i);

int main() {

    char s1[MAX] ={'\0'}, s2[MAX] = {'\0'};
    printf("Write string with sequences to be expanded:\n");
    scanf("%s", s1);

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

void expand (char s1[], char s2[]) {
    int i, j, tempJ;
    for (i = j = 0; s1[i] != '\0' && j < MAX - 1; i++) {
        tempJ = j;
        if (s1[i] == '-') {
            if (i == 0) {
                if ((tempJ = expLeft(s2, s1[i+1], j)) >= 0)
                    j = tempJ;
            } 
            else if (s1[i+1] == '\0') { 
                if ((tempJ = expRight(s2, s1[i-1], j)) >= 0)
                    j = tempJ;
            } 
            else { 
                if ((tempJ = expMiddle(s2, s1[i-1], s1[i+1], j)) >= 0)
                    j = tempJ;
            }
        } else {
            s2[j++] = s1[i];
        }
    }       
}

int expLeft(char s[], char c, int i) {
    char cLower;
    if (c >= 'a' && c <= 'z')
        cLower = 'a';
    else if (c >= 'A' && c <= 'Z')
        cLower = 'A';
    else if (c >= '0' && c <= '9')
        cLower = '0';
    else
        return -1;
    
    while (cLower != c)
        s[i++] = cLower++;

    return i;
}

int expRight(char s[], char c, int i) {
    char cUpper;
    if (c >= 'a' && c < 'z')
        cUpper = 'z';
    else if (c >= 'A' && c < 'Z')
        cUpper = 'Z';
    else if (c >= '0' && c < '9')
        cUpper = '9';
    else
        return -1;
    
    do {
        s[i] = ++c;     
    } while (s[i++] != cUpper);

    return i;
}

int expMiddle(char s[], char c1, char c2, int i) {
    
    int ascending = c1 <= c2 ? 1 : 0;

    // check for proper sequence
    if (!(c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z' 
    || c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z'
    || c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9'))
        return -1;

    if (ascending)
            while (c1 < c2 - 1)
                s[i++] = ++c1;
        else 
            while (c1 > c2 + 1)
                s[i++] = --c1;

    return i;
}