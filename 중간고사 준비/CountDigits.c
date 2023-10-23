#include <stdio.h>

// 정수의 자릿수를 세는 함수
int CountDigits(int x);

int main() {
    int number;

    printf("정수를 입력하세요: ");
    scanf("%d", &number);

    int digitCount = CountDigits(number); // CountDigits 함수 호출

    printf("%d는 %d개의 숫자로 구성되어 있습니다.\n", number, digitCount);

    return 0;
}

// CountDigits 함수는 정수 x를 입력으로 받고 그 자릿수를 반환합니다.
int CountDigits(int x) {
    int count = 0;

    if (x == 0) {
        // 입력이 0인 경우, 한 자릿수로 처리합니다.
        return 1;
    }

    // 루프를 사용하여 자릿수를 세는 과정
    while (x != 0) {
        x /= 10;  // 숫자의 끝 자릿수를 제거합니다.
        count++;  // 각 제거된 숫자마다 자릿수를 증가시킵니다.
    }

    return count;
}
