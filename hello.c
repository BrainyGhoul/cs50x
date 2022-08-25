#include <stdio.h>
#include<cs50.h> 

int main(void)
{
    //asking for the name and storing in a string variable
    string name = get_string("What is your name?");
    //printing hello alonwith the name.
    printf("hello, %s\n", name);
}
