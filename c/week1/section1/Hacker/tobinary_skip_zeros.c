/**
 * tobinary_skip_zeros.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Prints a user-supplied non-negative integer in binary, skipping leading
 * 0s.
 */

#include <cs50.h>
#include <stdbool.h>
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

    // special case: no leading 1s, but we want to print a 0
    if (decimal == 0)
    {
        printf("0");
    }
    else
    {
        // use this to track when it's okay to print zeros (after first 1)
        bool print_zeros = false;

        // iterate over all bits in an int: use sizeof and don't assume 32
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
        {
            // an ith bit "mask" is all 0s with a 1 in the ith position
            int mask = (1 << i);

            // if this test succeeds, then the ith bit of "decimal" is 1
            if ((decimal & mask) != 0)
            {
                printf("1");
                print_zeros = true;
            }
            // only print a zero if we've already printed a 1
            else if (print_zeros)
            {
                printf("0");
            }
        }
    }
    printf("\n");

    return 0;
}
    
