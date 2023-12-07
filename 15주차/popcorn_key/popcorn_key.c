#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "Console.h"

#define MAX_KEY 100

typedef struct {
    float x, y;       // position
    float dx;
    float dy;         // vertical speed
    float acc;        // vertical acceleration
    char key;
} FlyingKey;

void MoveKey(FlyingKey *key, int screenWidth, int screenHeight);

int main()
{
    srand(time(NULL));
    int screenWidth = getWindowWidth();
    int screenHeight = getWindowHeight() - 3;

    FlyingKey key[MAX_KEY];
    int in = 0, out = 0;
    int no_key = 0;

    clrscr();
    gotoxy(1, 1);
    printf("Press keys. (ESC to quit.)");
    
    char order[] = "`1qa2zws3xed4crf5vtg6byh7nuj8mik9,ol0.p;-/[\'=]\\";
    int order_len = strlen(order);
    float g = 0.098F;

    EnableCursor(0);

    while(1){
        if(kbhit()){
            char k = getch();
            if(k == 27)
                break;

            char *p = strchr(order, tolower(k));
            if(p != NULL){
                key[in].x = (screenWidth - 1) * (p - order) / order_len + 1;
                key[in].y = screenHeight;
                key[in].dx = rand() / (float)RAND_MAX * 2.F - 1.F;
                key[in].dy = -(float)sqrt(2.0 * g * screenHeight * 0.8);
                key[in].acc = g;
                key[in].key = k;

                gotoxy((int)key[in].x, (int)key[in].y);
                putchar(k);

                in = (in + 1) % MAX_KEY;
                no_key++;

                gotoxy(1, screenHeight + 1);
                printf("in = %03d, out = %03d, no_key = %03d\n", in, out, no_key);
            }
        }

        if(no_key > 0){
            int n = no_key;
            int idx = out;
            for(int i = 0; i < n; i++){
                MoveKey(&key[idx], screenWidth, screenHeight);
                if(key[idx].y > screenHeight){
                    out = (out + 1) % MAX_KEY;
                    no_key--;

                    gotoxy(1, screenHeight + 1);
                    printf("in = %03d, out = %03d, no_key = %03d\n", in, out, no_key);
                }
                idx = (idx + 1) % MAX_KEY;
            }
        }

        gotoxy(1, screenHeight + 2);
        MySleep(10);
    }

    clrscr();
    gotoxy(1, 1);
    printf("Bye!\n");

    EnableCursor(1);

    return 0;
}

void MoveKey(FlyingKey *key, int screenWidth, int screenHeight)
{
    // erase the old position
    if(key->x >= 1 && key->x <= screenWidth
    && key->y >= 1 && key->y <= screenHeight){
        gotoxy((int)(key->x + 0.5F), (int)(key->y + 0.5F));
        putchar(' ');
    }

    // update y coordinate
    key->x += key->dx;
    key->y += key->dy;
    key->dy += key->acc;

    // draw at the new position
    if(key->x >= 1 && key->x <= screenWidth
    && key->y >= 1 && key->y <= screenHeight){
        gotoxy((int)(key->x + 0.5F), (int)(key->y + 0.5F));
        putchar(key->key);
    }
}

