#include <stdio.h>      // required for printf() and scanf()
#include <string.h>     // required for strlen()

// function declaration
char LowerToUpper(char lower);

int main()
{
    char inp_str[128] = "";

    // read a string
    printf("Input a string: ");
    scanf("%s", inp_str);

    // get the length of the string
    int len = strlen(inp_str);

    // convert all lowercase characters in inp_str to upper case
    // hint: use the for-statement
    int i = 0;
    for(i = 0; i < len; i++){
        inp_str[i] = LowerToUpper(inp_str[i]);   // function call to convert inp_str[i] to uppercase
    }

    // display the conversion result
    printf("conversion result = %s\n", inp_str);

    return 0;
}

char LowerToUpper(char lower)
{
    char upper = 0;

    // convert lowercase to uppercase
    if(lower >= 'a' && lower <= 'z'){
//      upper = lower - 'a' + 'A';    // fine
        upper = lower + 'A' - 'a';      // safer
    } else {
        upper = lower;
    }

    // return the result
    return upper;
}