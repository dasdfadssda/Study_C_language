#include <stdio.h>

#define FILE_NAME "my_file.txt"

int main()
{

    // open a file
    FILE *fp = fopen(FILE_NAME, "r"); // 읽을 때는 r

    // write data into file
    for (int i = 0; i <= 10; i++)
    {
        int x = 0;
        fscanf(fp, "%d", &x);
        printf("%d", x);
    }
    printf("\n");

    // close the file

    return 0;
}