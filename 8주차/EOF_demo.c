#include <stdio.h>
#include <limits.h>

int main() {
    int x = 0;          // 사용자로부터 입력받은 숫자를 저장하는 변수 초기화
    int ret = 0;        // scanf 함수의 반환 값을 저장하는 변수 초기화
    int min = INT_MAX, max = INT_MIN;  // 최소값과 최대값 초기화

    while (1) {
        printf("Input a number: ");  // 사용자에게 숫자 입력을 요청하는 메시지 출력
        ret = scanf("%d", &x);       // 사용자로부터 정수 입력을 받아 변수 x에 저장하고 반환 값을 ret에 저장
        printf("x = %d (ret = %d)\n", x, ret);  // 입력된 숫자와 scanf의 반환 값을 출력

        if (ret == EOF)  // 만약 입력이 끝나면(파일의 끝(EOF)에 도달하면) 무한 루프 탈출
            break;

        if (x > max)  // 입력된 숫자가 현재까지의 최대값 max보다 크면 max를 갱신
            max = x;

        if (x < min)  // 입력된 숫자가 현재까지의 최소값 min보다 작으면 min를 갱신
            min = x;
    }

    printf("min = %d, max = %d\n", min, max);  // 최소값과 최대값을 출력
    printf("Bye!\n");  // 프로그램 종료 메시지 출력

    return 0;  // 프로그램 종료
}
