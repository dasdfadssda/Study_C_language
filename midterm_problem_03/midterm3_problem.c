/*
    Extend your solution of hw3_3 to rotate the text in the center of the screen.                                                                                                                                                                                                                      in python
        See midterm_demo.mp4
        - DO NOT delete or modify the algorithms

    Complete the program by writing the following functions
        - int MoveStar(int x1, int y1, int x2, int y2, int delay, char mesg[], int len, int *idx, int sx, int sy);
            moves a star from (x1, y1) to (x2, y2), while rotating a string
            . mesg: the text to rotate
            . len: the length of mesg
            . *idx: the index in mesg from which the function starts to display
            . sx and sy: coordinate to display mesg
        - void PrintRotated(char str[], int idx, int len)
            . display a string from the specified index (idx).
              (e.g., for str = "hello", idx = 3, and len = 5, PrintRotated() should display "lohel" )

    Compilation:
        on Windows: gcc <source file> Console.c -D_WINDOWS
            * run in DOS Prompt
        on MacOS:   gcc <source file> Console.c -D_MAC
            * run in a separate terminal

    Run on a separate terminal.
        e.g., Dos Prompt on Windows, Terminal on Mac
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Console.h"

#define TRUE 1
#define FALSE 0

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

int screen_width = 0;
int screen_height = 0;

int completed = TRUE; // enable this line after completing MoveStar()
// int completed = FALSE;        // enable this line before completing MoveStar()

int MoveStar(int x1, int y1, int x2, int y2, int delay, char mesg[], int len, int *idx, int sx, int sy);
void PrintRotated(char str[], int idx, int len);

int main() // convert this into python without explanation
{
    char mesg[256] = "You are the masterpiece of God! ";
    int len = strlen(mesg);

    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;

    clrscr();

    if (completed == FALSE)
    {
        int idx = 0;
        MoveStar(screen_width / 2, 2, 1, screen_height / 2, 30, mesg, len, &idx, 1, 1);
        return 0;
    }
    else
    {
        gotoxy(1, screen_height);
        printf("Press ESC to quit.");

        // coordinates of the corners
        int x[5] = {screen_width / 4, screen_width * 3 / 4, screen_width * 3 / 4, screen_width / 4, screen_width / 4};
        int y[5] = {screen_height / 4, screen_height / 4, screen_height * 3 / 4, screen_height * 3 / 4, screen_height / 4};

        int sx = (screen_width - len) / 2;
        int sy = screen_height / 2;
        gotoxy(sx, sy);
        printf("%s", mesg);

        int idx = 0;
        for (int i = 0; 1; i = (i + 1) % 4)
        {
            int ret = 0;
            if (i % 2 == 0)
                ret = MoveStar(x[i], y[i], x[i + 1], y[i + 1], 30, mesg, len, &idx, sx, sy);
            else
                ret = MoveStar(x[i], y[i], x[i + 1], y[i + 1], 60, mesg, len, &idx, sx, sy);

            if (ret == FALSE)
                break;
        }
    }

    gotoxy(1, screen_height + 1);
    printf("Bye!\n");

    return 0;
}

int MoveStar(int x1, int y1, int x2, int y2, int delay, char mesg[], int len, int *idx, int sx, int sy) // convert this into python without explanation
{

    // TO DO: implement this function to move a star ('*') from (x1, y1) to (x2, y2), rotating mesg at (sx, sy)
    //  repeat for t from 0 to dist
    //      save x and y in prevx and prevy
    //      compute x and y by linear interpolation
    //          x = ((dist - t) * x1 + t * x2) / dist
    //          y = ((dist - t) * y1 + t * y2) / dist
    //      erase the previous star by displaying ' ' at the previous coordinate (prevx, prevy)
    //      draw '*' at the new coordinate (x, y)

    //      increase *idx
    //      if *idx is equal to len, set *idx to zero
    //      move cursor to (sx, sy)
    //      display mesg from *idx-th character by calling PrintRotated()

    //      insert the following two lines to break the loop on ESC
    //         if(kbhit() && getch() == 27)     // 27 is the ASCII code of ESC
    //            return FALSE;

    //      move the cursor to (1, screen_height)
    //      call "fflush(stdout);"
    //      wait for delay msec. (call "MySleep(delay);")

    int dx = ABS(x1 - x2);
    int dy = ABS(y1 - y2);
    int dist = MAX(dx, dy);

    int x = 0, y = 0;
    int prevx = x1, prevy = y1;

    for (int t = 0; t <= dist; t++)
    {
        prevx = x;
        prevy = y;
        x = ((dist - t) * x1 + t * x2) / dist;
        y = ((dist - t) * y1 + t * y2) / dist;

        gotoxy(prevx, prevy);
        putchar(' ');
        gotoxy(x, y);
        putchar('*');
        (*idx)++;
        if (*idx == len)
        {
            *idx = 0;
        }

        gotoxy(sx, sy);
        PrintRotated(mesg, *idx, len);

        if (kbhit() && getch() == 27)
        {
            return FALSE; // ESC key pressed
        }

        gotoxy(1, screen_height);
        fflush(stdout);
        MySleep(delay);
    }

    return TRUE;
}

void PrintRotated(char str[], int idx, int len) // convert this into python without explanation
{
    for (int i = 0; i < len; i++)
    {
        putchar(str[(idx + i) % len]);
    }
    /*
        TO DO: display str in a circular way, starting from idx-th character
            for i from 0 to len
                display str[(idx + i) % len];

    */
}
