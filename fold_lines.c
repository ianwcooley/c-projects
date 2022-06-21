#include <stdio.h>

/* Input: text file */
/* Output: prints text file with lines "folded" 
    after maximum character length of MAX */

#define MAX 30

#define IN 1
#define OUT 0

void clearLine(char line[]);

int main() {

    char line[2*MAX] = {'\0'};
    char newLine[2*MAX] = {'\0'};
    char c;
    int i = 0, j = 0;
    while ((c=getchar()) != EOF) {
      
        // Case 1
        // If we reach a break in the text, check to see if we are above the line limit.
        if (c == ' ' || c == '\n' || c == '\t' || c == '\b') {
            // Are we above the line limit?
            if (i >= MAX) {
                // If so, back up until the previous break.
                while (line[--i] != ' ' && line[i] != '\t' && line[i] != '\b')
                     ;
                // Replace that break with a null character.
                line[i] = '\0';
                // Then we fill the next line with the overlapping word,
                // and we overwrite the word in the current line with '\0'.
                while (line[++i] != '\0') {
                    newLine[j++] = line[i];
                    line[i] = '\0';
                }
                newLine[j] = ' ';
                // Print the line, reset indices, and clear the line.
                printf("%s\n", line); 
                i = j = 0;
                clearLine(line);
                // Fill line with overlapping word from newLine and clear newLine.
                // Notice we are incrementing i.
                while (newLine[j] != '\0')
                    line[i++] = newLine[j++];
                clearLine(newLine);
                // Reset j index
                j = 0;
            } 
            // If we are not above the line limit, but have reached a new line,
            // print the line, clear it, and reset i to 0.
            else if (c == '\n') {
                printf("%s\n", line);
                clearLine(line);
                i = 0;
            }
            // Otherwise, add the break character to the line.
            else {
                line[i++]= c;
            }
        } 

        // Case 2
        // If we don't reach a break, add the next character to the line.
        else {
            line[i++] = c;
        }
    }
    
    // In case the last character of the text doesn't end in '\n'
    if (line[0])
        printf("%s\n", line);

    
    return 0;
}

void clearLine(char line[]) {
    int i;
    for (i = 0; i < 2 * MAX; i++) {
        line[i] = '\0';
    }
}
