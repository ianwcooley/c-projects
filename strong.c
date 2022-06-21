#include <stdio.h>

/* Input: int */
/* Output: whether strong number or not */
/* A strong number, e.g. 145, 
is equal to the sum of its digits' factorials. 
145 = 1! + 4! + 5! */

int isStrong(unsigned int n);

int main() {

    unsigned int n;
    printf("Enter a number:\n");
    scanf("%u", &n);
    
    int arm = isStrong(n);
    if (arm)
        printf("Strong :)\n");
    else
        printf("Not Strong :'(\n");

    return 0;
}

int isStrong(unsigned int n) {
    
    // Calculate strong sum
    unsigned int sum = 0;
    unsigned int digit, summand, i;
    unsigned int num = n;
    while (num > 0) {
        summand = digit = num % 10;
        for (i = digit - 1; i > 0; i--)
            summand *= i;
        sum += summand;
        
        num /= 10;
    }
    printf("Sum: %u\n", sum);

    if (sum == n)
        return 1;
    else 
        return 0;
}