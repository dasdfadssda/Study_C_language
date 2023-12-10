#include <stdio.h>
#include <string.h>

void ReverseString(char str[]) {
     // know length
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int x;

    // Input a number
    printf("Input an integer: ");
    scanf("%d", &x);


    char binary[33];

    // Algorithm 
    if (x == 0) {
        binary[0] = '0';
        binary[1] = '\0';
        }
    else {
        int i = 0;
       
        while (x > 0){
            binary[i] = (x % 2) + '0';
            x /= 2;
            i++;
        }
         binary[i] = '\0';
    }
    // display the intermediate result
    printf("Intermediate result = %s (2) \n", binary);

    // horizontally flip the binary string
    ReverseString(binary);

    // display the result as a string
    printf("%d (10) = %s (2) \n", x, binary);

    return 0;
}
