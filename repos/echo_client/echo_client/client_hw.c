//#include <stdio.h>
//#include <stdlib.h>
//#include <winsock2.h>
//
//#define BUF_SIZE 1024
//void ErrorHandling(char *message);
//
//int main(int argc, char *argv[])
//{
//	WSADATA wsaData;
//	SOCKET hSocket;
//	SOCKADDR_IN servAdr;
//	char message[BUF_SIZE];
//	int strLen, readLen;
//	char buf[10];
//	int tp;
//
//	if (argc != 3) {
//		printf("Usage: %s <IP> <port>\n", argv[0]);
//		exit(1);
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	hSocket = socket(PF_INET, SOCK_STREAM, 0);
//	if (hSocket == INVALID_SOCKET)
//		ErrorHandling("socket() error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
//	servAdr.sin_port = htons(atoi(argv[2]));
//
//	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("connect() error!");
//	while (1)
//	{
//		fputs("[서버에 sin() 데이터 요청] 1:요청, 0:거절\n", stdout);
//		fgets(message, BUF_SIZE, stdin);
//		if (strcmp(message, "0\n") == 0)
//		{
//			break;
//		}
//		else if (strcmp(message, "1\n") == 0)
//		{
//			printf(">서버에 sin 데이터를 요청합니다.\n");
//			strLen = 100;
//			send(hSocket, message, strlen(message), 0);
//			printf("[TCP 클라이언트] 1 바이트를 보냈습니다.\n");
//			recv(hSocket, buf, 1, 0);
//			tp = (int*)buf[0];
//			printf("[TCP 클라이언트] %d 개의 sin 데이터를 받았습니다.\n", tp);
//			readLen = 0;
//			char temp = 0;
//			while (strLen = recv(hSocket, &temp, 1, 0))
//			{
//				int num = (int*)temp;
//				if (num == -1)
//					break;
//				while (1)
//				{
//					readLen += recv(hSocket, &message[readLen], num + 1, 0);
//					if (readLen >= num - 1)
//					{
//						printf("%s\n", message);
//						memset(message, 0, sizeof(message));
//						readLen = 0;
//						break;
//					}
//				}
//			}
//		}
//		else
//		{
//			fputs("0 아니면 1를 입력해주세요\n", stdout);
//			continue;
//		}
//	}
//
//	closesocket(hSocket);
//	WSACleanup();
//	return 0;
//}
//
//void ErrorHandling(char *message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}