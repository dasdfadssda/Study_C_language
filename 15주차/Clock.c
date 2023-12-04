#include <stdio.h>

// 시간을 나타내는 CLOCK 구조체 정의
typedef struct {
    int hr, min, sec;
} CLOCK;

// 시간을 1초씩 증가시키는 함수
void increment(CLOCK* pClock) {
    // 초를 1씩 증가시킴
    (pClock->sec)++;
    
    // 초가 60초에 도달했을 때
    if (pClock->sec == 60) {
        pClock->sec = 0; // 초를 0으로 초기화
        (pClock->min)++; // 분을 1 증가시킴
        
        // 분이 60분에 도달했을 때
        if (pClock->min == 60) {
            pClock->min = 0; // 분을 0으로 초기화
            (pClock->hr)++; // 시간을 1 증가시킴
            
            // 시간이 24시에 도달했을 때
            if (pClock->hr == 24)
                pClock->hr = 0; // 시간을 0으로 초기화
        } // if 60 min
    } // if 60 sec
} // increment

// 현재 시간을 military(24시간) 형태로 출력하는 함수
void show(CLOCK* pClock) {
    printf("%02d:%02d:%02d\n", pClock->hr, pClock->min, pClock->sec);
}

int main(void) {
    int i = 0;
    CLOCK clock = {14, 38, 56}; // 초기 시간 설정: 14시 38분 56초
    
    // 6번 반복하면서 시간을 증가시키고 출력
    for (i = 0; i < 6; ++i) {
        increment(&clock); // 시간을 1초씩 증가
        show(&clock); // 현재 시간 출력
    } // for

    return 0;
} // main



// CLOCK clock; // 일반적인 구조체 변수
// CLOCK* pClock = &clock; // 구조체 포인터

// // 구조체 포인터를 통해 멤버에 접근
// pClock->hr = 12;
// pClock->min = 30;
// pClock->sec = 45;

// // 위의 코드는 아래의 코드와 동일합니다.
// (*pClock).hr = 12;
// (*pClock).min = 30;
// (*pClock).sec = 45;