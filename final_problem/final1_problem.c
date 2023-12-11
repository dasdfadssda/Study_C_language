/*
    Mission: read the age and weight of a dog and convert its age into human years
        read age table from a text file (e.g., see age_table1.txt and age_table2.txt)
        repeat until the user inputs -1 for the age of the dog
            read the age and weight of a dog
            convert the age of the dog into human age using the age table
            display the converted human age

    First write your algorithm in pseudo-code and then implement each step of it.
    Do not erase the pseudo-code.    
    Note! Solutions without pseudo-code WILL NOT BE ACCEPTED!

    Avoid unnecessary modifications to existing code.

    Submit your solution in a file named final1_<student_ID>.c on LMS.

    Example) ./final1.exe
        Reading age table from file "age_table1.txt"
        // the content of age table (see DisplayAgeTable())
        age of dog (input -1 to quit): 10
        weight of dog: 7
        The dog's age is equivalent to 56 human years.
        age of dog (input -1 to quit): 8
        weight of dog: 30
        The dog's age is equivalent to 55 human years.
        age of dog (input -1 to quit): 7
        weight of dog: 9
        The dog's age is equivalent to 47 human years.
        age of dog (input -1 to quit): 12
        weight of dog: 23
        The dog's age is equivalent to 77 human years.
        age of dog (input -1 to quit): 5
        weight of dog: 15
        The dog's age is equivalent to 36 human years.
        age of dog (input -1 to quit): -1
        Bye!

    * the category of a dog is decided by its weight
        the weight range of each catogory is described in the text file as follows (see age_table1.txt and age_table2.txt):
            no_category 3       // there are three categories
            9 23                // category 0: 0 <= weight < 9
                                // category 1: 9 <= weight < 23
                                // category 2: weight >= 23

            no_category 4       // there are four categories
            9 23 30             // category 0: 0 <= weight < 9
                                // category 1: 9 <= weight < 23
                                // category 2: 23 <= weight < 30
                                // category 3: weight >= 30

        each row of the age table represents "<dog_age> <human_age_for_category 0> <human_age_for_category 2> ..."
        e.g., "11 	60 	65 	72" means that a dog's age of 11 is equivalent to 60, 65, and 72 human years for a dog of category 0, 1, and 2, resepectively.
        
    * implement the following two fucntions
        void ReadAgeTable(char filename[]): reads age table from a text file, e.g., age_table1.txt, to the global variables
        int GetCategory(int weight): takes the weight of a dog as input and returns the category using category_table

*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define FILE_NAME "age_table1.txt"

#define MAX_AGE 128
#define MAX_CATEGORY 16

// global variables for age table
int max_age = 0;
int no_category = 0;
int category_table[MAX_CATEGORY] = { 0 };
int age_table[MAX_AGE][MAX_CATEGORY] = { 0 };

void ReadAgeTable(char filename[]);
void DisplayAgeTable();
int GetCategory(int weight);

int main(int argc, char *argv[])
// DO NOT modify this function
{
    char *filename = FILE_NAME;
    if(argc > 1)
        filename = argv[1];         // the program should work for "./a.exe age_table2.txt" on Windows or "./a.out age_table2.txt" on MacOS
        
    printf("Reading age table from file \"%s\"\n", filename);
    ReadAgeTable(filename);
    DisplayAgeTable();

    int age = 0;
    int weight = 0;

    while(1){
        printf("age of dog (input -1 to quit): ");
        scanf("%d", &age);

        if(age < 0)
            break;

        printf("weight of dog: ");
        scanf("%d", &weight);
        
        int category = GetCategory(weight);
        printf("The dog's age is equivalent to %d human years.\n", age_table[age][category]);
    }

    printf("Bye!\n");

    return 0;
}

void ReadAgeTable(char filename[])
// TO DO: implement this function
{
    // open text file
    FILE *fp;
    fp = fopen(filename, "r");
    
    // check error
    if (fp == NULL) {
       printf("Failed to open file %s in Line %d of file %s\n",
                filename, __LINE__, __FILE__);
        exit(1);
    }
    
    // read no_category from first line
    fscanf(fp, "no_category %d", &no_category);
    
    // read category to category_table
    for (int i = 0; i < no_category; i++) {
        fscanf(fp, "%d", &category_table[i]);
    }
    
    // read max_age 
    fscanf(fp, "max_age %d", &max_age);
    
    //initialize age_table
     for (int i = 1; i <= max_age; i++) {
        for (int j = 0; j < no_category; j++) {
            fscanf(fp, "%d", &age_table[i][j]);
        }
    }
    
    // close file
    fclose(fp);
}

int GetCategory(int weight)
// TO DO: implement this function
{
    // write your code here

   int category = 0;
    
   while (category < no_category && weight >= category_table[category]) {
        category++;
    }
    
    return category;
}

void DisplayAgeTable()
// DO NOT modify this function
{
    printf("%d catories:\n", no_category);
    printf("\tcategory 0: 0 <= weight < %d\n", category_table[0]);
    for(int j = 1; j < no_category - 1; j++)
        printf("\tcategory %d: %d <= weight < %d\n", j, category_table[j - 1], category_table[j]);
    printf("\tcategory %d: weight >= %d\n", no_category - 1, category_table[no_category - 2]);

    for(int i = 1; i <= max_age; i++){
        printf("%d) ", i);
        for(int j = 0; j < no_category; j++)
            printf("%5d ", age_table[i][j]);
        putchar('\n');
    }
}
