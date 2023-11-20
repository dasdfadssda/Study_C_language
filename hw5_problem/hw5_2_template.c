#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Console.h"

#define MAX_ROW 256
#define MAX_COLUMN 512

char GetRandomChar();
void FillAlphaNum(char array[], int *no_char); // hw5_1
void Shuffle(char array[], int size);          // hw5_1

// screen buffer
char screen[MAX_ROW][MAX_COLUMN];
int screen_width = 0;
int screen_height = 0;

void DisplayBuffer(char buffer[][MAX_COLUMN], int width, int height);
void RandomizeBuffer(char buffer[][MAX_COLUMN], int width, int height);
void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c);

int main()
// DO NOT modify main()
{
    srand(time(NULL));

    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;

    clrscr();

    RandomizeBuffer(screen, screen_width, screen_height);
    DisplayBuffer(screen, screen_width, screen_height);
    gotoxy(1, screen_height + 1);
    fflush(stdout);
    MyPause();

    FillRectangle(screen, screen_width / 3, screen_height / 3, screen_width * 2 / 3, screen_height * 2 / 3, ' ');
    DisplayBuffer(screen, screen_width, screen_height);
    gotoxy(1, screen_height + 1);
    fflush(stdout);
    MyPause();

    return 0;
}

void DisplayBuffer(char buffer[][MAX_COLUMN], int width, int height)
{
    // DO NOT modify this function
    gotoxy(1, 1);
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            putchar(buffer[i][j]);
    }
}

void RandomizeBuffer(char buffer[][MAX_COLUMN], int width, int height)
{
    // TO DO: fill buffer with random alphanumeric characters
    //      for i in [1, height] and j in [1, width], fill buffer[i][j] with a random alphanumeric character using GetRandomChar()
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            buffer[i][j] = GetRandomChar();
    }
}

void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c)
{
    // TO DO: fill the rectangle (left, top, right, bottom) in buffer with character c
    //      for i in [top, bottom] and j in [left, right], set buffer[i][j] to c
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
            buffer[i][j] = c;
    }
}

// global variables for GetRandomChar()
char random_char[128]; // buffer to store random characters
int no_random = 0;     // # of character in the buffer
int cur_idx = 0;       // the index of the next random character

char GetRandomChar()
{
    // TO DO: provide a random alphanumeric character minimizing duplication
    //      if cur_idx is the same as no_random

    if (cur_idx == no_random)
    {
        //          if no_random is zero, fill random_char with alphanumeric characters using the FillAlphaNum() of hw5_1

        if (no_random == 0)
        {
            //          shuffle random_char using the Shuffle() function of hw5_1
            //      return random_char[cur_idx], increasing cur_idx (use the postfix increment operator)
            FillAlphaNum(random_char, &no_random);
            Shuffle(random_char, no_random);
        }
        cur_idx = 0;
    }

    return random_char[cur_idx++];
}

void FillAlphaNum(char array[], int *no_char)
{
    // TO DO: fill array with digits ('0' ~ '9'), uppercase characters ('A' ~ 'Z'), and lower case characters ('a' ~ 'z')
    //      reuse your solution to hw5_1
    int index = 0;

    for (char c = '0'; c <= '9'; ++c)
    {
        array[index++] = c;
    }

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        array[index++] = c;
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        array[index++] = c;
    }

    *no_char = index;
}

void Shuffle(char array[], int size)
{
    // TO DO: shuffle all elements of array
    //      reuse your solution to hw5_1
    for (int i = 0; i < size; ++i)
    {
        int j = rand() % size;

        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
