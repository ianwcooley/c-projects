#include <stdio.h>

/* Input: text file */
/* Output: number of spaces, tabs, and newlines in text file */

int main() {

    int c;
    int ns = 0, nt = 0, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ns++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
    }
    printf("Spaces: %d\n", ns);
    printf("Tabs: %d\n", nt);
    printf("Newlines: %d\n", nl);
    
    return 0;
}