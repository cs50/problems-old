/**
 * toupper.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Converts a user-supplied lowercase letter to uppercase without using
 * binary operators.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for a lowercase letter
    char lower = 'a';
    do
    {
        lower = GetChar();
    }
    while (lower < 'a' || 'z' < lower);

    // in ASCII, the uppercase letters are 32 before the lowercase letters
    printf("%c\n", lower - 32);

    return 0;
}

