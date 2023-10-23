#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // 사용자로부터 문자열 입력 받기
    printf("문자열을 입력하세요: ");
    gets(str1);

    // 문자열을 역순으로 출력
    printf("입력한 문자열을 역순으로 출력: ");
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        putchar(str1[i]);
    }
    printf("\n");

    // 문자열의 길이 출력
    printf("문자열의 길이: %d\n", strlen(str1));

    // 두 문자열을 연결
    printf("두 번째 문자열을 입력하세요: ");
    gets(str2);
    strcat(str1, str2);
    printf("두 문자열을 연결한 결과: %s\n", str1);

    return 0;
}
