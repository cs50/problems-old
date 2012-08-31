#include <arduino50.h>

// instantiate new arduino50 instance 
Arduino50 a50(0);

// globalize terminal variables
int TERMINAL_A, TERMINAL_B, POWER_DOWN_FOR = 0;

void setup()
{
  // begin serial console
  Serial.begin(9600);

  /*
   * OBJECTIVE ZERO: TERMINAL CONFIGURATION
   */
   
  // STUDENT TODO, set pins
  TERMINAL_A     = 11;
  TERMINAL_B     = 12;

  // STUDENT TODO, set time to shutdown for
  POWER_DOWN_FOR = 10000;

  // STUDENT TODO, using pin mode, set terminal and output 
  pinMode(TERMINAL_A,  OUTPUT);
  pinMode(TERMINAL_B,  OUTPUT);
  
  /*******************************/
  a50.set_pin(TERMINAL_A);
  a50.checkpoint(0);
  
  a50.set_pin(TERMINAL_B);
  a50.checkpoint(1);
  
  a50.set_number(POWER_DOWN_FOR);
  a50.checkpoint(2);
  /*******************************/
  
  // execute the mission
  execute_mission();  
}

void execute_mission()
{

  /*
   * OBJECTIVE ONE: CONFIRM PINS ARE ON
   */
  //STUDENT TODO, write an if statement to read the terminal, if it's off, then turn on
  if(digitalRead(TERMINAL_A) == LOW)
    digitalWrite(TERMINAL_A,HIGH);

  if(digitalRead(TERMINAL_B) == LOW) 
    digitalWrite(TERMINAL_B,HIGH);
    
  /*****************************/
  a50.checkpoint(3);
  a50.checkpoint(4);
  /*****************************/
  
  // Forced delay for 5 seconds
  delay(5000);

  /*
   * OBJECTIVE TWO: SHUTDOWN POWER IN TERMINAL A 
   */
  // STUDENT TODO, shut down power for TERMINAL_A
  
  digitalWrite(TERMINAL_A,LOW);
  
  /*****************************/
  a50.checkpoint(5);
  a50.checkpoint(6);
  /*****************************/

  // STUDENT TODO, set delay to your power down variable
  delay(POWER_DOWN_FOR / 2);

  /*
   * OBJECTIVE THREE: SHUTDOWN POWER IN TERMINAL_B
   */
  // STUDENT TODO, shutdown power for TERMINAL_B
  digitalWrite(TERMINAL_B,LOW);
  
  /*****************************/
  a50.checkpoint(7);
  a50.checkpoint(8);
  /*****************************/

  // STUDENT TODO, 
  delay(POWER_DOWN_FOR / 2);

  /*
   * OBJECTIVE FOUR: TURN ON POWER IN TERMINALS A & B
   */
   
  // STUDENT TODO, turn power back on for both terminals
  digitalWrite(TERMINAL_A,HIGH);
  digitalWrite(TERMINAL_B,HIGH);
  
  /*****************************/
  a50.checkpoint(9); 
    /*****************************/
  a50.output();
}

void loop() 
{
  // not applicable for this mission
}



