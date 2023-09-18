#include <stdio.h>

int main() {
    int number;
    
    //  input Num
    printf("Input a 3-digit number: ");
    scanf("%d", &number);
    
    if (number >= 100 && number <= 999) {
        int digit1 = number / 100;       
        int digit2 = (number / 10) % 10;  
        int digit3 = number % 10;        
        
        // Print each digit
        printf("<%d, %d, %d>\n", digit1, digit2, digit3);
    } else {
        printf("Please enter a valid 3-digit number.\n");
    }
    
    return 0;
}
