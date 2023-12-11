// Typedef :
#include <stdio.h>

// typedef를 사용하여 int라는 기존의 자료형에 INTEGER라는 새로운 이름을 지정합니다.
// 이렇게 하면 INTEGER를 int처럼 사용할 수 있게 됩니다.
typedef int INTEGER;

int main()
{
    // INTEGER라는 새로운 이름의 자료형을 사용하여 변수 a를 선언하고 초기화합니다.
    // INTEGER는 실제로는 int 형이므로, int형 변수를 선언하는 것과 동일합니다.
    INTEGER a = 5;

    printf("a의 값: %d", a);  // a의 값을 출력합니다.

    return 0;
}


// Enumerated type:
#include <stdio.h>

// enum을 사용하여 요일을 나타내는 열거형 DAY를 선언합니다.
// 각 요일은 SUN부터 SAT까지로, 각각 0부터 6의 값을 갖습니다.
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
    // 열거형 DAY의 값 WED를 today라는 변수에 저장합니다.
    // 이 때, WED는 3이므로 today의 값은 3이 됩니다.
    enum DAY today = WED;

    printf("오늘은 요일 코드: %d", today);  // today의 값을 출력합니다. 출력값은 3이 됩니다.

    return 0;
}


// Structures:
#include <stdio.h>

// struct를 사용하여 사람의 이름과 나이를 저장하는 구조체 Person을 선언합니다.
// 구조체는 서로 다른 타입의 변수들을 묶어서 하나의 새로운 타입을 만드는 것입니다.
struct Person
{
    char name[20]; // 사람의 이름을 저장하는 문자 배열입니다.
    int age;       // 사람의 나이를 저장하는 정수 변수입니다.
};

int main()
{
    // Person 구조체의 인스턴스 p1을 선언하고, 이름과 나이를 초기화합니다.
    struct Person p1 = {"John", 30};

    printf("이름: %s, 나이: %d", p1.name, p1.age);  // p1의 이름과 나이를 출력합니다.

    return 0;
}

// Unions:
#include <stdio.h>

// union을 사용하여 int, float, char[20]을 저장할 수 있는 공용체 Data를 선언합니다.
// 공용체는 여러 멤버 중 하나만 값을 저장할 수 있는 구조체와 같은 자료형입니다.
union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    // Data 공용체의 인스턴스 data를 선언합니다.
    union Data data;

    data.i = 10;  // data의 int 멤버 i에 10을 저장합니다.
    printf("data.i: %d", data.i);  // data의 int 멤버 i의 값을 출력합니다.

    data.f = 220.5;  // data의 float 멤버 f에 220.5를 저장합니다.
    printf("data.f: %.1f", data.f);  // data의 float 멤버 f의 값을 출력합니다.

    return 0;
}
