#include"header.h"

int line1Train_num = 1;
int line3Train_num = 1;

void display(int i, int j, struct HourMinSec trainStartHMS) {	// 열차 출발시 (몇호선, 몇호차) 인지 출력

	printf("\n%d호선 %d호차 운행 시작합니다.\n", i, j);

	printf("열차 출발 시간 : %d시 %d분 %d초\n", trainStartHMS.hour, trainStartHMS.min, trainStartHMS.sec);

}

void nextTrainStart(int train_line_num, int line_station) {

	if (train_line == 0 && line_station == 4) {
		line1Train_num++;
		switch (line1Train_num) {
			case 2 :
				// 다음 열차 출발
				// subwayLine1_no2();
				break;
			default :
				break;
		}
	}
	else if (train_line == 2 && line_station == 4) {
		line3Train_num++;
		switch (line3Train_num) {
			case 2:
				// 다음 열차 출발
				// subwayLine3_no2();
				break;
			default:
				break;
		}
	}

}

int duringTime(int train_line_num, int distance_index, double speed) {

	double KMperH = stationDistanceWithKM[train_line_num][distance_index] / speed;

	int during_time = KMperH * 60 * 60;

	return during_time;

}

int arriveTime(int start_time, int during_time) {

	int arrive_time = start_time + during_time;

	return arrive_time;

}

void mayArriveDisplay(int train_line_num, int line_station, struct HourMinSec sectoHMS) {

	printf("\n%s역까지 도착 예정시간은 %d시 %d분 %d초 입니다.\n", subwayLine1[train_line_num][line_station], sectoHMS.hour, sectoHMS.min, sectoHMS.sec);

}

void delaySubway(int train_num, int line_station) {

	int door_direction = rand() % 2;

	printf("\n열차가 도착했습니다. %s문이 열립니다.\n\n", doorSide[door_direction]);

	delay(1000);

	subwayCap(train_num, line_station);

	delay(3000);

	printf("\n문이 닫힙니다. 열차 출발합니다.\n");

	delay(1000);

}

void subwayCap(int train_num, int line_station) {

	int inP[TRAIN_CAP] = { 0 };
	int	outP[TRAIN_CAP] = { 0 };

	int i, j;
	int test = 0;

	switch (line_station) {
		case 4 :	// 용산역
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 20;
				outP[i] = rand() % 10;
			}
			break;
		case 5 :	// 서울역
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 15;
				outP[i] = rand() % 20;
			}
			break;
		case 7 :	// 종로3가
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 20;
				outP[i] = rand() % 15;
			}
			break;
		case 11 :	// 청량리
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 20;
				outP[i] = rand() % 10;
			}
			break;
		default :
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 10;
				outP[i] = rand() % 10;
			}
			break;
	}

	for (i = 0; i < TRAIN_CAP; i++) {
		if (test == 1) {
			printf("%d호차 %d칸 탑승 인원은 %d명입니다.\n", train_num + 1, i + 1, inP[i]);
			printf("%d호차 %d칸 하차 인원은 %d명입니다.\n", train_num + 1, i + 1, outP[i]);
		}
	}

	for (j = 0; j < TRAIN_CAP; j++) {
		line1Train[train_num][j] -= inP[j];
		line1Train[train_num][j] += outP[j];
		if (line1Train[train_num][j] < 1) {
			line1Train[train_num][j] = 0;
			printf("%d호차 %d칸은 만석입니다.\n", train_num + 1, j + 1);
		}
		if (line1Train[train_num][j] > 40) {
			line1Train[train_num][j] = 40;
			printf("%d호차 %d칸을 이용바랍니다.\n", train_num + 1, j + 1);
		}
	}

}