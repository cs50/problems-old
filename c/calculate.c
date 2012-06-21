
/****************************************************************************
* calculate.c
*
* Computer Science 50
* Julia Mitelman
*
* Tip calculator based on user's desired %age.
*
* Demonstrates use of basic logic, define, float/int math, user input.
* Bug find:  there is at least one major error in this program.  Find it.
*
***************************************************************************/

#include <ctype.h>
#include <stdio.h>

#define MINTIP 15
#define MEDTIP 18
#define HIGHTIP 20

int
main (void) {
    int percentage;
    
    // initialize total to -1 so we can easily check for valid inputs
    float total = -1;
    
    // make sure total is a valid value
    while (total < 0) {
        // get total from user
        printf ("Total Bill:  ");
        scanf ("%f", &total);
    }
    
    // ensure tip is a valid value
    while (percentage != MINTIP && percentage != MEDTIP && percentage != HIGHTIP) {
        // get tip from user
        printf ("\nTip Percentage (15, 18, 20)? ");
        scanf ("%d", &percentage);
    }
    
    // calculate appropriate tip
    float tip = ((float) percentage / 100) * total;
    
    printf ("\nYour tip is: %2f!\n", tip);
    
}
