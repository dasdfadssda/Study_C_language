/*
    이 프로그램은 사용자로부터 텍스트를 입력받아 화면 주위를 텍스트가 회전하도록 표시합니다.
    사용자가 ESC 키를 입력하면 프로그램이 종료됩니다.
    사용자가 스페이스바를 누르면 회전 방향이 변경됩니다.
    RepeatText() 및 RotateRight() 함수를 구현하여 프로그램을 완성하세요.

    컴파일
    - Windows에서: gcc final1_21800712.c Console.c -D_WINDOWS -Wall
    - Mac에서: gcc final1.c Console.c -D_MAC -Wall
*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

#define ESC 27

void RepeatText(char *text, int target_len);
void TrimText(char *text, int target_len);
void DrawTextRect(char *text, int left, int top, int right, int bottom);
void RotateLeft(char *text);
void RotateRight(char *text);

int main()
{
    {
        /*
            RepeatText() 및 RotateRight()의 테스트 코드입니다.
            결과는 다음과 같아야 합니다:

                str = [Hello, World!]
                after RepeatText(), str = [Hello, World! Hello, World! Hello, World! Hello, W]
                after RotateRight(), str = [WHello, World! Hello, World! Hello, World! Hello, ]
                after RotateRight(), str = [ WHello, World! Hello, World! Hello, World! Hello,]
                after RotateRight(), str = [, WHello, World! Hello, World! Hello, World! Hello]
                after RotateLeft(), str = [ WHello, World! Hello, World! Hello, World! Hello,]
                after RotateLeft(), str = [WHello, World! Hello, World! Hello, World! Hello, ]
                after RotateLeft(), str = [Hello, World! Hello, World! Hello, World! Hello, W]

        */
        char str[256] = "";
        strcpy(str, "Hello, World!");
        printf("str = [%s]\n", str);
        RepeatText(str, 50);
        printf("after RepeatText(), str = [%s]\n", str);
        for (int i = 0; i < 3; i++)
        {
            RotateRight(str);
            printf("after RotateRight(), str = [%s]\n", str);
        }

        for (int i = 0; i < 3; i++)
        {
            RotateLeft(str);
            printf("after RotateLeft(), str = [%s]\n", str);
        }

        printf("Press Enter to continue: ");
        getchar();
    }

    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;

    clrscr();

    printf("화면 크기 = %d x %d\n", screen_width, screen_height);

    char text[512] = "";
    printf("텍스트를 입력하세요: ");
    fgets(text, 512, stdin);
    int len = strlen(text) - 1;
    text[len] = 0;

    int left = 1;
    int right = screen_width;
    int top = 1;
    int bottom = screen_height;

    clrscr();
    //    EnableCursor(FALSE);      // 이 라인은 화면에서 커서를 숨깁니다.
    // 모든 솔루션을 제출한 후에 활성화하세요.
    int rect_perimeter = (right - left + 1) * 2 + (bottom - top + 1) * 2 - 4;
    if (len < rect_perimeter)
        RepeatText(text, rect_perimeter);
    else if (len > rect_perimeter)
        TrimText(text, rect_perimeter);

    char guide[] = "스페이스바를 눌러 방향을 변경하고 ESC를 눌러 종료하세요!";
    int guideLength = strlen(guide);
    int x = (screen_width - guideLength+guideLength/2) / 2;
    int y = screen_height / 2;

    gotoxy(x, y);
    printf("%s", guide);

    int dir = 0;
    while (1)
    {
        int key = 0;
        if (kbhit())
        {
            key = getch();
            if (key == ' ') // 스페이스바를 누르면 방향 변경
                dir = 1 - dir;
            else if (key == ESC) // ESC를 누르면 애니메이션 종료
                break;
        }

        DrawTextRect(text, left, top, right, bottom);

        // dir 값에 따라 회전
        if (dir == 0)
            RotateRight(text);
        else
            RotateLeft(text);

        gotoxy(1, screen_height);
        fflush(stdout);
        MySleep(20);
    }

    gotoxy(1, screen_height);
    printf("종료합니다!\n");

    //    EnableCursor(TRUE);       // 모든 솔루션을 제출한 후에 활성화하세요

    return 0;
}

void DrawTextRect(char *text, int left, int top, int right, int bottom)
{
    int x = 0, y = 0;
    int t = 0;

    // 위쪽 테두리 그리기
    for (x = left; text[t] != 0 && x <= right; x++)
    {
        gotoxy(x, top);
        putchar(text[t++]);
    }

    // 오른쪽 테두리 그리기
    for (y = top + 1; text[t] != 0 && y <= bottom; y++)
    {
        gotoxy(right, y);
        putchar(text[t++]);
    }

    // 아래쪽 테두리 그리기
    for (x = right - 1; text[t] != 0 && x >= left; x--)
    {
        gotoxy(x, bottom);
        putchar(text[t++]);
    }

    // 왼쪽 테두리 그리기
    for (y = bottom - 1; y > top; y--)
    {
        gotoxy(left, y);
        putchar(text[t++]);
    }
}

void RepeatText(char *text, int target_len)
// 입력된 문자열을 반복하여 확장하고 각 반복 사이에 공백 문자를 삽입합니다.
// 예를 들어, text == "Hello, World!"라면 RepeatText(text, 50)는 "Hello, World! Hello, World! Hello, World! Hello, W"로 만듭니다.
{
    // TO DO: 이 함수를 구현하세요
    //     만약 text의 길이가 target_len보다 작다면,
    //        text의 끝에 공백 문자 (' ')를 추가하고
    //        text를 target_len 길이까지 확장하세요 (len <= i < target_len에 대해 text[i]를 text[i % len]으로 설정,
    //           여기서 'len'은 입력된 텍스트의 원래 길이 + 1입니다. +1은 공백 문자를 추가한 것입니다.)

    int len = strlen(text);
    if (len < target_len)
    {
        char temp[512];     // 임시 버퍼
        strcpy(temp, text); // text를 임시 버퍼에 복사
        strcat(temp, " ");  // 공백 추가

        while (strlen(temp) < target_len) // 길이가 target_len보다 작을 때까지 반복
        {
            strcat(temp, "Hello, World! "); // 텍스트 추가
        }

        strncpy(text, temp, target_len); // target_len 길이로 다시 text에 복사
        text[target_len] = '\0';         // 문자열 종료
    }
}

void TrimText(char *text, int target_len)
{
    int len = strlen(text);
    if (len > target_len)
        text[target_len] = 0;
}

void RotateLeft(char *text)
// 문자열을 한 칸 왼쪽으로 회전시킵니다.
// 예를 들어, "HELLO" --> "ELLOH"
{
    int len = strlen(text);
    char num = text[0];
    for (int i = 0; i < len - 1; i++)
        text[i] = text[i + 1];

    text[len - 1] = num;
}

void RotateRight(char *text)
// 문자열을 한 칸 오른쪽으로 회전시킵니다.
// 예를 들어, "HELLO" --> "OHELL"
{
    int len = strlen(text);
    char last_char = text[len - 1]; // 마지막 문자를 저장

    // 문자열의 각 문자를 오른쪽으로 이동시킴
    for (int i = len - 1; i > 0; i--) {
        text[i] = text[i - 1];
    }

    text[0] = last_char; // 마지막 문자를 첫 번째 위치로 이동
}
