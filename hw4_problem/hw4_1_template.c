#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WHITESPACE 0
#define ALPHABET 1
#define DIGIT 2
#define SYMBOL 3
#define OTHER 4

int GetCharacterType(int c);

int main()
{
    char text[256] = "";

    // read a text line from the user
    printf("Input text: ");
    fgets(text, 255, stdin);        // read a text line from the keyboard upto the Enter key.
    int len = strlen(text);         // get the length of text
    text[--len] = 0;                // trim '\n' at the end of text

    int no_word = 0;                // word counter
    char word[128] = "";            // buffer to store the characters of the current word
    int p = 0;                      // index in word

    int prev_type = WHITESPACE;     // the type of the previous character

    // TO DO: display and count all words in the input text
    //  repeat for i in range [0, len)
    //      decide the type of the current chracter, text[i]
    //      if the type is different from the that of the previous character,
    //          make word a zero-terminated string by appending zero
    //          if the previous character was not a whitespace character,
    //              display word and increase the word counter
    //          start a new word by resetting p to zero
    //      copy text[i] to word[p] and increase p
    //      save the type of the current character in prev_type

    //  if p is not zero, append zero to word, display word, and increase the word counter



    printf("Totally, %d words\n", no_word);

    return 0;
}

int GetCharacterType(int c)
{
    int type = OTHER;

    // TO DO: return the type of c
    //      Use isspace(), isalpha(), isdigit(), ispunct() to decide the type of the character.

    
    return type;
}
