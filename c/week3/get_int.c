/*****************************************************
 *
 *	get_int.c
 *  Kevin Schmid
 *
 *  Introduction to recursion.
 *
 *  Implement get_even_int, a function that uses the
 *  CS50's library GetInt() function to get an even
 *  integer from the user.
 *
 *  No need for loops - if the integer you get back from
 *  a call to GetInt() happens to be odd, don't panic!
 *  Just use the magic of recursion!
 *
 *  Otherwise, you can return the integer.
 *
*******************************************************/

#include<stdio.h>
#include<cs50.h>

/*
 *	Gets an even integer from the user.
 *  Does _not_ use a loop of any sort.
 */
int get_even_int(void)
{
	// Try to get an integer
	int x = GetInt();

	if (/* TODO: is x even? */)
	{
		/* TODO: return it */
	}
	else
	{
		/* TODO: tell the user to try again, and re-prompt */
	}
}

int main(void)
{
	printf("Could I have an even integer, please? ");
	int x = get_even_int();
	printf("Thanks for the %d! I appreciate it.\n", x);
}
