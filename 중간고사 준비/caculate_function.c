#include <stdio.h>
#include <stdbool.h>

// 함수 선언
float CalculateAverage(int scores[], int size);
char GetGrade(float score);
bool IsEven(int score);

int main()
{
    int scores[5]; // 다섯 과목의 점수 배열
    char *subjects[] = {"국어", "수학", "영어", "사회", "과학"};
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        printf("%s 점수를 0에서 100 사이에서 입력하세요: ", subjects[i]);
        scanf("%d", &scores[i]);
        if (scores[i] < 0 || scores[i] > 100)
        {
            printf("잘못된 범위의 점수입니다. 다시 입력하세요.\n");
            i--;
        }
    }

    // 평균을 계산하는 함수 호출
    float average = CalculateAverage(scores, size);
    printf("평균 성적: %.2f\n", average);

    // 평균 점수를 받아 성적을 반환하는 함수 호출
    char grade = GetGrade(average);
    printf("학점: %c\n", grade);

    // 각 과목의 점수가 짝수인지 홀수인지 확인
    for (int i = 0; i < size; i++)
    {
        if (IsEven(scores[i]))
        {
            printf("%s: 짝수\n", subjects[i]);
        }
        else
        {
            printf("%s: 홀수\n", subjects[i]);
        }
    }

    return 0;
}

// 배열의 평균을 계산하는 함수
float CalculateAverage(int scores[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    return (float)sum / size;
}

// 평균 점수를 받아 성적을 반환하는 함수
char GetGrade(float score)
{
    if (score >= 90)
    {
        return 'A';
    }
    else if (score >= 80)
    {
        return 'B';
    }
    else if (score >= 70)
    {
        return 'C';
    }
    else if (score >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

// 점수가 짝수인지 여부를 판단하는 함수
bool IsEven(int score)
{
    return score % 2 == 0;
}
