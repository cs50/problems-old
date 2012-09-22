/**
 * swap.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Swaps two user-provided integers without using a temporary variable.
 */

 #include <cs50.h>
 #include <stdio.h>

int main(void)
{
    printf("x: ");
    int x = GetInt();

    printf("y: ");
    int y = GetInt();

    printf("x is %d\n", x);
    printf("y is %d\n", y);

    // you gotta see it to believe it!
    x ^= y;
    y ^= x;
    x ^= y;

    printf("x is %d\n", x);
    printf("y is %d\n", y);

    return 0;
}

