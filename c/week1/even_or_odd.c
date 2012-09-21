/**
 * even_or_odd.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Determines whether or not a user-provided number is even or odd.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = GetInt();

    if (n % 2 == 0)
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
}
