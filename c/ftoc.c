
/************************************************************************************
* ftoc.c
*
* Computer Science 50
* Julia Mitelman
*
* Converts F to C.
*
* Demonstrates use of math, argc.
*
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARGCS 2

int
main (int argc, char *argv[]) {    
    
    // make sure we supplied the right # of args
    if (argc != ARGCS) {
        printf ("Please include the F temp.\n");
        // exit with error
        return 1;
    }
    
    // convert string input into int
    int ftemp = atoi(argv[1]);
    
    // convert F to C
    int ctemp = (ftemp - 32) * 5/9;
    
    printf ("The  temperature in Celsius is %d degrees.\n", ctemp);       
}
