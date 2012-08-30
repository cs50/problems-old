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
  TERMINAL_A     = 0;
  TERMINAL_B     = 0;

  // Set time to shutdown for
  // STUDENT TODO
  POWER_DOWN_FOR = 0;

  // Using pin mode, set terminal and output 
  // STUDENT TODO
  pinMode();
  pinMode();
  
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
 
  // Write an if statement to read the terminal, if it's off, then turn on
  //STUDENT TODO
  if()

  if() 
=   
  /*****************************/
  a50.checkpoint(3);
  a50.checkpoint(4);
  /*****************************/
  
  // Forced delay for 5 seconds
  delay(5000);

  /*
   * OBJECTIVE TWO: SHUTDOWN POWER IN TERMINAL A 
   */
  // Shut down power for TERMINAL_A
  // STUDENT TODO
  
  /*****************************/
  a50.checkpoint(5);
  a50.checkpoint(6);
  /*****************************/
  
  // Set delay to the power down variable
  // STUDENT TODO
  delay();

  /*
   * OBJECTIVE THREE: SHUTDOWN POWER IN TERMINAL_B
   */
   
  // Shutdown power for TERMINAL_B 
  // STUDENT TODO
  
  
  /*****************************/
  a50.checkpoint(7);
  a50.checkpoint(8);
  /*****************************/

  // STUDENT TODO, delay five seconds before moving to the next building
  delay()

  /*
   * OBJECTIVE FOUR: TURN ON POWER IN TERMINALS A & B
   */
   
  // Turn power back on for both terminals
  // STUDENT TODO

  /*****************************/
  a50.checkpoint(9); 
  a50.output();
  /*****************************/
}

void loop() 
{
  // not applicable for this mission
}



