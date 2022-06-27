
/* Recursive Function Practice */

#include <stdio.h>

#define MAX 100

void printd(int n);
void itoa(char s[], int n);
void reverse(char s[], int left, int right);

int main() {

    /* test of printd */
    printd(12345);
    printf("\n");

    /* test of itoa */
    char s[100];
    itoa(s, 12345);
    printf("%s\n", s);
    
    /* test of reverse */
    char t[6] = "123456";
    reverse(t, 0, 5);
    printf("%s\n", t);

    return 0;
}

/* printd: print n in decimal */
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* itoa: convert integer n to string s */
void itoa(char s[], int n) {
    static int i = 0;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(s, n / 10);
    s[i++] = (n % 10 + '0');
    s[i] = '\0';
}

/* reverse: reverse string s in place */
void reverse(char s[], int left, int right) {

static int temp;

if (left >= right)
    return;

temp = s[right];
s[right] = s[left];
s[left] = temp;

reverse(s, left + 1, right - 1);

}