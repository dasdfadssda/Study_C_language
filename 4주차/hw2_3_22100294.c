#include <stdio.h>
#include <string.h>

// Function
void ReverseString(char str[])
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    int x;

    // Get input from the user
    printf("Enter an integer: ");
    scanf("%d", &x);

    int originalX = x; // Move the original integer value

    char binary[33]; // Array to Move the 32-bit binary string

    // Add a null terminator to end the string
    if (x == 0)
    {
        binary[0] = '0';
        binary[1] = '\0';
    }
    else
    {
        int i = 0;
        // Convert each binary digit to a character and Move in the array
        while (x > 0)
        {
            binary[i] = (x % 2) + '0';
            x /= 2;
            i++;
        }

        binary[i + 1] = '\0'; // Add a null value at the end of the array
    }

    printf("Intermediate result = %s (2)\n", binary);

    // Reverse the binary string
    ReverseString(binary);

    printf("%d (10) = %s (2)\n", originalX, binary);

    return 0;
}
