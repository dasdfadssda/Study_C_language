/*
    Compilation on Windows
        gcc console_demo2.c Console.c -D_WINDOWS

    Compilation on Mac
        gcc console_demo2.c Console.c -D_MAC

*/

#include <stdio.h>                      // includes a file in the system directory

#include "Console.h"                    // includes a file in the current directory

int screen_width = 0;
int screen_height = 0;

void MoveRight(int x1, int x2, int y);
void MoveLeft(int x1, int x2, int y);

int main()
{
    // get the size of the screen
    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;      // -3 is to prevent vertical scroll

    clrscr();                   // clear screen
    
    MoveRight(1, screen_width, screen_height / 2);
        MoveLeft(1, screen_width, screen_height / 2);


/*
    int x = 0;
    int y = screen_height / 2;          // set y to the vertical center
    int prevx = 1;

    for(x = screen_width; x >= 1; x--){
        // erarse previous coordinate
        gotoxy(prevx, y);
        putchar(' ');

        // draw a new '*' at the new coordinate
        gotoxy(x, y);
        putchar('*');

        // save the previous coordinate
        prevx = x;
        gotoxy(1, screen_height);   // place the cursor at the lower-left corner to prevent blicking

        fflush(stdout);             // flush contents to display on the screen

        // wait for 50 msec.
        MySleep(25);
    }
*/
    gotoxy(1, screen_height);       // move the cursor to lower left coordinate
//    MyPause();                    // wait for the user to type Enter key.

    return 0;
}

void MoveRight(int x1, int x2, int y)
{
    int x = 0;
    int prevx = x1;

    for(x = x1; x <= x2; x++){
        // erarse previous coordinate
        gotoxy(prevx, y);
        putchar(' ');

        // draw a new '*' at the new coordinate
        gotoxy(x, y);
        putchar('*');

        // save the previous coordinate
        prevx = x;
        gotoxy(1, screen_height);   // place the cursor at the lower-left corner to prevent blicking

        fflush(stdout);             // flush contents to display on the screen

        // wait for 50 msec.
        MySleep(25);
    }
}


void MoveLeft(int x1, int x2, int y)
{
    int x = 0;
    int prevx = x1;

    for(x = x2; x <= x1; x--){
        // erarse previous coordinate
        gotoxy(prevx, y);
        putchar(' ');

        // draw a new '*' at the new coordinate
        gotoxy(x, y);
        putchar('*');

        // save the previous coordinate
        prevx = x;
        gotoxy(1, screen_height);   // place the cursor at the lower-left corner to prevent blicking

        fflush(stdout);             // flush contents to display on the screen

        // wait for 50 msec.
        MySleep(25);
    }
}