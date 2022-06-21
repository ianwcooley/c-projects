#include <stdio.h>

/* Input: two strings, s1 and s2 */
/* Output: the first location in s1 where any character from s2 occurs,
or -1 if s1 contains no characters from s2. */

#define MAX 1000

int any(char s1[], char s2[]);

int main() {

    char s1[MAX] = {'\0'}, s2[MAX] = {'\0'};
    printf("Enter string (no spaces):\n");
    scanf("%s", s1);
    printf("Enter characters to look for:\n");
    scanf("%s", s2);

    printf("%d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++)
        for (k= 0; s2[k] != '\0' ; k++)
            if (s1[i] == s2[k])
                return i;
    return -1;
}               