#include <stdio.h>
#include "Console.h"
#include <ctype.h>
#include <string.h>

void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space);

int main() {
    char inputString[100];
    int upperCount = 0, lowerCount = 0, digitCount = 0, spaceCount = 0;

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the trailing newline character
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    CountCharacter(inputString, &upperCount, &lowerCount, &digitCount, &spaceCount);

    printf("Input string = \"%s\"\n", inputString);
    printf("The input string contains:\n");
    printf("%d uppercase characters\n", upperCount);
    printf("%d lowercase characters\n", lowerCount);
    printf("%d digit characters\n", digitCount);
    printf("%d space characters\n", spaceCount);

    return 0;
}

void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space) {
    *no_upper = 0;
    *no_lower = 0;
    *no_digit = 0;
    *no_space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            (*no_upper)++;
        else if (islower(str[i]))
            (*no_lower)++;
        else if (isdigit(str[i]))
            (*no_digit)++;
        else if (isspace(str[i]))
            (*no_space)++;
    }
}
