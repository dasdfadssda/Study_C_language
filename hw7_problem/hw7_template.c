#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Console.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define TRUE 1
#define FALSE 0

#define MAX_LEN 256
#define ESC 27

typedef struct
{
    char c;
    int sx, sy; // starting coordinate
    int ex, ey; // ending coordinate

    int vlen; // vertical distance to move
} MovingCharacter;

typedef struct
{
    MovingCharacter *chars; // pointer for the dynamically allocated array
    int *index;             // pointer for the dynamically allocated array
    int len;                // the # of characters
} CharBuffer;

// Constructor that allocates arrays of MovingCharacters and indices
void CreateCharBuffer(CharBuffer *cb, char text[], int width, int height);

// Destructor to deallocate chars and index
void DeleteCharBuffer(CharBuffer *cb);

// suffle index
void ShuffleIndex(CharBuffer *cb);

// set x and y according to t
void GetCharacterCoordinate(MovingCharacter *p, int t, int *px, int *py);

int main()
{
    int no_message = 10;
    static char message[][MAX_LEN] = {
        "Merry Christmas and Happy New Year!",
        "God loves you and has a wonderful plan for your life!",
        "Everything is gonna be okay!",
        "May you always find happiness and peace in your heart.",
        "You are the masterpiece of God!",
        "Live long and prosper!",
        "May your life be filled with joy and blessing.",
        "Wishing you peace, love, and happiness in all your endeavors.",
        "May love and joy surround you every day.",
        "May you always find strength and courage to face any challenge.",
    };

    srand(time(NULL));
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 1;

    clrscr();

    gotoxy(1, screen_height + 1);
    printf("Press ESC to quit.");

    CharBuffer cb = {NULL, NULL, 0}; // initialization is essential

    int cont = TRUE;
    while (cont)
    {
        // Create a character buffer with a text randomly chosen from message
        int rand_index = rand() % no_message;
        CreateCharBuffer(&cb, message[rand_index], screen_width, screen_height);

        for (int i = 0; i < cb.len; i++)
        {
            MovingCharacter *p = &cb.chars[cb.index[i]];

            if (p->c == ' ')
                continue;

            int x = p->sx, y = p->sy;
            gotoxy(x, y);
            printf("%c", p->c);
            fflush(stdout);

            for (int t = 1; t <= p->vlen; t++)
            {
                int prevx = x, prevy = y;
                GetCharacterCoordinate(p, t, &x, &y);

                gotoxy(prevx, prevy);
                printf(" ");

                gotoxy(x, y);
                printf("%c", p->c);
                fflush(stdout);
                MySleep(10);

                if (kbhit() && getch() == ESC)
                {
                    cont = FALSE;
                    break;
                }
            }

            if (!cont)
                break;
        }

        if (cont)
        {
            gotoxy(1, screen_height);
            fflush(stdout);
            MySleep(3000);
            clrscr();
        }

        DeleteCharBuffer(&cb);
    }

    clrscr();
    printf("Bye!\n");

    return 0;
}

void CreateCharBuffer(CharBuffer *cb, char text[], int width, int height)
{
    DeleteCharBuffer(cb); // Clear previous data if any

    cb->len = strlen(text);
    cb->chars = (MovingCharacter *)malloc(cb->len * sizeof(MovingCharacter));
    cb->index = (int *)malloc(cb->len * sizeof(int));

    if (cb->chars == NULL || cb->index == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize cb->chars and cb->index
    for (int i = 0; i < cb->len; i++)
    {
        MovingCharacter *p = &cb->chars[i];
        p->c = text[i];
        p->sx = (width - 1) * i / (cb->len - 1) + 1;
        p->sy = (i % 2 == 0) ? 1 : height;
        p->ex = (width - cb->len) / 2 + i;
        p->ey = height / 2;
        p->vlen = ABS(p->sy - p->ey);
        cb->index[i] = i;
    }

    ShuffleIndex(cb);
}

void DeleteCharBuffer(CharBuffer *cb)
{
    if (cb->chars != NULL)
    {
        free(cb->chars);
        cb->chars = NULL;
    }
    if (cb->index != NULL)
    {
        free(cb->index);
        cb->index = NULL;
    }
    cb->len = 0;
}

void ShuffleIndex(CharBuffer *cb)
{
    // TO DO: shuffle cb->index using the algorith used in the previous homework

    for (int i = cb->len - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);

        int temp = cb->index[i];
        cb->index[i] = cb->index[j];
        cb->index[j] = temp;
    }
}

void GetCharacterCoordinate(MovingCharacter *p, int t, int *px, int *py)
{
    *px = ((p->vlen - t) * p->sx + t * p->ex) / p->vlen;
    *py = ((p->vlen - t) * p->sy + t * p->ey) / p->vlen;
}
