#include <stdio.h>
#include "Console.h"
#include <ctype.h>
#include <string.h>

// 함수 선언
void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space);

int main()
{
    char inputString[100];
    int upperCount = 0, lowerCount = 0, digitCount = 0, spaceCount = 0;

    printf("문자열을 입력하세요: ");
    fgets(inputString, sizeof(inputString), stdin);

    // 입력 문자열에서 개행 문자 제거
    if (inputString[strlen(inputString) - 1] == '\n')
    {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // CountCharacter 함수로 문자열 분석
    CountCharacter(inputString, &upperCount, &lowerCount, &digitCount, &spaceCount);

    // 결과 출력
    printf("입력한 문자열: \"%s\"\n", inputString);
    printf("입력한 문자열에는 다음과 같은 문자가 포함되어 있습니다:\n");
    printf("%d 개의 대문자\n", upperCount);
    printf("%d 개의 소문자\n", lowerCount);
    printf("%d 개의 숫자\n", digitCount);
    printf("%d 개의 공백 문자\n", spaceCount);

    return 0;
}

// 문자열을 분석하여 각 문자 유형의 개수를 세는 함수
void CountCharacter(char str[], int *no_upper, int *no_lower, int *no_digit, int *no_space)
{
    *no_upper = 0;  // 대문자 개수 초기화
    *no_lower = 0;  // 소문자 개수 초기화
    *no_digit = 0;  // 숫자 개수 초기화
    *no_space = 0;  // 공백 문자 개수 초기화

    // 문자열을 순회하며 각 문자 유형 세기
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper(str[i]))   // 대문자 확인
            (*no_upper)++;
        else if (islower(str[i]))  // 소문자 확인
            (*no_lower)++;
        else if (isdigit(str[i]))  // 숫자 확인
            (*no_digit)++;
        else if (isspace(str[i]))  // 공백 문자 확인
            (*no_space)++;
    }
}
