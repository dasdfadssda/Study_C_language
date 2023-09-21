#include <stdio.h>
#include <string.h>

void ReverseString(char str[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int x;
    printf("정수를 입력하세요: ");
    scanf("%d", &x);

    int originalX = x; // 원래의 정수 값을 저장

    char binary[33]; // 32비트 이진 문자열을 저장할 배열 (마지막에 널 문자를 포함하기 위해 33개의 공간을 할당)

    if (x == 0) {
        binary[0] = '0';
        binary[1] = '0'; // 널 문자를 추가하여 문자열을 종료
    } else {
        int i = 0;

        while (x > 0) {
            binary[i] = (x % 2) + '0'; // 이진수의 각 자릿수를 문자로 변환하여 배열에 저장
            x /= 2;
            i++;
        }

        binary[i + 1] = '\0'; // 널 문자를 배열의 끝에 추가
    }

    printf("intermediate result = %s (2)\n", binary);

    // 이진 문자열을 뒤집기
    ReverseString(binary);

    printf("%d (10) = %s (2)\n", originalX, binary);

    return 0;
}
