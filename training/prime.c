#include<stdio.h>
#include<cs50.h>

/*****************************************************
* prime.c
*
* Kevin Schmid
* Computer Science 50
*
* Explores some techniques for calculating the nth prime number.
*******************************************************/

#define FIRST_PRIME 2
#define IS_ODD(i) i%2 != 0

bool
is_prime_naive(int k)
{

	for(int i = 2; i < k; i++)
	{
		if (k%i == 0)
		{
			return false;
		}
	}

	return true;
}

bool
is_prime_better(int k)
{

	// we only actually have to up until k/2 (why?)
	for(int i = 2; i*2 < k; i++)
	{
		if (k%i == 0)
		{
			return false;
		}
	}

	return true;

}

int
main(void)
{

	// declare initialize n, which will store the user's request
	int n = 0;

	printf("Please enter a positive integer n: ");

	// get an integer from the user, pestering them if it's not positive
	do {

		n = GetInt();

	} while(n < 1 && printf("Sorry, I need a positive integer: "));

	// initialize the current_prime to 1
	// in the event that the user provides "1", the for loop won't execute at all
	int current_prime = FIRST_PRIME;

	for(int i = FIRST_PRIME; n > 1; i++)
	{
		// short circuit evaluation to ignore even i
		if (IS_ODD(i) && is_prime_better(i))
		{
			current_prime = i;
			n--;
		}

	}

	// print the nth prime number
	printf("The nth prime number is: %d\n", current_prime);

}
