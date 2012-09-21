/**
 * percent.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Prompts the user for a non-negative numerator and a positive
 * denominator and prints numerator / denominator as a percent with two
 * decimal places.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // why do we declare "numerator" before the loop?
    int numerator = 0;

    // prompt the user for a non-negative numerator [0, inf)
    do
    {
        printf("non-negative numerator: ");
        numerator = GetInt();
    }
    while (numerator < 0);


    // why do we declare "denominator" before the loop?
    int denominator = 0;

    // prompt the user for a positive denominator (0, inf)
    do
    {
        printf("positive denominator: ");
        denominator = GetInt();
    }
    while (denominator <= 0);

    // what happens if we don't cast "numerator" to a float? 
    float percent = ((float) numerator / denominator) * 100;

    // funky syntax here! % escapes %
    printf("%.02f%%\n", percent);

    return 0;
}

