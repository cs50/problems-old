/**
 * oldman.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * "Plays" the traditional children's song, "This Old Man."
 */

#include <cs50.h>
#include <stdio.h>

#define VERSES 10

// the number strings corresponding to the verses in the song
string number[] = {"one",
                   "two",
                   "three",
                   "four",
                   "five",
                   "six",
                   "seven",
                   "eight",
                   "nine",
                   "ten"};

// where the old man plays knick-knack in each verse
string where[] = {"on my thumb",
                   "on my shoe",
                   "on my knee",
                   "on my door",
                   "on my hive",
                   "on my sticks",
                   "up in heaven",
                   "on my gate",
                   "on my spine",
                   "once again"};

void print_verse(int verse)
{
    printf("This old man, he played %s\n", number[verse]);
    printf("He played knick-knack %s\n", where[verse]);
    printf("Knick-knack paddywhack, give your dog a bone\n");
    printf("This old man came rolling home\n");
}

int main(void)
{
    for (int i = 0; i < VERSES; i++) 
    {
	    print_verse(i);

        // print an extra line between verses, but not after last one!
        if (i < VERSES - 1)
            printf("\n");
    }

    return 0;
}
