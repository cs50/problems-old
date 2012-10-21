/****************************************************************************
 * WHY_RAINBOW_NO_WORK
 *
 * Computer Science 50
 * Christopher Bartholomew
 * Sort Solutions created by: Nate Hardison 
 *
 * The rainbow creator is broken! Someone messed up all the pin locations in
 * the array, can you sort the array to fix it?
 *
 * Demonstrates use of sorts and binary searches
 * 
 * BONUS:
 * 1. Use #defines for colors
 * 2. Implement pick_my_color using binary search!
 ***************************************************************************/

#include <arduino50.h>
#define SIZE 6

// BONUS - pound define pin numbers to the actual colors, replace nums in pins w/ them
// NEEDED FOR BINARY SEARCH
// #define RED    2


void setup()
{
  
  // You're rainbox is broken, only sorting it will fix it
  int pins[SIZE] = {12,4,2,10,6,8};
  
  // TODO -  Enable pinMode() for each pin, going to OUTPUT
  
  // TODO - show the rainbow, by passing in first parameter the array and the second parameter HIGH/LOW
  rainbow(param1, param2);
  
  // TODO - turn off your rainbow
  rainbow(param1, param2);
  
  // TODO - pick one of the three methods to implement.
  // bubble_sort(pins, SIZE);
  // http://en.wikipedia.org/wiki/Bubble_sort
  
  // selection_sort(pins, SIZE);
  // http://en.wikipedia.org/wiki/Selection_sort
  
  // merge_sort(pins, SIZE);
  //http://en.wikipedia.org/wiki/Merge_sort
  
  
  // create anticpiation
  delay(2000);
  
  // TODO - light our rainbow up again by calling its function with the correct param
  rainbow(param1, param2);
  
  // TODO - turn off our rainbow to prepare for binary search
  rainbow(param1, param2);
  
  // create anticpiation
  delay(2000);
  
  // BONUS - implement pick_my_color(COLOR,RAINBOW,SIZE) using binary search
  // Remeber! Binary Search will need a "Sorted" array! Pass in a COLOR as a parameter
  // pick_my_color(BLUE,pins,SIZE);
 
 }

void rainbow(int *pins, int power)
{
  // TODO - turn on the Broken Rainbow, using digitalWrite - for each pin - setting it to high
  for(int i=0;i<=SIZE;i++) 
  {   
     // TODO - Turn on each LED in the rainbow array ( digitalWrite(x,y) )
     
    
     // TODO if power is HIGH - delay for 1 seonds    
  }
  
}

/* bubble_sort(int*, int)
 * @param1: a reference to pins
 * @param2: size of array
 * purpose: sorts the array using bubble sort
 * http://en.wikipedia.org/wiki/Bubble_sort
 */
void bubble_sort(int *pins, int size)
{
  // TODO - Bubble Sort
  for (int i = 0; i < size; i++)
  {
        // as the big values "bubble" to the end of the array, we only have to
        // focus on the first size - i values (-1 to accommodate array[j + 1])
        for (int j = 0; j < size - i - 1; j++)
        {
          // TODO
        }  
    }
}

/* selection_sort(int*, int)
 * @param1: a reference to pins
 * @param2: size of array
 * purpose: sorts the array using selection sort
 * http://en.wikipedia.org/wiki/Selection_sort
 */
void selection_sort(int *pins, int size)
{
    // TODO - Selection Sort
    for (int i = 0; i < size; i++)
    {
        int min = i;
        // TODO
        // find the index of the minimum value in the array

        // if the index of the min value is not i, swap so that the min value
        // goes into the array at index i.

    }
}
/* merge_sort(int*, int)
 * @param1: a reference to pins
 * @param2: size of array
 * purpose: sorts the array using merge sort / recurison
 * http://en.wikipedia.org/wiki/Merge_sort
 */
void merge_sort(int* pins, int size)
{
    // base case! array is guaranteed to be sorted

    // split the list and create copies of each half

    // make sure you start this for loop at 0 too, not at mid!

    // Some recursion goes here, BTW
    // merge_sort left 
    
    // merge_sort right

  
    // reset the index to zero for each half
    int left_index = 0, right_index = 0;
    
    // create a for loop to merge the lists back into array
    for (int i = 0; i < size; i++)
    {
        // be careful to not index out of bounds!
        

    }
    
}

/* pick_my_color(int,int*,size)
 * using binary search, displays the person's color
 * @param1: the color(pin)
 * @param2: a reference to the pins
 * @param3: a size reference
 * purpose: picks the user colors
 * http://en.wikipedia.org/wiki/Binary_search_algorithm
 */
void pick_my_color(int color, int* rainbow, int size)
{

    int low = 0;
    int high = size - 1;
    
    while (low <= high)
    {
        // calculate the midpoint of the array
        // cast to unsigned int to avoid overflow if array is big enough
        // http://googleresearch.blogspot.com/2006/06/extra-extra-read-all-about-it-nearly.html
        int mid = ((unsigned int)low + (unsigned int)high) >> 1;

        // turn on the selected light if we've found a match


        // gotta look in the upper half of the array


        // gotta look in the lower half of the array
   
    }
}

void loop()
{
   // ignore for now
}
