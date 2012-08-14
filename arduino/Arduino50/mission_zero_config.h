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
#define MISSION_ZERO_Q_AMOUNT			3;

// CHECKPOINT ZERO
#define MISSION_ZERO_0_NUM   	 	  	0;
#define MISSION_ZERO_0_PIN   	 	  	13;
#define MISSION_ZERO_0_VAL   	 	  	HIGH;
#define MISSION_ZERO_0_TYPE   	 	  	READ;
#define MISSION_ZERO_0_IS_CHALLENGE   	false;
#define MISSION_ZERO_0_ERROR   		  	"CHECKPOINT 0: Isn't there suppose to be a power shift to the next building?";
#define MISSION_ZERO_0_HASH   		  	_MISSION_ZERO_;

// CHECKPOINT ONE
#define MISSION_ZERO_1_NUM   	 	  	1;
#define MISSION_ZERO_1_PIN   	 	  	13;
#define MISSION_ZERO_1_VAL   	 	  	15000;
#define MISSION_ZERO_1_TYPE   	 	  	NUMBER;
#define MISSION_ZERO_1_IS_CHALLENGE   	false;
#define MISSION_ZERO_1_ERROR   		  	"ERROR: Are you sure you configured 30 seconds?";
#define MISSION_ZERO_1_HASH   		  	_MISSION_ZERO_;

// CHECKPOINT TWO
#define MISSION_ZERO_2_NUM   	 	  	2;
#define MISSION_ZERO_2_PIN   	 	  	13;
#define MISSION_ZERO_2_VAL   	 	  	LOW;
#define MISSION_ZERO_2_TYPE   	 	  	READ;
#define MISSION_ZERO_2_IS_CHALLENGE   	false;
#define MISSION_ZERO_2_ERROR   		  	"ERROR: Why didn't you shift power back to the building?";
#define MISSION_ZERO_2_HASH   		  	_MISSION_ZERO_;

// CHECKPOINT THREE
#define MISSION_ZERO_3_NUM   	 	  NULL
#define MISSION_ZERO_3_PIN   	 	  NULL
#define MISSION_ZERO_3_VAL   	 	  NULL
#define MISSION_ZERO_3_TYPE   	 	  NULL
#define MISSION_ZERO_3_IS_CHALLENGE   NULL
#define MISSION_ZERO_3_ERROR   		  NULL
#define MISSION_ZERO_3_HASH   		  NULL

// CHECKPOINT FOUR
#define MISSION_ZERO_4_NUM   	 	  NULL
#define MISSION_ZERO_4_PIN   	 	  NULL
#define MISSION_ZERO_4_VAL   	 	  NULL
#define MISSION_ZERO_4_TYPE   	 	  NULL
#define MISSION_ZERO_4_IS_CHALLENGE   NULL
#define MISSION_ZERO_4_ERROR   		  NULL
#define MISSION_ZERO_4_HASH   		  NULL

// CHECKPOINT FIVE
#define MISSION_ZERO_5_NUM   	 	  NULL
#define MISSION_ZERO_5_PIN   	 	  NULL
#define MISSION_ZERO_5_VAL   	 	  NULL
#define MISSION_ZERO_5_TYPE   	 	  NULL
#define MISSION_ZERO_5_IS_CHALLENGE   NULL
#define MISSION_ZERO_5_ERROR   		  NULL
#define MISSION_ZERO_5_HASH   		  NULL

// CHECKPOINT SIX
#define MISSION_ZERO_6_NUM   	 	  NULL
#define MISSION_ZERO_6_PIN   	 	  NULL
#define MISSION_ZERO_6_VAL   	 	  NULL
#define MISSION_ZERO_6_TYPE   	 	  NULL
#define MISSION_ZERO_6_IS_CHALLENGE   NULL
#define MISSION_ZERO_6_ERROR   		  NULL
#define MISSION_ZERO_6_HASH   		  NULL

// CHECKPOINT SEVEN
#define MISSION_ZERO_7_NUM   	 	  NULL
#define MISSION_ZERO_7_PIN   	 	  NULL
#define MISSION_ZERO_7_VAL   	 	  NULL
#define MISSION_ZERO_7_TYPE   	 	  NULL
#define MISSION_ZERO_7_IS_CHALLENGE   NULL
#define MISSION_ZERO_7_ERROR   		  NULL
#define MISSION_ZERO_7_HASH   		  NULL

// CHECKPOINT EIGHT
#define MISSION_ZERO_8_NUM   	 	  NULL
#define MISSION_ZERO_8_PIN   	 	  NULL
#define MISSION_ZERO_8_VAL   	 	  NULL
#define MISSION_ZERO_8_TYPE   	 	  NULL
#define MISSION_ZERO_8_IS_CHALLENGE   NULL
#define MISSION_ZERO_8_ERROR   		  NULL
#define MISSION_ZERO_8_HASH   		  NULL

#endif