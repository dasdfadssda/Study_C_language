
#include <stdio.h>
int main()
{
    int x = 0;
    int min = 10000000, max = 0;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("Input an integer : ");
        scanf("%d", &x);
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    printf("min = %d, max = %d\n", min, max);
    return 0;
}