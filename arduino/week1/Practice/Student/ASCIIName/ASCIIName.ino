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

/* 
 * setup() function is the Arduino's equivalent to C's main().
 */
void setup() { 
  
  //TODO: create an "array" of UPPERCASE chars that contain the ascii values of your name - use constant for length
  
  //TODO: create an "array" of "int" numbers 0-9
  
  /* 
   * pinMode() is used to tell the arduino input pins to 
   * either listen for INPUT or OUTPUT. 
   */ 
   
  //TODO: From the schematic that you built, which pins must be set? What should they be set to (INPUT or OUTPUT)?
  
  //TODO: call the function to showLetters()
  showLetters();
  
  //TODO: call the function to showNumbers()
  showNumbers();
  
}

/* void showLetters(char *letters)
 * @param1 an array of letters
 * using Arduino50 library function, write7_alpha(char), display your full name
 */ 
void showLetters(char *letters)
{
  //TODO: Using a loop, iterate through the letters array, displaying each character inside of it. 
  //TODO: Utilize arduino library function "delay()" to provide a some time between character display

}

/* void showLetters(char *letters)
 * @param1 an array of letters
 * using Arduino50 library function, write7_alpha(char), display your full name
 */ 
void showNumbers(int *numbers)
{
  //TODO: Using a loop, iterate through the numbers array, displaying each number inside of it. 
  //TODO: Utilize arduino library function "delay()" to provide a some time between character displau

}

void loop() {
  // Ignore the loop function for now!
}
