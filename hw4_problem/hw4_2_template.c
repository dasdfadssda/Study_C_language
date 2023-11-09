#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WHITESPACE 0
#define ALPHABET 1
#define DIGIT 2
#define SYMBOL 3
#define OTHER 4

int GetCharacterType(int c);

int main(int argc, char *argv[])
// argv[0]: executable file (e.g., a.exe, a.out, etc.)
// argv[1]: target word
// argv[2]: text file
{
    if(argc <= 2){
        printf("Usage: %s <target_word> <filename>\n", argv[0]);
        exit(0);
    }

    char *target = argv[1];
    char *filename = argv[2];

    FILE *fp = NULL;
    // TO DO: open file using filename.
    //      on failure, display an error message and quit.




    int no_line = 0;                // line counter
    int no_word = 0;                // word counter
    int no_target_word = 0;         // target-word counter

    char word[128] = "";            // buffer to store the characters of the current word
    int p = 0;                      // index in word

    int prev_type = WHITESPACE;

    int c = 0;
    while((c = fgetc(fp)) != EOF){
        // TO DO: implement the boy of this loop
        //      if c is the new line character, increase the line counter
        //      get the type of the current character
        //
        //      extract words by the same way as hw4_1
        //
        //      when word is the same as the target word,
        //          display a message indicating the target word was found in the current line (use no_line) and increase the target-word counter
        // hint) a standard function strcmp(str1, str2) returns zero when str1 and str2 contains the same string





    }

    // TO DO: increase no_line to count the last line

    // TO DO: close the file

    

    printf(" %d / %d target words are found from %d lines.\n", no_target_word, no_word, no_line);

    return 0;
}

int GetCharacterType(int c)
{
    int type = OTHER;

    // TO DO: return the type of c (reuse your solution to hw4_1)
        if (isspace(c))
    {
        return WHITESPACE;
    }
    else if (isalpha(c))
    {
        return ALPHABET;
    }
    else if (isdigit(c))
    {
        return DIGIT;
    }
    else if (ispunct(c))
    {
        return SYMBOL;
    }
    else
    {
        return OTHER;
    }

    return type;


    
    return type;
}
