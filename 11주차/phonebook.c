#include <stdio.h>

#define MAX_LEN 128
#define MAX_ROW 100

char studentID[MAX_ROW][MAX_LEN];
char first_name[MAX_ROW][MAX_LEN];
char last_name[MAX_ROW][MAX_LEN];
char phone[MAX_ROW][MAX_LEN];
int no_student = 0;

int main()
{
    // read data from the file
    
    //  file open
    FILE *fp = NULL;
    fp = fopen("studentInfo.txt", "r");
    if(fp == NULL){
        printf("Failed to open file studentInfo.txt\n");
        return -1;
    }

    //  read the contents of the file
    //      repeat until fscanf() returns EOF
    while(1){
    //          read studentID, first name, last name, phone number
        int ret = fscanf(fp, "%s %s %s %s", studentID[no_student],
            first_name[no_student], last_name[no_student], phone[no_student]);
    
        if(ret == EOF)
            break;

    //          increase no_student
        no_student++;
    }

    // close the file
    fclose(fp);

    // display students' info
    // repeat for i from 0 to no_student
    for(int i = 0; i < no_student; i++){
    //     for each i, display studentID, first name, last name, and phone
        printf("%d) %s %s %s %s\n", i, studentID[i], first_name[i], last_name[i], phone[i]);
    }

    return 0;
}