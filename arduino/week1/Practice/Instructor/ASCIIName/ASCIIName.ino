#include <arduino50.h>
/**************************************************************************************
 * ASCIIName
 *
 * Computer Science 50
 * Christopher Bartholomew
 *
 * Prints an array of ascii chars and numbers using Arduino50 library 
 *
 * Demonstrates use of 7 segment display, arrays, functions, parameter passing, #defines
 *************************************************************************************/
//TODO: avoid magic numbers by creating an "array" length constant for name and numbers
#define NAME_LEN 11
#define NUM_LEN  10

/* 
 * setup() function is the Arduino's equivalent to C's main().
 * For now, we tell it to call a "fake" version of main.
 */
void setup() { 
  
  //TODO: create an "array" of UPPERCASE chars that contain the ascii values of your name - use constant for length
  char name[NAME_LEN] =  {67,72,82,73,83,84,79,80,72,69,82};
  
  //TODO: create an "array" of "int" numbers 0-9
  int numbers[NUM_LEN] = {0,1,2,3,4,5,6,7,8,9};
  
  /* 
   * pinMode() is used to tell the arduino input pins to 
   * either listen for INPUT or OUTPUT. 
   */ 
   
  //TODO: From the schematic that you built, which pins must be set? What should they be set to (INPUT or OUTPUT)?
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  //TODO: call the function to showLetters()
  showLetters(name);
  
  //TODO: call the function to showNumbers()
  showNumbers(numbers);
  
}

/* void showLetters(char *letters)
 * @param1 an array of letters
 * using Arduino50 library function, write7_alpha(char), display your full name
 */ 
void showLetters(char *letters)
{
  //TODO: Using a loop, iterate through the letters array, displaying each character inside of it. 
  //TODO: Utilize arduino library function "delay()" to provide a some time between character displau
  for(int i=0;i<NAME_LEN;i++)
  {
     // writes out letters
      write7_alpha(letters[i]);
      
      // delays each letter
      delay(1000);
  }

}

/* void showLetters(char *letters)
 * @param1 an array of letters
 * using Arduino50 library function, write7_alpha(char), display your full name
 */ 
void showNumbers(int *numbers)
{
  //TODO: Using a loop, iterate through the numbers array, displaying each number inside of it. 
  //TODO: Utilize arduino library function "delay()" to provide a some time between character displau
  for(int i=0;i<NUM_LEN;i++)
  {
     // writes out numbers using write7_digit
      write7_digit(numbers[i]);
      
      // delays each letter
      delay(1000);
  }

}

void loop() {
  // Ignore the loop function for now!
}
