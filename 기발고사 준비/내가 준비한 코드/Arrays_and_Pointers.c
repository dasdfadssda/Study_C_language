// Arrays and Pointers:
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};  // 정수 배열을 선언하고 초기화합니다.
    int *ptr = arr;  // 배열의 첫 번째 원소를 가리키는 포인터를 선언합니다.

    // 배열의 원소를 포인터를 이용해 출력합니다.
    for (int i = 0; i < 3; i++) {
        printf("배열의 %d번째 원소: %d
", i, *(ptr + i));
    }

    return 0;
}

// Pointer Arithmetic and Arrays:
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int *ptr = arr;

    // 포인터 산술을 이용해 배열의 원소에 접근합니다.
    for (int i = 0; i < 3; i++) {
        printf("배열의 %d번째 원소: %d
", i, *(ptr++));
    }

    return 0;
}

// Memory Allocation Functions:
#include <stdio.h>
#include <stdlib.h>  // malloc, free 함수를 사용하기 위한 헤더 파일입니다.

int main() {
    // malloc 함수를 사용하여 메모리를 동적으로 할당합니다. 
    // malloc 함수는 인자로 받은 바이트 수만큼의 메모리를 할당하고, 그 메모리의 시작 주소를 반환합니다.
    // 여기서는 int형 변수 3개의 크기인 3 * sizeof(int) 바이트의 메모리를 할당합니다.
    // malloc 함수가 반환하는 메모리 주소는 void* 타입이므로, 실제 사용할 타입인 int* 타입으로 캐스팅합니다.
    int *ptr = (int *)malloc(3 * sizeof(int));

    // 메모리 할당이 실패하면 malloc 함수는 NULL을 반환합니다. 
    // 따라서 ptr이 NULL인지 확인하여 메모리 할당이 제대로 되었는지 검사합니다.
    if (ptr == NULL) {
        printf("메모리 할당 실패!
");
        return -1;
    }

    // 할당된 메모리에 값을 저장합니다. 배열과 마찬가지로 ptr[i] 형태로 접근할 수 있습니다.
    for (int i = 0; i < 3; i++) {
        ptr[i] = i + 1;
    }

    // 할당된 메모리의 값을 출력합니다.
    for (int i = 0; i < 3; i++) {
        printf("메모리의 %d번째 원소: %d
", i, ptr[i]);
    }

    // 동적으로 할당한 메모리는 사용이 끝나면 반드시 해제해야 합니다. 
    // 메모리 해제는 free 함수를 사용하여 수행합니다.
    free(ptr);

    return 0;
}
