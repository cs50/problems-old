/**
 * lookup.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * Checks to see if the user-supplied command-line argument is in the
 * dictionary at /usr/share/dict/words.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the location of the dictionary in the filesystem
#define DICTIONARY "/usr/share/dict/words"

// there definitely aren't any words longer than this in English
#define MAX_LINE_LENGTH 128

int main(int argc, char* argv[])
{
    // print a nice message if run improperly
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        exit(1);
    }

    // open up the dictionary and make sure it indeed opened
    FILE* dictionary = fopen(DICTIONARY, "r");
    if (dictionary == NULL)
    {
        printf("Error opening dictionary %s\n", DICTIONARY);
        exit(1);
    }

    // track whether or not we've found the word
    bool found = false;

    // typical C idiom: use a stack array as a buffer for your character data
    char buffer[MAX_LINE_LENGTH];

    // use fscanf instead of fgets to avoid issues with newlines
    // unfortunately, can't use #define in format string sans some hackishness
    while (fscanf(dictionary, "%127s\n", buffer) == 1)
    {
        if (strcmp(argv[1], buffer) == 0)
        {
            found = true;
            break;
        }
    }

    // always gotta make sure to clean up after yourself!
    fclose(dictionary);

    if (found)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

