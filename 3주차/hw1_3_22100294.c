#include <stdio.h>

int main() {
    // Setting variable
    char C[100];

    // Get a word starting with 'C' from the user
    printf("What is between birth and death?\nAnswer in a word starting with C: ");
    scanf("%s", C);

   // output the input word in the desired format
    printf("Birth - %s - Death\n", C);

    return 0;
}
ㅊ