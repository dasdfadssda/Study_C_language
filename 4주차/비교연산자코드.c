#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    // "<" 비교 연산자: 왼쪽 값이 오른쪽 값보다 작으면 참
    if (a < b) {
        printf("a는 b보다 작습니다.\n");
    } else {
        printf("a는 b보다 크거나 같습니다.\n");
    }

    // "<=" 비교 연산자: 왼쪽 값이 오른쪽 값보다 작거나 같으면 참
    if (a <= b) {
        printf("a는 b보다 작거나 같습니다.\n");
    } else {
        printf("a는 b보다 큽니다.\n");
    }

    // ">" 비교 연산자: 왼쪽 값이 오른쪽 값보다 크면 참
    if (a > b) {
        printf("a는 b보다 큽니다.\n");
    } else {
        printf("a는 b보다 작거나 같습니다.\n");
    }

    // ">=" 비교 연산자: 왼쪽 값이 오른쪽 값보다 크거나 같으면 참
    if (a >= b) {
        printf("a는 b보다 크거나 같습니다.\n");
    } else {
        printf("a는 b보다 작습니다.\n");
    }

    return 0;
}
