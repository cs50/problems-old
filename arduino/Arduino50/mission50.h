/*
 * mission50.h - Library for Harvard CS50 Arduino
 * Created by Christopher M. Bartholomew, August 11, 2012.
 * Released into the public domain.
 */
#ifndef mission50_h
#define mission50_h
#define QUESTIONS 10
#include "Arduino.h"

// enum for checl_types used by arduino50
enum check_types 
{ 
	READ, 
	PIN, 
	NUMBER,
	MODE 
};

// structure used to hold solution information
typedef struct solution 
{
    int num;
    int pin;
    int val;
	check_types type;
    bool is_challenge;
    String error;
    String hash;
} solution;

class Mission50
{
  public:
    Mission50(int missionid);
	int  get_mission_max();
	solution* get_mission();
  private:
	int _missionid;
	int _missionmax;
	void load_mission();
	void set_mission_max(int qnums);
	void mission_zero(solution* input_arr);
};
#endif