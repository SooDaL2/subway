#include "header.h"

int* map[MAP_COL][MAP_ROW];

int mapInit() {

	int i, j, k, m, n;
	int count = 5;

	// �׵θ� ��
	for (i = 0; i < MAP_COL; i++) {
		for (j = 0; j < MAP_ROW; j++) {
			map[i][j] = SPACE;
		}
	}
	for (k = 0; k < MAP_ROW; k++) {
		map[0][k] = WALL;
		map[MAP_COL - 1][k] = WALL;
	}
	for (m = 0; m < MAP_COL; m++) {
		map[m][0] = WALL;
		map[m][MAP_ROW - 1] = WALL;
	}

	// ����ö ������ �̸� ǥ��
	for (n = 0; n < 30; n += 2) {
		map[1][n] = count;
		map[1][n + 1] = STATION_BAR;
		count++;
	}
	// ����ĭ 1ĭ, ������ĭ 1ĭ ����
	// cmdâ MAP_ROW�� ���缭 �ø���

	// ����ö ǥ��



}

int mapDisplay() {

	int i, j, k;
	int m = 0;

	for (i = 0; i < MAP_COL; i++) {
		for (j = 0; j < MAP_ROW; j++) {
			if (map[i][j] == SPACE) {
				printf("  ");
			}
			else if (map[i][j] == WALL) {
				printf("��");
			}
			else if (map[i][j] == STATION_BAR) {
				printf("----");
			}
			else if (map[i][j] == SUBWAY_BAR) {
				printf("->->");
			}
			else if (map[i][j] == SUBWAY) {
				printf("����ࢹ");
			}
			else if (map[i][j] == m + 5) {
				printf("%s", subwayLine1[1][m]);
				m++;
			}
		}
		printf("\n");
	}


}