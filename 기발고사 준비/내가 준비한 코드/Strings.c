// Strings in C Language:

#include <stdio.h>

int main() {
    char str[6] = "Hello";  // 문자열은 문자 배열로 표현되며, '\0' 문자로 끝납니다.
    printf("%s", str);      // 문자열을 출력합니다.

    return 0;
}


// String Input/Output Functions:
#include <stdio.h>

int main() {
    char str1[50], str2[50];  // 두 개의 문자열을 저장할 배열을 선언합니다.

    printf("문자열을 입력하세요: ");
    fgets(str1, sizeof(str1), stdin);  // fgets 함수를 사용하여 문자열을 입력받습니다.
    // fgets 함수는 첫 번째 인자로 주어진 배열에 두 번째 인자에 지정한 길이만큼의 문자를 세 번째 인자로 지정한 스트림에서 읽어옵니다.
    // 여기서는 표준 입력 스트림인 stdin에서 문자를 읽어와 str1에 저장하며, 최대 50개의 문자를 읽어옵니다.
    // fgets 함수는 문자열의 끝에 null 문자('\0')를 추가하므로, 실제로 읽어올 수 있는 문자의 수는 지정한 길이보다 하나 적습니다.
    // 또한 fgets 함수는 개행 문자('\n')를 만나면 그 즉시 읽기를 중단하고, 읽어온 문자열에 개행 문자를 포함시킵니다.
    printf("fgets로 입력받은 문자열: %s", str1);  // printf 함수를 사용하여 문자열을 출력합니다.

    printf("다른 문자열을 입력하세요: ");
    gets(str2);  // gets 함수를 사용하여 문자열을 입력받습니다. 
    // gets 함수는 첫 번째 인자로 주어진 배열에 문자를 읽어와 저장합니다.
    // gets 함수는 개행 문자('\n')를 만나면 그 즉시 읽기를 중단하고, 읽어온 문자열의 끝에 null 문자('\0')를 추가합니다.
    // gets 함수는 버퍼 오버플로우의 위험이 있으므로, 보안상의 이유로 C11 표준에서는 삭제되었습니다.
    puts("gets로 입력받은 문자열: ");  // puts 함수를 사용하여 문자열을 출력합니다.
    puts(str2);  // puts 함수는 첫 번째 인자로 주어진 문자열을 출력하고, 출력 후에 개행 문자('\n')를 추가로 출력합니다.

    return 0;
}


// String Manipulation Functions:
#include <stdio.h>
#include <string.h>

int main() {
    char src[50] = "Hello";
    char dest[50];

    strcpy(dest, src);  // strcpy 함수를 사용하여 src 문자열을 dest 문자열로 복사합니다.
    printf("복사된 문자열: %s", dest);

    strcat(dest, ", World!");  // strcat 함수를 사용하여 dest 문자열에 ", World!"를 이어 붙입니다.
    printf("변경된 문자열: %s", dest);

    printf("문자열의 길이: %d", strlen(dest));  // strlen 함수를 사용하여 문자열의 길이를 출력합니다.

    return 0;
}

// String/Data Conversion:
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[10] = "123";
    int num;

    num = atoi(str);  // atoi 함수를 사용하여 문자열을 정수로 변환합니다.
    printf("변환된 숫자: %d", num);

    return 0;
}
