#include <stdio.h>

// GCD(최대공약수) 계산 함수
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

// LCM(최소공배수) 계산 함수
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

// 팩토리얼 계산 함수
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// 피보나치 수열 계산 함수
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 정육면체 부피 계산 함수
double cubeVolume(double sideLength) {
    return sideLength * sideLength * sideLength;
}

// 구체 부피 계산 함수
double sphereVolume(double radius) {
    return (4.0 / 3.0) * 3.14159265359 * radius * radius * radius;
}

int main() {
    int num1, num2;

    // 사용자로부터 두 개의 정수 입력 받기
    printf("두 개의 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    // GCD 및 LCM 계산
    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);

    // 결과 출력
    printf("최대공약수(GCD)는: %d\n", gcd);
    printf("최소공배수(LCM)는: %d\n", lcm);

    // 팩토리얼 및 피보나치 수열 계산
    int n;
    printf("팩토리얼 및 피보나치 수열 계산을 위한 양의 정수를 입력하세요: ");
    scanf("%d", &n);
    printf("%d의 팩토리얼: %d\n", n, factorial(n));
    printf("%d까지의 피보나치 수열: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    // 정육면체 및 구체 부피 계산
    double sideLength, radius;
    printf("정육면체의 변의 길이를 입력하세요: ");
    scanf("%lf", &sideLength);
    printf("정육면체의 부피: %.2lf\n", cubeVolume(sideLength));

    printf("구의 반지름을 입력하세요: ");
    scanf("%lf", &radius);
    printf("구의 부피: %.2lf\n", sphereVolume(radius));

    return 0;
}
