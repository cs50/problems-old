
/*****************************************************************************************
* rps.c
*
* Computer Science 50
* Julia Mitelman
*
* Plays rock paper scissors.
*
* Demonstrates use of more complex logic, arrays, malloc, string iteration, comparison.
* Design challenges:
*   - How can we design this to easily handle new options (besides rock, paper, or
*       scissors)?  What will we have to change? 
*   - How else can we determine a winner?
*   - How can this program be currently broken and how do we fix that?
*****************************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHOICE_COUNT 3

int
main (void) {
    // list of possible choices
    char *choices[CHOICE_COUNT] = {
            "rock",
            "paper",
            "scissors"
        };
        
    // initialize user's choice
    char *uchoice = malloc(sizeof(char));
    int loop = 1;
    
    while (loop == 1) {
        // get user's choice
        printf ("Rock, paper, or scissors?\n");
        scanf ("%s", uchoice);
        
        // make all lowercase to ensure check
        int length = sizeof(uchoice);
        for (int i = 0; i < length; i++) {
            uchoice[i] = tolower(uchoice[i]);
        }
        
        // check if the user picked a valid choice
        for (int i = 0; i < CHOICE_COUNT; i++) {
            if (strcmp(uchoice, choices[i]) == 0)
                loop = 0;
        }
    }
    
    // choose one randomly
    srand(time(NULL));
    int index = rand() % CHOICE_COUNT;   
    printf("I chose %s!\n", choices[index]);
    
    // determine winner
    if (strcmp(uchoice, choices[index]) == 0) {
        printf("We tied.  Let's play again!\n");
    }
    // we can use the lengths of the words to set up rules
    else if (strlen(uchoice) < strlen(choices[index])) {
        // rock beats scissors, exception
        if (strcmp(uchoice, "rock") == 0 && strcmp(choices[index], "scissors") == 0) {
            printf("Woah, you win.  Play again?\n");
        }
        else
            printf("I win!  Again?  I dare you to beat me.\n");
    }
    else {
        // scissors loses to rock, exception
        if (strcmp(choices[index], "rock") == 0 && strcmp(uchoice, "scissors") == 0) {
            printf("I win!  Again?  I dare you to beat me.\n");
        }
        else
            printf("Woah, you win.  Play again?\n");
    }
    
}
