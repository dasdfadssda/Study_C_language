#include <stdio.h>

int main() {
    int year, month, day;
    
    // Get input from the user
    printf("Input your birthday year: ");
    scanf("%d", &year);
    
     // Get input from the user
    printf("month: ");
    scanf("%d", &month);
    
    // Get input from the user
    printf("day in month: ");
    scanf("%d", &day);
    
    char birthdayNum[7];
    
    // save year
    birthdayNum[0] = (year / 100) % 100 + '0';
    birthdayNum[1] = (year % 100) / 10 + '0';
    birthdayNum[2] = (year % 10) + '0';
    
    // save month
    birthdayNum[3] = (month / 10) + '0';
    birthdayNum[4] = (month % 10) + '0';
    
    // save day
    birthdayNum[5] = (day / 10) + '0';
    birthdayNum[6] = (day % 10) + '0';
    
    // add null
    birthdayNum[7] = '\0';
    
    // result
    printf("birthday in YYMMDD format = %s\n", birthdayNum);
    
    return 0;
}
