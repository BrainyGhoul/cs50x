#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int length = strlen(text);
    for (int i = 0; i <= length; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]) && !(isspace(text[i + 1])))
        {
            words++;
        }
    }
    float L = 100 * (float) letters / words;
    float S = 100 * (float) sentences / words;
    int level = round(0.0588 * L - 0.296 * S - 15.8);
    if (level > 16)
    {
        printf("Grade 16+\n");
    }
    else if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}