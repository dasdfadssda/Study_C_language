#include <stdio.h>

int main()
{
    short s = 0;
    int i = 0;
    long l = 0;
    long long ll = 0;

    printf("size of short = %lu\n", sizeof(s));
    printf("size of int = %lu\n", sizeof(i));
    printf("size of long = %lu\n", sizeof(l));
    printf("size of long long = %lu\n", sizeof(ll));

    printf("size of short = %lu\n", sizeof(short));
    printf("size of int = %lu\n", sizeof(int));
    printf("size of long = %lu\n", sizeof(long));
    printf("size of long long = %lu\n", sizeof(long long));

    return 0;
}