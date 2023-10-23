/*
    Windows에서 컴파일
        gcc console_demo1.c Console.c -D_WINDOWS

    Mac에서 컴파일
        gcc console_demo1.c Console.c -D_MAC

*/

#include <stdio.h>                  // 시스템 디렉토리의 파일을 포함

#include "Console.h"                // 현재 디렉토리의 파일을 포함

int main()
{
    // 화면 크기 가져오기
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3; // 수직 스크롤 방지를 위해 -3 설정

    clrscr();               // 화면 지우기

    int x = 0, y = 0;

    for (x = 1; x < 20; x++)
    {
        y = x / 2 + 1;      // y 좌표 설정
        gotoxy(x, y);       // x, y 좌표로 이동
        putchar('*');       // '*' 출력
    }

    gotoxy(1, screen_height);   // 커서를 왼쪽 아래 모서리로 이동
    MyPause();                  // 사용자가 Enter 키를 누를 때까지 대기

    return 0;
}
