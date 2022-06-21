#include <stdio.h>

/* Input: a text file */
/* Output: histogram of word lengths */

#define MAXLENGTH 50
#define HORI 0
#define VERT 1

int lengths[MAXLENGTH] = {0};

void count(void);
void printHist(int dir);

int main() {

    count();
    printHist(HORI);
    
    return 0;
}

void count(void) {  
    int c, length = 0;
    while ((c = getchar()) != EOF) {
        if ( 'a' <= c && c <= 'z'
        || 'A' <= c && c <= 'Z' 
        || c == '\'') {
            length++;
        }
        else {
            if (length == 0)
                ;
            else {
                lengths[length - 1]++;
                length = 0;
            }
        }
    }
}

void printHist(int dir) {
    int i, j;
    int most = 0;
    if (dir == VERT) {
        for (i = 0; i < MAXLENGTH; i++)
            if (lengths[i] > most)
                most = lengths[i];
        for (j = most; j >= 1; j--) {
            for (i = 0; i < MAXLENGTH; i++) {
                if (!lengths[i])
                    continue;
                printf("  ");
                if (lengths[i] >= j)
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
        }
        for (i = 0; i < MAXLENGTH; i++) {
            if (!lengths[i])
                continue;
            printf("%3d", i+1);
        }
        printf("\n");

        return;
    }
    
    for (i = 0; i < MAXLENGTH; i++)
        if (lengths[i]) {
            printf("%2d:", i+1);
            for (j = 0; j < lengths[i]; j++)
                printf("-");
            printf("\n");
        }
}