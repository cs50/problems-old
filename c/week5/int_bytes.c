/************************************************
* int_bytes.c
*
* Rob Bowden
* Computer Science 50
*
* Write a function to print out the individual
* bytes in the user-supplied integer, 1 per line
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int
main(void)
{
    int x = GetInt();

    /**
     * Loop over the bytes in int x, printing out each individual byte
     *
     * Fill in the two ssets of question marks to complete the problem
     * Remember that an integer might have a different number of bytes,
     * depending on what system you are working on. This is a hint for
     * the first set of question marks!
     */
    for (int i = 0; i < ???; i++)
    {
        /**
         * remember that a char is always exactly 1 byte, and so we
         * can use a char* to point to a single byte within an integer
         *
         * fill in the question marks so that c points to the i'th byte
         * in the integer x
         */
        char* c = ???;

        // print out the byte
        printf("%x\n", *c);
    }
}
