#include <stdio.h>

int main() {
    int number;
    int digit1, digit2, digit3;

    // 사용자로부터 3자리 숫자 입력 요청
    printf("Input a 3-digit number: ");
    scanf("%d", &number);

    // 입력받은 숫자를 각 자릿수로 분리
    digit1 = number / 100;
    digit2 = (number % 100) / 10;
    digit3 = number % 10;

    // 분리된 각 자릿수 출력
    printf("<%d, %d, %d>\n", digit1, digit2, digit3);

    return 0;
}
