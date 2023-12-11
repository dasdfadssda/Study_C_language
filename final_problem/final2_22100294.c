/*
    Mission: read an integer and convert it into string

    First write your algorithm in pseudo-code and then implement each step of it.
    Do not erase the pseudo-code.
    Note! Solutions without pseudo-code WILL NOT BE ACCEPTED!

    The following code has a few bugs. Correct all of them.
    Modifying correct code can be penalized.

    Submit your solution in a file named final2_<student_ID>.c on LMS.

    Ex) Input an integer: 3141592
        3141592 = [three one four one five nine two]

    Ex) Input an integer: 98742
        98742 = [nine eight seven four two]

    Ex) Input an integer: 9876
        9876 = [nine eight seven six]

    Ex) Input an integer: 0
        0 = [zero]

*/

#include <stdio.h>
#include <string.h>

char digit_strings[][16] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"};

// ignore these declarations but leave them as they are.
int GetDigit(int x, int place);
int CountDigit(int x);

int main(){
    int x = 0;
    printf("Input an integer: ");
    scanf("%d", &x);

    // TO DO: convert x into string
    //   e.g., for x == 123, num_str should be "one two three"
    //         for x == 70239, num_str should be "seven zero two three nine"
    char num_str[256] = "";

    //  Initialize count
    int count = 1; // DO NOT modify this line
    // TO DO: find the number of digits (implement here)

    //  Find the number of digits in x
    count = CountDigit(x);

    for (int i = count-1; i >= 0; i--){

        //  Initialize idx
        int idx = 0;
        // TO DO: get idx to retrieve substring (implement here)

        // Get the index of the current digit
        idx = GetDigit(x, i);

        // Append digit_strings[idx] to num_str
        strcat(num_str, digit_strings[idx]);
        if (i > 0)
            strcat(num_str," ");
    }

    // print x, num_str
    printf("%d = [%s]\n", x, num_str); // TO DO modify this line

    return 0;
}

int GetDigit(int x, int place){

    while (place > 0){
        // Divide x by 10 and place -1
        x = x / 10;
        place = place - 1;
    }
    return x % 10;
}

int CountDigit(int x){

    // Initialize num = 0 and update x by dividing it by 10
    int num = 0;
    while (x != 0){
        x = x / 10;
        num = num + 1; 
    }
    return num;
}