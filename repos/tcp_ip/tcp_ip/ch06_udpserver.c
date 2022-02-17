//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<WinSock2.h>
//#define MAX_BUF 100
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	int strLen;
//	char message[MAX_BUF];
//	int clntAdrSz;
//	WSADATA wsaData;
//	SOCKET servSock;
//	SOCKADDR_IN servAdr, clntAdr;
//	printf("> UDP기반 echo 서버 프로그램 실행\n");
//	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
//		ErrorHandling("WSAStartup Error");
//
//
//	if ((servSock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//	servAdr.sin_family = AF_INET;
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//
//
//	while (1)
//	{
//		clntAdrSz = sizeof(clntAdr);
//		strLen = recvfrom(servSock, message, MAX_BUF, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		message[strLen-1] = '\0'; 
//		printf("수신 msg: %s (from:%s, %d)\n", message,inet_ntoa(clntAdr.sin_addr),ntohs(clntAdr.sin_port));
//		sendto(servSock, message, strLen,0,(SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	}
//
//
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}