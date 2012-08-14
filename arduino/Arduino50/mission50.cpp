/*
 * mission50.cpp - Library for Harvard CS50 Arduino
 * Created by Christopher M. Bartholomew, August 11, 2012.
 * Released into the public domain.
 * Grading helper for Arduino In Class Problem Sets
 * Usage:
 * Instantiate mission50 object with problem set id
 * mission50 m50(n);
 * To obtain the specific mission, instantiate using the mission id.
 * then, get array of solution objects and call m50.get_mission();
 */

#include "Arduino.h"
#include "mission50.h"
#include "mission_zero_config.h"
solution solution_storage[QUESTIONS];

/* int Mission50::Mission50() 
 * @param1: int missionid 
 * purpose: constructs mission 50 object, will load specific mission based on mission id
 */
Mission50::Mission50(int missionid) 
{
	_missionid = missionid;
	load_mission();
}

/* void Mission50::load_mission() 
 * @param1: void
 * purpose: based on private missionid var, load up specific missions
 */
void 
Mission50::load_mission()
{	
	switch(_missionid)
	{
		case 0:
		mission_zero(solution_storage);
		break;
		case 1:
		//mission_two(solution_storage);
		break;
		case 3:
		//mission_three(solution_storage);
		break;
		default:
		break;
	}
}


/* void Mission50::mission_zero()
 * @param1: solution* solution_arr
 * purpose: used for mission zero only, take in mission_n_config.h that contains
 * constants, which acts as the values that are created within each structure. 
 */
void
Mission50::mission_zero(solution* solution_arr)
{
	// although we max at 10 questions, we set a limit still if it is less than
	int MAX_QUESTIONS = MISSION_ZERO_Q_AMOUNT;
	
	// setter 
	set_mission_max(MAX_QUESTIONS);
	
	// each solution needs its own structure
	solution mzero_zero;
	mzero_zero.num  		= MISSION_ZERO_0_NUM;   	 
	mzero_zero.pin  		= MISSION_ZERO_0_PIN;   	 
	mzero_zero.val  		= MISSION_ZERO_0_VAL;   	 
	mzero_zero.type			= MISSION_ZERO_0_TYPE;   	 
	mzero_zero.is_challenge = MISSION_ZERO_0_IS_CHALLENGE;
	mzero_zero.error		= MISSION_ZERO_0_ERROR;   	
	mzero_zero.hash			= MISSION_ZERO_0_HASH;   	
		
	solution mzero_one;
	mzero_one.num  			= MISSION_ZERO_1_NUM   	 
	mzero_one.pin  			= MISSION_ZERO_1_PIN   	 
	mzero_one.val  			= MISSION_ZERO_1_VAL   	 
	mzero_one.type			= MISSION_ZERO_1_TYPE   	 
	mzero_one.is_challenge 	= MISSION_ZERO_1_IS_CHALLENGE
	mzero_one.error			= MISSION_ZERO_1_ERROR   	
	mzero_one.hash			= MISSION_ZERO_1_HASH   	
	
	solution mzero_two;
	mzero_two.num  			= MISSION_ZERO_2_NUM   	 
	mzero_two.pin  			= MISSION_ZERO_2_PIN   	 
	mzero_two.val  			= MISSION_ZERO_2_VAL   	 
	mzero_two.type			= MISSION_ZERO_2_TYPE   	 
	mzero_two.is_challenge 	= MISSION_ZERO_2_IS_CHALLENGE
	mzero_two.error			= MISSION_ZERO_2_ERROR   	
	mzero_two.hash			= MISSION_ZERO_2_HASH   	
	
	// solution arr, which holds each solution
	solution_arr[0]		= mzero_zero;
	solution_arr[1]		= mzero_one;
	solution_arr[2]		= mzero_two;
	
}

/* void Mission50::set_mission_max()
 * @param1: int qnums
 * purpose: used to set the max question amount for missions
 */
void
Mission50::set_mission_max(int qnums)
{
	_missionmax = qnums;
}

/* void Mission50::get_mission_max()
 * @param1: void
 * purpose: used to get the max question amount for missions
 */
int
Mission50::get_mission_max()
{
	return _missionmax;
}

/* void Mission50::get_mission()
 * @param1: void
 * purpose: used to all the questions that were loaded
 */
solution*
Mission50::get_mission()
{
	return solution_storage;
}