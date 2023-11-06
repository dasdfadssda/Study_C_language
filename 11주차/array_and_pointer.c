#include <stdio.h>

int main()
{
    int a[10] = { 0 };
    for(int i = 0; i < 10; i++)
        a[i] = i;

    printf("a = %p\n", a);      // display the starting address of a
    printf("sizeof(int) = %d\n", sizeof(int));

    printf("a[0] = %d (%p), a + 0 = %p\n", a[0], &a[0], a + 0);
    printf("a[1] = %d (%p), a + 1 = %p\n", a[1], &a[1], a + 1);
    // for any i, a + i (* size of the type) == &a[i]

    return 0;
}