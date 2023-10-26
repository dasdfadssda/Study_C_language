#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "my_file.txt"

int main()
{

    // open a file
    FILE *fp = fopen(FILE_NAME, "r"); // 읽을 때는 r
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", FILE_NAME); // 에러 체크
        exit(-1);
    }

    // write data into file
    for (int i = 0; i <= 10; i++)
    {
        int x = 0;
        fscanf(fp, "%d", &x);
        printf("%d", x);
    }
    printf("\n");

    // close the file
    fclose(fp); // 중요하다.
    return 0;
}
