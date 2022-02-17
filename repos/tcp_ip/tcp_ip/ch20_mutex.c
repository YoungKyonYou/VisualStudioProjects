//#include<stdio.h>
//#include<windows.h>
//#include<process.h>
//#include<time.h>
//#define THREAD_NUM 50
//unsigned WINAPI ThreadInc(void* arg);
//unsigned WINAPI ThreadDec(void* arg);
//long long num;
//CRITICAL_SECTION cs;
//
//HANDLE hMutex;
//
//int main(void)
//{
//	unsigned threadID;
//	HANDLE hThread[THREAD_NUM];
//	clock_t start, end;
//	double result;
//	printf("> main thread를 시작합니다.\n");
//	hMutex=CreateMutext(NULL, FALSE, NULL);
//	start = clock();
//	//50개의 쓰레드 생성하기...
//	for (int i = 0; i < THREAD_NUM; i++)
//	{
//		if (i % 2 == 0) {//짝수
//			hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadInc, NULL, 0, &threadID);
//		}
//		else {
//			hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadDec, NULL, 0, &threadID);//홀수
//		}
//	}
//
//
//	DWORD ret = WaitForMultipleObjects(THREAD_NUM, hThread, TRUE, INFINITE);
//	end = clock();
//	CloseHandle(hMutex);
//
//	result = end - start;//msec
//	printf("> 실행시간 = %lf msec\n", result);
//	printf(">main thread를 종료합니다, num=%lld\n", num);
//	return 0;
//}
//unsigned WINAPI ThreadInc(void* arg)
//{
//	WaitForSingleObject(hMutex, INFINITE);
//	for (int i = 0; i < 1000000; i++)
//	{
//
//		num += 1;
//
//	}
//	ReleaseMutex(hMutex);
//	return 0;
//}
//unsigned WINAPI ThreadDec(void* arg)
//{
//	WaitForSingleObject(hMutex, INFINITE);
//	for (int i = 0; i < 1000000; i++)
//	{
//		num -= 1;
//	}
//	ReleaseMutex(hMutex);
//	return 0;
//}