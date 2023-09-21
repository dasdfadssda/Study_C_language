/*
    Compilation on Windows
        gcc console_demo1.c Console.c -D_WINDOWS

    Compilation on Mac
        gcc console_demo1.c Console.c -D_MAC

*/

#include <stdio.h>                      // includes a file in the system directory

#include "Console.h"                    // includes a file in the current directory

int main()
{
    // get the size of the screen
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;      // -3 is to prevent vertical scroll

    clrscr();                   // clear screen

    int x = 0, y = 0;

    for(x = 1; x < 20; x++){
        y = x / 2 + 1;
        gotoxy(x, y);
        putchar('*');
    }

    gotoxy(1, screen_height);   // move the cursor to lower left coordinate
    MyPause();                  // wait for the user to type Enter key.

    return 0;
}
