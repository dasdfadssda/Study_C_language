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
    char str1[50], str2[50];

    printf("문자열을 입력하세요: ");
    fgets(str1, sizeof(str1), stdin);  // fgets 함수를 사용하여 문자열을 입력받습니다.
    printf("fgets로 입력받은 문자열: %s", str1);  // printf 함수를 사용하여 문자열을 출력합니다.

    printf("다른 문자열을 입력하세요: ");
    gets(str2);  // gets 함수를 사용하여 문자열을 입력받습니다. 
    puts("gets로 입력받은 문자열: ");  // puts 함수를 사용하여 문자열을 출력합니다.
    puts(str2);

    return 0;
}

// String Manipulation Functions:
#include <stdio.h>
#include <string.h>

int main() {
    char src[50] = "Hello";
    char dest[50];

    strcpy(dest, src);  // strcpy 함수를 사용하여 src 문자열을 dest 문자열로 복사합니다.
    printf("복사된 문자열: %s
", dest);

    strcat(dest, ", World!");  // strcat 함수를 사용하여 dest 문자열에 ", World!"를 이어 붙입니다.
    printf("변경된 문자열: %s
", dest);

    printf("문자열의 길이: %d
", strlen(dest));  // strlen 함수를 사용하여 문자열의 길이를 출력합니다.

    return 0;
}

// String/Data Conversion:
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[10] = "123";
    int num;

    num = atoi(str);  // atoi 함수를 사용하여 문자열을 정수로 변환합니다.
    printf("변환된 숫자: %d
", num);

    return 0;
}
