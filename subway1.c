#include"header.h"

// ����ö �����ο�
int line1Train[TRAIN_NUM][TRAIN_CAP] = { {40, 40, 40, 40, 40},
										 {40, 40, 40, 40, 40} };

// 1ȣ�� �뼱
char* subwayLine1[TRAIN_NUM][LINE_SIZE] = { { "�ŵ���", "�ű�", "���", "�뷮��", "���", "����", "��û", "����3��", "���빮", "������", "�ż���", "û����", "ȸ��", "����", "�����" },
											{ "�ŵ���", "�ű�", "���", "�뷮��", "���", "����", "��û", "����3��", "���빮", "������", "�ż���", "û����", "ȸ��", "����", "�����" } };

// �� ���� �Ÿ�
double stationDistanceWithKM[TRAIN_LINE_NUM][LINE_SIZE - 1] = { { 1, 2, 4, 2, 4, 5, 3, 4, 5, 2, 4, 5, 3, 2 },
																{ 3, 2, 4, 2, 5, 3, 3, 2, 3, 4, 3, 5, 2, 3 } };

// ������ ��
char* doorSide[DOOR_DIRECTION] = { "����", "������" };

struct HourMinSec Line1No1TrainStartHMS, Line1No2TrainStartHMS;

int subwayLine1_no1() {

	struct HourMinSec HMS;
	struct HourMinSec sectoHMS;

	int i = 0, start_time, check_time, during_time, arrive_time;
	int train_line_num = 0;	// 1ȣ��
	int train_num = 0;		// 1ȣ��
	int distance_index = 1;	// ������
	int line_station = 1;	// ������ �̸�

	srand(time(NULL));

	Line1No1TrainStartHMS = nowTime();

	display(1, 1, Line1No1TrainStartHMS);

	HMS = nowTime();
	start_time = HMStoSec(HMS);

	during_time = duringTime(train_line_num, distance_index, TRAIN_SPEED);

	arrive_time = arriveTime(start_time, during_time);
	sectoHMS = SectoHMS(arrive_time);

	mayArriveDisplay(train_line_num, line_station, sectoHMS);

	while(1) {

		HMS = nowTime();
		check_time = HMStoSec(HMS);

		if (check_time > arrive_time) {

			delaySubway(train_num, line_station);

			distance_index++;
			line_station++;

			during_time = duringTime(train_line_num, distance_index, TRAIN_SPEED);

			HMS = nowTime();
			start_time = HMStoSec(HMS);

			arrive_time = arriveTime(start_time, during_time);
			sectoHMS = SectoHMS(arrive_time);
			
			if (line_station == 4) {
				nextTrainStart(train_line_num, line_station);
				i++;
			}

			system("cls");

			display(1, 1, Line1No1TrainStartHMS);

			if (Line1No2TrainStartHMS.sec != 0) {
				display(1, 2, Line1No2TrainStartHMS);
			}

			mayArriveDisplay(train_line_num, line_station, sectoHMS);

			if (line_station == LINE_SIZE - 1) {
				printf("������ �����߽��ϴ�.\n");
				break;
			}

		}
		
	}

}

int subwayLine1_no2() {

	struct HourMinSec HMS;
	struct HourMinSec sectoHMS;

	int i = 0, start_time, check_time, during_time, arrive_time;
	int train_line_num = 0;	// 1ȣ��
	int train_num = 1;		// 2ȣ��
	int distance_index = 1;	// ������
	int line_station = 1;	// ������ �̸�

	srand(time(NULL));

	Line1No2TrainStartHMS = nowTime();

	display(1, 2, Line1No1TrainStartHMS);

	HMS = nowTime();
	start_time = HMStoSec(HMS);

	during_time = duringTime(train_line_num, distance_index, TRAIN_SPEED);

	arrive_time = arriveTime(start_time, during_time);
	sectoHMS = SectoHMS(arrive_time);

	mayArriveDisplay(train_line_num, line_station, sectoHMS);

	while (1) {

		HMS = nowTime();
		check_time = HMStoSec(HMS);

		if (check_time > arrive_time) {

			delaySubway(train_num, line_station);

			distance_index++;
			line_station++;

			during_time = duringTime(train_line_num, distance_index, TRAIN_SPEED);

			HMS = nowTime();
			start_time = HMStoSec(HMS);

			arrive_time = arriveTime(start_time, during_time);
			sectoHMS = SectoHMS(arrive_time);

			system("cls");

			display(1, 2, Line1No2TrainStartHMS);

			mayArriveDisplay(train_line_num, line_station, sectoHMS);

			if (line_station == LINE_SIZE - 1) {
				printf("������ �����߽��ϴ�.\n");
				break;
			}

		}

	}

}