//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<WinSock2.h>
//#define BUF_SIZE 1024
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	char message[BUF_SIZE];
//	int i, strLen, clntAdrSize;
//	WSADATA wsaData;
//	SOCKET servSock, clntSock;
//	SOCKADDR_IN servAdr, clntAdr;
//
//	if(argc!=2)
//	{
//		printf("Usage : %s <port>\n", argv[0]);
//		exit(1);
//	}
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup error");
//	servSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("socket error");
//	
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//	servAdr.sin_family = AF_INET;
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//	if (listen(servSock, 5) == SOCKET_ERROR)
//		ErrorHandling("listen() error");
//
//	clntAdrSize = sizeof(clntAdr);
//	for (i = 0; i < 5; i++)
//	{
//		clntSock = accept(servSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
//		if (clntSock == INVALID_SOCKET)
//			ErrorHandling("socket error");
//		else
//			printf("Connected socket: %d\n", i + 1);
//
//		while ((strLen = recv(clntSock, message, BUF_SIZE, 0)) != 0)
//			send(clntSock, message, strLen, 0);
//
//		closesocket(clntSock);
//	}
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}