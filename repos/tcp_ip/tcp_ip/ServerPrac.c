//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<Winsock2.h>
//#include<process.h>
//#include<windows.h>
//#define BUF_SIZE 100
//unsigned WINAPI send_Thread(void* arg);
//unsigned WINAPI receive_Thread(void* arg);
//void ErrorHandling(char* msg);
//int main(int argc, char* argv[])
//{
//	HANDLE tHandles[2];
//	WSADATA wsaData;
//	SOCKET servSocket, clntSocket;
//	SOCKADDR_IN servAdr, clntAdr;
//	int clntAdrLen;
//	if (argc != 2)
//	{
//		printf("Usage: %s <port>\n", argv[0]);
//		exit(1);
//	}
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	servSocket = socket(PF_INET, SOCK_STREAM, 0);
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//
//	if (bind(servSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//
//	if (listen(servSocket, 5) == SOCKET_ERROR)
//		ErrorHandling("listen() error");
//
//	clntAdrLen = sizeof(clntAdr);
//	clntSocket = accept(servSocket, (SOCKADDR*)&clntAdr, &clntAdrLen);
//
//	tHandles[0] = (HANDLE)_beginthreadex(NULL, 0, send_Thread, (void*)&clntSocket, 0, NULL);
//	tHandles[1] = (HANDLE)_beginthreadex(NULL, 0, receive_Thread, (void*)&clntSocket, 0, NULL);
//	WaitForMultipleObjects(2, tHandles, TRUE, INFINITE);
//	closesocket(clntSocket);
//	closesocket(servSocket);
//	WSACleanup();
//}
//void ErrorHandling(char* msg)
//{
//	fputs(msg, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//unsigned WINAPI send_Thread(void* arg)
//{
//	int strLen = 0;
//	char message[255];
//	SOCKET clntSock = *((SOCKET*)arg);
//	while (1)
//	{
//		fgets(message, BUF_SIZE, stdin);
//		send(clntSock, message,strlen(message), 0);
//	}
//}
//unsigned WINAPI receive_Thread(void* arg)
//{
//	int strLen=100, readLen = 4;
//	char message[255];
//	SOCKET clntSock = *((SOCKET*)arg);
//	while (1)
//	{
//		strLen = recv(clntSock, message, sizeof(message), 0);
//		if (strLen == -1)
//			return -1;
//		message[strLen] = 0;
//		printf("Message from Client: %s", message);
//	}
//}