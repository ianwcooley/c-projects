#include <stdio.h>

    /* Input: int */
    /* Output: prints reverse number
    and states whether palindrome or not */

void printPalindrome(unsigned int num);

int main() {

    unsigned int num;
    printf("Enter a number:\n");
    scanf("%u", &num);

    printPalindrome(num);
    

    return 0;
}

void printPalindrome(unsigned int num) {
    unsigned int origNum = num;
    unsigned int newNum = 0;
    unsigned int placeValue = 1;
    while (num > 0) {
        newNum *= 10;
        newNum += (num % 10);
        num /= 10;
    }
    printf("Reverse number:%u\n", newNum);
    if (newNum == origNum)
        printf("palindrome!!\n");
    else
        printf("not a palindrome :(\n");
}