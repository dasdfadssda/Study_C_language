#include <stdio.h>

#include <limits.h>

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
    for(i = 1; i <= no_digit; i++){
        x = RotateDigit(x, no_digit, LEFT);
        printf("after %d left-rotations: %d\n", i, x);
    }

    printf("Rotating Right:\n");
    for(i = 1; i <= no_digit; i++){
        x = RotateDigit(x, no_digit, RIGHT);
        printf("after %d right-rotations: %d\n", i, x);
    }

    return 0;
}

int CountDigit(int x)
{
    // TO DO: implement this function
    //  initialize n to 1
    //  if x is a negative number, make it positive by assigning -x to x
    //  repeat while x is greater than or equal to 10
    //      divide x by 10
    //      increase n
    //  return n;

 
}

int RotateDigit(int x, int no_digit, int dir)
{
    // TO DO: implement this function
    //  if dir is LEFT,
    //      initialize msd (most significant digit, e.g., msd of 321 is 3) to x and divider to 10
    //      repeat for i from 0 to no_digit - 1
    //          divide msd by 10
    //          multiply divider by 10
    //      rotate-left x using divider and msd  (solve for yourself)

    //  if dir is RIGHT,
    //      initialize ones by lsd (least significant digit, e.g., lsd of 321 is 1)
    //      repeat for i from 0 to no_digit - 1
    //          multiply ones by 10
    //      rotate-right x using ones (solve for yourself)

    //  return x

    
    return x;
}