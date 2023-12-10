#include <stdio.h>
#include <string.h>  // strcpy 함수를 사용하기 위해 추가

// 구조체 정의
typedef struct {
    int age;
    char name[10];
} Student;

// 함수 정의 : Student 구조체의 포인터를 파라미터로 받아 age와 name을 변경합니다.
void changeStudentInfo(Student *s, int new_age, char *new_name) {
    s->age = new_age;            // '->' 연산자를 사용해 age에 접근합니다.
    strcpy(s->name, new_name);   // '->' 연산자를 사용해 name에 접근합니다.
}

int main() {
    Student s = {15, "홍길동"};  // Student 구조체 s를 초기화합니다.

    printf("변경 전 - 나이: %d, 이름: %s\n", s.age, s.name);

    changeStudentInfo(&s, 16, "이몽룡");  // changeStudentInfo 함수를 호출하여 s의 정보를 변경합니다.

    printf("변경 후 - 나이: %d, 이름: %s\n", s.age, s.name);

    return 0;
}
