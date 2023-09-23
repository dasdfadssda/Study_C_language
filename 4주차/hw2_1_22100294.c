#include <stdio.h>

int main() {
    int x;

    // Get input from the user
    printf("Input a 4-digit number: ");
    scanf("%d", &x);

    int originalX = x;

    printf("x = %04d\n", x); // Display the original num with leading zero

    for (int i = 0; i < 4; i++) {
        int onesDigit = x % 10;    // Retrieve the one digit

        x = x / 10 + onesDigit * 1000; // Move right and add the one digit to the left
        printf("x = %04d\n", x);    // Display the moved number with leading zero
    }

    return 0;
}
