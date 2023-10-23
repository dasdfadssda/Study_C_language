/*
    Windows에서 컴파일
        gcc console_demo2.c Console.c -D_WINDOWS

    Mac에서 컴파일
        gcc console_demo2.c Console.c -D_MAC

*/

#include <stdio.h>            // 시스템 디렉토리의 파일을 포함

#include "Console.h"          // 현재 디렉토리의 파일을 포함

int screen_width = 0;
int screen_height = 0;

void MoveRight(int x1, int x2, int y);
void MoveLeft(int x1, int x2, int y);

int main()
{
    // 화면 크기 가져오기
    screen_width = getWindowWidth();
    screen_height = getWindowHeight() - 3; // 수직 스크롤 방지를 위해 -3 설정

    clrscr(); // 화면 지우기

    MoveRight(1, screen_width, screen_height / 2);
    MoveLeft(1, screen_width, screen_height / 2);

    gotoxy(1, screen_height); // 커서를 왼쪽 아래 모서리로 이동
    // MyPause(); // 사용자가 Enter 키를 누를 때까지 대기.

    return 0;
}

void MoveRight(int x1, int x2, int y)
{
    int x = 0;
    int prevx = x1;

    for (x = x1; x <= x2; x++)
    {
        // 이전 좌표 지우기
        gotoxy(prevx, y);
        putchar(' ');

        // 새로운 좌표에 '*' 그리기
        gotoxy(x, y);
        putchar('*');

        // 이전 좌표 저장
        prevx = x;
        gotoxy(1, screen_height); // 화면 깜박임 방지를 위해 커서를 좌하단으로 이동

        fflush(stdout); // 화면에 내용 표시

        // 50밀리초 대기
        MySleep(25);
    }
}

void MoveLeft(int x1, int x2, int y)
{
    int x = 0;
    int prevx = x1;

    for (x = x2; x >= x1; x--)
    {
        // 이전 좌표 지우기
        gotoxy(prevx, y);
        putchar(' ');

        // 새로운 좌표에 '*' 그리기
        gotoxy(x, y);
        putchar('*');

        // 이전 좌표 저장
        prevx = x;
        gotoxy(1, screen_height); // 화면 깜박임 방지를 위해 커서를 좌하단으로 이동

        fflush(stdout); // 화면에 내용 표시

        // 50밀리초 대기
        MySleep(25);
    }
}
