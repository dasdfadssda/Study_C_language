#include <stdio.h>
#include <string.h>
#include "Console.h"

// 매크로 함수 정의
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

// MoveStar 함수의 완료 여부 설정 (0: 비활성화, 1: 활성화)
int completed = 1;

int screen_width = 0;
int screen_height = 0;

// 별표를 움직이는 함수
void MoveStar(int x1, int y1, int x2, int y2, int delay);

int main()
{
    // 화면 크기 설정
    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3;

    // 화면 지우기
    clrscr();

    if (completed == 0)
    {
        // 별표를 움직이는 예제
        MoveStar(1, 10, 50, 1, 20);
        MoveStar(50, 10, 1, 1, 20);
        gotoxy(1, screen_height);
        printf("안녕!\n");
    }
    else
    {
        gotoxy(1, screen_height);
        printf("CTRL-C를 눌러 종료하세요.");

        // 메시지 표시
        char mesg[256] = "당신은 신의 걸작입니다!";
        int len = strlen(mesg);
        gotoxy((screen_width - len) / 2, screen_height / 2);
        printf("%s", mesg);

        // 별표의 초기 위치 설정
        int x[5] = {screen_width / 4, screen_width * 3 / 4, screen_width * 3 / 4, screen_width / 4, screen_width / 4};
        int y[5] = {screen_height / 4, screen_height / 4, screen_height * 3 / 4, screen_height * 3 / 4, screen_height / 4};

        for (int i = 0; 1; i = (i + 1) % 4)
        {
            if (i % 2 == 0)
                MoveStar(x[i], y[i], x[i + 1], y[i + 1], 10);
            else
                MoveStar(x[i], y[i], x[i + 1], y[i + 1], 20);
        }
    }

    return 0;
}

// 별표를 움직이는 함수
void MoveStar(int x1, int y1, int x2, int y2, int delay)
{
    int dx = ABS(x1 - x2);
    int dy = ABS(y1 - y2);
    int dist = MAX(dx, dy);

    int x = 0, y = 0;
    int prevx = x1, prevy = y1;

    for (int t = 0; t <= dist; t++)
    {
        int x = ((dist - t) * x1 + t * x2) / (float)dist;
        int y = ((dist - t) * y1 + t * y2) / (float)dist;

        gotoxy(prevx, prevy);
        putchar(' '); // 이전 위치를 비우기

        gotoxy(x, y);
        putchar('*'); // 새로운 별표 표시

        gotoxy(1, screen_height);
        fflush(stdout);

        prevx = x;
        prevy = y;

        MySleep(delay);
    }

    // 마지막 별표 삭제
    gotoxy(prevx, prevy);
    putchar(' ');
}
