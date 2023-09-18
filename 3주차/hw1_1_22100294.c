#include <stdio.h>

int main() {

    // Setting variables
    int unit_price, count, shipping_rate, discount, total_price;

    // Get input from the user
    printf("Input unit price: ");
    scanf("%d", &unit_price);

    printf("Input count: ");
    scanf("%d", &count);

    printf("Input shipping rate: ");
    scanf("%d", &shipping_rate);

    printf("Input discount: ");
    scanf("%d", &discount);

    // Calculate total price
    total_price = unit_price * count + shipping_rate - discount;

    // print total price
    printf("total price = %d * %d + %d - %d = %d KRW\n", unit_price, count, shipping_rate, discount, total_price);

    return 0;
}
