#include"header.h"

CRITICAL_SECTION cs;

unsigned _stdcall Thread_1(void* arg) {

	while (1) {
		EnterCriticalSection(&cs);
		printf("스레드 테스트1\n");
		LeaveCriticalSection(&cs);
		Sleep(5000);
	}

}

unsigned _stdcall Thread_2(void* arg) {

	while (1) {
		EnterCriticalSection(&cs);
		printf("스레드 테스트2\n");
		LeaveCriticalSection(&cs);
		Sleep(5000);
	}

}

int main(void) {
	
	//InitializeCriticalSection(&cs);

	//HANDLE thread1 = _beginthreadex(NULL, 0, Thread_1, NULL, 0, NULL);

	//HANDLE thread2 = _beginthreadex(NULL, 0, Thread_2, NULL, 0, NULL);

	//WaitForSingleObject(thread1, INFINITE);

	//DeleteCriticalSection(&cs);

	//return 0;

	// subwayLine1_no1();
	// subwayLine1_no2();

	mapInit();
	mapDisplay();

}