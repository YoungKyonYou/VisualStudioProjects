//#include<stdio.h>
//#include<string.h>
//#include<WinSock2.h>
//#include<stdlib.h>
//#define BUF_SIZE 30
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET servSock;
//	char message[BUF_SIZE];
//	int strLen;
//	int clntAdrSz;
//
//	SOCKADDR_IN servAdr, clntAdr;
//	if (argc != 2)
//	{
//		printf("Usage : %s <port>\n", argv[0]);
//		exit(1);
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup error");
//
//	servSock = socket(PF_INET, SOCK_DGRAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_port = htons(atoi(argv[1]));
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind error");
//
//	while (1)
//	{
//		clntAdrSz = sizeof(clntAdr);
//		strLen = recvfrom(servSock, message, BUF_SIZE, 0, (SOCKADDR*)&clntAdr,&clntAdrSz);
//		sendto(servSock, message, strLen, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	}
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}