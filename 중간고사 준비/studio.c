#include <stdio.h>

int main() {
    // printf: 텍스트 출력
    printf("Hello, world!\n");

    // scanf: 입력 받기
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);

    // getchar 및 putchar: 문자 입출력
    int ch;
    printf("Type a character: ");
    ch = getchar();
    printf("You typed: ");
    putchar(ch);

    // fgets 및 fputs: 문자열 입출력
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("You entered: ");
    fputs(str, stdout);

    // 파일 입출력
    FILE *file = fopen("example.txt", "r");  // 파일 열기 (읽기 모드)
    char buffer[100];
    fread(buffer, 1, sizeof(buffer), file);  // 파일에서 데이터 읽기
    fclose(file);  // 파일 닫기

    // fprintf: 파일로 데이터 출력
    FILE *outputFile = fopen("output.txt", "w");  // 파일 열기 (쓰기 모드)
    int num = 42;
    fprintf(outputFile, "The answer is %d.\n", num);  // 파일에 출력
    fclose(outputFile);  // 파일 닫기

    return 0;
}
