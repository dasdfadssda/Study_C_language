// Arrays:
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // 정수형 배열을 선언하고 초기화합니다.

    for (int i = 0; i < 5; i++)
    {
        printf("배열의 %d번째 원소: %d", i, arr[i]);  // 배열의 각 원소를 출력합니다.
    }

    return 0;
}

// Passing Array as Function Arguments:
#include <stdio.h>

// 함수 정의: printArray
// 이 함수는 정수형 배열과 그 배열의 크기를 인자로 받아, 배열의 모든 원소를 출력합니다.
// arr[]: 출력할 정수형 배열
// size: 배열의 크기
void printArray(int arr[], int size)
{
    // 배열의 크기만큼 반복하는 for 루프를 시작합니다.
    // i는 배열의 인덱스를 나타냅니다.
    for (int i = 0; i < size; i++)
    {
        // printf 함수를 사용하여 배열의 인덱스와 그 위치의 원소를 출력합니다.
        // %d는 정수를 출력하기 위한 형식 지정자입니다.
        printf("배열의 %d번째 원소: %d", i, arr[i]);
    }
}

int main()
{
    // 5개의 원소를 갖는 정수형 배열 arr을 선언하고 초기화합니다.
    int arr[5] = {1, 2, 3, 4, 5};

    // printArray 함수를 호출하여 배열 arr과 그 크기를 인자로 전달합니다.
    // 이렇게 하면 함수 내부에서 배열의 모든 원소를 출력할 수 있습니다.
    printArray(arr, 5);

    // 프로그램의 정상 종료를 알리기 위해 0을 반환합니다.
    return 0;
}

// Multi-Dimensional Arrays:
#include <stdio.h>

int main()
{
    int arr[2][3] = {// 2x3 크기의 2차원 배열을 선언하고 초기화합니다.
                     {1, 2, 3},
                     {4, 5, 6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("배열의 (%d, %d) 원소: %d", i, j, arr[i][j]);  // 배열의 각 원소를 출력합니다.
        }
    }

    return 0;
}

// Sorting :
#include <stdio.h>

void bubbleSort(int arr[], int size)
{ // 버블 정렬 알고리즘을 구현한 함수입니다.
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            { // 앞의 원소가 뒤의 원소보다 크면 두 원소를 교환합니다.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[5] = {5, 3, 2, 4, 1};

    bubbleSort(arr, 5); // 배열을 정렬합니다.

    for (int i = 0; i < 5; i++)
    {
        printf("배열의 %d번째 원소: %d", i, arr[i]);  // 정렬된 배열의 각 원소를 출력합니다.
    }

    return 0;
}
