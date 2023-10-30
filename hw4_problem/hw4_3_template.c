/*
    Compilation
        gcc <source_file> Console.c -D_WINDOWS      // on Windows
        gcc <source_file> Console.c -D_MAC      // on MacOS

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Console.h"

#define TRUE 1
#define FALSE 0

#define PI 3.141592

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

int screen_width = 0;
int screen_height = 0;

void MoveStar(int x1, int y1, int x2, int y2, int delay);
int IsPointInRect(int x, int y, int left, int top, int right, int bottom);

int main()
{
    srand(time(NULL));

    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;
    clrscr();

    gotoxy(1, screen_height + 1);
    printf("Press ESC to quit.\n");

    int x = screen_width / 2;                               // initial coordinate
    int y = screen_height / 2;
    int dist = MIN(screen_width, screen_height) / 2;        // distance from the current point to the new target
    int delay = 20;                                         // the delay parameter for the MoveStar() function

    // TO DO: repeat to move a star to a random coordinate until the user types ESC.
    do{
        int prevx = x, prevy = y;
        int dx = 0, dy = 0;             // horizontal and vertical distance to the new target coordinate

        // TO DO: randomly select dx and dy such the length of (dx, dy) is the same as dist.
        //     repeat until the new point is in the rectangle (1, 1, screen_width, screen_height)
        //          generate a random number in range [0, 360) to decide the direction
        //          convert the angle in degree to radian by dividing it by PI
        //          compute dx and dy
        //              dx = (int)(cos(direction) * dist * 2 + 0.5)     // * 2 is to compensate for the difference between the horizontal and vertical scale
        //              dy = (int)(sin(direction) * dist + 0.5);
        //          (then, the new target coordinate is (x + dx, y + dy))

        // TO DO: update x and y using dx and dy
        


        // TO DO: display the next target by '+'
        //      move the cursor to the new target coordinate
        //      print '+'
        //      call "fflush(stdout);"



        // TO DO: move a star from previous coordinate to the new target coordinate


    } while(!kbhit() || getch() != 27);          // if type user types ESC, terminate the loop

    clrscr();
    gotoxy(1, screen_height + 1);
    printf("Bye!\n");

    return 0;
}

void MoveStar(int x1, int y1, int x2, int y2, int delay)
{
    int dx = ABS(x1 - x2);
    int dy = ABS(y1 - y2);
    int dist = MAX(dx, dy);

    int x = 0, y = 0;
    int prevx = x1, prevy = y1;

    //  repeat for t from 0 to dist
    for(int t = 0; t <= dist; t++){
    //      compute x and y by linear interpolation
    //          x = ((dist - t) * x1 + t * x2 + dist / 2) / (float)dist
    //          y = ((dist - t) * y1 + t * y2 + dist / 2) / (float)dist 
        x = ((dist - t) * x1 + t * x2 + dist / 2) / (float)dist;    // + dist / 2 is for rounding
        y = ((dist - t) * y1 + t * y2 + dist / 2) / (float)dist;

    //      erase the previous coordinate (prevx, prevy)
        gotoxy(prevx, prevy);
        putchar(' ');

    //      draw '*' at the new coordinate (x, y)
        gotoxy(x, y);
        putchar('*');

    //      move the cursor to (1, screen_height)
        gotoxy(1, screen_height);

    //      call "fflush(stdout);"
        fflush(stdout);


    //      save x and y in prevx and prevy
        prevx = x;
        prevy = y;
        
    //      wait for delay msec. (call "MySleep(delay);")
        MySleep(delay);
    }

    gotoxy(x, y);
    putchar(' ');
}

int IsPointInRect(int x, int y, int left, int top, int right, int bottom)
{
    // TO DO: if x is in range [left, rigth] and y is in range [top, bottom], return TRUE
    //        otherwise, return FALSE



}
