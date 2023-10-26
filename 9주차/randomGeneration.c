#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "random.txt"

int main()
{
    srand(time(NULL));

    // open a file
    FILE *fp = NULL;
    fp = fopen("random.txt", "w");

    // write data into file
    for (int i = 0; i <= 10; i++)
    {
        fprintf(fp, "%d", rand() % 100); // 파일에 입력.
        fprintf(fp, "\n");
    }
    // close a file
    fclose(fp);
    return 0;
}