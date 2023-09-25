#include <stdio.h>

void swapNonePointer(int x, int y);
void swap(int *x, int *y);

int main()
{
    int a = 5, b = 15;

    printf("a = %d, b = %d\n", a, b);

    swapNonePointer(a, b); // 주소값으로 이전 X;
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b); // 주소 위치로 변수 사용

    printf("a = %d, b = %d\n", a, b);

    return 0;
}


void swapNonePointer(int x, int y) // 받은 변수에 대해 Pointer로 지정
{
    int temp = x;
    x = y;
    y = temp;

    printf("포인터 적용 안한 것은 : x = %d, y = %d\n", x, y);
}

void swap(int *x, int *y) // 받은 변수에 대해 Pointer로 지정
{
    int temp = *x;
    *x = *y;
    *y = temp;

    printf("포인터 적용 한 것은 : x = %d, y = %d\n", *x, *y);
}