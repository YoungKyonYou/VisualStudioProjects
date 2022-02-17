//#include<stdio.h>
//#include<stdlib.h>
//#include<WinSock2.h>
//#define  BUF_SIZE 30
//
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
//	SOCKADDR_IN servAdr, clntAdr;
//	char message[BUF_SIZE];
//	int clntAdrSz, strLen;
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//	
//	servSock = socket(PF_INET, SOCK_DGRAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind error");
//
//	while (1)
//	{
//		clntAdrSz = sizeof(clntAdr);
//		strLen = recvfrom(servSock, message, BUF_SIZE, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		sendto(servSock, message, strLen, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	}
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}