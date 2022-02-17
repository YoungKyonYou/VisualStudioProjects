//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<WinSock2.h>
//#include<math.h>
//#define PH 3.1415926535
//#define BUF_SIZE 1024
//#define DEGREE 1080
//#define INTERVAL 20
//void ErrorHandling(char* message);
//void sin_degree(int i, int x, double si, SOCKET clnt, int strLen)
//{
//	char buf[BUF_SIZE];
//	char buf2[255];
//	char temp[100];
//	int cnt = 0;
//	int index = 1;
//	for (i = 0; i <= DEGREE; i += 20)
//	{
//		si = sin((PH*i) / 180, 0);
//
//		for (x = -15; x < si * 16; x++)
//		{
//			buf[index++] = '-';
//		}
//		buf[index++] = '0';
//		buf[index] = '\0';
//		buf[0] = (char)strlen(&buf[1]);
//	//	printf("strlen:%d\n", strlen(&buf[1]));
//		//send(clnt, buf2, 1, 0);
//
//		//printf("%s\n", &buf[1]);
//		send(clnt, buf, strlen(buf) + 1, 0);
//		index = 1;
//		cnt++;
//	}
//	memset(buf, 0, sizeof(buf));
//	printf("[TCP 서버 %d개 sin 데이터 전송.\n",cnt);
//	int t = 0;
//	buf[0] = (char)-1;
//	send(clnt, buf, 1, 0);
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
//	printf("IO 멀티플렉싱(select) 서버 프로그램 실행.\n");
//
//	while (1)
//	{
//		cpyReads = reads;
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 5000;
//		printf("accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//		if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
//			break;
//		if (fdNum == 0)
//			continue;
//		for (i = 0; i<reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == hServSock)     // connection request!
//				{
//					adrSz = sizeof(clntAdr);
//				//	printf("accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//					hClntSock =accept(hServSock, (SOCKADDR*)&clntAdr, &adrSz);
//					printf("클라이언트(IP:%s, Port:%d가 연결되었습니다.\n", inet_ntoa(clntAdr.sin_addr), ntohs(clntAdr.sin_port));
//					FD_SET(hClntSock, &reads);
//				}
//				else    // read message!
//				{
//					strLen = recv(reads.fd_array[i], buf, BUF_SIZE - 1, 0);
//					printf("[서버 수신 data] R\n");
//					if (strLen == 0)    // close request!
//					{
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("closed client: %d \n", cpyReads.fd_array[i]);
//					}
//					else
//					{
//						char buf[10];
//						int temp = (DEGREE / INTERVAL)+1;
//						buf[0] = (char)temp;
//						send(reads.fd_array[i], buf, 1,0);
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
