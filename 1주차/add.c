#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;

    // read two numbers from the user into two a and b
    printf("Input two numbers :");
    scanf("%d %d", &a, &b);

    // add a and b, and store the result into another variable c
    int c = 0;
    c = a + b;
    // display the result in c
    printf("result : ");
    printf("%d + %d = %d\n",a,b,c);

    return 0;
}