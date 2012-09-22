/**
 * myspace.c
 *
 * Nate Hardison <nate@cs.harvard.edu>
 *
 * CoNvErTs UsEr-InPuTtEd TeXt InTo MySpAcE sTyLe!
 *
 * Could also use islower() and/or isupper().
 * Doesn't *need* to use bitwise ops to swap case.
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
        if (('A' <= s[i] && s[i] <= 'Z') ||
            ('a' <= s[i] && s[i] <= 'z'))
        {
            // w00t look at my l33t binary ops
            // #h4ckr edition!
            if (num_letters_seen % 2 == 0)
                s[i] &= ~(1 << 5);
            else
                s[i] |= (1 << 5);
            num_letters_seen++;
        }
    }
    printf("%s\n", s);

    return 0;
}

