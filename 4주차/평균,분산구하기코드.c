#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2, num3, num4;
    double average, variance;

    printf("input 4 numbers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    // 평균 계산
    average = (num1 + num2 + num3 + num4) / 4.0;

    // 분산 계산
    variance = ((num1 - average) * (num1 - average) +
                (num2 - average) * (num2 - average) +
                (num3 - average) * (num3 - average) +
                (num4 - average) * (num4 - average)) / 4.0;

    printf("average = %.6lf, variance = %.6lf\n", average, variance);

    return 0;
}
