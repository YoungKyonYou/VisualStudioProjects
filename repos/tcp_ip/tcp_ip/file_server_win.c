//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<WinSock2.h>
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
//	SOCKET hServSock, hClntSock;
//	FILE* fp;
//	char buf[BUF_SIZE];
//	int readCnt;
//
//	SOCKADDR_IN servAdr, clntAdr;
//	int clntAdrSz;
//	if (argc != 2)
//	{
//		printf("Usage: %s <port>\n", argv[0]);
//		exit(1);
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//	
//	fp = fopen("news.txt", "r");
//	hServSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (socket == INVALID_SOCKET)
//		ErrorHandling("Socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_port = htons(atoi(argv[1]));
//	servAdr.sin_addr.s_addr=htonl(INADDR_ANY);
//	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//	if(listen(hServSock, 5)==SOCKET_ERROR)
//		ErrorHandling("listen() error");
//	clntAdrSz = sizeof(clntAdr);
//	hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
//	while (1)
//	{
//		readCnt = fread(buf, 1, BUF_SIZE, fp);
//		if (readCnt < BUF_SIZE)
//		{
//			send(hClntSock, buf, readCnt, 0);
//			break;
//		}
//		send(hClntSock, buf, BUF_SIZE, 0);
//	}
//	shutdown(hClntSock, SD_SEND);
//	recv(hClntSock, buf, BUF_SIZE, 0);
//	printf("Message from client: %s \n", buf);
//	fclose(fp);
//	closesocket(hClntSock);
//	closesocket(hServSock);
//	WSACleanup();
//	return 0;
//}