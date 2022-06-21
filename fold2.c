#include <stdio.h>

/* Input: text file */
/* Output: input "folded". (maximum line of MAX, lines separated without slicing words).
            (similar to wrap.c, but without slicing words)*/

#define MAX 10 // must be at least 2

void clearLine(char s[]);
void copyLine(char src[], char dest[]);
int isWhiteSpace(char c);

int main() {

    int newLineSeen = 0;
    int nonWhiteSpaceSeen = 0;
    int inFirstWord = 0;
    char c, tempChar;
    char line[MAX+1] = {'\0'}; // will store characters as they are read
    char tempLine[MAX+1] = {'\0'}; // will store strings in event of line overflow
    int i = 0; // index for "line"

    while ((c = getchar()) != EOF) {

        // beginning of string case:
        // if at beginning of line, and haven't seen non-whitespace
        if (!nonWhiteSpaceSeen) {
            // subcase 1: have already seen newLine, so can print more new lines
            if (c == '\n' && newLineSeen)
                printf("\n");
            // subcase 2: haven't seen newLine, so ignore newLine, but not the next ones
            else if (c == '\n' && !newLineSeen)
                newLineSeen = 1;
            // subcase 3: first non-whitespace of line
            else if (!isWhiteSpace(c)) {
                line[i++] = c;
                nonWhiteSpaceSeen = 1;
                inFirstWord = 1;
                newLineSeen = 0;
            }
        }
        
        // end of string case 1: '\n'
        // print line, clear line, reset index i to 0.
        // set newLineSeen = 1, so extra new lines can be printed.
        else if (c == '\n' && nonWhiteSpaceSeen && !newLineSeen) {
            printf("%s\n", line);
            clearLine(line);
            i = 0;
            nonWhiteSpaceSeen = 0;
            inFirstWord = 0; // necessary?
            newLineSeen = 1;
        } 
        
        // end of string case 2: i == MAX
        // (the maximum # of characters have been read into the line, 
        // and now we must print it)
        else if (i >= MAX) {
            if (i > MAX)
                printf("\n---\nERROR\n---\n"); // i should never be > MAX
            // subcase 1: next character is whitespace
            // print line, clear line, reset index i to 0.    
            if (isWhiteSpace(c)) {
                printf("%s\n", line);
                clearLine(line);
                i = 0;
                newLineSeen = 0;
                nonWhiteSpaceSeen = 0;
                inFirstWord = 0; // necessary?
            }
            // subcase 2: next character is not whitespace, but previous character is.
            // print line, clear line, intialize line with next character, set index i to 1.
            // set nonWhiteSpaceSeen = 1;
            else if (!isWhiteSpace(c) && isWhiteSpace(line[i - 1])) {
                printf("%s\n", line);
                clearLine(line);
                line[0] = c;
                i = 1;
                inFirstWord = 1;
            }
           
            // subcase 3: next character is not whitespace, and previous character is not whitespace,
            // and still in first word
            // store previous character in tempChar, replace it in line with '-'.
            // print line, clearLine, intialize line with previous character and next character,
            // set index i to 2.
            else if (!isWhiteSpace(c) && !isWhiteSpace(line[i - 1]) && inFirstWord) {
                tempChar = line[i-1];
                line[i-1] = '-';
                printf("%s\n", line);
                clearLine(line);
                line[0] = tempChar;
                line[1] = c;
                i = 2;
            }

            // subcase 3: next character is not whitespace, and previous character is not whitespace,
            // but not in first word.
            // back up until reach closest whitespace, then store that word in tempLine,
            // erase it in line, print line, and finally copy tempLine to line and clear tempLine.
            else if (!isWhiteSpace(c) && !isWhiteSpace(line[i - 1]) && !inFirstWord) {
                    int j = i;
                    while (!isWhiteSpace(line[--j]))
                        ;
                    int k = 0;
                    while (++j < i) {
                        tempLine[k++] = line[j];
                        line[j]='\0';
                    }
                    tempLine[k++] = c;
                    printf("%s\n", line);
                    clearLine(line);
                    copyLine(tempLine, line);
                    clearLine(tempLine);
                    i = k;
                    inFirstWord = 1; 
            }
                
        }

        // middle of string case 
        else {
            if (i >= MAX) 
                printf("\n---\nERROR 2\n---\n"); // i should be < MAX in this case
            if (isWhiteSpace(c) && inFirstWord)
                inFirstWord = 0;
            line[i++] = c;
        }
    }
    // print the final line
    printf("%s\n", line);


    
        
        
        
        
        
    
    return 0;
}

void clearLine(char s[]) {
    for (int i = 0; i < MAX + 1; i++)
        s[i] = '\0';
}
void copyLine(char src[], char dest[]) {
    for (int i = 0; i < MAX + 1; i++)
        dest[i] = src[i];
}

int isWhiteSpace(char c) {
    if (c == ' ' || c == '\n' || c == '\t'){
        return 1;
    } else return 0;
}