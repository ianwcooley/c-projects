#include <stdio.h>

/* Input: int */
/* Output: whether armstrong number or not */
/* An armstrong number, e.g. 153, which is of order 3,
    is equal to the sum of each of its digits raised to the order.
    153 = 1^3 + 5^3 + 3^3. */

int isArmstrong(unsigned int n);

int main() {

    unsigned int n;
    printf("Enter a number:\n");
    scanf("%u", &n);
    
    int arm = isArmstrong(n);
    if (arm)
        printf("Armstrong :)\n");
    else
        printf("Not Armstrong :'(\n");

    return 0;
}

int isArmstrong(unsigned int n) {
    
    // Get order of number
    unsigned int order = 0;
    unsigned int num = n;
    while (num > 0) {
        order += 1;
        num /= 10;
    }
    // printf("Order: %u\n", order);
    
    // Calculate armstrong sum
    unsigned int sum = 0;
    unsigned int digit, summand, i;
    num = n;
    while (num > 0) {
        summand = digit = num % 10;
        for (i = 0; i < order - 1; i++)
            summand *= digit;
        sum += summand;
        
        num /= 10;
    }
    // printf("Sum: %u\n", sum);

    if (sum == n)
        return 1;
    else 
        return 0;
}