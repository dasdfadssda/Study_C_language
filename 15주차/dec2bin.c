#include <stdio.h>

int main()
{
    int x = 0;
    char bin[64] = "";
    
    // read x from the user
    printf("input an integer: ");
    scanf("%d", &x);

    // convert x into binary string in bin

    int i = 0;
    // repeat until x becomes zero
    while(x > 0){
    //     set bin[i] to x & 1 + '0'
        bin[i++] = (x & 1) + '0';
    //     shift-right x  ( equivalent to division by 2)
        x >>= 1;
    }
    // set bin[i] to 0
    bin[i] = 0;

    printf("bin = [%s]\n", bin);

    // reverse bin
    for(int j = 0; j < i / 2; j++){
        char temp = bin[i - j - 1];
        bin[i - j - 1] = bin[j];
        bin[j] = temp;
    }

    // display the result
    printf("%d = [%s]\n", x, bin);

    return 0;
}