//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<Windows.h>
//#include<process.h>
//
//#define BUF_SIZE 100
//
//unsigned WINAPI SendMsg(void* arg);
//unsigned WINAPI RecvMsg(void* arg);
//void ErrorHandling(char* msg);
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET hSock;
//	SOCKADDR_IN servAdr;
//	HANDLE hSndThread, hRcvThread;
//	if (argc != 3)
//	{
//		printf("Usage: %s <IP> <port> <name>\n", argv[0]);
//		exit(1);
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	hSock = socket(PF_INET, SOCK_STREAM, 0);
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
//	servAdr.sin_port = htons(atoi(argv[2]));
//
//	if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("connect() error");
//
//	hSndThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&hSock, 0, NULL);
//	hRcvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&hSock, 0, NULL);
//
//	WaitForSingleObject(hSndThread, INFINITE);
//	WaitForSingleObject(hRcvThread, INFINITE);
//	closesocket(hSock);
//	WSACleanup();
//	return 0;
//}
//void ErrorHandling(char* msg)
//{
//	fputs(msg, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//unsigned WINAPI SendMsg(void* arg)
//{
//	SOCKET hSock = *((SOCKET*)arg);
//	char message[255];
//	while (1)
//	{
//		fgets(message, BUF_SIZE, stdin);
//		send(hSock, message, strlen(message), 0);
//	}
//	return 0;
//}
//unsigned WINAPI RecvMsg(void* arg)
//{
//	SOCKET hSock = *((SOCKET*)arg);
//	char message[255];
//	int strLen;
//	while (1)
//	{
//		strLen = recv(hSock, message, sizeof(message), 0);
//		if (strLen == -1)
//			return -1;
//		message[strLen] = 0;
//		printf("Message from Server: %s", message);
//	}
//	return 0;
//}