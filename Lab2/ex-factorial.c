/* This program reads a single integer from standard input then
 * computes its factorial. For example, if the user enters 5, the program
 * outputs 120 because 1*2*3*4*5=120. */

#include <stdio.h>

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(void)
{
    int n;
    long long result;

    if (scanf("%d", &n) != 1) {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    result = factorial(n);
    printf("%lld\n", result);
    return 0;
}
