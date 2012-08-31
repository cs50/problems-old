#include<stdio.h>

/*****************************************************
* times.c
*
* Kevin Schmid
* Computer Science 50
*
* Performs multiplication of two unsigned integers without
* using the * operating.
*******************************************************/


/*
 * adds the integer a 'b' times to an accumulator
 * complexity?
 */
int
naive_times(unsigned int a, unsigned int b)
{
	int result = 0;

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
	int result = 0;

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
	if (a == 0 || b == 0)
	{
		return 0;
	}

	int multiplier = 2;
	int result = a;

	while(multiplier < b) {
		result = result << 1;
		multiplier = multiplier << 1;
	}

	multiplier = multiplier >> 1;

	int remaining = b - multiplier;

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
