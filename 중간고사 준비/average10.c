#include <stdio.h>
#include <math.h>

int main()
{
    int numbers[10];
    int sum = 0;
    double average, variance = 0.0;

    // Input 10 numbers
    for (int i = 0; i < 10; i++)
    {
        printf("Enter 10 numbers: ");
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // Calculate the average
    average = (double)sum / 10;

    // Calculate the variance
    for (int i = 0; i < 10; i++)c
    {
        variance += pow(numbers[i] - average, 2);
    }
    variance /= 10;

    printf("average = %.2lf, variance = %.2lf\n", average, variance);

    return 0;
}
