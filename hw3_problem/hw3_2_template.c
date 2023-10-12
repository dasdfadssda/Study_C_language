#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space);

int main()
{
    int no_upper = 0;
    int no_lower = 0;
    int no_digit = 0;
    int no_space = 0;

    char text[256] = "";

    // reads a text line beyond space characters.
    printf("Input a string: ");    
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;

    printf("Input string = \"%s\"\n", text);

    // TO DO: call CountCharacter() to get the number of uppercase, lowercase, digit, and space characters.
    


    printf("The input string contains\n");
    printf("\t%d uppercase characters,\n", no_upper);
    printf("\t%d lowercase characters,\n", no_lower);
    printf("\t%d digit characters,\n", no_digit);
    printf("\t%d space characters.\n", no_space);

    return 0;
}

void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space)
{
    // TO DO: implement this function
    //  initialize all output variables to zero

    //  repeat for i from 0 to the length of str
    //      if str[i] is a uppercase character, increase *no_upper
    //      if str[i] is a lowercase character, increase *no_lower
    //      if str[i] is a digit character, increase *no_digit
    //      if str[i] is a space character, increase *no_space

    // Hint) *no_upper++ does not work correctly. use (*no_upper)++ to increase 8no_upper

 



}