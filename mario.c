#include <cs50.h>
#include <stdio.h>

//the function for hashes
void hashes(int number);

int main(void)
{
    //declaring int before inputting it from user
    int height;
    do
    {
        //getting the height of hases
        height = get_int("Height: ");
    }
    //criteria for the input
    while (height < 1 || height > 8);
    // makin Makin the number of lines
    for (int i = 0; i < height; i++)
    {
        //the spaces before the first stack
        for (int j  = height - i; j > 1; j--)
        {
            printf(" ");
        }
        //the first part
        hashes(i);
        //space between them
        printf("  ");
        //second part
        hashes(i);
        //makin a new line
        printf("\n");
    }
}


//makes the hashes
void hashes(int number)
{
    for (int a = 0; a < number + 1; a++)
    {
        printf("#");
    }
}
