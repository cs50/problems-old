/*****************************************************
* ints_and_floats.c
*
* Jackson Steinkamp
* Computer Science 50
*
* What will each of these printf expressions print, and why?
*
* Demonstrates many of the subtle differences between ints
* and floats, how they work at a basic level in I/O expressions,
* arithmetic expressions, explicit and implicit typecasting.
*******************************************************/

#include<stdio.h>

int 
main(void)
{
   // 1. Pretty simple. (What does "%d" tell the program to do?)
   int a = 1;
   printf("A is %d\n", a);

   // 2. Again, pretty basic. (Why did we change the '%d' to a '%f'?)
   float b = 2.0;
   printf("B is %f\n", b);

   // 3. What happens if we try to PRINT C as an int, although it's a float?
   float c = 3.0;
   printf("C is %d...or is it?\n", c);
 
   // 4. How about the reverse? What is ACTUALLY happening here, and why could this be
   // extremely misleading (much worse than an explicit error)?
   int d = 4;
   printf("D is %f...or is it?\n", d);

   // 5. What happens if we try to store a float in an variable of type int?
   int e = 5.14159265;
   printf("E is %d\n", e);

   // 6. What happens if we try to store an int in a floating point variable?
   float f = 6;
   printf("F is %f\n", f);

   // 7. How do integers handle division? 
   int g = 9 / 4;
   printf("G is %d\n", g);

   // 8. How about floating points?
   float h = 9.0 / 4.0;
   printf("H is %f\n", h);

   // 9. This one might be tricky. You know that H will literally take on the value
   // which is the result of the expression (17 / 6). What is this result, though?
   // Don't forget what type 'i' is.
   float i = 17 / 6;
   printf("I is %f\n", i);

   // 10. The reverse case. Remember, two things are happening in the first line.
   // First, the division. Then, the result of that divison gets stored 
   // as an integer. Hint: Remember what happened in questions 8 and 5!
   int j = 17.0 / 6.0;
   printf("J is %d\n", j);
  
   // 11. What if the dividing operation is conducted with one float and one int?
   float k = 16.2 / 2;
   printf("K is %f\n", k);

   // 12. What happens when you explicitly "cast" one number type as another? 
   int z = (int) 14.8;
   printf("Z is %d\n", z);

   // 13. CHALLENGE!!1 (Don't forget the order of operations. Don't forget that storing a number in
   // a variable is also an 'operation' and requires careful checking of types.)
   float l = 3 / 2;
   float m = 2.3 + (3.3 / 3);
   int n = 12.3 - 9.4;
   float o = (m + ((int) (l + 0.9999))) / (n + .2);
   printf("O is %f\n", o);
}

/**********************************************************
* ANSWERS: Run the program to see them, but here are some that 
* might require additional explanation.
*
* 3&4: A garbage value is being printed to the screen. This value 
* is not necessarily the value stored in the variables. In fact, it
* could be anything, and might be different each time you run 
* the program. This is much harder to detect than an explicit error message, 
* so make sure you are always printing the right type of values! 
*
* 5. Note that trying to 'force' the float value into an 'int-shaped box' (variable E)
* results in a loss of information. The floating point value '3.14159265' 
* is truncated (NOT rounded!) to result in the int 3, which is stored in E.
*
* 9. The division 17/6 is a division of two integers. As seen in question 7,
* this results in the integer '2'. It is this integer that is stored in the
* floating-point variable I. Similarly to question 6, this results in 
* a floating point version of an integer, 2.000000.
*
* 10. (17.0 / 6.0) is a floating-point division, which results in 2.83333.
* This float is stored in the integer variable J. During this storage,
* the 2.8333 must be truncated to the integer 2.
*
* 12. Again, you are forcing the float 14.8 to fit into an 'int-shaped box',
* this time explicitly with the casting function: (int).
***********************************************************/
