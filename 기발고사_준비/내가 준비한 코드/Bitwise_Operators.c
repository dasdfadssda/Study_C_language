// Logical Operations:
#include <stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary

    // 논리 AND 연산
    printf("a && b = %d", a && b);  // 둘 다 참이므로 1을 출력합니다.

    // 논리 OR 연산
    printf("a || b = %d", a || b);  // 둘 중 하나라도 참이므로 1을 출력합니다.

    // 논리 NOT 연산
    printf("!a = %d", !a);  // a는 참이므로, !a는 거짓인 0을 출력합니다.

    return 0;
}

// Bitwise Logical Operators:
#include <stdio.h>

int main() {
    unsigned char a = 5;  // 0101 in binary
    unsigned char b = 3;  // 0011 in binary

    // 비트 단위 AND 연산
    printf("a & b = %d", a & b);  // 0101 AND 0011 equals 0001, 따라서 1을 출력합니다.

    // 비트 단위 OR 연산
    printf("a | b = %d", a | b);  // 0101 OR 0011 equals 0111, 따라서 7을 출력합니다.

    // 비트 단위 XOR 연산
    printf("a ^ b = %d", a ^ b);  // 0101 XOR 0011 equals 0110, 따라서 6을 출력합니다.

    // 비트 단위 NOT 연산
    printf("~a = %d", (unsigned char)~a);  // NOT 0101 equals 1010, 따라서 10을 출력합니다.

    return 0;
}

// Bitwise Shift Operators:
#include <stdio.h>

int main() {
    unsigned char a = 5;  // 0101 in binary

    // 왼쪽 시프트 연산
    printf("a << 1 = %d", a << 1);  // 0101을 왼쪽으로 1비트 시프트하면 1010이 되므로, 10을 출력합니다.

    // 오른쪽 시프트 연산
    printf("a >> 1 = %d", a >> 1);  // 0101을 오른쪽으로 1비트 시프트하면 0010이 되므로, 2를 출력합니다.

    return 0;
}


// 예를 들어, 2진수 0110을 10진수로 변환하면 다음과 같습니다:
// 2의 0승 자리: 0 * (2^0) = 0
// 2의 1승 자리: 1 * (2^1) = 2
// 2의 2승 자리: 1 * (2^2) = 4
// 2의 3승 자리: 0 * (2^3) = 0