#include <stdio.h>

int main()
{
    float fahr = 0.0;
    float cel = 0.0;

    // read current temperature in Fahr
    printf("Input temperature in Fahr: ");
    scanf("%f", &fahr);

    // convert Fahr into Celsius
    cel = (fahr - 32) * 5 / 9; 

    // display the conversion result
    printf("%f fahr is %f celsius\n", fahr, cel);

    return 0;
}