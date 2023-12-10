// #include <stdio.h>

// int main() {
//     int num = 10;           // 정수형 변수 num을 선언하고 10으로 초기화합니다.
//     int *ptr;               // 정수형 포인터 ptr을 선언합니다. 아직 어떤 주소도 가리키지 않습니다.

//     ptr = &num;             // ptr에 num 변수의 주소를 대입합니다. 이제 ptr은 num을 가리키게 됩니다.

//     printf("num의 값: %d\n", num);          // num의 값을 출력합니다.
//     printf("num의 주소: %p\n", &num);       // num의 주소를 출력합니다.
//     printf("ptr의 값: %p\n", ptr);          // ptr의 값(즉, num의 주소)을 출력합니다.
//     printf("*ptr의 값: %d\n", *ptr);        // ptr이 가리키는 주소의 값(즉, num의 값)을 출력합니다.

//     *ptr = 20;              // ptr이 가리키는 주소에 있는 값(즉, num)을 20으로 변경합니다.

//     printf("num의 값: %d\n", num);          // num의 값을 출력합니다. 이전에 20으로 변경했으므로 20이 출력됩니다.

//     return 0;
// }
#include <stdio.h>

void updateValue(int *p)
{            // 포인터를 파라미터로 받는 함수를 선언합니다.
    *p = 20; // 포인터가 가리키는 값을 변경합니다.
}

int main()
{
    int num = 10;
    int *ptr;
    ptr = &num;

    printf("num의 값: %d\n", num);         
    printf("num의 주소: %p\n", &num);      
    printf("ptr의 값: %p\n", ptr);         
    printf("*ptr의 값: %d\n", *ptr);       

    updateValue(ptr); // num의 주소를 가리키는 ptr을 함수에 전달합니다.

    printf("함수 호출 후 num의 값: %d\n", num);  // 함수 호출 후 num의 값을 출력합니다. 이전에 20으로 변경했으므로 20이 출력됩니다.

    return 0;
}
