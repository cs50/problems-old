/**
 * toupper_bitwise.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Converts a user-supplied lowercase letter to uppercase using binary
 * operators.
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

    // flip the bit in the 2^5th position to convert to uppercase
    printf("%c\n", lower ^ (1 << 5));

    return 0;
}

