#include <stdio.h>
#include <limits.h>

int main()
{
    int x = 0;
    int ret = 0;
    int min = INT_MAX, max = INT_MIN;

    while(1){
        printf("Input a number: ");
        ret = scanf("%d", &x);
        printf("x = %d (ret = %d)\n", x, ret);
        if(ret == EOF)
            break;
        if(x > max)
            max = x;
        if(x < min)
            min = x;
    }

    printf("min = %d, max = %d\n", min, max);
    printf("Bye!\n");

    return 0;
}