/*****************************************************
* buggy_sum.c
*
* #debugging #scope #atoi #for #loops
*
* Kevin Schmid
* Computer Science 50
*
* I intended to write a program called "sum" that would accept, as
* a command-line argument, a positive integer n.  It would
* then find the sum of the numbers from 1 to n, inclusive.
* I was hoping that, for example, executing ./sum 3 would return 6.
*
* But it doesn't! I've pasted it here for reference.
* It compiles, but it looks like there are some bugs.
*
* See if you can spot some of them, and even get the program working!
* (Thanks in advance! :-))
*
* It might be a good idea to debug this code in small pieces, and even
* print out values to the terminal.  Am I even getting user input correctly?
* How many times does that for loop execute?
*
* For some debugging tips (and a sneak peak of GDB, a _program_ that you
* can use to debug code!), see http://manual.cs50.net/Debugging.
*******************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	// make sure the user passed at least one argument
	if (argc < 1)
	{
		printf("Usage: ./sum <n>.");
		return 1;
	}

	// convert the first argument to an integer
	int n = atoi(argv[0]);

	if (n < 1)
	{
		printf("Invalid argument supplied.  Please use a positive integer.");
		return 2;
	}

	// start the "total" off at zero
	int total = 0;
	int i = 0;

	// add each "i" (index variable) to the total
	for(i = 1; i < n; i++);
	{
		int total = total + i;
	}

	printf("The total is %d!\n", total);

}
