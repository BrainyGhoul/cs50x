#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    //initializing input
    float cash;
    //asking for it
    do
    {
        cash = get_float("Change owed: ");
    }
    //making a loop so that the user is restricted to put in a valid input
    while (cash < 0);
    //converting dollars to cents
    int cents = round(cash * 100);
    //a loop counter that counts the number of iterations
    int coin_count = 0;
    //looping through the conditions
    while (cents > 0)
    {
        //conditions for every amount or more
        if (cents >= 25)
        {
            //if a condition if fulfilled, the amount is subtracted
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        //adding value to count on evey iteration
        coin_count++;
    }
    //printing the number or iterations.
    printf("%i\n", coin_count);
}
