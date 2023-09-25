#include <stdio.h>

void swap(int x, int y);

int main()
{
    int a = 5, b = 15;

    printf("a = %d, b = %d\n", a, b);

    swap(a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;

    printf("x = %d, y = %d\n", x, y);
}