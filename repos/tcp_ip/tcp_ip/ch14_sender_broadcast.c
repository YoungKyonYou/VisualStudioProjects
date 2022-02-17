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
//	SOCKADDR_IN multicastAddr;
//	SOCKET senderSocket;
//	int so_broad = 1;
//	FILE* fp;
//	char buf[BUF_SIZE];
//
//
//	printf("> Broadcast sender 프로그램 실행.\n");
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//	senderSocket = socket(PF_INET, SOCK_DGRAM, 0);
//	if (senderSocket == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&multicastAddr, 0, sizeof(multicastAddr));
//	multicastAddr.sin_family = AF_INET;
//	multicastAddr.sin_port = htons(atoi(argv[2]));
//	multicastAddr.sin_addr.s_addr = inet_addr("255.255.255.255");
//
//	setsockopt(senderSocket, SOL_SOCKET,SO_BROADCAST, (void*)&so_broad, sizeof(so_broad));
//	if ((fp = fopen("news.txt", "r")) == NULL)
//		ErrorHandling("fopen error");
//
//	printf("> file open 완료...\n");
//	while (!feof(fp))
//	{
//		fgets(buf, BUF_SIZE, fp);
//		sendto(senderSocket, buf, sizeof(buf), 0, (SOCKADDR*)&multicastAddr, sizeof(multicastAddr));
//		printf("%s", buf);
//		Sleep(2000);
//	}
//	fclose(fp);
//	closesocket(senderSocket);
//	WSACleanup();
//	return 0;
//}