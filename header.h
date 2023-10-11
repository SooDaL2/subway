#ifndef __HEADER_H__
#define __HEADER_H__
#define _CRT_SECURE_NO_WARNINGS

// 해더 파일
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<WinCon.h>
#include<time.h>
#include<process.h>

// 정의
#define		LINE_SIZE		15
#define		TRAIN_NUM		2
#define		TRAIN_CAP		5
#define		TRAIN_SPEED		2000
#define		TRAIN_LINE_NUM	2
#define		DOOR_DIRECTION	2

// map 정의
#define		MAP_COL			5
#define		MAP_ROW			60
#define		SPACE			0
#define		WALL			1
#define		STATION_BAR		2
#define		SUBWAY_BAR		3
#define		SUBWAY			4


// 배열
int* map[MAP_COL][MAP_ROW];
int line1Train[TRAIN_NUM][TRAIN_CAP];
int line3Train[TRAIN_NUM][TRAIN_CAP];
char* subwayLine1[TRAIN_NUM][LINE_SIZE];
char* subwayLine3[TRAIN_NUM][LINE_SIZE];
double stationDistanceWithKM[TRAIN_LINE_NUM][LINE_SIZE - 1];
char* doorSide[DOOR_DIRECTION];

// 전역 변수
int train_line, line1Train_num, line3Train_num, line_station;

// 시각화 함수
int mapInit();
int mapDisplay();

// 라이브러리 함수
struct HourMinSec nowTime();
void delay(int sec);
int HMStoSec(struct HourMinSec HMS);
struct HourMinSec SectoHMS(int sec);

// 기능 함수
void display(int i, int j, struct HourMinSec trainStartHMS);
void nextTrainStart(int train_line_num, int line_station);
int duringTime(int train_line_num, int distance_index, double speed);
int arriveTime(int start_time, int during_time);
void mayArriveDisplay(int train_line_num, int line_station, struct HourMinSec sectoHMS);
void delaySubway(int train_num, int line_station);
void subwayCap(int train_num, int line_station);

// 1호선 함수
int subwayLine1_no1();
int subwayLine1_no2();

// 3호선 함수
int subwayLine3_no1();
int subwayLine3_no2();

// 구조체
typedef struct HourMinSec {
	int hour;
	int min;
	int sec;
} HMS;

#endif