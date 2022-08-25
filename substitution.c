#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


bool validation(string key[], int no);
void cypher(string key, string plain);

int main(int argc, string argv[])
{
    if (validation(argv, argc) == false)
    {
        return (1);
    }
    string input = get_string("plaintext: ");
    printf("ciphertext: ");
    cypher(argv[1], input);
    return (0);
}


bool validation(string key[], int no)
{
    if (no < 2)
    {
        printf("do you think I am a fool?\n");
        return false;
    }
    string decypher = key[1];
    int length = strlen(decypher);

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (i == 1)
        {
            for (int b = 0; b < length; b++)
            {
                if (!(isalpha(decypher[b])))
                {
                    printf("don't put anything other than alphabets\n");
                    return false;
                }
                //now seeing if the characters repeat
                for (int c = b + 1; c < length; c++)
                {
                    if (decypher[b] == decypher[c])
                    {
                        printf("It has a repeating character\n");
                        return false;
                    }
                }
            }
        }
    }
    if (strlen(decypher) != 26)
    {
        printf("you have got more or less characters\n");
        return false;
    }
    return true;
}
//this function computes the ciphered text
void cypher(string key, string plain)
{
    string lower_key = key;
    for (int i = 0; i < 26; i++)
    {
        if (lower_key[i] >= 'A' && lower_key[i] <= 'Z')
        {
            lower_key[i] += 32;
        }
    }
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int plaintext_length = strlen(plain);
    for (int i = 0; i < plaintext_length; i++)
    {
        for (int a = 0; a < 26; a++)
        {
            if (plain[i] == alpha[a])
            {
                printf("%c", lower_key[a]);
            }
        }
        for (int b = 0; b < 26; b++)
        {
            if (plain[i] == ALPHA[b])
            {
                printf("%c", lower_key[b] - 32);
            }
        }
        if (!(isalpha(plain[i])))
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
