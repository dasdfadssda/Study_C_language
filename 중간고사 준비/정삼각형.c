#include <stdio.h>

int main() {
    int height = 3; // 넓이

    for (int i = 0; i < height; i++) {
        // 공백 출력
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        // 별표 출력
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
