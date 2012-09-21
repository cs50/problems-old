/**
 * myspace.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * CoNvErTs UsEr-InPuTtEd TeXt InTo MySpAcE sTyLe!
 * 
 * Could also use islower().
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    int num_letters_seen = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (num_letters_seen % 2 == 0)
                s[i] -= 32;
            num_letters_seen++;
        }
    }
    printf("%s\n", s);

    return 0;
}
