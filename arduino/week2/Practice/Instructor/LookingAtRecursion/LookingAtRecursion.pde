/* Looking at Recursion!
 * Arduino Exploration Three
 * Author: Christopher Bartholomew
 * Course: CS50 
 *
 * In class experiment on how to interact with the arduino using C's functions and using LEDS to look at recursion / frame stacks
 * Goals:
 * - Using resursive functions as a method of iteration
 * - Seeing how functions execute on the stack visually, and how the variables become destroyed as they fall off the stack.
 * - Building a project using Multiple Lights defined in a global array
 * - Passing arrays by reference to other functions.
 */

// Define your LED to PIN Constant 
#define RED    8
#define ORANGE 9
#define YELLOW 10
#define GREEN  11
#define BLUE   12

// Define the Max number of lights we will be iterating through. This also acts as your base case.
#define MAX    5

//TODO: Create an array with MAX 
//BONUS: Make the below array into a 2D array or create an additional array with each color's indivudal duration time. 
int LIGHTS[MAX] = {RED, ORANGE, YELLOW, GREEN, BLUE }; 

void setup(){
    
   //Arduino's serial console init. 
   Serial.begin(9600);
   
   // let the arduino know that you will be utilizing the following PINS
   // TODO: create additional pinModes for the rest of the PINS. (Only Red Shown).
   pinMode(RED,       OUTPUT);
   pinMode(ORANGE,    OUTPUT);  
   pinMode(YELLOW,    OUTPUT); 
   pinMode(GREEN,     OUTPUT);
   pinMode(BLUE,      OUTPUT); 
   
   //TODO: Populate the parameters
   beginRecursiveLightCycle(MAX,0,LIGHTS);
      
}

/* beginRecursiveLightCycle
 * @param1 : length  - used against your "Base Case" - the length of the array, also known as "MAX"
 * @param2 : current - when iterating, we must always feed where the current index of the array.
 * Purpose : Recusive function which will turn on each light as it pushes onto the stack. The light will turn off as it falls off.
 * Bonus   : Create a new parameter (or use lights parameter) for an array that contains the each light's duration. 
 */
void beginRecursiveLightCycle(int length, int current, int *lights){

    //TODO/QUESTION: What's your base case? When do you stop? Write a conditional statement that will stop the recursion. 
    if (current == length) { return; }
    
    //Arduino's printf 
    Serial.println(lights[current]);      
    
    //TODO: Fill in the parameters for digitalWrite to turn the LED ON
    digitalWrite(lights[current], HIGH);
     
    //QUESTION: What is this here? What would happen if we didn't know this? 
    int c = current + 1;
    
    //TODO[OPTIONAL]: If you are doing bonus, this is where you would place the duration. 
    delay(2000);
    
    beginRecursiveLightCycle(length, c, lights);
    
    //TODO[OPTIONAL]: If you are doing bonus, this is where you would place the duration. 
    delay(2000);
    
    //TODO: Fill in the parameters for digitalWrite to turn the LED OFF
    //QUESTION: What is line representing in terms of variable scope?
    digitalWrite(lights[current], LOW);   
                                         
}


void loop(){
// not needed
}

