#include <stdio.h>

int main()
{

    int unit_price = 0;
    int count = 0;
    int shipping_rate = 0;
    int discount = 0;

    //read two numbers from the user
    printf("Input unit price: ");
    scanf ("%d", &unit_price);
    printf("Input count: ");
    scanf ("%d", &count);
    printf("Input shipping rate: ");
    scanf ("%d", &shipping_rate);
    printf("Input unit discount: ");
    scanf ("%d", &discount);

    // calculate it and make another int
    int sum = 0;
    sum = unit_price * count + shipping_rate - discount;



    // print the result 
    printf ("%d * %d + %d - %d = %d KRW", unit_price, count,shipping_rate, discount, sum);

    return 0;

}