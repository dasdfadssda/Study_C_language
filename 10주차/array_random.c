#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main()
{

    srand(time(NULL)); // initialize random seed (run once!)

    int a[SIZE] = {0};

    // generate random numbers and store them in array a
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() %21 - 10;   // rand()   returns a random number between [0 and RAND_MAX)

    }

    // display the random numbers in array a
    for (int i = 0; i < SIZE; i++)
    {
       printf("a[%d] = %d\n",i, a[i]);
    }
    
}