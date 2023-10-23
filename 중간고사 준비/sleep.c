#include <stdio.h>
#include <unistd.h>

int main() {
    // getpid: 현재 프로세스의 ID를 가져옵니다.
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    // getppid: 부모 프로세스의 ID를 가져옵니다.
    pid_t parent_pid = getppid();
    printf("Parent Process ID: %d\n", parent_pid);

    // sleep: 지정된 시간(초) 동안 프로세스를 일시 중지합니다.
    printf("Sleeping for 2 seconds...\n");
    sleep(2); // 2초 동안 대기

    // write: 파일 디스크립터를 통해 데이터를 쓰거나 출력합니다.
    const char *message = "Hello, Unix!\n";
    write(STDOUT_FILENO, message, strlen(message));

    // read: 파일 디스크립터를 통해 데이터를 읽습니다.
    char buffer[256];
    printf("Type something: ");
    ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';  // 문자열 종료
    printf("You typed: %s", buffer);

    return 0;
}
