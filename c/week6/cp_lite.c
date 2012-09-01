/*****************************************************
* cp_lite.c
*
* #file #io #fread #fwrite #fopen #fclose #data #information #context
*
* Kevin Schmid (Source code from http://cdn.cs50.net/2011/fall/psets/5/pset5/bmp/copy.c)
* Computer Science 50
*
* Covers fread, fwrite, fopen, and fclose.
*
* Below is an excerpted version of the source code from
* Problem Set 5's copy.c.  Check it out!
*
* Directions: See if you can add code in the labeled space below that
* will copy the contents (bytes) of infile (not necessarily a BMP) to outfile.
*
* You'll probably want to do something like:
* - Declare a array that can act as a buffer. (Which C type(s) would work well for this?)
* - Using fread(), try to read bytes into the buffer from the input file.
	(What if not all of the bytes you asked for were read? How would you know?)
* - Using fwrite(), write bytes from the buffer to the output file.
*
* How would you know when you should continue? Stop?
*
* Follow up questions:
* 1) How is cp_lite.c different from copy.c?
* 2) Why might it be useful to look at data within a certain context, as in copy.c?
* 3) When might it be useful to look at data without context, as in cp_lite.c?
*******************************************************/

#include<stdio.h>

int main(int argc, char * argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: cp_lite infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

	// ADD CODE HERE!

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
