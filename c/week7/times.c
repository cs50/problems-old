#include<stdio.h>

/*****************************************************
* times.c
*
* Kevin Schmid
* Computer Science 50
*
* Performs multiplication of two unsigned integers without
* using the * operator.
*******************************************************/


/*
 * adds the integer a 'b' times to an accumulator
 * complexity?
 */
int
naive_times(unsigned int a, unsigned int b)
{
	// declare and initialize an accumulator
	int result = 0;

	// add a 'b' times to the accumulator
	for(int i = 0; i < b; i++)
	{
		result += a;
	}

	return result;
}

/*
 * adds the integer a 'b' times or b 'a' times to
 * an accumulator, depending on whether a or b is larger
 */

int
less_naive_times(unsigned int a, unsigned int b)
{
	// declare and initialize an accumulator
	int result = 0;

	// if a is smaller than b, loop add b 'a' times
	if (a < b)
	{
		for(int i = 0; i < a; i++)
		{
			result += b;
		}
	}
	else
	{
		for(int i = 0; i < b; i++)
		{
			result += a;
		}
	}

	return result;

}

/*
 * makes as much use of bit shifting operators as possible
 * before resorting to the previous methods
 */
int
bit_shift_times(unsigned int a, unsigned int b)
{
	// quick return: if one variable is 0
	if (a == 0 || b == 0)
	{
		return 0;
	}

	// start by considering multiplying by 2
	int multiplier = 1;
	int result = a;

	// if the factor we are about to multiply the result by is less than b, go for it!
	while(multiplier << 1 < b) {

		// multiply the multiplier by 2
		multiplier = multiplier << 1;

		// multiply result by 2
		result = result << 1;

	}

	// find out how many more times we need to add
	int remaining = b - multiplier;

	// do that using conventional method
	for(int i = 0; i < remaining ; i++)
	{
		result += a;
	}

	return result;

}

int
main(void)
{
	// testing code

	int total_tests = 0;
	int tests_passed = 0;

	printf("Testing...\n");
	fflush(stdout);

	for(int i = 0; i < 1000; i++) {

		for(int j = 0; j < 1000; j++) {

			total_tests+=3;

			int x = less_naive_times(i, j);
			int y = less_naive_times(i, j);
			int z = bit_shift_times(i, j);

			int correct_ans = i*j;

			if (x != correct_ans)
			{
				printf("error multiplying %d by %d with naive_times: expected %d, got %d\n", i, j, correct_ans, x);
			}
			else {
				tests_passed++;
			}

			if (y != correct_ans)
			{
				printf("error multiplying %d by %d with less_naive_times: expected %d, got %d\n", i, j, correct_ans, y);
			}
			else {
				tests_passed++;
			}

			if (z != correct_ans)
			{
				printf("error multiplying %d by %d with bit_shift_times: expected %d, got %d\n", i, j, correct_ans, z);
			}
			else {
				tests_passed++;
			}

		}
	}

	printf("Passed %d of %d tests.\n", tests_passed, total_tests);

	return 0;

}
