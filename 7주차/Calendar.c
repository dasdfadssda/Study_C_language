#include <stdio.h>

int main()
{
    int day = 0;
    int day_in_week = 0;
    int total_days = 0;
    int start_day = 0;

    // read start_day and total_days
    printf("Input start day and number of days: ");
    scanf("%d %d", &start_day, &total_days);

    // display SUN MON, ...
    printf("SUN MON TUE WED THU FRI SAT\n");

    // display a horizontal bar
    printf("--- --- --- --- --- --- ---\n");
    
    // display numbers
    // print blank start_day times
    for(int i = 0; i < start_day; i++)
        printf("    ");

    for(day = 1; day <= total_days; day++){
        printf("%3d ", day);
        start_day++;
        if(start_day == 7){
            start_day = 0;
            putchar('\n');
        }
    }

    putchar('\n');
    
    // display a horizontal bar
    printf("--- --- --- --- --- --- ---\n");

    return 0;
}