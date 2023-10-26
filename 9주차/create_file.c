#include <stdio.h>
#include <stdlib.h>

#define FileName "text.txt"
int main()
{
    char c = 0;
    FILE *fp = fopen(FileName, "w");
    if (fp == NULL)
    {
        printf("Failed to open %s\n", FileName);
        exit(-1);
    }
    printf("Write a text to store in %s\n", FileName);
    printf("Press CTRL-Z to terminate.\n");
    while ((c = getchar()) != EOF)
        fputc(c, fp);
    fclose(fp);
    return 0;
}
