//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////#include "windows.h"
////#include "mmsystem.h"
//#include <winsock2.h>
//
//#define BUF_SIZE 30
//int cnt = 0;
//int status = 0;
//int input;
//SOCKET servSock;
//SOCKADDR_IN servAdr, clntAdr;
//char message[BUF_SIZE];
//void ErrorHandling(char* message);
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	input = 1;
//	message[0] = (char)input;
//	sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	timeKillEvent(m_nTimerID);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	//SOCKET servSock;
//	//char message[BUF_SIZE];
//	int strLen;
//	int clntAdrSz;
//	UINT m_nTimerID;
//	//SOCKADDR_IN servAdr, clntAdr;
//	//if (argc != 2) {
//	//	printf("Usage : %s <port>\n", argv[0]);
//	//	exit(1);
//	//}
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
//	while (1)
//	{
//		clntAdrSz = sizeof(clntAdr);
//		strLen = recvfrom(servSock, &status, 1, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		//	printf("server status:%d\n",status);
//		m_nTimerID = timeSetEvent(4000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//		printf("1번 ACK 전달\n2번 중복 ACK 전달\n3번 Time-out 발생\n");
//		printf("입력: ");
//		scanf("%d", &input);
//		timeKillEvent(m_nTimerID);
//		message[0] = (char)input;
//		sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	}
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