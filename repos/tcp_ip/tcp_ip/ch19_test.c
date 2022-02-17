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
//int main(void)
//{
//	unsigned threadID;
//	HANDLE hThread[THREAD_NUM];
//	clock_t start, end;
//	double result;
//	printf("> main thread를 시작합니다.\n");
//	InitializeCriticalSection(&cs);
//	start = clock();
//	//50개의 쓰레드 생성하기...
//	for (int i = 0; i < THREAD_NUM; i++)
//	{
//		if (i % 2==0) {//짝수
//			hThread[i]=(HANDLE)_beginthreadex(NULL, 0, ThreadInc, NULL, 0, &threadID);
//		}
//		else {
//			hThread[i]=(HANDLE)_beginthreadex(NULL, 0, ThreadDec, NULL, 0, &threadID);//홀수
//		}
//	}
//	
//	//hThread = _beginthreadex(NULL, 0, ThreadFunc, (void*)&param,0, &threadID);//두 번째 매개변서 스택사이즈 0 넣으면 디폴트 들어감
//	//DWORD ret=WaitForSingleObject(hThread, INFINITE);
//	DWORD ret=WaitForMultipleObjects(THREAD_NUM,hThread,TRUE, INFINITE);
//	end = clock();
//	DeleteCriticalSection(&cs);
//	/*if (ret == WAIT_OBJECT_0)
//	{
//		printf("> thread 종료 signal 수신 상태\n");
//	}
//	else if (ret == WAIT_TIMEOUT)
//	{
//		printf("> time out 상태\n");
//	}
//	else
//	{
//		printf("> 비정상 종료");
//	}*/
//	//Sleep(3000);
//	result = end - start;//msec
//	printf("> 실행시간 = %lf msec\n",result);
//	printf(">main thread를 종료합니다, num=%lld\n",num);
//	return 0;
//}
//unsigned WINAPI ThreadInc(void* arg)
//{
//	EnterCriticalSection(&cs);
//	for (int i = 0; i < 1000000; i++)
//	{
//
//		num += 1;
//
//	}
//	LeaveCriticalSection(&cs);
//	return 0;
//}
//unsigned WINAPI ThreadDec(void* arg)
//{
//	EnterCriticalSection(&cs);
//	for (int i = 0; i < 1000000; i++)
//	{
//		num -= 1;
//	}
//	LeaveCriticalSection(&cs);
//	return 0;
//}