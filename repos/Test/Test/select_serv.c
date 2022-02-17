//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<WinSock2.h>
//#include<math.h>
//#define PH 3.1415926535
//#define BUF_SIZE 1024
//void ErrorHandling(char* message);
//void sin_degree(int i, int x, double si,SOCKET clnt,int strLen)
//{
//	char buf[BUF_SIZE];
//	char buf2[255];
//	char temp[100];
//	int index = 0;
//	int strLLen;
//	int cnt = 0;
//	for (i = 0; i <= 720; i+=20)
//	{
//    	si = sin((PH*i) / 180, 0);
//	
//		for (x = -15; x < si * 16; x++)
//		{
//			buf[index++] = '-';
//			cnt++;
//		}
//		buf[index++] = '0';
//		buf[index++] = '\n';
//	}
//	buf[index] = '\0';
//	buf2[0] = (char)strlen(buf);
//	buf2[1] = '0';
//	send(clnt, buf2, 1, 0);
//	send(clnt, buf, strlen(buf)+1, 0);
//}
//int main(int argc, char *argv[])
//{
//	WSADATA wsaData;
//	SOCKET hServSock, hClntSock;
//	SOCKADDR_IN servAdr, clntAdr;
//	TIMEVAL timeout;
//	fd_set reads, cpyReads;
//
//	int adrSz;
//	int strLen, fdNum, i;
//	char buf[BUF_SIZE];
//
//	if (argc != 2) {
//		printf("Usage : %s <port>\n", argv[0]);
//		exit(1);
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	hServSock = socket(PF_INET, SOCK_STREAM, 0);
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(atoi(argv[1]));
//
//	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//	if (listen(hServSock, 5) == SOCKET_ERROR)
//		ErrorHandling("listen() error");
//
//	FD_ZERO(&reads);
//	FD_SET(hServSock, &reads);
//
//	while (1)
//	{
//		cpyReads = reads;
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 5000;
//
//		if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
//			break;
//
//		if (fdNum == 0)
//			continue;
//
//		for (i = 0; i<reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == hServSock)     // connection request!
//				{
//					adrSz = sizeof(clntAdr);
//					hClntSock =
//						accept(hServSock, (SOCKADDR*)&clntAdr, &adrSz);
//					FD_SET(hClntSock, &reads);
//					printf("connected client: %d \n", hClntSock);
//				}
//				else    // read message!
//				{
//					strLen = recv(reads.fd_array[i], buf, BUF_SIZE - 1, 0);
//					if (strLen == 0)    // close request!
//					{
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("closed client: %d \n", cpyReads.fd_array[i]);
//					}
//					else
//					{
//						sin_degree(0, 0, 0, reads.fd_array[i], 100);
//					}
//				}
//			}
//		}
//	}
//	closesocket(hServSock);
//	WSACleanup();
//	return 0;
//}
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
