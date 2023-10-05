#include <stdio.h>

#define PI 3.141592

int main()
{

    float x = 0;
    char t = 'a';

    // read a character t and a number x
    printf("Input x : \n");
    scanf("%f", &x);
    printf("Input t: \n");
    scanf(" %c", &t);

    // If t is 'c', print size of a circle whose diameter is x.
    if (t == 'c')
    {
        printf("%f", (x * x * PI));
    }
    // If t is 's', print size of a square whose width is x.
    else if (t == 's')
    {
        printf("%f", (x * x));
    }
    // Otherwise print "Onvalid type."
    else
    {
        printf("Onvalid type.");
    }

    return 0;
}