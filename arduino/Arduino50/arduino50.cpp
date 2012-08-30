/*
 * arduino50.cpp - Library for Harvard CS50 Arduino
 * Created by Christopher M. Bartholomew, August 11, 2012.
 * Released into the public domain.
 * Grading helper for Arduino In Class Problem Sets
 * Usage:
 * Instantiate arduino50 object with problem set id
 * arduino50 a50(n);
 * For every solution in your config, add a checkpoint method
 * a50.checkpoint(n)
 */

#include "Arduino.h"
#include "arduino50.h"


// currently, the max amount of questions are 10
String inputs[MAX_Q];

/* int Arduino50::Arduino50()
 * @param1: int problemid 
 * purpose: constructor for the object
 */
Arduino50::Arduino50(int problemid) 
{
	// init problem id
	_problemid 	= problemid;
	// load the problem information
	load();
}

/* void Arduino50::load()
 * @param1: void 
 * purpose: creates mission50 object that contains the problem info
 */
void 
Arduino50::load()
{	
	// define new mission class w/ problem id
	Mission50 m(_problemid);
	
	// get the output file
	outputs = m.get_mission();
	
	// get the total amount of question numbers and set it
	int qnums = m.get_mission_max();
	set_q_total(qnums);
}

/* void Arduino50::checkpoint()
 * @param1: int checkpoint_id 
 * purpose: based on the checkpoint id, obtains the correct solution object
 */
void 
Arduino50::checkpoint(int checkpoint_id)
{	
	// get the specific solution for this checkpoint
	solution s = outputs[checkpoint_id];
	
	// based on the ENUM to Solution.Type pairing, check the current input
	switch(s.type)
	{
		case READ:
			inputs[checkpoint_id] = check_read(s);
		break;
		case PIN:
			inputs[checkpoint_id] = check_pin(s);			
		break;
		case NUMBER:
			inputs[checkpoint_id] = check_number(s);
		break;
		case MODE:
		break;
		default:
		break;
	}

}

/* String Arduino50::check_read()
 * @param1: solution s
 * purpose: reads the digital pin value, if matches solution return hash : error msg
 */
String
Arduino50::check_read(solution s)
{
	return (digitalRead(s.pin) == s.val) ? silly(s.hash, s.num) : s.error;
}

/* String Arduino50::check_number()
 * @param1: solution s
 * purpose: reads the number value, (set using set_number) if matches solution return hash : error msg
 */
String
Arduino50::check_number(solution s)
{
	return (_number == s.val) ? silly(s.hash, s.num) : s.error;
}

/* String Arduino50::check_pin()
 * @param1: solution s
 * purpose: reads the pin id, (set using set_pin) if matches solution return hash : error msg
 */
String
Arduino50::check_pin(solution s)
{
	return (_pin == s.pin) ? silly(s.hash, s.num) : s.error;
}

/* String Arduino50::silly(String str, int num)
 * @param1: String str, int num
 * purpose: responsible for hashing output to make test when user submits
 */
String  
Arduino50::silly(String str, int num)
{   
	// index_vale will be used for bitwise      
	int index_value = 0;
	
	// get total integer value
	for(int i=0,n=str.length();i<n;i++)
		index_value += str.charAt(i) - '0' + num;
		
	// current value, multiply by index, plus its value
    index_value = num + index_value * str.length();
	
	// convert to Arduno String
	return String(index_value);
}

/* void Arduino50::output()
 * @param1: void
 * purpose: responsible for outputting the data to Arduino Serial Monitor
 */
void 
Arduino50::output()
{
	Serial.println("#####OUTPUT#####");
	
	// inputs contains all student's answers
	for(int i=0,n=get_q_total();i<n;i++)
		Serial.println(inputs[i]);
	
	Serial.println("#####OUTPUT#####");
}

/* void Arduino50::set_pin()
 * @param1: int pin
 * purpose: setter for pin
 */
void
Arduino50::set_pin(int pin)
{
	_pin = pin;
}

/* void Arduino50::set_number()
 * @param1: int num
 * purpose: setter for num
 */
void
Arduino50::set_number(int num)
{	
	_number = num;	
}

/* void Arduino50::set_q_total()
 * @param1: int qnum
 * purpose: setter for qtotal, question total
 */
void
Arduino50::set_q_total(int qnum)
{
	_qtotal = qnum;
}

/* int Arduino50::get_q_total()
 * @param1: void
 * purpose: getter for qtotal, question total
 */
int
Arduino50::get_q_total()
{
	return _qtotal;
}

