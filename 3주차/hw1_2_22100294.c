#include <stdio.h>

int main() {

     // Setting variables
    float unit_price, count, shipping_rate, discount, exchange_rate, total_price_USD, total_price_KRW;
    
    // Get input from the user
    printf("Input unit price in USD: ");
    scanf("%f", &unit_price);

    printf("Input count in USD: ");
    scanf("%f", &count);

    printf("Input shipping rate in USD: ");
    scanf("%f", &shipping_rate);

    printf("Input discount in USD: ");
    scanf("%f", &discount);

    printf("Input exchange rate (KRW per USD): ");
    scanf("%f", &exchange_rate);

    // Calculate total USD price
    total_price_USD = unit_price * count + shipping_rate - discount;

    // Calculate total KRW price
    total_price_KRW = total_price_USD * exchange_rate;

    // Print the total price(USD and KRW)
    printf("total price = $ %.6f * $ %.6f + $ %.6f - $ %.6f = $ %.6f = %.6f KRW\n",
           unit_price, count, shipping_rate, discount, total_price_USD, total_price_KRW);

    return 0;
}
