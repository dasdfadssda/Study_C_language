#include <stdio.h>

void exchange(int *x, int *y);

int main()
{
    int a = 10, b = 20;

    // Input Num
    printf("숫자 2개를 입력해주세요.\n");
    scanf("%d %d", &a, &b);

    exchange(&a, &b);

    printf("바꾼 후\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void exchange(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    return;
}