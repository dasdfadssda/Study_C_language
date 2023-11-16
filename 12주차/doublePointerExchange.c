#include <stdio.h>

void exchange(int x, int y);
void exchange_pointer(int **ppx, int **ppy);

int main()
{
    int a = 10, b = 20;
    int *pa = &a; // pa ----> a
    int *pb = &b; // pb ----> b

    printf("Before exchange: \n");
    printf("a = %d, b = %d\n", a, b);
    printf("*pa (%p) = %d (%p), *pb = %d\n", pa, *pa, pb, *pb);

    //   exchange(a, b);

    // pa ---> b
    // pb ---> a
    exchange_pointer(&pa, &pb);

    printf("After exchange: \n");
    printf("a = %d, b = %d\n", a, b);
    printf("*pa (%p) = %d (%p), *pb = %d\n", pa, *pa, pb, *pb);

    return 0;
}

void exchange(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void exchange_pointer(int **ppx, int **ppy)
// ppx ---> pa ---> a
// ppy ---> pb ---> b
{
    int *temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}