//#include<stdio.h>
//#include<stdlib.h>
//#include<WinSock2.h>
//#define MAX_BUF 100
//
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET servSock;
//	SOCKADDR_IN sockAdr;
//	int errorCode;
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//
//	servSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("Socket Error");
//
//	memset(&sockAdr, 0, sizeof(sockAdr));
//	sockAdr.sin_addr.s_addr = inet_addr(argv[1]);
//	sockAdr.sin_family = AF_INET;
//	sockAdr.sin_port = htons(atoi(argv[2]));
//
//	if (connect(servSock, (SOCKADDR*)&sockAdr, sizeof(sockAdr)) == SOCKET_ERROR)
//		ErrorHandling("connect Error");
//
//	// client 응용 계층 프로토콜 작성.....
//	// 1. 파일 open
//	// 2. while(1){ recv()...파일에 기록... until recvCnt == 0까지 -shutdown }
//	// 3. send("Thank you");
//
//	FILE* fp;
//	int recvCnt;
//	char buf[MAX_BUF];
//	fp=fopen("received.dat","wb");
//
//	while (1)
//	{
//		recvCnt=recv(servSock,buf,MAX_BUF,0);
//		if (recvCnt != 0)
//		{
//			//파일에 저장..
//			fwrite((void*)buf, 1, recvCnt, fp);
//		}
//		else
//		{
//			printf(">서버가 shutdown 수행\n");
//			break;
//		}
//	}
//	printf("> 서버로부터 파일 수신 완료.\n");
//	send(servSock, "Thank you", strlen("Thank you"), 0);
//
//	fclose(fp);
//
//	errorCode = closesocket(servSock);
//	if (errorCode == SOCKET_ERROR)
//		ErrorHandling("error code");
//
//	errorCode=WSACleanup();
//	if (errorCode == SOCKET_ERROR)
//		ErrorHandling("error code");
//
//	return 0;
//}