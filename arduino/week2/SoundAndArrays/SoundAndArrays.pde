/* Sound And Arrays!
 * Arduino Exploration Two
 * Author: Christopher Bartholomew
 * Course: CS50 
 *
 * In class experiment on how to interact with the arduino using C's standard loops, arrays, and sound!
 * Goals:
 * - Understanding how to initialize multidimensional arrays. 
 * - Learning to iterate through multidimensional arrays.
 * - Including new libraries.
 * - Interfacing code to make sound using a speaker.
 */
 
// inlude the library that will be used to handle notes
#include "pitches.h"

// Providing constants is always good thing!
#define MELODY    0
#define DURATION  1
#define SOUND_PIN 8

/* Row One, Columns 1-14: The "pitch" or "note frequency" that we wish to play
 * Row Two, Columns 1-14: The duration of the note, that will be in Row One, Columns 1-14. for example: quater note, eighth note, whole note.
 */
#define ROWS      2
#define COLUMNS   14

// A 2d Multie Demensional Array
// TODO: Using the following Notes, what would this array be initalized like?
int stanza[ROWS][COLUMNS]  = {
                                {
                                 NOTE_A4,  NOTE_A4,   NOTE_E5,   NOTE_E5, 
                                 NOTE_FS5, NOTE_FS5,  NOTE_E5,   NOTE_D5,
                                 NOTE_D5,  NOTE_CS5,  NOTE_CS5,  NOTE_B4,
                                 NOTE_B4,  NOTE_A4
                                },
                                {
                                 4,4,4,4,
                                 4,4,1,4,
                                 4,4,4,4,
                                 4,1
                                } 
                             };

// Arduino's Main()
void setup() {
  
  
  // BONUS: What is another way to find out the total amount of columns one would need to iterate through?
  // Using sizeof(array)/sizeof(datat_type) will give you the total array size. For 2d, divide by columns. 
  // int stanza_note_len = sizeof(stanza)/sizeof(int) / ROWS;
  
  // TODO: How would you iterate through this array? 
  for (int current_note = 0,max_notes = COLUMNS; current_note < max_notes; current_note++) {
    
    //TODO: How would you determine the note duration?
    // based on the note, calculate the duration of the note to be played  
    int note_duration = 1000 / stanza[DURATION][current_note];
    
    // TODO: Using the "Tone" Method, what values would need be here in order to play a tone?
    // Using "tone" will play the note. Here we pass in the pin, the frequency, and the duration.
    tone(SOUND_PIN, stanza[MELODY][current_note],note_duration);
     
    // Calculates a "rest" period between each note  
    int rest = note_duration * 1.30;
    
    // TODO: What could you use to "prolong" the notes from playing back to back
    delay(rest);
    
    // TODO: What should be inside of noTone() according to the library? 
    noTone(SOUND_PIN);
  } 
  
}

void loop() {
// not needed
}
