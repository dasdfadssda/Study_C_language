// Text vs. Binary Streams:
#include <stdio.h>

int main() {
    int num = 65;  // 저장할 데이터를 선언합니다.

    // 텍스트 스트림으로 파일에 쓰기
    FILE *text_stream = fopen("text.txt", "w");  // 텍스트 모드로 파일을 연 후 파일 포인터를 반환합니다.
    fprintf(text_stream, "%d", num);  // num의 값을 텍스트 형식으로 파일에 씁니다.
    fclose(text_stream);  // 파일을 닫습니다. 이것은 버퍼링된 출력을 파일에 쓰고, 파일을 닫습니다.

    // 바이너리 스트림으로 파일에 쓰기
    FILE *binary_stream = fopen("binary.bin", "wb");  // 바이너리 모드로 파일을 연 후 파일 포인터를 반환합니다.
    fwrite(&num, sizeof(int), 1, binary_stream);  // num의 값을 바이너리 형식으로 파일에 씁니다.
    fclose(binary_stream);  // 파일을 닫습니다.

    return 0;
}


// Accessing Binary Files:
#include <stdio.h>

int main() {
    int num;  // 파일에서 읽은 데이터를 저장할 변수를 선언합니다.

    // 바이너리 스트림으로 파일 읽기
    FILE *binary_stream = fopen("binary.bin", "rb");  // 바이너리 모드로 파일을 연 후 파일 포인터를 반환합니다.
    fread(&num, sizeof(int), 1, binary_stream);  // 파일에서 바이너리 형식의 데이터를 읽어 num에 저장합니다.
    fclose(binary_stream);  // 파일을 닫습니다.

    printf("읽은 값: %d", num);  // 읽은 값을 출력합니다.

    return 0;
}


// Other I/O Functions:
#include <stdio.h>

int main() {
    int num = 65;  // 저장할 데이터를 선언합니다.

    // 파일에 쓰기
    FILE *stream = fopen("file.txt", "w");  // 쓰기 모드로 파일을 연 후 파일 포인터를 반환합니다.
    putc(num, stream);  // num의 값을 파일에 씁니다.
    fclose(stream);  // 파일을 닫습니다.

    // 파일에서 읽기
    stream = fopen("file.txt", "r");  // 읽기 모드로 파일을 연 후 파일 포인터를 반환합니다.
    char c = getc(stream);  // 파일에서 문자를 읽어 c에 저장합니다.
    fclose(stream);  // 파일을 닫습니다.

    printf("읽은 값: %c", c);  // 읽은 값을 출력합니다.

    return 0;
}
