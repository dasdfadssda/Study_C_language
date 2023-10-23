// #include <stdio.h>

// int main() {
//     int num;

//     // 사용자로부터 숫자 입력 받기
//     printf("구구단을 출력할 숫자를 입력하세요: ");
//     scanf("%d", &num);

//     if (num < 2 || num > 9) {
//         printf("2에서 9 사이의 숫자를 입력하세요.\n");
//     } else {
//         printf("%d단을 출력합니다:\n", num);
//         for (int i = 1; i <= 9; i++) { // for문용
//             printf("%d x %d = %d\n", num, i, num * i);
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main() {
    int num;

    // 사용자로부터 숫자 입력 받기
    printf("구구단을 출력할 숫자를 입력하세요 (2에서 9 사이): ");
    scanf("%d", &num);

    if (num < 2 || num > 9) {
        printf("2에서 9 사이의 숫자를 입력하세요.\n");
    } else {
        printf("%d단을 출력합니다:\n", num);

        int i = 1;
        while (i <= 9) {
            printf("%d x %d = %d\n", num, i, num * i);
            i++;
        }
    }

    return 0;
}
