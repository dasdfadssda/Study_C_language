#include <stdio.h>
int main()
{
    int x = 0;
    while (!(x >= 1 && x <= 100))
    {
        printf("Input an integer in [1, 100] : ");
        scanf("%d", &x);
    }
    printf("Thank you very much. You typed %d\n", x);
    return 0;
}