#include<stdio.h>

/*****************************************************
* div.c
*
* Kevin Schmid
* Computer Science 50
*
* Performs division of two unsigned integers without
* using the / operator.
*******************************************************/

typedef struct {
	int quotient;
	int remainder;

} result;

result
new_result() {
	result s;
	s.quotient = 0;
	s.remainder = 0;

	return s;
}

result
naive_div(unsigned int a, unsigned int b)
{

	result res = new_result();

	int i;

	for(i = 0; i+b <= a; i+=b)
	{
		res.quotient++;
	}

	res.remainder = a - i;

	return res;
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

		for(int j = 1; j < 1000; j++) {

			total_tests += 2;

			result res = naive_div(i, j);

			int correct_quotient = i/j;
            int correct_remainder = i%j;

			if (res.quotient != correct_quotient)
			{
				printf("error dividing %d by %d with naive_div: expected quotient of %d, got %d\n", i, j, correct_quotient, res.quotient);
			}
			else
			{
			    tests_passed++;
			}

			if (res.remainder != correct_remainder)
			{
				printf("error dividing %d by %d with naive_div: expected remainder of %d, got %d\n", i, j, correct_remainder, res.remainder);
			}
			else
			{
			    tests_passed++;
			}

		}
	}

	printf("Passed %d of %d tests.\n", tests_passed, total_tests);

	return 0;

}
