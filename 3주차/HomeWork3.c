#include <stdio.h>

int main ()
{

    char s[] = "";

    // receive the word 
    printf ("What is between birth and death?\n");
    printf ("Answer in a word starting with C: ");
    scanf("%s", s);


    //read the word, wheather it starts with C
    char str = 'c'; 


    //print the result in format “Birth - <input word> - Death”
    printf ( "Birth - %s - Death", s);

    return 0;

}