//#include<stdio.h>
//#include<Windows.h>
//#include<process.h>
//#define STR_LEN 100
//
//unsigned WINAPI NumberOfA(void* arg);
//unsigned WINAPI NumberOfOthers(void* arg);
//
//char str[STR_LEN];
//static HANDLE hEvent;
//
//int main(int argc, char *argv[])
//{
//	HANDLE hThread1, hThread2;
//
//	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);	// 문장 ①
//
//
//	hThread1 = (HANDLE)_beginthreadex(NULL, 0, NumberOfA, NULL, 0, NULL);
//	hThread2 = (HANDLE)_beginthreadex(NULL, 0, NumberOfOthers, NULL, 0, NULL);
//
//	fputs("Input string :", stdout);				// 문장 ②
//	fgets(str, STR_LEN, stdin);
//	SetEvent(hEvent);					// 문장 ③
//	WaitForSingleObject(hThread1, INFINITE);
//	WaitForSingleObject(hThread2, INFINITE);
//	ResetEvent(hEvent);					// 문장 ④
//	CloseHandle(hEvent);
//	return 0;
//}
//
//unsigned WINAPI NumberOfA(void *arg)
//{
//	int i, cnt = 0;
//	WaitForSingleObject(hEvent, INFINITE);
//	for (i = 0; str[i] != 0; i++)
//	{
//		if (str[i] == 'A') cnt++;
//	}
//	printf("Num1: %d\n", cnt);				// 문장 ⑤
//	return 0;
//}
//unsigned WINAPI NumberOfOthers(void *arg)
//{
//	int i, cnt = 0;
//	WaitForSingleObject(hEvent, INFINITE);
//	for (i = 0; str[i] != 0; i++)
//	{
//		if (str[i] == 'B') cnt++;
//	}
//	printf("Num2: %d\n", cnt-1);				// 문장 ⑥
//	return 0;
//}