#include <stdio.h>

#define SIZE 10

int main(){
    int a[SIZE] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

    int target = 9;
    int i = 0;

    printf("Input target number : ");
    scanf("%d",&target);
    // repeat for i froem to size -1 
    for (i = 0; i < SIZE; i++)
    {
        // if a[i] is the target number, break the loop
        if(a[i] == target){
            break;
        }
    }

    // display the result
    if(i == SIZE){
        printf("Failed to find target (%d).\n", target);
    } else {
        printf("target (%d) is found at index %d.\n", target, i);

    }
    



}