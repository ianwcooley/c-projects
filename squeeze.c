#include <stdio.h>

/* Input: two strings, s1 and s2*/
/* Output: s1 with all occurences of anything in s2 removed*/

#define MAX 1000

void squeeze(char s1[], char s2[]);

int main() {

    char s1[MAX] = {'\0'}, s2[MAX] = {'\0'};
    printf("Enter string (no spaces):\n");
    scanf("%s", s1);
    printf("Enter characters to be removed from string (no spaces):\n");
    scanf("%s", s2);

    squeeze(s1, s2);
    printf("New string:\n%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k, match = 0;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k= 0; s2[k] != '\0' ; k++) {
            if (s1[i] == s2[k]) {
                match = 1;
                break;
            }
        }
        if (!match)
            s1[j++] = s1[i];
        else
            match = 0;
    }
    s1[j] = '\0';

}               