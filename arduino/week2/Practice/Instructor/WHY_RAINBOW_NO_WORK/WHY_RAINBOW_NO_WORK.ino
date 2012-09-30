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

// BONUS - ppound define pin numbers to the actual colors, replace nums in pins w/ them
#define RED    2
#define ORANGE 4
#define YELLOW 6
#define GREEN  8
#define BLUE   10
#define INDIGO 12

void setup()
{
  
  // You're rainbox is broken, only sorting it will fix it
  int pins[SIZE] = {12,4,2,10,6,8};
  
  // TODO -  Enable pinMode() for each pin, going to OUTPUT
  for(int i=0;i<=SIZE;i++)
    pinMode(pins[i],OUTPUT);
  
  // TODO - show the rainbow, by passing in first parameter the array and the second parameter HIGH/LOW
  rainbow(pins,HIGH);
  
  // TODO - turn off your rainbow
  rainbow(pins,LOW);
  
  // TODO - Use one of the three methods to Sort the Rainbow
  //bubble_sort(pins, SIZE);
  selection_sort(pins, SIZE);
  //merge_sort(pins, SIZE);
  
  // anticpiation
  delay(2000);
  
  // TODO - is the rainbow fixed?
  rainbow(pins, HIGH);
  
  rainbow(pins, LOW);
  // anticpiation
  delay(2000);
  
  // BONUS - implement pick_my_color(COLOR,RAINBOW,SIZE) using binary search
  // Remeber! Binary Search will need a "Sorted" array!
  pick_my_color(BLUE,pins,SIZE);
 
 }

void rainbow(int *pins, int power)
{
  // TODO - turn on the Broken Rainbow, using digitalWrite - for each pin - setting it to high
  for(int i=0;i<=SIZE;i++) 
  {   
    // TODO - Turn on each LED in the rainbow array
      digitalWrite(pins[i], power); 
    
      // TODO if power is HIGH - delay for 3 seonds
      if(power==HIGH)
        delay(1000);
    
  }
}

void bubble_sort(int *pins, int size)
{
  // TODO - Bubble Sort
  for (int i = 0; i < size; i++)
  {
        // as the big values "bubble" to the end of the array, we only have to
        // focus on the first size - i values (-1 to accommodate array[j + 1])
        for (int j = 0; j < size - i - 1; j++)
        {
            // swap if the next element in the array is smaller
            if (pins[j] > pins[j + 1])
            {
                int temp = pins[j];
                pins[j]  = pins[j + 1];
                pins[j + 1] = temp;
            }
        }
    }
}

/* merge_sort(int*, int)
 * @param1: a reference to pins
 * @param2: size of array
 * purpose: sorts the array using selection sort
 */
void selection_sort(int *pins, int size)
{
   // TODO - Selection Sort
   for (int i = 0; i < size; i++)
   {
        // as the big values "bubble" to the end of the array, we only have to
        // focus on the first size - i values (-1 to accommodate array[j + 1])
        for (int j = 0; j < size - i - 1; j++)
        {
            // swap if the next element in the array is smaller
            if (pins[j] > pins[j + 1])
            {
                int temp = pins[j];
                pins[j] = pins[j + 1];
                pins[j + 1] = temp;
            }
        }
    }
}
/* merge_sort(int*, int)
 * @param1: a reference to pins
 * @param2: size of array
 * purpose: sorts the array using merge sort / recurison
 */
void merge_sort(int* pins, int size)
{
    // base case! array is guaranteed to be sorted
    if (size < 2)
        return;

    // split the list and create copies of each half
    int mid = size / 2;

    int left[mid];
    for (int i = 0; i < mid; i++)
        left[i] = pins[i];

    // make sure you start this for loop at 0 too, not at mid!
    int right[size - mid];
    for (int i = 0; i < size - mid; i++)
        right[i] = pins[mid + i];

    // recurrecurrecur...sionsionsion!
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // merge the lists back into array
    int left_index = 0, right_index = 0;
    for (int i = 0; i < size; i++)
    {
        // be careful to not index out of bounds!
        if (left_index < mid && right_index < size - mid)
        {
            if (left[left_index] <= right[right_index])
                pins[i] = left[left_index++];
            else
                pins[i] = right[right_index++];
        }
        else if (left_index >= mid)
        {
            pins[i] = right[right_index++];
        }
        else
        {
            pins[i] = left[left_index++];
        }
    }
}

/* pick_my_color(int,int*,size)
 * using binary search, displays the person's color
 * @param1: the color(pin)
 * @param2: a reference to the pins
 * @param3: a size reference
 * purpose: picks the user colors
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

        // return if we've found a match!
        if (rainbow[mid] == color)
            return digitalWrite(color,HIGH);

        // gotta look in the upper half of the array
        else if (rainbow[mid] < color)
            low = mid + 1;

        // gotta look in the lower half of the array
        else
            high = mid - 1;
    }
}

void loop()
{
   // ignore for now
}
