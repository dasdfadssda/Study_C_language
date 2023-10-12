#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int CountDigit(int x);
int RotateDigit(int x, int no_digit, int dir);

int main()
{
    int x = 0;

    printf("Input an integer: ");
    scanf("%d", &x);

    int no_digit = CountDigit(x);
    printf("%d has %d digits.\n", x, no_digit);

    printf("Rotating Left:\n");
    int i = 0;
    for (i = 1; i <= no_digit; i++)
    {
        x = RotateDigit(x, no_digit, LEFT);
        printf("after %d left-rotations: %d\n", i, x);
    }

    printf("Rotating Right:\n");
    for (i = 1; i <= no_digit; i++)
    {
        x = RotateDigit(x, no_digit, RIGHT);
        printf("after %d right-rotations: %d\n", i, x);
    }

    return 0;
}

int CountDigit(int x)
{
    int n = 0;
    if (x < 0)
    {
        x = -x; // Make it positive
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
    { // Left rotation code
        int msd = x / power;
        int rest = x % power;
        x = rest * 10 + msd;
    }
    else if (dir == RIGHT)
    { // Right rotation code
        int lsd = x % 10;
        int rest = x / 10;
        x = lsd * power + rest;
    }

    return x;
}
