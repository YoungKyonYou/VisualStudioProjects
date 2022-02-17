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
//		fputs("[������ sin() ������ ��û] 1:��û, 0:����\n", stdout);
//		fgets(message, BUF_SIZE, stdin);
//		if (strcmp(message, "0\n") == 0)
//		{
//			break;
//		}
//		else if (strcmp(message, "1\n") == 0)
//		{
//			printf(">������ sin �����͸� ��û�մϴ�.\n");
//			strLen = 100;
//			send(hSocket, message, strlen(message), 0);
//			printf("[TCP Ŭ���̾�Ʈ] 1 ����Ʈ�� ���½��ϴ�.\n");
//			recv(hSocket, buf, 1, 0);
//			tp = (int*)buf[0];
//			printf("[TCP Ŭ���̾�Ʈ] %d ���� sin �����͸� �޾ҽ��ϴ�.\n", tp);
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
//			fputs("0 �ƴϸ� 1�� �Է����ּ���\n", stdout);
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