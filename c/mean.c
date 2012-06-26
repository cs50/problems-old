/*********************************************************
* mean.c
* Jackson Steinkamp
*
* Takes in a user-specified number of data points and 
* prints the average of all the points. 
*
* Demonstrates the differences between ints and floats, 
* iteration, for loops, and basic I/O. (What are some
* ways this code could be improved to better shield it 
* from an 'unfriendly user?')
**********************************************************/

#include<stdio.h>

// predetermined limit on maximum amount of data user can submit
#define MAX_POINTS 10

int
main(void)
{      
    // how many numbers the user will give you; initialized to zero
    int length = 0;

    // make sure user inputs a valid input length
    while (length < 1 || length > MAX_POINTS)
    {
       // scan the user's data set size into 'length'
       printf("How many data points are you averaging? It must be less than %d.\n", MAX_POINTS);
       scanf ("%d", &length);
    }

    // a placeholder to store the points as they are given, one by one
    float point;

    // the total of all the points the user has given so far
    float total = 0;

    // prompt the user for numbers to average
    printf("Please enter data points.\n");

    // until the user has given you all the points they said they would...
    for (int i = 0; i < length; i++)
    {
        //tell the user how many points they've entered so far
        printf("You've entered %d points so far. Please enter more.\n", i);

        // get the new number and add it to the cumulative total
        scanf("%f", &point);
        total = total + point;      
    }    
    // print the mean, which is just the total divided by the number of points
    float mean = total / (float) length;
    printf("The mean is %.2f\n.", mean);   
}
