//#include<stdio.h>
//#include<Windows.h>
//#include<process.h>
//#define NUM_THREAD 5
//unsigned WINAPI threadInc(void* arg);
//unsigned WINAPI threadDes(void* arg);
//
//long long num = 0;
//HANDLE hMutex;
//
//int main(int argc, char* argv[])
//{
//	HANDLE tHandles[NUM_THREAD];
//	int i;
//
//	hMutex = CreateMutex(NULL, FALSE, NULL);
//	for (i = 0; i < NUM_THREAD; i++)
//	{
//		if (i % 2)
//			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadInc, NULL, 0, NULL);
//		else
//			tHandles[i] = (HANDLE)_beginthreadex(NULL, 0, threadDes, NULL, 0, NULL);
//	}
//
//	WaitForMultipleObjects(NUM_THREAD, tHandles, TRUE, INFINITE);
//	CloseHandle(hMutex);
//	printf("result: %lld \n", num);
//	return 0;
//}
//unsigned WINAPI threadInc(void* arg)
//{
//	int i;
//	printf("hello1\n");
//	WaitForSingleObject(hMutex, INFINITE);
//	printf("hello2\n");
//	for (i = 0; i < 2; i++)
//	{
//		printf("hello3\n");
//		num += 1;
//		printf("hello4\n");
//
//	}
//	ReleaseMutex(hMutex);
//	return 0;
//}
//unsigned WINAPI threadDes(void* arg)
//{
//	int i;
//	printf("hello5\n");
//	WaitForSingleObject(hMutex, INFINITE);
//	printf("hello6\n");
//	for (i = 0; i < 2; i++)
//	{
//		printf("hello7\n");
//		num -= 1;
//		printf("hello8\n");
//	}
//	ReleaseMutex(hMutex);
//	return 0;
//}