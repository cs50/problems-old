#include<stdio.h>
#include<cs50.h>

#define ever (;;)

/*****************************************************
* loops.c
*
* Kevin Schmid
* Computer Science 50
*
* Fun with loops.
*******************************************************/

int
main(void)
{

	// 1) Rewrite the following for loop as a while loop.
	for(int i = 0; i < 5; i++)
	{
		printf("%d\n", i);
	}

	// 2) Rewrite the following while loop as a do-while loop.
	int j = -1;
	while(j < 0)
	{
		printf("Please enter an integer: ");
		j = GetInt();

	}


	// 3) Rewrite the following while loop as a for loop.
	int b = 1;

	while(b < 1024)
	{
		b += b;

	}

	// 4) Can you express this double for loop as a single for loop?
	// Make sure it prints the same output, even though you may not have variables s and t around.
	for(int s = 0; s < 5; s++)
	{
		for(int t = 0; t < 5; t++)
		{
			printf("s = %d, t = %d\n", s, t);
		}

	}

	/* 5) Francis wants to prompt a user for an integer using the CS50 library.
	 * For some reason, he wants the integer provided to be greater than 100.
	 * He also wants to display the following message to prompt the user initially:
	 * "Please provide an integer greater than 100: "
	 * If he has to prompt the user again, he wants to use this message:
	 * "Can you try again? That is not greater than 100: "
	 *
	 * See if, you can, using a loop, implement this behavior.
	 * Store the value in a variable called x.
	 */

	// int x;
	// TODO: get an integer from the user greater than 100 according to the specification above

	/*
	 * 6) The following code, within the context of this C file, is the skeleton of an infinite
	 *    loop, just like:
	 *
	 *    while(true)
	 *    {
	 *
	 *
	 * 	  }
	 *
	 *	  Why?
	 *	  Idea from Stack Overflow: http://stackoverflow.com/questions/1401159/for-or-while-true-which-is-the-correct-c-sharp-infinite-loop
	 */

	for ever
	{



	}

}
