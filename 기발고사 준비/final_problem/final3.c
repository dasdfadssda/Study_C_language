/*
    Write a program that reads a text line, shuffles the words in the input text, and concatenate the suffled words into a text.
    Implement AddWord() and ShuffleWords().
    DO NOT modify main().

    Example) The user types "God loves you and has a wonderful plan for your life."
        Input text: God loves you and has a wonderful plan for your life.                                                     
        ### Before shuffle: 11 words
        word   0: 0 3 "God"
        word   1: 4 9 "loves"
        word   2: 10 13 "you"
        word   3: 14 17 "and"
        word   4: 18 21 "has"
        word   5: 22 23 "a"
        word   6: 24 33 "wonderful"
        word   7: 34 38 "plan"
        word   8: 39 42 "for"
        word   9: 43 47 "your"
        word  10: 48 53 "life."
        ### After shuffle: 11 words
        word   0: 10 13 "you"
        word   1: 48 53 "life."
        word   2: 39 42 "for"
        word   3: 34 38 "plan"
        word   4: 4 9 "loves"
        word   5: 0 3 "God"
        word   6: 24 33 "wonderful"
        word   7: 43 47 "your"
        word   8: 14 17 "and"
        word   9: 18 21 "has"
        word  10: 22 23 "a"
        shuffled text = "you life. for plan loves God wonderful your and has a"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_WORD 256
#define MAX_WORD_LEN 64

typedef struct {
    int start, end;
    char word[MAX_WORD_LEN];
} Word;

Word words[MAX_WORD];
int no_word = 0;

void DisplayWords(Word words[], int n);
void AddWord(char *str, int start, int end);
void ShuffleWords(Word words[], int n);
void ConcatAllWords(Word words[], int n, char text[]);

int FindNextWord(char *str, int *start, int *end);

int main()
{
    srand(time(NULL));

#ifdef DEBUG
    char text[] = "God loves you and has a wonderful plan for your life.";
    printf("Input text: %s\n", text);
#else
    char text[256] = "";
    printf("Input text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;
#endif

    int start_idx = 0, end_idx = 0;

    while (FindNextWord(text, &start_idx, &end_idx))
        AddWord(text, start_idx, end_idx);

    printf("### Before shuffle: ");
    DisplayWords(words, no_word);

    ShuffleWords(words, no_word);
    printf("### After shuffle: ");
    DisplayWords(words, no_word);

    ConcatAllWords(words, no_word, text);
    printf("shuffled text = \"%s\"\n", text);

    return 0;
}

int FindNextWord(char *str, int *start, int *end)
{
    while (isspace(str[*start]) && str[*start] != '\0') {
        (*start)++;
    }

    if (str[*start] == '\0') {
        *start = -1;
        *end = -1;
        return FALSE;
    }

    *end = *start + 1;
    while (!isspace(str[*end]) && str[*end] != '\0') {
        (*end)++;
    }

    return TRUE;
}

void DisplayWords(Word words[], int n)
{
    printf("%d words\n", n);
    for (int i = 0; i < n; i++) {
        printf("word %3d: %d %d \"%s\"\n", i, words[i].start, words[i].end, words[i].word);
    }
}

void AddWord(char *str, int start, int end)
{
    for (int i = start; i < end; i++) {
        words[no_word].word[i - start] = str[i];
    }
    words[no_word].word[end - start] = '\0';
    no_word++;
}

void ShuffleWords(Word words[], int n)
{
    Word temp;
    int rand_index;

    for (int i = 0; i < n; i++) {
        rand_index = rand() % n;
        temp = words[i];
        words[i] = words[rand_index];
        words[rand_index] = temp;
    }
}

void ConcatAllWords(Word words[], int n, char text[])
{
    text[0] = '\0';

    for (int i = 0; i < n; i++) {
        strcat(text, words[i].word);
        if (i < n - 1) {
            strcat(text, " ");
        }
    }
}
