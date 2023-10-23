#include <stdio.h>

int main() {
    int length;

    // 사용자로부터 길이 입력 받기
    printf("별의 길이를 입력하세요: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
