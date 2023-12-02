#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN 64
typedef char String[MAX_LEN];           // define 'String' as 'char [MAX_LEN]'

String *lexicon = NULL;
int *count = NULL;
int capacity = 0;
int no_word = 0;

int CountWords(char filename[]);
void AddWord2(char new_word[]);
void DisplayLexicon();

int FindWord2(char target_word[]);
void SortLexicon();

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
   
    capacity = CountWords(filename);
    printf("file %s contains %d words\n", filename, capacity);

    // TO DO: allocate an array of String whose size is capacity (size should be capacity * sizeof(String))
    //      on failure, display an error message and quit.
    //  reuse your solution to hw6_1
    

    // TO DO: fill count with zeros (use a for-statement)
    //  reuse your solution to hw6_1

    // TO DO: open the file
    //      on failure, display an error message and quit.
    //  reuse your solution to hw6_1
    FILE *fp = NULL;
    

    int c = 0;
    int prev = ' ';
    char new_word[MAX_LEN] = "";
    int j = 0;

    // TO DO: retrieve words from the file
    //      The following algorithm is incomplete, missing a few steps. Complete the algorithm and implement it.
    for(int i = 0; (c = fgetc(fp)) != EOF; i++){
        //  if the previous character is space and c is not,
        //      reset j to zero (start of a new word)
        //  otherwise, if the previous character is not space and c is space,
        //      add zero at the end of new_word to make a zero-terminated string
        //      add new_word to the lexicon by calling AddWord2()

        // if c is not space, append c at the end of new_word and increase j

    }

    // TO DO: add the last word to the lexicon, if necessary
    //  if j is not zero
    //      add zero at the end of new_word to make a zero-terminated string
    //      add new_word to the lexicon by calling AddWord2()



    // TO DO: close the file




//    DisplayLexicon();         // if necessary, enable this line during debugging

    SortLexicon();

    DisplayLexicon();


    // TO DO: delete lexcion
    //      deallocate lexicon
    //      reset lexicon to NULL for safety
    //      reset no_word and capacity to zero

    


    return 0;
}

int CountWords(char filename[])
{
    // reuse your solution to hw6_1
    
}

void AddWord2(char new_word[])
// add new_word into the lexicon avoiding duplication
// NOTE! This function is different from that AddWord2 of hw6_1
{
    // TO DO: 
    //   find the index of new_word from the lexicon by calling FindWord2() (store the index of new_word in a variable)
    //   if new_word exists in the lexicon,
    //       increase the corresponding counter (e.g, count[index])
    //   otherwise, add new_word into lexicon and initialize its counter by one
    //      if no_word is greter than or equal to capacity,
    //          display a warning message indicating the lexicon is full
    //          wait for the Enter key (call getchar())
    //      otherwise,
    //          copy new_word to lexicon[no_word]
    //          set counter[no_word] to one
    //          increase no_word

    



}

void DisplayLexicon()
{
    for(int i = 0; i < no_word; i++)
        printf("\tlexicon[%d] = \"%s\" (count = %d)\n", i, lexicon[i], count[i]);
    printf("Totally, %d words. (capacity = %d)\n", no_word, capacity);
}

int FindWord2(char target_word[])
{
    // TO DO: return the index of target_word in lexicon
    //  if target_word is not in lexicon, return -1




}

void SortLexicon()
{
    // TO DO: sort lexicon and count in alphabetical order
    //     adapt the algorithm SelectionSort() in chap. 8 slide to sort the two arrays 


}
