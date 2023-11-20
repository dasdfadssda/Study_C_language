#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillAlphaNum(char array[], int *no_char);
void Shuffle(char array[], int size);

int main()
// DO NOT modify main()
{
    char alphanum[128] = {0};
    int no_char = 0;

    srand(time(NULL));

    FillAlphaNum(alphanum, &no_char);

    printf("alphanum (%d) = [%s]\n", no_char, alphanum);

    Shuffle(alphanum, no_char);

    printf("alphanum (%d) = [%s]\n", no_char, alphanum);

    return 0;
}

void FillAlphaNum(char array[], int *no_char)
{
    // TO DO: fill array with digits ('0' ~ '9'), uppercase characters ('A' ~ 'Z'), and lower case characters ('a' ~ 'z')
    int num = 0;

    // fill array[0] ~ array[9] with digit characters '0' ~ '9' (for c from '0' to '9', set array[c] with c.)
    for (char c = '0'; c <= '9'; ++c)
    {
        array[num++] = c;
    }
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        array[num++] = c;
    }
    for (char c = 'a'; c <= 'z'; ++c)
    {
        array[num++] = c;
    }

    // set the number of characters in array
    *no_char = num;
    //      append a null character at the end of array to make a zero-terminated string
    array[num] = '\0';
}

void Shuffle(char array[], int size)
{
    // TO DO: shuffle all elements of array
    for (int i = 0; i < size; ++i)
    {
        //      repeat for i from 0 to size
        int j = rand() % size;

        // exchange array[i] and array[j]
        // generate a random number j in range [0, size)
        // exchange array[i] and array[j]
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
