#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int CountDigit(int x);
int RotateDigit(int x, int no_digit, int dir);

int main()
{
    int x = 0;

    // 값 입력
    printf("정수를 입력하세요: ");
    scanf("%d", &x);

    int no_digit = CountDigit(x);
    printf("%d는 %d자리 수입니다.\n", x, no_digit);

    printf("왼쪽으로 회전:\n");
    int i = 0;
    for (i = 1; i <= no_digit; i++)
    {
        x = RotateDigit(x, no_digit, LEFT);
        printf("%d번 왼쪽 회전 후: %d\n", i, x);
    }

    printf("오른쪽으로 회전:\n");
    for (i = 1; i <= no_digit; i++)
    {
        x = RotateDigit(x, no_digit, RIGHT);
        printf("%d번 오른쪽 회전 후: %d\n", i, x);
    }

    return 0;
}

int CountDigit(int x)
{
    int n = 0;
    if (x < 0)
    {
        x = -x; // 양수로 변환
    }
    do
    {
        x /= 10;
        n++;
    } while (x != 0);
    return n;
}

int RotateDigit(int x, int no_digit, int dir)
{
    int power = 1;
    for (int i = 1; i < no_digit; i++)
    {
        power *= 10;
    }

    if (dir == LEFT)
    { // 왼쪽 회전 코드
        int msd = x / power; // 가장 왼쪽 자릿수 (Most Significant Digit)
        int rest = x % power; // 나머지 자릿수
        x = rest * 10 + msd;
    }
    else if (dir == RIGHT)
    { // 오른쪽 회전 코드
        int lsd = x % 10; // 가장 오른쪽 자릿수 (Least Significant Digit)
        int rest = x / 10; // 나머지 자릿수
        x = lsd * power + rest;
    }

    return x;
}
