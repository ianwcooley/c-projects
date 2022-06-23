#include <stdio.h>
#include <ctype.h>

/* Input: a string representing a double */
/* Output: the double as a number */

#define MAX 50

double atof(char s[]);

int main() {

    char s[MAX] = {'\0'};
    printf("Enter string representing double:\n");
    scanf("%s", s);

    printf("%lf\n", atof(s));
    
    return 0;
}

double atof(char s[]) {
    double val, power, exp; // exp: exponent
    int i, sign, expsign;

    for (i = 0; isspace(s[i]); i++) /* skp white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    // support for scientific notation
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp = 0.0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');

    if (expsign == -1)
        for (int j = 0; j < exp; j++)
            val /= 10.0;
    else
        for (int j = 0; j < exp; j++)
            val *= 10.0;
    

    return sign * val / power;
}