#include <stdio.h>

    int main()
    {

        float unit_price = 0;
        float count = 0;
        float shipping_rate = 0;
        float discount = 0;
        float exchange_rate = 0;

        //make users to insert numbers
        printf ("Input unit price in USD: ");
        scanf ("%f", &unit_price);
        printf ("Input count: ");
        scanf ("%f", &count);
        printf ("Input shipping rate in USD: ");
        scanf ("%f", &shipping_rate);
        printf ("Input discount in USD: ");
        scanf("%f", &discount);
        printf ("Input exchange rate (KRW per USD): ");
        scanf ("%f", &exchange_rate);


        // make the calculations of the numbers in USD and in KRW 
        float total_price_USD = 0;
        total_price_USD = unit_price * count + shipping_rate - discount;
        float total_price_KRW = 0;
        total_price_KRW = total_price_USD * exchange_rate;


        // show the result
        printf ("total price = $ %f * %f + $ %f - $ %f = $ %f = %f KRW", unit_price, count, shipping_rate, discount, total_price_USD, total_price_KRW);

        return 0;

    }