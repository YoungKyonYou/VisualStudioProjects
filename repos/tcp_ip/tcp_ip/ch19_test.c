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
//	printf("> main thread�� �����մϴ�.\n");
//	InitializeCriticalSection(&cs);
//	start = clock();
//	//50���� ������ �����ϱ�...
//	for (int i = 0; i < THREAD_NUM; i++)
//	{
//		if (i % 2==0) {//¦��
//			hThread[i]=(HANDLE)_beginthreadex(NULL, 0, ThreadInc, NULL, 0, &threadID);
//		}
//		else {
//			hThread[i]=(HANDLE)_beginthreadex(NULL, 0, ThreadDec, NULL, 0, &threadID);//Ȧ��
//		}
//	}
//	
//	//hThread = _beginthreadex(NULL, 0, ThreadFunc, (void*)&param,0, &threadID);//�� ��° �Ű����� ���û����� 0 ������ ����Ʈ ��
//	//DWORD ret=WaitForSingleObject(hThread, INFINITE);
//	DWORD ret=WaitForMultipleObjects(THREAD_NUM,hThread,TRUE, INFINITE);
//	end = clock();
//	DeleteCriticalSection(&cs);
//	/*if (ret == WAIT_OBJECT_0)
//	{
//		printf("> thread ���� signal ���� ����\n");
//	}
//	else if (ret == WAIT_TIMEOUT)
//	{
//		printf("> time out ����\n");
//	}
//	else
//	{
//		printf("> ������ ����");
//	}*/
//	//Sleep(3000);
//	result = end - start;//msec
//	printf("> ����ð� = %lf msec\n",result);
//	printf(">main thread�� �����մϴ�, num=%lld\n",num);
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