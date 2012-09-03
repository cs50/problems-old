/*****************************************************
* str_rev.c
* Kevin Schmid
* #in #place #string #reversal
*
* Kevin Schmid
* Computer Science 50
*
* Implement str_rev, a program that reverses a string, in place.
* Reminiscient of "echo" when you enter a palindrome :-).
*******************************************************/

#include<stdio.h>
#include<string.h>
#include<cs50.h>

int
main(void)
{

	printf("Please enter a string for me to reverse, in place: ");
	char *s = GetString();
	printf("Your original string is at memory address %p\n", s);

	// TODO: Reverse s, in place

	printf("Okay, cool! Here's your new string, at memory address %p: %s\n", s, s);

}
