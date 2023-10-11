#include"header.h"

struct HourMinSec nowTime() {

    struct HourMinSec HMS;

    time_t timer;
    struct tm* t;

    timer = time(NULL);     // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    t = localtime(&timer);  // �������� ���� ����ü�� �ֱ�

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

    start = clock();    // clock() : ���� �ð��� �� ������ ǥ��

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