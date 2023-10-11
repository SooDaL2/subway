#include"header.h"

int line1Train_num = 1;
int line3Train_num = 1;

void display(int i, int j, struct HourMinSec trainStartHMS) {	// ���� ��߽� (��ȣ��, ��ȣ��) ���� ���

	printf("\n%dȣ�� %dȣ�� ���� �����մϴ�.\n", i, j);

	printf("���� ��� �ð� : %d�� %d�� %d��\n", trainStartHMS.hour, trainStartHMS.min, trainStartHMS.sec);

}

void nextTrainStart(int train_line_num, int line_station) {

	if (train_line == 0 && line_station == 4) {
		line1Train_num++;
		switch (line1Train_num) {
			case 2 :
				// ���� ���� ���
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
				// ���� ���� ���
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

	printf("\n%s������ ���� �����ð��� %d�� %d�� %d�� �Դϴ�.\n", subwayLine1[train_line_num][line_station], sectoHMS.hour, sectoHMS.min, sectoHMS.sec);

}

void delaySubway(int train_num, int line_station) {

	int door_direction = rand() % 2;

	printf("\n������ �����߽��ϴ�. %s���� �����ϴ�.\n\n", doorSide[door_direction]);

	delay(1000);

	subwayCap(train_num, line_station);

	delay(3000);

	printf("\n���� �����ϴ�. ���� ����մϴ�.\n");

	delay(1000);

}

void subwayCap(int train_num, int line_station) {

	int inP[TRAIN_CAP] = { 0 };
	int	outP[TRAIN_CAP] = { 0 };

	int i, j;
	int test = 0;

	switch (line_station) {
		case 4 :	// ��꿪
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 20;
				outP[i] = rand() % 10;
			}
			break;
		case 5 :	// ���￪
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 15;
				outP[i] = rand() % 20;
			}
			break;
		case 7 :	// ����3��
			for (i = 0; i < TRAIN_CAP; i++) {
				inP[i] = rand() % 20;
				outP[i] = rand() % 15;
			}
			break;
		case 11 :	// û����
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
			printf("%dȣ�� %dĭ ž�� �ο��� %d���Դϴ�.\n", train_num + 1, i + 1, inP[i]);
			printf("%dȣ�� %dĭ ���� �ο��� %d���Դϴ�.\n", train_num + 1, i + 1, outP[i]);
		}
	}

	for (j = 0; j < TRAIN_CAP; j++) {
		line1Train[train_num][j] -= inP[j];
		line1Train[train_num][j] += outP[j];
		if (line1Train[train_num][j] < 1) {
			line1Train[train_num][j] = 0;
			printf("%dȣ�� %dĭ�� �����Դϴ�.\n", train_num + 1, j + 1);
		}
		if (line1Train[train_num][j] > 40) {
			line1Train[train_num][j] = 40;
			printf("%dȣ�� %dĭ�� �̿�ٶ��ϴ�.\n", train_num + 1, j + 1);
		}
	}

}