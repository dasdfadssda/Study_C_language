#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "my_cat.c"

int main()
{
    // open file
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("Failed to open file %s\n", FILE_NAME);
        exit(-1);
    }

    // read all characters from the file and display them on the screen
    char c = 0;
    int ret = 0;
    do {
        ret = fscanf(fp, "%c", &c);
        if(ret == 1)
            printf("%c", c);
    } while(ret != EOF);

    // close file
    fclose(fp);

    printf("\n");
    
    return 0;
}