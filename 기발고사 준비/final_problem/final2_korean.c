#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_WORD_LEN 64

// 단어의 시작과 끝 인덱스를 찾는 함수
int FindNextWord(char *str, int *start, int *end);

// 문자열에서 특정 부분 문자열을 추출하는 함수
void Substring(char *str, int start, int end, char *substring);

int main()
{
#ifdef DEBUG
    // 테스트용 문자열 (디버그 모드에서만 사용됨)
    char text[] = "God loves you    and  has  a wonderful plan      for your life.     ";
    printf("Input text: %s\n", text);
#else
    // 사용자 입력을 받는 부분
    char text[256] = "";
    printf("Input text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0; // 개행 문자 제거
#endif

    int start_idx = 0, end_idx = 0;

    // FindNextWord 함수를 이용하여 모든 단어를 찾고 출력
    while (FindNextWord(text, &start_idx, &end_idx))
    {
        printf("start_idx = %d, end_idx = %d, ", start_idx, end_idx);
        fflush(stdout);

        char substring[MAX_WORD_LEN] = "";
        Substring(text, start_idx, end_idx, substring);
        printf("substring = \"%s\"\n", substring);

        // 현재 단어의 다음 문자로 시작 인덱스 이동
        start_idx = end_idx + 1;
    }

    return 0;
}

// 다음 단어의 시작과 끝 인덱스를 찾는 함수
int FindNextWord(char *str, int *start, int *end)
{
    // 단어의 시작 인덱스 찾기
    while (isspace(str[*start]) && str[*start] != '\0')
    {
        (*start)++;
    }

    // 문자열의 끝인지 확인
    if (str[*start] == '\0')
    {
        *start = -1;
        *end = -1;
        return FALSE;
    }

    // 단어의 끝 인덱스 찾기
    *end = *start + 1;
    while (!isspace(str[*end]) && str[*end] != '\0')
    {
        (*end)++;
    }

    return TRUE;
}

// 주어진 문자열에서 특정 부분 문자열을 추출하는 함수
void Substring(char *str, int start, int end, char *substring)
{
    int i = 0, j = 0;

    for (i = start; i < end; i++, j++)
    {
        substring[j] = str[i];
    }
    // 부분 문자열의 끝에 null 문자 추가
    substring[j] = '\0';
}
