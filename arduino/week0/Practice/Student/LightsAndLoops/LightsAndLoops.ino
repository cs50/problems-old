/* Lights And Loops!
 * Arduino Exploration One
 * Author: Christopher Bartholomew
 * Course: CS50 
 *
 * In class experiment on how to interact with the arduino using C's standard loops and conditional operators.
 * Goals:
 * - Understanding constants by #define
 * - Variable Initialization
 * - Functions and Parameters
 * - Using Ternary operators
 * - Interfacing basic code with hardware using Arduino Microcontroller
 */

// constant pin to LED mapping
#define r_led_pin 8
#define y_led_pin 9
#define g_led_pin 10

// The arduino's version of int main(void)
void setup(){
  
// prepare the Arduino's pins to allow output on specific pins
pinMode();  
pinMode();  
pinMode();  

// 1000 milliseconds = 1 second
int led_duration  = ;
// Amount of times you wish to itterate 
int max_interval  = ;

// initialize the serial connection
Serial.begin(9600);

// run FOR loop just for red led
doForLoop(max_interval,led_duration);

// run WHILE loop w/ any led
doWhileLoop(max_interval,led_duration,y_led_pin);

// run DO WHILE loop w/ any led
doDoWhileLoop(max_interval,led_duration);

}

/* doForLoop
 * @param1 : interval - used for the amount of times the for loop will iterate
 * @param2 : duration - used for the amount of time in milliseconds before light will turn on or off
 * Purpose : Using a FOR loop and if statement, write a loop that turns the light on or off. 
 * Bonus   : Instead of a regular if / else statement, try using a ternary operator. 
 */
void doForLoop(int interval, int duration)
{
  // TODO: Create a for loop that will iterate through the intervals
  for(){
   
    //TODO: Using digitalRead(LED) Write a conditional statement that will check the value)
    if ()  
        digitalWrite();
    else  
        digitalWrite();
  
    // QUESTION: How could you do the same using a ternary operator? 
    // Bonus! ternary operator version
    (digitalRead(r_led_pin) == HIGH) ? //True : //False ; 
    
    // Arduino's printf
    //Serial.println(i);
    
    // how long should the light delay for before moving to the next?
    delay();
  }

}

/* doWhileLoop
 * @param1 : interval - used for the amount of times the for loop will iterate
 * @param2 : duration - used for the amount of time in milliseconds before light will turn on or off
 * Purpose : Using a WHILE loop and if/else statement or ternary operator, write a loop that turns any led on or off. 
 * Bonus   : if the led is not "yellow", exit function.
 */
void doWhileLoop(int interval, int duration, int led)
{
  // TODO: Create a while loop that will turn any LED on or Off.
  int i=0;
  
  //Bonus!
  if (led != ) 
    return;
  
  while(){
   
    //TODO: Using digitalRead(LED) Write a conditional statement that will check the value)
    //QUESTION: Why are brackets not needed?
    if (digitalRead(led) == HIGH)  
      digitalWrite(led, LOW);
    else  
      digitalWrite(led, HIGH);

    // ternary operator version
    () ? : ; 
    
    // Arduino's printf
    //Serial.println(led);
    
    // how long should the light delay for before moving to the next?
    delay();
   
   // increase i's value to eventually meet the interval
   i++; 
  }
  
}

/* doDoWhileLoop
 * @param1 : interval - used for the amount of times the for loop will iterate
 * @param2 : duration - used for the amount of time in milliseconds before light will turn on or off
 * Purpose : Using a DO WHILE loop and if/else statement or ternary operator, write a loop that turns any led on or off. 
 * Bonus   : alternate between green and red
 */
void doDoWhileLoop(int interval, int duration)
{
  // initialize i to zero
  int i = 0;
  
  //TODO: Write a do while loop, how does it differ from the while loop if the interval was zero?
  do
  {
    // QUESTION: Why do I need brackets with the bonus example? 
    if (digitalRead(r_led_pin) == HIGH) {
        digitalWrite();
        digitalWrite(); // BONUS!
    } else {
        digitalWrite(); 
        digitalWrite();  // BONUS!
    }
    
    // Arduino's printf
    //Serial.println(i);
    
    // how long should the light delay for before moving to the next?
    delay();
    
    //QUESTION: What would happen if this was not here?
    i++;
    
  } while();
  
}

// standard set up for an arduino - "forever" or endless loop.
void loop() {
  //Empty on purpose
}
