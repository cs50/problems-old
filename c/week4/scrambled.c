/*****************************************************
* scrambled.c
*
* Kevin Schmid
* Computer Science 50
*
* A short puzzle, which covers pointers
* and reviews ASCII representation.
*******************************************************/

#include<stdio.h>

int
main(void)
{
   int s = 65;
   int *t = &s;

   /*

   Can you pass the seven variables below into the printf
   function call so that executing this code would
   print the word "POINTER"?

   You only need each variable once.

   */

   char C = 'I';
   char N = s + 'P' - 'A';
   char B = *t - s + N + 2;
   char E = &s - t + 78;
   char J = *t + 19;
   char I = N + 'A' - s - 1;
   char O = 347/5;

   //printf("%c%c%c%c%c%c%c\n", ?, ?, ?, ?, ?, ?, ?);

}
