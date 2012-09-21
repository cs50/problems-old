/**
 * tofahrenheit.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Converts a user-supplied temperature in Celsius to Fahrenheit and
 * prints the result with one decimal place.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for a temperature in Celsius
    printf("C: ");
    float celsius = GetFloat();

    // no need for typecasts with the proper order of operations
    float fahrenheit = ((celsius * 9) / 5) + 32;

    // .01 syntax prints just one decimal place
    printf("F: %.01f\n", fahrenheit);

    return 0;
}

