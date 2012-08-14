/*
 * arduino50.h - Library for Harvard CS50 Arduino
 * Created by Christopher M. Bartholomew, August 11, 2012.
 * Released into the public domain.
 */
#ifndef arduino50_h
#define arduino50_h
#define MAX_Q 10

#include "Arduino.h"
#include "mission50.h"

class Arduino50
{
  public:
    Arduino50(int problemid);
	void checkpoint(int checkpoint_id);
	void set_number(int num);
	void set_pin(int pin);
	void output();
  private:
	void set_q_total(int qnum);
	String check_read(solution s);
	String check_number(solution s);
	String check_pin(solution s);
	String  silly(String str, int num);
	int  get_q_total();
	void load();
	void write();
	int _problemid;
	int _qtotal;
	int _number;
	int _pin;
	solution* outputs;
};
#endif
