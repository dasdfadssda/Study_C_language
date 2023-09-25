#include <stdio.h>

int main()
{
    int year, month, day;

    // Get input from the user
    printf("Input your birthday\n");

    printf("year: ");
    scanf("%d", &year);

    // Get input from the user
    printf("month: ");
    scanf("%d", &month);

    // Get input from the user
    printf("day in month: ");
    scanf("%d", &day);

    char birthdayNum[32] = "Hello,World!\n";

    // save year
    birthdayNum[0] = (year % 100) / 10 + '0';
    birthdayNum[1] = (year % 10) + '0';

    // save month
    birthdayNum[2] = (month / 10) + '0';ㄴ
    birthdayNum[3] = (month % 10) + '0';

    // save day
    birthdayNum[4] = (day / 10) + '0';
    birthdayNum[5] = (day % 10) + '0';

    // add null
    birthdayNum[6] = '\0';

    // result
    printf("birthday in YYMMDD format = %s\n", birthdayNum);

    return 0;
}
