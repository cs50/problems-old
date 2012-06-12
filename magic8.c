
/************************************************************************************
* magic8.c
*
* Computer Science 50
* Julia Mitelman
*
* Ask a question and get an answer.
*
* Demonstrates use of arrays, malloc, string iteration.
* Design challenges: 
*   - How can this program be currently broken, and how do we fix that?
*   - How can we make this handle new answer options more easily?  Right now we
*     have to add it to the array and change ANSWER_COUNT.
***********************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSWER_COUNT 8

int
main (void) {
    // initialize user's question
    char *question = malloc(sizeof(char));
    
    // get user's question
    printf ("What is your question?\n");
    scanf ("%s", question);
  
    // list of possible answers
    char *answers[ANSWER_COUNT] = {
            "It is absolutely certain.\n",
            "Most likely.\n",
            "I see it as a possibility.\n",
            "The outlook does not look promising.\n",
            "No, definitely not.\n",
            "Are you simply mad?\n",
            "Unclear.  Ask again later.\n"
        };
    
    // choose one answer randomly
    srand(time(NULL));
    int index = rand() % ANSWER_COUNT;
    
    printf("%s", answers[index]);
        
}
