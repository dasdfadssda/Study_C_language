// File and Stream:
#include <stdio.h>

int main()
{
    FILE *fp; // FILE 포인터를 선언합니다. 이 포인터는 파일을 가리킵니다.

    fp = fopen("test.txt", "w"); // "test.txt"라는 이름의 파일을 쓰기 모드("w")로 엽니다.
    if (fp == NULL)
    { // 파일이 제대로 열리지 않으면 에러 메시지를 출력하고 종료합니다.
        printf("파일 열기 실패!
");
        return -1;
    }

    fputs("Hello, World!", fp); // 파일에 문자열을 씁니다.

    fclose(fp); // 파일을 닫습니다.

    return 0;
}

// File Open/Close:
#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("test.txt", "r"); // "test.txt"라는 이름의 파일을 읽기 모드("r")로 엽니다.
    if (fp == NULL)
    {
        printf("파일 열기 실패!
");
        return -1;
    }

    // 파일 처리 코드를 여기에 작성합니다.

    fclose(fp); // 파일을 닫습니다. 파일을 열었으면 반드시 닫아야 합니다.

    return 0;
}

// Formatted Input/Output Functions:
#include <stdio.h>

int main()
{
    FILE *fp;
    char str[50];
    int num;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패!
");
        return -1;
    }

    fscanf(fp, "%s %d", str, &num); // fscanf 함수를 사용하여 파일에서 형식화된 입력을 받습니다.
    printf("파일에서 읽은 데이터: %s, %d
", str, num);  // printf 함수를 사용하여 형식화된 출력을 합니다.

    fclose(fp);

    return 0;
}

// Character Input/Output Functions:
#include <stdio.h>

int main()
{
    FILE *fp; // 파일을 가리키는 포인터 fp를 선언합니다.
    int ch;   // 파일에서 읽어올 문자를 저장할 변수 ch를 선언합니다.

    fp = fopen("test.txt", "r"); // "test.txt" 파일을 읽기 모드("r")로 엽니다. 파일이 제대로 열리면 파일의 주소를 반환하고, 그 주소를 fp에 저장합니다.
    if (fp == NULL)
    { // 만약 파일이 제대로 열리지 않았다면 fopen 함수는 NULL을 반환합니다. 따라서 이 경우에는 에러 메시지를 출력하고 프로그램을 종료합니다.
        printf("파일 열기 실패!");
        return -1;
    }

    // while 문을 사용하여 파일의 끝에 도달할 때까지 파일에서 문자를 하나씩 읽어옵니다.
    while ((ch = fgetc(fp)) != EOF)
    {                      // fgetc 함수는 파일에서 문자 하나를 읽어옵니다. 파일의 끝에 도달하면 EOF(End Of File)를 반환합니다.
        fputc(ch, stdout); // 읽어온 문자를 stdout(표준 출력, 보통은 콘솔 화면)에 출력합니다.
    }

    fclose(fp); // 파일을 닫습니다. 파일을 열었으면 반드시 닫아야 합니다.

    return 0;
}
