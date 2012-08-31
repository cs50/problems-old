/*****************************************************
* editdistance.c
* Kevin Schmid
* #edit #distance #strings
*
* Kevin Schmid
* Computer Science 50
*
* Calculates edit distance between two strings, using classic recursive version and a DP version.
* Based on description of algorithm available at http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Dynamic/Edit/
*******************************************************/

#include<stdio.h>
#include<string.h>
#include<cs50.h>

// http://gcc.gnu.org/onlinedocs/gcc-3.4.2/gcc/Min-and-Max.html
#define MIN(X,Y) (X < Y ? X : Y)
#define MAX(X,Y) (X > Y ? X : Y)

// calculates the edit distance but uses an s1_len * s2_len array to memoize calculations
// assumes that data is an s1_len * s2_len 2-D array and that data has originally been initialized to NULL
// has side effect of printing view of matrix to stdout
int
edit_distance_dp(char *s1, int s1_len, char *s2, int s2_len)
{

	if (s1_len * s2_len == 0)
	{
		return MAX(s1_len, s2_len);
	}


	// declare an array, which represents a matrix of edit distances for the substrings
	int data[s1_len + 1][s2_len + 1];

	// here we calculate the edit distance, starting with the smallest substrings
	// i and j implicitly represent the substring's lengths
	// we store the edit distance of s1(0:i) and s2(0:j) in data[i][j]
	for(int i = 0; i <= s1_len; i++)
	{
		for(int j = 0; j <= s2_len; j++)
		{
			if (i * j == 0)
			{
				data[i][j] = MAX(i, j);
			}
			else {

			// otherwise, we can use the recurrence defined in edit_distance_helper
			// note that data[i-1][j], data[i][j-1], and data[i-1][j-1] will be already computed
			// it's safe to assume those values are in the array
			int change_last_char = data[i-1][j-1] + (s1[i-1] != s2[j-1]);
			int delete_last_char_of_s1 = data[i-1][j] + 1;
			int delete_last_char_of_s2 = data[i][j-1] + 1;

			// the edit distance for these non-empty strings is the minimum of these
			data[i][j] = MIN(MIN(change_last_char, delete_last_char_of_s1), delete_last_char_of_s2);
			}
		}
	}

	printf("Here's what the final matrix looks like:\n");

	// TODO: i put this here cause it looks cool but i can get rid of it -ks
	for(int i = 0; i < s1_len; i++)
	{
		for(int j = 0; j < s2_len; j++)
		{
			printf("%3d  |  ", data[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	return data[s1_len][s2_len];

}

int
edit_distance_helper(char *s1, int s1_len, char *s2, int s2_len)
{

	// see edit_distance_dp for a more concise way to express these base cases

	// base cases
	// edit distance between "" and "" is 0
	if (s1_len ==  0 && s2_len == 0)
	{
		return 0;
	}

	// edit distance between s1 and "" is |s1|
	if (s1_len > 0 && s2_len == 0)
	{
		return s1_len;
	}

	// edit distance between "" and s2 is |s2|
	if (s1_len == 0 && s2_len > 0)
	{
		return s2_len;
	}

	/* one option: we could change the last char of one of the
	 * strings to match the last char of the other string
	 *
	 * if those two last characters were equal, no additional cost
     * is incurred (other than editing the substrings)
	 * however, if the two last characters were not equal, the edit
	 * distance is incremented by one because we have change one
	 * into the other
	 *
	 * Note that these three operations correspond nicely to the three
	 * operations one can do to a string.
	 * A deletion in s1 has the same effect on the size of the problem
	 * as an insertion in s2.
	 */
	int change_last_char = edit_distance_helper(s1, s1_len - 1, s2, s2_len - 1) + (s1[s1_len-1] != s2[s2_len-1]);

	/*
	 * another option: we could delete the last char of s1, which is one edit
	 * then we just need to figure out the edit distance of sub(s1) and s2
	 */
	int delete_last_char_of_s1 = edit_distance_helper(s1, s1_len - 1, s2, s2_len) + 1;


	/*
	 * another option: we could delete the last char of s2, which is one edit
	 * then we just need to figure out the edit distance of s1 and sub(s2)
	 *
	 */
	int delete_last_char_of_s2 = edit_distance_helper(s1, s1_len, s2, s2_len - 1) + 1;

	return MIN(MIN(change_last_char, delete_last_char_of_s1), delete_last_char_of_s2);

}

// front facing function
int
edit_distance(char *s1, char *s2)
{
	// feel free to interchange this with edit_distance_helper
	return edit_distance_dp(s1, strlen(s1), s2, strlen(s2));
}

int
main(void)
{

	printf("Please enter string 1: ");

	char *s1 = GetString();

	printf("Please enter string 2: ");

	char *s2 = GetString();

	printf("The edit distance is: %d\n", edit_distance(s1, s2));

}
