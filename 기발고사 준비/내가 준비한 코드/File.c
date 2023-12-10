// File and Stream:
#include <stdio.h>

int main() {
    FILE *fp;  // FILE 포인터를 선언합니다. 이 포인터는 파일을 가리킵니다.

    fp = fopen("test.txt", "w");  // "test.txt"라는 이름의 파일을 쓰기 모드("w")로 엽니다.
    if (fp == NULL) {  // 파일이 제대로 열리지 않으면 에러 메시지를 출력하고 종료합니다.
        printf("파일 열기 실패!
");
        return -1;
    }

    fputs("Hello, World!", fp);  // 파일에 문자열을 씁니다.

    fclose(fp);  // 파일을 닫습니다.

    return 0;
}

// File Open/Close:
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("test.txt", "r");  // "test.txt"라는 이름의 파일을 읽기 모드("r")로 엽니다.
    if (fp == NULL) {
        printf("파일 열기 실패!
");
        return -1;
    }

    // 파일 처리 코드를 여기에 작성합니다.

    fclose(fp);  // 파일을 닫습니다. 파일을 열었으면 반드시 닫아야 합니다.

    return 0;
}


// Formatted Input/Output Functions:
#include <stdio.h>

int main() {
    FILE *fp;
    char str[50];
    int num;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("파일 열기 실패!
");
        return -1;
    }

    fscanf(fp, "%s %d", str, &num);  // fscanf 함수를 사용하여 파일에서 형식화된 입력을 받습니다.
    printf("파일에서 읽은 데이터: %s, %d
", str, num);  // printf 함수를 사용하여 형식화된 출력을 합니다.

    fclose(fp);

    return 0;
}

// Character Input/Output Functions:
