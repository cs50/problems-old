/*********************************************
/ bounded_get.c
/ Jackson Steinkamp
/
/ Demonstrates basic decomposition of code
/ using a function with parameters. 
/
/ (Assumes the CS50 Library is still being used
/ to acquire inputs)
**********************************************/

#include<cs50.h>
#include<stdio.h>

/* This code can be decomposed using a function. 
* Using functions with arguments, 'clean up' this code 
* by abstracting out the common pattern. Replace the redundant 
* code in main with calls to your new function. */

int
main_nofunctions(void)
{
  // get the user's birth month, making sure it's a valid month
  int month;
  printf("What month were you born in?\n");
  while (month < 1 || month > 12)
  {
    printf("Please enter an integer between 1 and 12.\n");
    month = GetInt();
  }

  // get the user's birth date, making sure it's a valid day
  int day;
  printf("What day were you born on?\n");
  while (day < 1 || day > 31)
  {
    printf("Please enter an integer between 1 and 31.\n");
    day = GetInt();
  } 

  // give back the user's birthday
  printf("Your birthday is %d/%d.\n", month, day);
  return 0;

}


/******************/
    //ANSWER//
/******************/

/* This helper function makes it easy to get integers with bounds.
 the arguments 'min' and 'max', which get passed to this function,
 determine the bounds for the int that will get returned to the main function. */
int
getint_bounded(int min, int max)
{
  int x;

  // Make sure the user is 'cooperative' and gives numbers within your bounds
  while (x < min || x > max)
  {
    // Get an integer from the user
    printf("Please enter an integer between %d and %d.\n", min, max);
    x = GetInt();
  }

  // 'Return' the integer to the main function
  return x;
}

int
main(void)
{
  /* Get the user's birth month, using our helper function and 
  passing in '1' and '12' as the minimum and maximum, respectively. */
  printf("What month were you born in?\n");
  int month = getint_bounded(1, 12);

  /* Get the user's birth date, this time passing in appropriate bounds
  on the number of days in a month. */
  printf("What day were you born on?\n");
  int day = getint_bounded(1, 31);

  // Print the user's birthday.
  printf("Your birthday is %d/%d.", month, day);
  return 0;
}
