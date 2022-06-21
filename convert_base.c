#include <stdio.h>

/* Input: a number, its base (2-20), and the desired base */
/* Output: a string of the number in the desired base */

#define MAX 100 // maximum length of string to read or write

void reverseString(char s[]);
    
int main() {

    // num1: string of number, num2: string of desired number
    char num1[100] = {'\0'}, num2[100] = {'\0'}; 
    unsigned long n1 = 0; // actual number
    // b1: base, b2: desired base
    unsigned long b1, b2;

    int uppercase = 0, lowercase= 0;
    

    printf("ONLY BASES 1-20\n");
    printf("---\n");
    printf("Enter number: ");
    scanf("%s", num1);
    printf("Enter base of number: ");
    scanf("%lu", &b1);
    printf("Enter desired base: ");
    scanf("%lu", &b2);
    
    int i = 0, digit;

    while (num1[i] != '\0') {
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit = num1[i] - '0';
        } else if (b1 > 10 && num1[i] >= 'A' && num1[i] <= 'A' + b1 - 11) {
            digit = num1[i] - 'A' + 10;
            uppercase = 1;
        } else if (b1 > 10 && num1[i] >= 'a' && num1[i] <= 'a' + b1 - 11) {
            digit = num1[i] - 'a' + 10;
            lowercase = 1;
        } else {
            printf("ERROR: Invalid number entered.\n");
            return 0;
        }

        n1 = b1 * n1 + digit;
        i++;
    }

    i = 0;
    while (n1 > 0) {
        digit = n1 % b2;
        if (digit < 10) {
            num2[i] = '0' + digit;
        } else if (digit >= 10 && lowercase) {
            num2[i] = 'a' + digit - 10;
        } else if (digit >= 10) {
            num2[i] = 'A' + digit - 10;
        } else {
            printf("ERROR: Something is terribly wrong. :O\n");
            return 0;
        }
        n1 /= b2;
        if (++i >= MAX) {
            printf("ERROR: Desired number is too long.\n");
            return 0;
        }
    }

    reverseString(num2);

    printf("Number in desired base: %s\n", num2);

    return 0;
}

void reverseString(char s[]) {
    int length = 0;
    while (s[length] != '\0') 
        length++;
    int i; 
    char temp;
    for (i = 0; i < length / 2; i++) {
        temp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = temp;
    }

}