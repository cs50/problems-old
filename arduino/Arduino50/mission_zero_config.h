/*
 * mission_zero_config.h - Library for Harvard CS50 Arduino
 * Created by Christopher M. Bartholomew, August 11, 2012.
 * Released into the public domain.
 * Purpose - because arduino doesn't have a file system, I have to store each set of solutions within this header file.
 * each mission will contain its own header file that will have this information inside of it.
 */
#ifndef missionzero_h
#define missionzero_h
#include "Arduino.h"

// message of the day
String _MISSION_ZERO_ = "everything has a moral";

// max questions in this config
#define MISSION_ZERO_Q_AMOUNT		  10;

// CHECKPOINT ZERO
#define MISSION_ZERO_0_NUM   	 	  0;
#define MISSION_ZERO_0_PIN   	 	  12;
#define MISSION_ZERO_0_VAL   	 	  HIGH;
#define MISSION_ZERO_0_TYPE   	 	  PIN;
#define MISSION_ZERO_0_IS_CHALLENGE   false;
#define MISSION_ZERO_0_ERROR   		  "CHECKPOINT 0: TERMINAL_A isn't configured - check TERMINAL_A's pin definition!";
#define MISSION_ZERO_0_HASH   		  _MISSION_ZERO_;
                                      
// CHECKPOINT ONE                     
#define MISSION_ZERO_1_NUM   	 	  1;
#define MISSION_ZERO_1_PIN   	 	  13;
#define MISSION_ZERO_1_VAL   	 	  HIGH;
#define MISSION_ZERO_1_TYPE   	 	  PIN;
#define MISSION_ZERO_1_IS_CHALLENGE   false;
#define MISSION_ZERO_1_ERROR   		  "CHECKPOINT 1: TERMINAL_B isn't configured - check TERMINAL_B's pin definition!";
#define MISSION_ZERO_1_HASH   		  _MISSION_ZERO_;
                                      
// CHECKPOINT TWO                     
#define MISSION_ZERO_2_NUM   	 	  2;
#define MISSION_ZERO_2_PIN   	 	  13;
#define MISSION_ZERO_2_VAL   	 	  10000;
#define MISSION_ZERO_2_TYPE   	 	  NUMBER;
#define MISSION_ZERO_2_IS_CHALLENGE   false;
#define MISSION_ZERO_2_ERROR   		  "CHECKPOINT 2: POWER_DOWN_FOR isn't initialized correctly!";
#define MISSION_ZERO_2_HASH   		  _MISSION_ZERO_;

// CHECKPOINT THREE
#define MISSION_ZERO_3_NUM   	 	  3;
#define MISSION_ZERO_3_PIN   	 	  12;
#define MISSION_ZERO_3_VAL   	 	  HIGH;
#define MISSION_ZERO_3_TYPE   	 	  READ;
#define MISSION_ZERO_3_IS_CHALLENGE   false;
#define MISSION_ZERO_3_ERROR   		  "CHECKPOINT 3: TERMINAL_A's power is down!";
#define MISSION_ZERO_3_HASH   		  _MISSION_ZERO_;

// CHECKPOINT FOUR
#define MISSION_ZERO_4_NUM   	 	  4
#define MISSION_ZERO_4_PIN   	 	  13
#define MISSION_ZERO_4_VAL   	 	  HIGH
#define MISSION_ZERO_4_TYPE   	 	  READ
#define MISSION_ZERO_4_IS_CHALLENGE   false
#define MISSION_ZERO_4_ERROR   		  "CHECKPOINT 4: TERMINAL_B's power is down!";
#define MISSION_ZERO_4_HASH   		  _MISSION_ZERO_;

// CHECKPOINT FIVE
#define MISSION_ZERO_5_NUM   	 	  5
#define MISSION_ZERO_5_PIN   	 	  12
#define MISSION_ZERO_5_VAL   	 	  LOW
#define MISSION_ZERO_5_TYPE   	 	  READ
#define MISSION_ZERO_5_IS_CHALLENGE   false
#define MISSION_ZERO_5_ERROR   		  "CHECKPOINT 5: TERMINAL_A's power is up still!";
#define MISSION_ZERO_5_HASH   		  _MISSION_ZERO_;

// CHECKPOINT SIX
#define MISSION_ZERO_6_NUM   	 	  6;
#define MISSION_ZERO_6_PIN   	 	  13;
#define MISSION_ZERO_6_VAL   	 	  HIGH;
#define MISSION_ZERO_6_TYPE   	 	  READ;
#define MISSION_ZERO_6_IS_CHALLENGE   false;
#define MISSION_ZERO_6_ERROR   		  "CHECKPOINT 6: TERMINAL_B's power is down!";
#define MISSION_ZERO_6_HASH   		  _MISSION_ZERO_;

// CHECKPOINT SEVEN
#define MISSION_ZERO_7_NUM   	 	  7;
#define MISSION_ZERO_7_PIN   	 	  12;
#define MISSION_ZERO_7_VAL   	 	  LOW;
#define MISSION_ZERO_7_TYPE   	 	  READ;
#define MISSION_ZERO_7_IS_CHALLENGE   false;
#define MISSION_ZERO_7_ERROR   		  "CHECKPOINT 7: TERMINAL_A's power is up before TERMINAL_B's power!";
#define MISSION_ZERO_7_HASH   		  _MISSION_ZERO_;

// CHECKPOINT EIGHT
#define MISSION_ZERO_8_NUM   	 	  8;
#define MISSION_ZERO_8_PIN   	 	  13;
#define MISSION_ZERO_8_VAL   	 	  LOW
#define MISSION_ZERO_8_TYPE   	 	  READ;
#define MISSION_ZERO_8_IS_CHALLENGE   false
#define MISSION_ZERO_8_ERROR   		  "CHECKPOINT 8: TERMINAL_B's power is still up!";
#define MISSION_ZERO_8_HASH   		  _MISSION_ZERO_;

// CHECKPOINT NINE
#define MISSION_ZERO_9_NUM   	 	  9;
#define MISSION_ZERO_9_PIN   	 	  12;
#define MISSION_ZERO_9_VAL   	 	  HIGH
#define MISSION_ZERO_9_TYPE   	 	  READ;
#define MISSION_ZERO_9_IS_CHALLENGE   false
#define MISSION_ZERO_9_ERROR   		  "CHECKPOINT 9: TERMINAL_A's power is still down!";
#define MISSION_ZERO_9_HASH   		  _MISSION_ZERO_;

#endif