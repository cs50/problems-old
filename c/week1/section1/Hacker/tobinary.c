/**
 * tobinary.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Prints a user-supplied non-negative integer in binary.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt for a non-negative integer [0, inf)
    int decimal = 0;
    do
    {
        printf("Enter a non-negative integer: ");
        decimal = GetInt();
    }
    while (decimal < 0);

    // iterate over all bits in an int: use sizeof and don't assume 32
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        // an ith bit "mask" is all 0s with a 1 in the ith position
        int mask = (1 << i);

        // if this test succeeds, then the ith bit of "decimal" is 1
        if ((decimal & mask) != 0)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}
 
