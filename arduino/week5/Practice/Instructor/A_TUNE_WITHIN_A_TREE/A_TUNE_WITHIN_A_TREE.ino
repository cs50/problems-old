/****************************************************************************
 * A Tune in a tree
 *
 * Computer Science 50
 * Christopher Bartholomew
 * Binary Solutions Created by: Nate Hardison 
 * 
 * Store your tune inside of a tree by building an insert function, then play your tune using contains
 *
 * Demonstrates use of binary search trees
 * 
 * BONUS:
 * 1. Use contains_recursive 
 * 2. Add LEDs so that when a note is found - it will also light green - else red!
 ***************************************************************************/

#include <stdlib.h>
#include <arduino.h>
#include <avr-libc.h>
#define SOUND_PIN 8
#define LED_PIN 2
#define COLUMNS  14
#include "pitches.h"


int music[COLUMNS]      =   {
                                 NOTE_A4,  NOTE_A4,   NOTE_E5,   NOTE_E5, 
                                 NOTE_FS5, NOTE_FS5,  NOTE_E5,   NOTE_D5,
                                 NOTE_D5,  NOTE_CS5,  NOTE_CS5,  NOTE_B4,
                                 NOTE_B4,  NOTE_A4
                             };

int durations[COLUMNS]   =  {
                                4,4,4,4,
                                4,4,1,4,
                                4,4,4,4,
                                4,1
                            };
                             
                     
// TODO : create a data structure that will contain the note and duration.
typedef struct sound_node
{
    // TODO: What two values within your data structure (other than left and right children will you need?)
    int value;
    int duration;
    struct sound_node* left_child;
    struct sound_node* right_child;
}
sound_node;

// global variable to hold the root of our tree
sound_node* root = NULL;

void setup() 
{
  	// begin reading from serial
	Serial.begin(9600); 

        // TODO: using pinMode() set output to the pins you specified above
        pinMode(SOUND_PIN,OUTPUT);
         
         // used to load your values inside of the data structure
         for (int note = 0,max_notes = COLUMNS; note < max_notes; note++) 
         {
           
           int pitch = music[note];
           int dur   = durations[note];
           
           // this will first insert it into our tree
           insert(pitch, dur);
         }
         
         // used to then play our pitches that we stored
         for (int note = 0,max_notes = COLUMNS; note < max_notes; note++) 
         {
           // get the pitch
           int pitch = music[note];
           
           // get the duration
           int dur   = durations[note];
                 
           // TODO - Call contains or contains_recursive to play your sound
           //contains(pitch);
           //contains_recursive(root, pitch);
         }
        
        
}

/**
 * Returns true if the tree contains value and false otherwise.
 * Also... if value is found - then we should then play a tone
 */
bool contains(int value)
{  
    sound_node* cur = root;
    // TODO - finish the rest of this while loop
    while (cur != NULL)
    {
        if (cur->value == value)
        {
            playTone(cur->value,cur->duration);
            delay(1000);
            return true;
        }
        else if (cur->value > value)
        {
            cur = cur->left_child;
        }
        else
        {
            cur = cur->right_child;
        }
    }
    return false;
}

/**
 * Recursive implementation of contains, for challenge!
 * If value is found; however, play the tone inside of the node
 */
bool contains_recursive(struct sound_node* tree, int value)
{
    if (tree == NULL)
    {
        return false;
    }
    
    if (tree->value == value)
    {
        playTone(tree->value,tree->duration);
        delay(1000);
        return true;
    }

    return (contains_recursive(tree->left_child, value) ||contains_recursive(tree->right_child, value));
}

/**
 * Helper function to build a node (and clean the insert code up a bit!).
 */
static struct sound_node* build_node(int value, int duration)
{
    sound_node* new_node = (sound_node *)malloc(sizeof(sound_node));
    if (new_node != NULL)
    {
        new_node->value = value;
        new_node->duration = duration;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
    }
    return new_node;
}

/**
 * Inserts a new node containing value into the tree. Returns true if the
 * insert succeeded (or LED) and false otherwise (e.g., insufficient heap memory,
 * value already in the tree).
 *
 * In general, it's often cleaner to do this recursively, but that requires
 * either (a) passing in a node** or (b) returning a node*. For simplicity,
 * we pass on (a). We pass on (b) so that we can return a bool instead.
 */
bool insert(int value, int duration)
{
    // look for the appropriate place in the tree
    sound_node* parent = NULL;
    sound_node* cur = root;
    
    // TODO: Find the correct node to place our new structure in
    while (cur != NULL)
    {
        parent = cur;
        if (cur->value == value)
        {
            return false;
        }
        else if (cur->value > value)
        {
            cur = cur->left_child;
        }
        else
        {
            cur = cur->right_child;
        }
    }

    // build a new node 
    sound_node* new_node = build_node(value, duration);
    if (new_node == NULL)
    {
        return false;
    }

    // TODO: Place the new node in the correct position of the tree
    if (parent->value > new_node->value)
    {
        parent->left_child = new_node;
    }
    else
    {
        parent->right_child = new_node;
    }
    return true;
}

/**
 * Helper function to free a tree. Not needed for students'
 * implementations but here for completion (and interest!).
 */
static void free_tree(sound_node* tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left_child);
        free_tree(tree->right_child);
        free(tree);
    }
}

/**
 * Helper function to play a tone
 */
void playTone(int pitch, int duration)
{
  
  // create the duration of the note
  int note_duration = 1000 / duration;
  
  // play the sound
  // TODO: use tone() to play the tone
  tone(SOUND_PIN, pitch, note_duration);
  
  // crate a "rest" period between each note
  int rest = note_duration * 1.30;
  
  // delay
  delay(rest);
  
  // stop the tone
  noTone(SOUND_PIN);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  
}
