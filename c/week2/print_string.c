/*****************************************************
 *
 *	print_string.c
 *  Kevin Schmid
 *
 *  Demonstrates the C representation of strings.
 *
 *  Implement the function print_string below.
 *  print_string takes 1 string (char* argument) and
 *  prints it to stdout.
 *
 *  Only use print_char in your implemntation.
 *
*******************************************************/

#include<stdio.h>
#include<cs50.h>

/*
 *	Prints a character, c, to stdout.
 */
void print_char(char c)
{
	printf("%c", c);
}

/*
 *	Prints a string, s, to stdout.
 *  Only uses print_char.
 */
void print_string(char* s)
{

}

int main(void)
{
	char* s = GetString();
	print_string(s);
}
