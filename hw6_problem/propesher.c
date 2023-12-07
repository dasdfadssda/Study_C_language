#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN 64
 
struct String {
    char word[MAX_LEN];
    int count;
};

struct String *lexicon = NULL;
int capacity = 0;
int no_word = 0;

int CountWords(char filename[]);
void AddWord3(char new_word[]);
void DisplayLexicon();

int FindWord3(char target_word[]);
void SortLexiconByCount();

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
   
    capacity = CountWords(filename);
    printf("file %s contains %d words\n", filename, capacity);

    // TO DO: allocate an array of String whose size is capacity (size should be capacity * sizeof(struct String))
    //      on failure, display an error message and quit.
    //  reuse your solution to hw6_1
    lexicon = (struct String *)malloc(capacity * sizeof(struct String));
    if(lexicon == NULL){
        printf("failed to allocate memory in Line %s of %s\n", __LINE__, __FILE__);
        exit(-1);
    }

    // TO DO: open the file
    //      on failure, display an error message and quit.
    //  reuse your solution to hw6_2
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Failed to open file %s\n", filename);
        exit(-1);
    }

    int c = 0;
    int prev = ' ';
    char new_word[MAX_LEN] = "";
    int j = 0;

    // TO DO: retrieve words from the file
    //      The following algorithm is incomplete, missing a few steps. Complete the algorithm and implement it.
    for(int i = 0; (c = fgetc(fp)) != EOF; i++){
        //  if the previous character is space and c is not,
        //      reset j to zero (start of a new word)
        if(isspace(prev) && !isspace(prev))
            j = 0;
        //  otherwise, if the previous character is not space and c is space,
        else if(!isspace(prev) && isspace(c)){
        //      add zero at the end of new_word to make a zero-terminated string
            new_word[j] = 0;
        //      add new_word to the lexicon by calling AddWord3()
            AddWord3(new_word);

            j = 0;
        }

        // if c is not space, append c at the end of new_word and increase j
        if(!isspace(c))
            new_word[j++] = c;

        prev = c;
    }

    // TO DO: add the last word to the lexicon, if necessary
    //  if j is not zero
    if(j > 0){
    //      add zero at the end of new_word to make a zero-terminated string
        new_word[j] = 0;
    //      add new_word to the lexicon by calling AddWord3()
        AddWord3(new_word);
    }

    // TO DO: close the file
    fclose(fp);

//    DisplayLexicon();         // if necessary, enable this line during debugging

    SortLexiconByCount();

    DisplayLexicon();


    // TO DO: delete lexcion
    //      deallocate lexicon
    free(lexicon));
    //      reset lexicon to NULL for safety
    lexicon = NULL;
    //      reset no_word and capacity to zero
    no_word = capacity = 0;
    
    return 0;
}

int CountWords(char filename[])
{
    // reuse your solution to hw6_1

}

void AddWord3(char new_word[])
// add new_word into the lexicon avoiding duplication
{
    // TO DO: 
    //   find the index of new_word from the lexicon by calling FindWord3() (store the index of new_word in a variable)
    int index = FindWord3(new_word);

    //   if new_word exists in the lexicon,
    //       increase the corresponding counter (e.g, lexicon[index].count)
    if(index >= 0)
        lexicon[index].count++;
    //   otherwise, add new_word into lexicon and initialize its counter by one
    else {
    //      if no_word is greter than or equal to capacity,
        if(no_word >= capacity){
    //          display a warning message indicating the lexicon is full
            printf("Warning! Lexicon is full!!!\n");
    //          wait for the Enter key (call getchar())
            getchar();
        } else {
    //      otherwise,
    //          copy new_word to lexicon[no_word].word
            strcpy(lexicon[no_word].word, new_word);
    //          set lexicon[no_word].count to one
            lexicon[no_word].count = 1;
    //          increase no_word
            no_word++;
        }
    }
    
}

void DisplayLexicon()
{
    for(int i = 0; i < no_word; i++)
        printf("\tlexicon[%d] = \"%s\" (count = %d)\n", i, lexicon[i].word, lexicon[i].count);
    printf("Totally, %d words. (capacity = %d)\n", no_word, capacity);
}

int FindWord3(char target_word[])
{
    // TO DO: return the index of target_word in lexicon
    //  if target_word is not in lexicon, return -1

    int i = 0;
    for(i = 0; i < no_word; i++){
        //if(a[i] == target)
        if(strcmp(target_word, lexicon[i].word) == 0)
            break;
    }

    if(i == no_word)
        return -1;

    return i;
}

void SortLexiconByCount()
{
    // TO DO: sort lexicon BY COUNT in DESCENDING ORDER
    //     adapt the algorithm SelectionSort() in chap. 8 slide to sort an array of 'struct String'

   int current = 0;         // the start of the unsorted list
   for(current = 0; current < no_word - 1; current++){
      // find the smallest in the unsorted list
      int smallest = current;   // location of the smallest element 
      for(int i = current + 1; i < no_word; i++)
         if(lexicon[i].count > lexicon[smallest].count)
            smallest = i;

      // exchange the smallest with the first of unsorted list
      struct String temp = lexicon[current];
      lexicon[current] = lexicon[smallest];
      lexicon[smallest] = temp;
   }
}