/*****************************************************
* overflow.c
*
* Kevin Schmid
* Computer Science 50
*
* Covers loops and data types, with an accent
* on integer overflow.
*
* Implement, in overflow.c, a program that behaves
* in the following way:
*
* It accepts an integer from the user
* (x below; assume this is a signed,
* 32-bit integer) and prints the number of times that
* x woud need to be incremented so that its value
* is 0.  This should be greater than or equal to 0.
*
* Some things to think about:
* 1) What data type(s) would be acceptable containers for
*    the value to be printed?
* 2) In a similar vein, what is the maximum value that should
*    ever be printed? Minimum?
* 3) Be creative in your implementation, but make
*    correctness and not speed the ultimate goal!
*******************************************************/

#include<stdio.h>
#include<cs50.h>

int main(void)
{

	printf("Please enter an integer: ");
	int x = GetInt();

	// TODO: Print a positive number representing the number of times
	// x would need to be incremented to be equal to 0

	// Make the assumption stated in the specification.
	// Why is this assumption not the best to make in practice?


}
