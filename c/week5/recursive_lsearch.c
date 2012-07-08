/*******************************
* recursive_lsearch.c
*
* Jackson Steinkamp
* Computer Science 50
*
* A recursive version of linear search. 
* Demonstrates pointer traversal of arrays,
* a simple function, and basic recursion.
**********************************/

#include<stdbool.h>
#include<stdio.h>

/* Recursive helper function. 'check' is the integer
to be searched for within the array. arr_front is a 
pointer to the array's first element. 'left' is a parameter, 
changed on each stack frame, which measures how many
array slots there are left to check. It is decremented
on each recursive call. */

int
array_mem(int val_to_find, int *arr_front, int left)
{
    // If we're at (or, somehow, past) the end of the array
    if (left <= 1)
    {
       /* base case. return true ony if the element left in
       the array is the one we're looking for */
       return (*arr_front == val_to_find);
    }
    else 
    {
       // make a pointer that points to the rest of the array
       int *new_front = arr_front + 1;

       // decrement the number of elements left to search
       left--;

       /* if the head of the array holds the int we're looking for, or if 
       the rest of the array contains the int, return true */
       return (*arr_front == val_to_find || 
               array_mem(val_to_find, new_front, left));
    }
}

int
main(void)
{
  // an arbitrary test array
  int full_len = 3;
  int arr[full_len];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 5;
  
  // pointer to the head of the full array
  int *ptr = arr;

  // check to see if '5' is in the array (it is, clearly)
  if (array_mem(5, ptr, full_len))
     printf("5 is in the array.\n");
  else printf("5 isn't in the array.\n");

  // check to see if '32' is in the array (it isn't).
  if (array_mem(32, ptr, full_len))
     printf("32 is in the array.\n");
  else printf("32 isn't in the array.\n");

  return 0;
}

/**********************************************************************
* 1. What is the worst case asymptotic running time of array_mem
* proportional to the length of the array ('len')?
* 2. What's the best case asymptotic running time? Besides using
* a more efficient algorithm (like binary search!) how can this be optimized?
***********************************************************************/
