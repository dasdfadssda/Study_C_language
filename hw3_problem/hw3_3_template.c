#include <stdio.h>
#include <string.h>

#include "Console.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : -(x))


// int completed = 0;         // Disable this line after completing MoveStar().
int completed = 1;         // Enable this line after completing MoveStar().

int screen_width = 0;
int screen_height = 0;

void MoveStar(int x1, int y1, int x2, int y2, int delay);

int main()
{
    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;

    clrscr();

    if(completed == 0){
        MoveStar(1, 10, 50, 1, 20);
        MoveStar(50, 10, 1, 1, 20);
        gotoxy(1, screen_height);
        printf("Bye!\n");
     } else {
        gotoxy(1, screen_height);
        printf("Press CTRL-C to quit.");

        char mesg[256] = "You are the masterpiece of God!";
        int len = strlen(mesg);
        gotoxy((screen_width - len) / 2, screen_height / 2);
        printf("%s", mesg);

        int x[5] = { screen_width / 4,  screen_width * 3 / 4, screen_width * 3 / 4,  screen_width / 4,      screen_width / 4};
        int y[5] = { screen_height / 4, screen_height / 4,    screen_height * 3 / 4, screen_height * 3 / 4, screen_height / 4};

        for(int i = 0; 1; i = (i + 1) % 4){
            if(i % 2 == 0)
                MoveStar(x[i], y[i], x[i+1], y[i+1], 10);
            else
                MoveStar(x[i], y[i], x[i+1], y[i+1], 20);
        }
    }

    return 0;
}

void MoveStar(int x1, int y1, int x2, int y2, int delay)
{
    int dx = ABS(x1 - x2);
    int dy = ABS(y1 - y2);
    int dist = MAX(dx, dy);

    int prevx = x1, prevy = y1;

    for (int t = 0; t <= dist; t++)
    {
        int x = ((dist - t) * x1 + t * x2) / (float)dist;
        int y = ((dist - t) * y1 + t * y2) / (float)dist;

        gotoxy(prevx, prevy);
        putchar(' '); // make empty

        gotoxy(x, y);
        putchar('*'); // start nwe star

        gotoxy(1, screen_height);
        fflush(stdout);

        prevx = x;
        prevy = y;

        MySleep(delay);
    }

    // erase last start
    gotoxy(prevx, prevy);
    putchar(' ');
}
