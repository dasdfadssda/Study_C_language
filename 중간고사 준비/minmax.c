#include <stdio.h>

int main() {
    int numbers[10];  // 10개의 숫자를 저장할 배열 선언
    int i;
    int max, min;

    // 사용자로부터 10개의 숫자 입력 받기
    for (i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // 초기값을 배열의 첫 번째 원소로 설정
    max = min = numbers[0];

    // 최대값과 최소값 찾기
    for (i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // 최대값과 최소값 출력
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}

// // 2대 입력해서 비교하는 경우
// #include <stdio.h>
// int main() {
// int x = 0, y = 0;
// int min = 0, max = 0;
// // read two numbers 
// printf("Input two integers : "); scanf("%d %d", &x, &y);
// // find min and max 
// if(x > y){
// // if x is bigger, set max by x and min by y // otherwise, set max by y and min by x
// } else {
// }
// max = x; min = y;
// max = y; min = x;
// // print the results
// printf("min = %d, max = %d\n", min, max);
// return 0; }
