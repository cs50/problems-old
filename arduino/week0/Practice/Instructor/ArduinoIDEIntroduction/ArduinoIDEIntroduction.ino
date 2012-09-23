/**************************************************************************************
 * Arudino IDE
 *
 * Computer Science 50
 * Christopher Bartholomew
 *
 * Introduction to the IDE and a few library functions
 *
 * makes onboard Arduino LED Blink
 *************************************************************************************/
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  // TODO - Set Pin Mode
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  // TODO - Send "HIGH" to pin 13
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  //#16
  delay(1000);
  
  // TODO - Send "LOW" to pin 13  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  
  //#16
  delay(1000);
}
