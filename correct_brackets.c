#include <stdio.h>

/* Input: files that use (), [], and/or {} to form nested expressions*/
/* Output: checks for syntax errors. prints first error, if found */
/* Drawback: Can only check expressions 1000 levels deep */

int main() {

    // as go through, keep track of where we are with (x,y)
    // y: line #
    // x: character in line y
    int x = 0, y = 0;
    char currentLvl[1000];
    int i = -1; // index for currentLevel

    int parLvl = 0, // how many ( levels deep are we?
        boxLvl = 0, // how many [ levels deep are we?
        braLvl = 0; // how many { levels deep are we?
    
    char c;
    while((c = getchar()) != EOF) {
        if (i >= 999) {
            printf("ERROR: too many levels of nesting. cannot compute.\n");
            return 0;
        }
        switch (c) {
        // enter next ( level
        case '(':
            parLvl++;
            currentLvl[++i] = '(';
            break;
        // enter next [ level
        case '[':
            boxLvl++;
            currentLvl[++i] = '[';
            break;
        // enter next { level
        case '{':
            braLvl++;
            currentLvl[++i] = '{';
            break;
        case ')':
            if (parLvl <= 0)  {
                printf("Line %d.%d : Too many right parentheses: )\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '(') {
                parLvl--;
                currentLvl[i--] = 0;
            } else if (currentLvl[i] == '[') {
                printf("Line %d.%d : Expecting ] but got )\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '{') {
                printf("Line %d.%d : Expecting } but got )\n", y+1, x+1);
                return 0;
            } else {
                printf("ERROR - this should not happen.\n");
                return 0;
            }
            break;
        case ']':
            if (boxLvl <= 0) {
                printf("Line %d.%d : Too many right boxes: ]\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '[') {
                boxLvl--;
                currentLvl[i--] = 0;
            } else if (currentLvl[i] == '(') {
                printf("Line %d.%d : Expecting ) but got ]\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '{') {
                printf("Line %d.%d : Expecting } but got ]\n", y+1, x+1);
                return 0;
            } else {
                printf("ERROR - this should not happen.\n");
                return 0;
            }
            break;
        case '}':
            if (braLvl <= 0) {
                printf("Line %d.%d : Too many right brackets: }\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '{') {
                braLvl--;
                currentLvl[i--] = 0;
            } else if (currentLvl[i] == '(') {
                printf("Line %d.%d : Expecting ) but got }\n", y+1, x+1);
                return 0;
            } else if (currentLvl[i] == '[') {
                printf("Line %d.%d : Expecting ] but got }\n", y+1, x+1);
                return 0;
            } else {
                printf("ERROR - this should not happen.\n");
                return 0;
            }
            break;
        default:
            break;
        }

        // increment indices
        if (c =='\n') {
            y++;
            x = 0;
        } else {
            x++;
        }

    }

    if (i >= 0) {
        switch (currentLvl[i])
        {
        case '(':
            printf("Unclosed paranthesis: (\n");
            return 0;
        case '[':
            printf("Unclosed box: [\n");
            return 0;
        case '{':
            printf("Unclosed bracket: {\n");
            return 0;
        default:
            return 0;
        }
    }

    printf("No errors! congrats :)\n");
    
    return 0;
}

