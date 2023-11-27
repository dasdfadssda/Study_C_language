#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buffer[512] = "";
    char *text[1024] = { NULL };
    int no_line = 0;

    while(1){
        // read a text line
        printf("Input text (type \"quit\" to quit): ");
        fgets(buffer, 512, stdin);  // "Hello\n"
        int len = strlen(buffer);   // len == 6
        buffer[--len] = 0;          // len == 6, buffer == "Hello"

        if(strcmp(buffer, "quit") == 0)
            break;

        // dynamically allocate memory for the new string
        // store the addresss in text[no_line]
        text[no_line] = (char*)malloc(strlen(buffer) + 1);  // + 1 is for the null character
        if(text[no_line] == NULL){
            printf("Failed to allocate memory in Line %d of %s\n", __LINE__, __FILE__);
            exit(-1);
        }
 
        // copy the input string into text[no_line]
        strcpy(text[no_line], buffer);

        // increase no_line
        no_line++;
    }

    for(int i = 0; i < no_line; i++)
        printf("text[%d] = [%s]\n", i, text[i]);

    // deallocate dynamic memory blocks
    for(int i = 0; i < no_line; i++){
        free(text[i]);
        text[i] = NULL;
    }

    return 0;
}