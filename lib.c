#include"header.h"

struct HourMinSec nowTime() {

    struct HourMinSec HMS;

    time_t timer;
    struct tm* t;

    timer = time(NULL);     // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer);  // 포맷팅을 위해 구조체에 넣기

    if (t->tm_hour > 12) {
        t->tm_hour = t->tm_hour - 12;
    }

    HMS.hour = t->tm_hour;
    HMS.min = t->tm_min;
    HMS.sec = t->tm_sec;

    return HMS;

}

void delay(int sec) {

    time_t start;
    time_t finish;

    start = clock();    // clock() : 현재 시간을 초 단위로 표현

    while (1) {
        finish = clock();
        if (finish - start > sec) {
            break;
        }
    }

}

int HMStoSec(struct HourMinSec HMS) {

    int result = 0;

    result += (HMS.hour * 60 * 60);
    result += (HMS.min * 60);
    result += HMS.sec;

    return result;

}

struct HourMinSec SectoHMS(int sec) {

    struct HourMinSec sectoHMS;

    sectoHMS.hour = sec / 60 / 60;
    sectoHMS.min = sec / 60 % 60;
    sectoHMS.sec = sec % 3600 % 60;

    return sectoHMS;

}