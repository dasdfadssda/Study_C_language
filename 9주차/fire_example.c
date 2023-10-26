#include <stdio.h>

int main()
{

    // open a file
    FILE *fp = NULL;
    fp = fopen("my_file.txt", "w"); // r은 읽겠다. w는 쓴다.

    // write data into file
    for (int i = 0; i <= 10; i++)
    {
        printf("%d", i);
        putchar("\n");
    }

    // close the file
    fclose()
    return 0;
}