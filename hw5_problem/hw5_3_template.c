#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Console.h"

#define MAX_ROW 256
#define MAX_COLUMN 512

char GetRandomChar();                          // hw5_2
void FillAlphaNum(char array[], int *no_char); // hw5_1
void Shuffle(char array[], int size);          // hw5_1

// screen buffer
char screen[MAX_ROW][MAX_COLUMN];
int screen_width = 0;
int screen_height = 0;

void DisplayBuffer(char buffer[][MAX_COLUMN], int width, int height);                            // hw5_2
void RandomizeBuffer(char buffer[][MAX_COLUMN], int width, int height);                          // hw5_2
void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c); // hw5_2

int main()
{
    srand(time(NULL));

    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;

    clrscr();

    RandomizeBuffer(screen, screen_width, screen_height);
    DisplayBuffer(screen, screen_width, screen_height);
    MySleep(1000);

    FillRectangle(screen, screen_width * 3 / 8, screen_height * 3 / 8, screen_width * 5 / 8, screen_height * 5 / 8, ' ');
    DisplayBuffer(screen, screen_width, screen_height);
    MySleep(1000);

    FillRectangle(screen, screen_width * 2 / 4, screen_height / 4, screen_width * 3 / 4, screen_height * 2 / 4, ' ');
    DisplayBuffer(screen, screen_width, screen_height);
    MySleep(1000);

    FillRectangle(screen, screen_width / 4, screen_height * 2 / 4, screen_width * 2 / 4, screen_height * 3 / 4, ' ');
    DisplayBuffer(screen, screen_width, screen_height);
    MySleep(1000);

    int x = screen_width / 2;
    int y = screen_height / 2;
    int dx = 2;
    int dy = 1;

    gotoxy(1, screen_height + 1);
    printf("Press ESC to quit!");

    while (!kbhit() || getch() != 27)
    { // repeat until the user presses ESC

        // TO DO: bounce a ball

        int prevx = x;
        int prevy = y;
        // check bounce and negiate dx and/or dy if the ball hit a non-space character
        // if screen[y + dy][x + dx] is not space character,
        //  if screen[y + dy][x - dx] is space and screen[y][x + dx] is not, set dx to -dx
        if (x + dx >= screen_width || x + dx < 1)
        {
            dx = -dx;
        }
        if (y + dy >= screen_height || y + dy < 1)
        {
            dy = -dy;
        }

        // otherwise, if screen[y - dy][x + dx] is space and screen[y + dy][x] != ' ' is not, set dy to -dy
        // otherwise, set dx to -dx and set dy to -dy
        if (screen[y + dy][x + dx] != ' ')
        {
            if (screen[y + dy][x - dx] == ' ' && screen[y][x + dx] != ' ')
            {
                dx = -dx;
            }
            else if (screen[y - dy][x + dx] == ' ' && screen[y + dy][x] != ' ')
            {
                dy = -dy;
            }
            else
            {
                dx = -dx;
                dy = -dy;
            }
        }

        // update x and y (add dx to x and dy to y)
        x += dx;
        y += dy;

        // erase the previous coordinate (set screen[prevy][prevx] to ' ' and print ' ' at (prevx, prevy))
        screen[prevy][prevx] = ' ';
        gotoxy(prevx, prevy);
        putchar(' ');

        // draw a ball at the new coordinate (set screen[y][x] to '*' and print '*' at (x, y))
        screen[y][x] = '*';
        gotoxy(x, y);
        putchar('*');

        // move the cursor to (1, screen_height)
        gotoxy(1, screen_height);

        // call fflush(stdout)
        fflush(stdout);
        // call MySleep(20)
        MySleep(20);
    }

    gotoxy(1, screen_height);
    printf("Bye!\n");

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
    //      reuse your solution to hw5_2
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            buffer[i][j] = GetRandomChar();
    }
}

void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c)
{
    // TO DO: fill the rectangle (left, top, right, bottom) in buffer with character c
    //      reuse your solution to hw5_2
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
    //      reuse your solution to hw5_2
    if (cur_idx == no_random)
    {
        if (no_random == 0)
        {
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
