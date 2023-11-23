#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"

int main()
{
    // open text file
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("Failed to open file %s in Line %d of file %s\n",
                FILE_NAME, __LINE__, __FILE__);
        exit(-1);
    }

    // read the # of data
    int n = 0;
    int ret = fscanf(fp, "%d", &n);
    if(ret != 1){
        printf("Failed to read number in %d of file %s\n", __LINE__, __FILE__);
        exit(-1);
    }

    // dynamically allocate memory
    int *array = (int *)malloc(n * sizeof(int));
    if(array == NULL){
        printf("Failed to allocate memory in Line %d of file %s\n", __LINE__, __FILE__);
        exit(-1);
    }

    // read the numbers in the file
    for(int i = 0; i < n; i++)
        fscanf(fp, "%d", &array[i]);

    // close the file
    fclose(fp);

    // display all numbers
    printf("Totally, %d elements.\n", n);
    for(int i = 0; i < n; i++)
        printf("\tarray[%d] = %d\n", i, array[i]);

    // free memory
    free(array);

    return 0;
}