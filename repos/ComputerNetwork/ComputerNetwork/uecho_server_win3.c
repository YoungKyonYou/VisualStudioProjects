//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<process.h>
////#include "windows.h"
////#include "mmsystem.h"
//#include <winsock2.h>
//
//#define BUF_SIZE 30
//int cnt = 0;
//int status = 0;
//int input;
//WSADATA wsaData;
//int strLen;
//UINT m_nTimerID;
//SOCKET servSock;
//SOCKADDR_IN servAdr, clntAdr;
//HANDLE hMutex;
//int clntAdrSz = sizeof(clntAdr);
//char message[BUF_SIZE];
//void ErrorHandling(char* message);
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	//WaitForSingleObject(hMutex, INFINITE);
//	input = 1;
//	message[0] = (char)input;
//	sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	//ReleaseMutex(hMutex);
//	timeKillEvent(m_nTimerID);
//}
//unsigned WINAPI subMain(void* arg)
//{
//	while (1)
//	{
//		//clntAdrSz = sizeof(clntAdr);
//		strLen = recvfrom(servSock, &status, 1, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		//m_nTimerID = timeSetEvent(4000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//		printf("1번 ACK 전달\n2번 중복 ACK 전달\n3번 Time-out 발생\n");
//		printf("입력: ");
//		scanf("%d", &input);
//		timeKillEvent(m_nTimerID);
//		m_nTimerID = timeSetEvent(4000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//		message[0] = (char)input;
//		sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	}
//}
//int main(int argc, char* argv[])
//{
//	HANDLE hThread;
//	unsigned threadID;
//	int param = 5;
//
//	int thread_param = 5;
//	hMutex = CreateMutex(NULL, FALSE, NULL);
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	servSock = socket(PF_INET, SOCK_DGRAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("UDP socket creation error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(9190);
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//
//	hThread = (HANDLE)_beginthreadex(NULL, 0, subMain, NULL, 0, &threadID);
//	if (hThread == 0)
//	{
//		puts("_beginthreadex() error");
//		return -1;
//	}
//	DWORD error;
//	while (1)
//	{
//		error=WaitForSingleObject(hMutex, INFINITE);
//		if (error == WAIT_FAILED)
//			printf("wait failed\n");
//		m_nTimerID = timeSetEvent(4000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//		//printf("ds\n");
//		//Sleep(5000);//세마포어 락걸림=0
//		//timeKillEvent(m_nTimerID);
//	}
//	CloseHandle(hMutex);
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}
//
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}