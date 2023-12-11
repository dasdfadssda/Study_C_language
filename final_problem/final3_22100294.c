/*
    Mission: read contact information from a text file, sort them by student ID, and display them
        with the contact.txt file, the output should be as the following example:

    First write your algorithm in pseudo-code and then implement each step of it.
    Do not erase the pseudo-code.
    Note! Solutions without pseudo-code WILL NOT BE ACCEPTED!
    Submit your solution in a file named final3_<student_ID>.c on LMS.

    Avoid unnecessary modifications to existing code.

    Ex) ./final3.exe
        Totally, 4 entries.
                209123 James Bond 010-1234-5678
                209124 Bruce Wayne 010-1234-1234
                209125 Peter Parker 010-1234-1111
                209126 Clark Kent 010-1234-0000

    Note) Modifying the order of the rows in contact.txt SHOULD NOT affect the output!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contact.txt"

typedef struct
{
    char ID[32];    // student ID
    char first[32]; // first name
    char last[32];  // last name
    char tel[32];   // telephone
} Contact;

Contact *contact = NULL; // pointer for dynamic memory allocation
int count = 0;           // the # of entries in contact

void DisplayContact(Contact contact[], int n);
void SortContact(Contact contact[], int n); // sort contact

int main()
{
    // TO DO: read the contact information from the text file "contact.txt"
    //      - dynamically allocate memory to store the contact information
    //      - on failure in file open or memory allocation, display an error message and quit
    // open file
    FILE *fp = NULL;
    fp = fopen(FILE_NAME, "r");
    int ch; 
    if (fp == NULL)
    {
        printf("Failed to open file contact.txt\n");
        return -1;
    }
       while ((ch = fgetc(fp)) != EOF)
    {                    
        fputc(ch, stdout); 
        count++;
    }
    printf("\n읽은 값은 %d\n",count);

    //  read the # of data
    // dynamically allocate memory to store the contact information
    int *ptr = (int *)malloc(5 * 4 * sizeof(int));
    if (ptr == NULL)
    {
        //  - on failure in file open or memory allocation, display an error message and quit
        printf("Failed to allocate memory in Line %d of file %s\n", __LINE__, __FILE__);
        exit(-1);
        return -1;
    }

    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fscanf(fp, "%d", &ptr[i][j]);
            printf("\ntr[%d][%d] = %d\n", i,j, ptr[i][j]);
        }
    }
    
      for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            contact->ID[i] = ptr[i][j]
            strcpy( contact->first[i], ptr[i][j]);
            strcpy( contact->last[i], ptr[i][j]);
            strcpy( contact->tel[i], ptr[i][j]);
        }
      }

    // close the file
    fclose(fp);

    // DO NOT modify the following two lines
    SortContact(contact, count);
    DisplayContact(contact, count);

    // TO DO: deallocate dynamically allocated memroy block and reset the pointer to NULL
       free(ptr);

    return 0;
}

void DisplayContact(Contact contact[], int n)
{
    // DO NOT modify this function
    printf("Totally, %d entries.\n", n);
    for (int i = 0; i < n; i++)
        printf("\t%s %s %s %s\n", contact[i].ID, contact[i].first, contact[i].last, contact[i].tel);
}

void SortContact(Contact contact[], int n)
{
    // TO DO: sort contact by student ID as the above example using the algorithm in Chap. 8.
    //      Using other algorith will not be accepted
     for (int i = 1; i < n - 1; i++)
     {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (contact->ID[j] > contact->ID[j + 1])
            { // chage the item
                int temp = contact->ID[j];
                contact->ID[j] = contact->ID[j + 1];
                contact->ID[j + 1] = temp;
            }
        }
    }
}
