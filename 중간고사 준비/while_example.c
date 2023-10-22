#include <stdio.h>

int main()
{
    int number;

    while (1)
    { // 무한 루프 시작
        printf("양의 정수를 입력하세요 (0을 입력하면 종료): ");
        scanf("%d", &number);

        if (number == 0)
        {
            printf("프로그램을 종료합니다.\n");
            break; // 루프 종료
        }

        if (number < 0)
        {
            printf("음수는 처리하지 않습니다. 다시 입력하세요.\n");
            continue; // 현재 반복을 종료하고 다음 반복으로 이동
        }

        printf("입력한 숫자는 %d입니다.\n", number);
        // 여기에 추가적인 작업을 수행할 수 있습니다.
    }

    return 0;
}
