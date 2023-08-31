#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("첫 번째 숫자를 입력하세요: ");
    scanf("%lf", &num1);

    printf("두 번째 숫자를 입력하세요: ");
    scanf("%lf", &num2);

    printf("사칙연산 중 하나를 선택하세요 (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("0으로 나눌 수 없습니다.\n");
                return 1;
            }
            break;
        default:
            printf("잘못된 연산자 입력입니다.\n");
            return 1;
    }

    printf("결과: %lf\n", result);

    return 0;
}
