//#include<stdio.h>
//#include<stdlib.h>
//#include<WinSock2.h>
//#define MAX_BUF_SIZE 100
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET servSock, clntSock;
//	SOCKADDR_IN servAdr, clntAdr;
//	int clntAdrSz;
//
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//
//	servSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_port = htons(atoi(argv[1]));
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind error");
//
//	if (listen(servSock, 5) == SOCKET_ERROR)
//		ErrorHandling("listen error");
//
//
//	clntAdrSz = sizeof(clntAdr);
//	clntSock = accept(servSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
//	if (clntSock == INVALID_SOCKET)
//		ErrorHandling("client socket error");
//
//	printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n", inet_ntoa(clntAdr.sin_addr), ntohs(clntAdr.sin_port));
//
//	//응용 계층
//	//서버...클라이언트...상호동작...메시지 교환...프로토콜...
//	//1. 연결...파일 open...
//	FILE* fp;
//	int readCnt, TargetSize, rcvedTotalBytes, recvCnt;
//	char buf[MAX_BUF_SIZE];
//
//	fp=fopen("addr_test.c", "rb");
//	if (fp == NULL) {
//		printf("<error> 파일 열기 실패..\n");
//		return 1;
//	}
//	//2. while(1){ 파일을 읽고, send() to client... until(파일 다 읽을 때까지)}
//	while (1)
//	{
//		//읽는 크기:1*MAX_BUF_SIZE
//		//256B, 100, 100, 56
//		readCnt=fread(buf,1,MAX_BUF_SIZE,fp);
//		send(clntSock, buf, readCnt, 0);
//		if (readCnt < MAX_BUF_SIZE)
//		{
//			break;
//		}
//	}
//	//3. shutdown(,출력 스트림 shutdown) ... client recv()=0 파일 전송 완료로 해석...
//	shutdown(clntSock, SD_SEND);//출력 스트림만 shutdown...
//	//4. recv() "Thank you...9 글자 수신"
//	TargetSize = strlen("Thank you");
//	rcvedTotalBytes = 0;
//	while (rcvedTotalBytes < TargetSize)
//	{
//		rcvedTotalBytes+=recv(clntSock, &buf[rcvedTotalBytes], MAX_BUF_SIZE, 0);
//	}
//	buf[rcvedTotalBytes] = 0;
//	printf("> 클라이언트 전달 : %s\n", buf);
//	//5. 소켓 종료...
//	
//	fclose(fp);
//	//E---------------------------
//	closesocket(clntSock);
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}