#include <stdio.h>

#define MAX 20

#define BEFORE_FIRST_WORD 0
#define IN_FIRST_WORD 1
#define AFTER_FIRST_WORD 2
#define OUT_OF_WORD 0
#define IN_WORD 1

/* Input: a textfile */
/* Output: the textfile "folded" about MAX characters, without word breaks*/

int isWhiteSpace(char c);
void clearLine(char s[]);
void printLine(char s[]);

int main() {

    int firstWord = BEFORE_FIRST_WORD;
    int word = OUT_OF_WORD;
    char c, tempC;
    char line[MAX+1] = {'\0'}, tempLine[MAX+1] = {'\0'};
    int i = 0, j = 0;


    while ((c = getchar()) != EOF) {

        // determine if next character will0 be part of word or not
        word = isWhiteSpace(c) ? OUT_OF_WORD : IN_WORD;
        if (firstWord == BEFORE_FIRST_WORD && word == IN_WORD)
            firstWord = IN_FIRST_WORD;
        else if (firstWord == IN_FIRST_WORD && word == OUT_OF_WORD)
            firstWord = AFTER_FIRST_WORD;

        printf("[%d %d %d]", i, firstWord, word);

        switch (firstWord) {
        case BEFORE_FIRST_WORD:
            if (c == '\n')
                printf("\n");
            break;
        case IN_FIRST_WORD:
            if (i < MAX) {
                line[i++] = c;
            } else {
                if (i > MAX) printf("\n\nERROR\n\n");
                tempC = line[i-1];
                line[i-1] = '-';
                printLine(line);
                clearLine(line);
                line[0] = tempC;
                line[1] = c;
                i = 2;
            }
            break;
        case AFTER_FIRST_WORD:
            if (c == '\n') {
                printLine(line);
                clearLine(line);
                firstWord = BEFORE_FIRST_WORD;
                i = 0;
            } else if (i < MAX) {
                line[i++] = c;
            } else {
                if (i > MAX) printf("\n\nERROR\n\n");
                if (word == OUT_OF_WORD || isWhiteSpace(line[i-1])) {
                    printLine(line);
                    clearLine(line);
                    firstWord = BEFORE_FIRST_WORD;
                    i = 0;
                } else {
                    // ameromaeor
                    tempC = line[i-1];
                    line[i-1] = '-';
                    printLine(line);
                    clearLine(line);
                    line[0] = tempC;
                    line[1] = c;
                    i = 2;
                    firstWord = IN_FIRST_WORD;
                    // aewrmapwerma

                }
            }

          
            break;
        default:
            printf("Something has gone horribly wrong :/\n");
            break;
        }
    }
    printf("%s\n", line);
    
    return 0;
}

int isWhiteSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t' || c == '\b');
} 

void clearLine(char s[]) {
    int i;
    for (i = 0; i < MAX+1; i++)
        s[i] = '\0';
}

void printLine(char s[]) {
    printf("%s\n", s);
}