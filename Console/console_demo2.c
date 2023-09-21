/*
    Compilation on Windows
        gcc console_demo2.c Console.c -D_WINDOWS

    Compilation on Mac
        gcc console_demo2.c Console.c -D_MAC

*/

#include <stdio.h>                      // includes a file in the system directory

#include "Console.h"                    // includes a file in the current directory

int main()
{
    // get the size of the screen
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;      // -3 is to prevent vertical scroll

    clrscr();                   // clear screen

    int x = 0;
    int y = screen_height / 2;          // set y to the vertical center
    int prevx = 1;

    for(x = 1; x <= screen_width; x++){
        // erarse previous coordinate
        gotoxy(prevx, y);
        putchar(' ');

        // draw a new '*' at the new coordinate
        gotoxy(x, y);
        putchar('*');

        // save the previous coordinate
        prevx = x;
        gotoxy(1, screen_height);   // place the cursor to prevent blicking

        fflush(stdout);             // flush contents to display on the screen

        // wait for 50 msec.
        MySleep(50);
    }

    gotoxy(1, screen_height);       // move the cursor to lower left coordinate
//    MyPause();                    // wait for the user to type Enter key.

    return 0;
}
