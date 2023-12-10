// Typedef :
#include <stdio.h>

// typedef를 사용하여 기존의 자료형에 새로운 이름을 지정할 수 있습니다.
typedef int INTEGER;

int main()
{
    INTEGER a = 5; // INTEGER라는 새로운 이름의 자료형을 사용하여 변수 a를 선언하고 초기화합니다.

    printf("a의 값: %d", a);

    return 0;
}

// Enumerated type:
#include <stdio.h>

// enum을 사용하여 열거형을 선언할 수 있습니다.
enum DAY
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

int main()
{
    enum DAY today = WED; // 열거형 DAY의 값 WED를 today라는 변수에 저장합니다.

    printf("오늘은 요일 코드: %d", today);

    return 0;
}

// Structures:
#include <stdio.h>

// struct를 사용하여 구조체를 선언할 수 있습니다.
struct Person
{
    char name[20]; // 구조체의 멤버로 문자 배열 name을 선언합니다.
    int age;       // 구조체의 멤버로 정수 age를 선언합니다.
};

int main()
{
    struct Person p1 = {"John", 30}; // Person 구조체의 인스턴스 p1을 선언하고 초기화합니다.

    printf("이름: %s, 나이: %d", p1.name, p1.age);

    return 0;
}

// Unions:
#include <stdio.h>

// union을 사용하여 공용체를 선언할 수 있습니다.
union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data; // Data 공용체의 인스턴스 data를 선언합니다.

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %.1f", data.f);

    return 0;
}
