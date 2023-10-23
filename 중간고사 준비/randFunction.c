#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // 랜덤 시드를 초기화 (현재 시간을 기반으로)
    srand(time(NULL));

    // // 0에서 99까지의 랜덤 숫자 생성
    // int random_number = rand() % 100;

    // 1에서 100까지의 랜덤 숫자 생성
    int random_number = rand() % 100 + 1;

    printf("랜덤 숫자: %d\n", random_number);

    return 0;
}
