//#include <stdio.h>
//#include <stdlib.h>
//#include <process.h>
//#include <winsock2.h>
//#include <windows.h>
//
//#define BUF_SIZE 100
//#define READ	3
//#define	WRITE	5
//
//typedef struct    // socket info
//{
//	SOCKET hClntSock;
//	SOCKADDR_IN clntAdr;
//} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;
//
//typedef struct    // buffer info
//{
//	OVERLAPPED overlapped;
//	WSABUF wsaBuf;
//	char buffer[BUF_SIZE];
//	int rwMode;    // READ or WRITE
//} PER_IO_DATA, *LPPER_IO_DATA;
//
//DWORD WINAPI EchoThreadMain(LPVOID CompletionPortIO);
//void ErrorHandling(char *message);
//
//int main(int argc, char* argv[])
//{
//	WSADATA	wsaData;
//	HANDLE hComPort;
//	SYSTEM_INFO sysInfo;
//	LPPER_IO_DATA ioInfo;
//	LPPER_HANDLE_DATA handleInfo;
//
//	SOCKET hServSock;
//	SOCKADDR_IN servAdr;
//	int recvBytes, i, flags = 0;
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//	printf("H 1\n");
//	hComPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
//	printf("H 2\n");
//	GetSystemInfo(&sysInfo);
//	printf("H 3\n");
//	for (i = 0; i<sysInfo.dwNumberOfProcessors; i++)
//		_beginthreadex(NULL, 0, EchoThreadMain, (LPVOID)hComPort, 0, NULL);
//	printf("CPU 개수: %d \n",sysInfo.dwNumberOfProcessors);
//	printf("H 4\n");
//	hServSock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//	printf("H 5\n");
//	bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr));
//	listen(hServSock, 5);
//
//	while (1)
//	{
//		printf("H 6\n");
//		SOCKET hClntSock;
//		SOCKADDR_IN clntAdr;
//		int addrLen = sizeof(clntAdr);
//		printf("H 6-1\n");
//		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &addrLen);
//		printf("H 6-2\n");
//		handleInfo = (LPPER_HANDLE_DATA)malloc(sizeof(PER_HANDLE_DATA));
//		handleInfo->hClntSock = hClntSock;
//		memcpy(&(handleInfo->clntAdr), &clntAdr, addrLen);
//		printf("H 7\n");
//		CreateIoCompletionPort((HANDLE)hClntSock, hComPort, (DWORD)handleInfo, 0);
//		printf("H 8\n");
//		ioInfo = (LPPER_IO_DATA)malloc(sizeof(PER_IO_DATA));
//		memset(&(ioInfo->overlapped), 0, sizeof(OVERLAPPED));
//		ioInfo->wsaBuf.len = BUF_SIZE;
//		ioInfo->wsaBuf.buf = ioInfo->buffer;
//		ioInfo->rwMode = READ;
//		printf("H 9\n");
//		WSARecv(handleInfo->hClntSock, &(ioInfo->wsaBuf),
//			1, &recvBytes, &flags, &(ioInfo->overlapped), NULL);
//		printf("H 10\n");
//	}
//	return 0;
//}
//
//DWORD WINAPI EchoThreadMain(LPVOID pComPort)
//{
//	printf("H 11\n");
//	HANDLE hComPort = (HANDLE)pComPort;
//	SOCKET sock;
//	DWORD bytesTrans;
//	LPPER_HANDLE_DATA handleInfo;
//	LPPER_IO_DATA ioInfo;
//	DWORD flags = 0;
//
//	while (1)
//	{
//		printf("H 12\n");
//		GetQueuedCompletionStatus(hComPort, &bytesTrans,
//			(LPDWORD)&handleInfo, (LPOVERLAPPED*)&ioInfo, INFINITE);
//		sock = handleInfo->hClntSock;
//		printf("H 13\n");
//		if (ioInfo->rwMode == READ)
//		{
//			puts("message received!");
//			if (bytesTrans == 0)    // EOF 전송 시
//			{
//				closesocket(sock);
//				free(handleInfo); free(ioInfo);
//				continue;
//			}
//			printf("H 14\n");
//			memset(&(ioInfo->overlapped), 0, sizeof(OVERLAPPED));
//			ioInfo->wsaBuf.len = bytesTrans;
//			ioInfo->rwMode = WRITE;
//			printf("H 14-0\n");
//			WSASend(sock, &(ioInfo->wsaBuf),
//				1, NULL, 0, &(ioInfo->overlapped), NULL);
//			printf("H 14-1\n");
//			ioInfo = (LPPER_IO_DATA)malloc(sizeof(PER_IO_DATA));
//			memset(&(ioInfo->overlapped), 0, sizeof(OVERLAPPED));
//			ioInfo->wsaBuf.len = BUF_SIZE;
//			ioInfo->wsaBuf.buf = ioInfo->buffer;
//			ioInfo->rwMode = READ;
//			printf("H 14-2\n");
//			WSARecv(sock, &(ioInfo->wsaBuf),
//				1, NULL, &flags, &(ioInfo->overlapped), NULL);
//			printf("H 15\n");
//		}
//#
//		}
//	}
//	return 0;
//}
//
//void ErrorHandling(char *message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//
//}