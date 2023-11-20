#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Console.h"

#define MAX_ROW 256
#define MAX_COLUMN 512

char GetRandomChar();                          // hw5_2 - 랜덤 문자 얻기 함수 선언
void FillAlphaNum(char array[], int *no_char); // hw5_1 - 숫자 및 알파벳 채우기 함수 선언
void Shuffle(char array[], int size);          // hw5_1 - 배열 요소 섞기 함수 선언

// 화면 버퍼
char screen[MAX_ROW][MAX_COLUMN]; // 화면 버퍼 배열
int screen_width = 0;             // 화면 너비
int screen_height = 0;            // 화면 높이

void DisplayBuffer(char buffer[][MAX_COLUMN], int width, int height);                            // hw5_2 - 화면 버퍼 표시 함수
void RandomizeBuffer(char buffer[][MAX_COLUMN], int width, int height);                          // hw5_2 - 화면 버퍼 랜덤 채우기 함수
void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c); // hw5_2 - 화면 버퍼에서 직사각형 채우기 함수

int main()
{
    srand(time(NULL)); // 랜덤 시드 설정

    screen_width = getWindowWidth();         // 화면 너비 가져오기
    screen_height = getWindowHeight() - 3;  // 화면 높이 가져오기, 상태 표시줄 고려

    clrscr(); // 콘솔 화면 지우기

    // 화면 초기화
    RandomizeBuffer(screen, screen_width, screen_height); // 화면 버퍼 랜덤 채우기
    DisplayBuffer(screen, screen_width, screen_height);   // 화면 버퍼 표시
    MySleep(1000);                                       // 1초 대기

    // 일부 영역 지우기
    FillRectangle(screen, screen_width * 3 / 8, screen_height * 3 / 8, screen_width * 5 / 8, screen_height * 5 / 8, ' '); // 화면 버퍼에서 일부 영역을 공백으로 채우기
    DisplayBuffer(screen, screen_width, screen_height);                                                                   // 새로운 화면 버퍼 표시
    MySleep(1000);                                                                                                         // 1초 대기

    // 다른 영역 지우기
    FillRectangle(screen, screen_width * 2 / 4, screen_height / 4, screen_width * 3 / 4, screen_height * 2 / 4, ' '); // 화면 버퍼에서 다른 영역을 공백으로 채우기
    DisplayBuffer(screen, screen_width, screen_height);                                                                // 새로운 화면 버퍼 표시
    MySleep(1000);                                                                                                      // 1초 대기

    // 또 다른 영역 지우기
    FillRectangle(screen, screen_width / 4, screen_height * 2 / 4, screen_width * 2 / 4, screen_height * 3 / 4, ' '); // 화면 버퍼에서 또 다른 영역을 공백으로 채우기
    DisplayBuffer(screen, screen_width, screen_height);                                                              // 새로운 화면 버퍼 표시
    MySleep(1000);                                                                                                    // 1초 대기

    // 공의 초기 위치 및 이동 속도 설정
    int x = screen_width / 2;
    int y = screen_height / 2;
    int dx = 2;
    int dy = 1;

    gotoxy(1, screen_height + 1); // 커서 이동
    printf("Press ESC to quit!"); // 종료 안내 메시지 출력

    // ESC 키가 눌릴 때까지 반복
    while (!kbhit() || getch() != 27)
    {
        // 공 튕기기 로직

        int prevx = x;
        int prevy = y;

        // 공의 이동 경로가 화면 끝에 닿을 경우 방향 바꾸기
        if (x + dx >= screen_width || x + dx < 1)
        {
            dx = -dx;
        }
        if (y + dy >= screen_height || y + dy < 1)
        {
            dy = -dy;
        }

        // 화면에 그려진 문자가 있는 경우, 공의 방향을 조정하여 충돌 처리
        if (screen[y + dy][x + dx] != ' ')
        {
            if (screen[y + dy][x - dx] == ' ' && screen[y][x + dx] != ' ')
            {
                dx = -dx;
            }
            else if (screen[y - dy][x + dx] == ' ' && screen[y + dy][x] != ' ')
            {
                dy = -dy;
            }
            else
            {
                dx = -dx;
                dy = -dy;
            }
        }

        // 공의 위치 업데이트
        x += dx;
        y += dy;

        // 이전 좌표에 있는 공 삭제
        screen[prevy][prevx] = ' ';
        gotoxy(prevx, prevy);
        putchar(' ');

        // 새로운 공 그리기
        screen[y][x] = '*';
        gotoxy(x, y);
        putchar('*');

        // 커서 이동 및 대기
        gotoxy(1, screen_height);
        fflush(stdout);
        MySleep(20);
    }

    // 종료 메시지 출력
    gotoxy(1, screen_height);
    printf("Bye!\n");

    return 0;
}

// 화면 버퍼 표시 함수
void DisplayBuffer(char buffer[][MAX_COLUMN], int width, int height)
{
    gotoxy(1, 1);
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            putchar(buffer[i][j]);
    }
}

// 화면 버퍼 랜덤 채우기 함수
void RandomizeBuffer(char buffer[][MAX_COLUMN], int width, int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            buffer[i][j] = GetRandomChar(); // 랜덤 문자로 화면 버퍼 채우기
    }
}

// 화면 버퍼에서 직사각형 채우기 함수
void FillRectangle(char buffer[][MAX_COLUMN], int left, int top, int right, int bottom, char c)
{
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
            buffer[i][j] = c; // 지정한 좌표에 직사각형 영역을 지정한 문자로 채우기
    }
}

// GetRandomChar 함수 - 랜덤 문자 반환
char GetRandomChar()
{
    if (cur_idx == no_random)
    {
        if (no_random == 0)
        {
            FillAlphaNum(random_char, &no_random); // 숫자와 알파벳을 포함한 문자 배열 채우기
            Shuffle(random_char, no_random);      // 문자 배열 섞기
        }
        cur_idx = 0;
    }

    return random_char[cur_idx++]; // 다음 랜덤 문자 반환 및 인덱스 증가
}

// FillAlphaNum 함수 - 숫자와 알파벳을 포함한 문자 배열 채우기
void FillAlphaNum(char array[], int *no_char)
{
    int index = 0;

    for (char c = '0'; c <= '9'; ++c)
    {
        array[index++] = c; // '0'부터 '9'까지 숫자 배열에 추가
    }

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        array[index++] = c; // 'A'부터 'Z'까지 대문자 알파벳 배열에 추가
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        array[index++] = c; // 'a'부터 'z'까지 소문자 알파벳 배열에 추가
    }

    *no_char = index; // 배열 요소 개수 업데이트
}

// Shuffle 함수 - 배열 요소 섞기
void Shuffle(char array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = rand() % size; // 배열 내 랜덤한 인덱스 선택

        char temp = array[i];
        array[i] = array[j]; // 두 요소 위치 변경
        array[j] = temp;
    }
}
