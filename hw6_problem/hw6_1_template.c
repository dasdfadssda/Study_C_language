#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN 64
typedef char String[MAX_LEN]; // define a new data type 'String' as 'char [MAX_LEN]'

String *lexicon = NULL; // pointer to store the address of dynamic memory block
int capacity = 0;       // maximum capacity of the lexicon
int no_word = 0;        // # of words in the lexicon

int CountWords(char filename[]);
void AddWord(char new_word[]);
void DisplayLexicon();

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];

    capacity = CountWords(filename);
    printf("file %s contains %d words\n", filename, capacity);

    // TO DO: allocate an array of String whose size is capacity (size should be capacity * sizeof(String))
    //      on failure, display an error message and quit.
    lexicon = (String *)malloc(capacity * sizeof(String));
    if (lexicon == NULL)
    {
        printf("Memory allocation failed");
        return -1;
    }

    // TO DO: open the file
    //      on failure, display an error message and quit.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File open failed");
        return -1;
    }

    int c = 0;
    int prev = ' ';
    char new_word[MAX_LEN] = "";
    int j = 0;

    // TO DO: retrieve words from the file
    //      The following algorithm is incomplete, missing a few steps. Complete the algorithm and implement it.

    for (int i = 0; (c = fgetc(fp)) != EOF; i++)
    {
        //  if the previous character is space and c is not,
        //      reset j to zero (start of a new word)
        //  otherwise, if the previous character is not space and c is,
        //      add zero at the end of new_word to make a zero-terminated string
        //      add new_word to the lexicon by calling AddWord()

        if (isspace(prev) && !isspace(c))
        {
            j = 0;
        }
        else if (!isspace(prev) && isspace(c))
        {
            new_word[j] = '\0';
            AddWord(new_word);
        }

        if (!isspace(c))
        {
            new_word[j] = (char)c;
            j++;
        }

        prev = c;
    }
    //  if c is not space, append c at the end of new_word and increase j
    if (j != 0)
    {
        new_word[j] = '\0';
        AddWord(new_word);
    }
    fclose(fp);
}

// TO DO: add the last word to the lexicon, if necessary
//  if j is not zero
//      add zero at the end of new_word to make a zero-terminated string
//      add new_word to the lexicon by calling AddWord()

// TO DO: close the file

DisplayLexicon();

// TO DO: delete lexcion
//      deallocate lexicon
//      reset lexicon to NULL for safety
//      reset no_word and capacity to zero
free(lexicon);
lexicon = NULL;
no_word = 0;
capacity = 0;

return 0;
}

int CountWords(char filename[])
{
    int count = 0;

    // TO DO: open file
    //      on failure, display an error message and quit.

    int c = 0;
    int prev = ' ';

    // TO DO: count transitions from space to non-space characters
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File open failed");
        return -1;
    }
    //      repeat to read a character from the file (use the fgetc() function)
    //          if the input character is EOF, break the loop
    //          if prev is space and the current charcter is not, increase count
    //          save the current character in prev

    while ((c = fgetc(fp)) != EOF)
    {
        if (isspace(prev) && !isspace(c))
        {
            count++;
        }

        prev = c;
    }

    // TO DO: close file
    fclose(fp);

    return count;
}

void AddWord(char new_word[])
// add new_word into the lexicon
{
    // TO DO:
    //      if no_word is greter than or equal to capacity,
    //          display a warning message indicating the lexicon is full
    //          wait for the Enter key (call getchar())
    //      otherwise,
    //          copy new_word to lexicon[no_word]
    //          increase no_word
    if (no_word >= capacity)
    {
        printf("Warning: The lexicon is full\n");
        getchar();
    }
    else
    {
        strcpy(lexicon[no_word], new_word);
        no_word++;
    }
}

void DisplayLexicon()
// DO NOT modify this function
{
    for (int i = 0; i < no_word; i++)
        printf("\tlexicon[%d] = \"%s\"\n", i, lexicon[i]);
    printf("Totally, %d words. (capacity = %d)\n", no_word, capacity);
}
