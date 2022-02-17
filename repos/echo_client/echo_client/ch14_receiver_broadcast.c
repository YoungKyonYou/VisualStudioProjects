//#include<stdio.h>
//#include<WinSock2.h>
//#include<WS2tcpip.h>
//#include<string.h>
//#include<stdlib.h>
//
//#define BUF_SIZE 20
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	printf("> Broadcast receiver 실행.\n");
//	SOCKADDR_IN recvAddr;
//	SOCKET receiverSocket;
//	struct ip_mreq joinAdr;
//	int strLen;
//
//	char buf[BUF_SIZE + 1];//\0문자 추가
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
//		ErrorHandling("wsaStartup Error");
//	receiverSocket = socket(PF_INET, SOCK_DGRAM, 0);
//	if (receiverSocket == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&recvAddr, 0, sizeof(recvAddr));
//	recvAddr.sin_family = AF_INET;
//	recvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//	recvAddr.sin_port = htons(atoi(argv[2]));
//	if (bind(receiverSocket, (SOCKADDR*)&recvAddr, sizeof(recvAddr)) == SOCKET_ERROR)
//		ErrorHandling("bind error");
//
//	
//	while (1)
//	{
//		strLen = recvfrom(receiverSocket, buf, BUF_SIZE, 0, NULL, 0);
//		if (strLen < 0)
//		{
//			break;
//		}
//		buf[strLen] = '\0';
//		printf("%s", buf);
//	}
//
//
//
//	closesocket(receiverSocket);
//	WSACleanup();
//	return 0;
//}