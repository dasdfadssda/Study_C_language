#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_WORD_LEN 64

int FindNextWord(char *str, int *start, int *end);
void Substring(char *str, int start, int end, char *substring);

int main()
{
#ifdef DEBUG
    char text[] = "God loves you    and  has  a wonderful plan      for your life.     ";
    printf("Input text: %s\n", text);
#else
    char text[256] = "";
    printf("Input text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;
#endif

    int start_idx = 0, end_idx = 0;

    while (FindNextWord(text, &start_idx, &end_idx))
    {
        printf("start_idx = %d, end_idx = %d, ", start_idx, end_idx);
        fflush(stdout);

        char substring[MAX_WORD_LEN] = "";
        Substring(text, start_idx, end_idx, substring);
        printf("substring = \"%s\"\n", substring);
    }

    return 0;
}

int FindNextWord(char *str, int *start, int *end)
{
    // Debugging purposes
    printf("str = [%s], *start = %d, *end = %d\n", str, *start, *end);

    // Finding the start index of a word
    while (isspace(str[*start]) && str[*start] != '\0')
    {
        (*start)++;
    }

    // Checking for the end of the string
    if (str[*start] == '\0')
    {
        *start = -1;
        *end = -1;
        return FALSE;
    }

    // Finding the end index of the word
    *end = *start + 1;
    while (!isspace(str[*end]) && str[*end] != '\0')
    {
        (*end)++;
    }

    return TRUE;
}

void Substring(char *str, int start, int end, char *substring)
{
    int i = 0, j = 0;

    for (i = start; i < end; i++, j++)
    {
        substring[j] = str[i];
    }
    // Adding null terminator at the end of the substring
    substring[j] = '\0';
}

