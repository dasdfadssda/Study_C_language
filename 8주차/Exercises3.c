// 아래는 C 프로그램 comma.c의 내용으로, 사용자로부터 9자리 숫자를 입력받아,
//  해당 숫자를 세 자릿수마다 쉼표로 구분된 형식 (ABC,DEF,GHI) 으로 출력하는 프로그램입니다.

#include <stdio.h>

int main()
{
    long long int number;
    char formatted_number[20]; // 충분한 공간을 확보하여 출력 형식을 저장

    // 사용자로부터 9자리 숫자 입력 요청
    printf("Input a 9-digit number: ");
    scanf("%lld", &number);

    // 숫자를 문자열 형태로 포맷팅하여 formatted_number에 저장
    snprintf(formatted_number, 20, "%lld", number);

    // formatted_number를 ABC,DEF,GHI 형식으로 출력
    printf("Your number = %c%c%c,%c%c%c,%c%c%c\n",
           formatted_number[0], formatted_number[1], formatted_number[2],
           formatted_number[3], formatted_number[4], formatted_number[5],
           formatted_number[6], formatted_number[7], formatted_number[8]);

    return 0;
}
