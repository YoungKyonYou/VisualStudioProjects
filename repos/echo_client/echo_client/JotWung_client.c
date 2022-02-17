//#include <stdio.h>
//#include <WinSock2.h>
//
//#define MAX_BUF_SIZE 100
//int recvn(SOCKET s, char* buf, int len, int flags);
//
//int main(void)
//{
//	WSADATA      winsockData;
//	int         errorNum, errorCode;
//
//	// 1. 소켓 라이브러리 초기화
//	errorNum = WSAStartup(MAKEWORD(2, 2), &winsockData);
//	if (errorNum == 0) { // 함수 실행 성공..
//	}
//	else {
//		printf("> 소켓 초기화 실패. 오류코드(%d)\n", errorNum);
//		return 1;
//	}
//
//	// 2. 소켓 생성, param  프로토콜 지정, TCP
//	SOCKET clientSocket;
//	clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (clientSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	SOCKADDR_IN  serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	// 서버와 연결하기...
//	errorNum = connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//	char  Buf[MAX_BUF_SIZE + 1];
//	int     retval;
//	char count;
//	int temp, stack = 0;
//	int index = 0;
//	char c;
//	// 데이타를 입력하고, 그 데이타를 서버에 전송하기...
//	// 버퍼 청소...
//	ZeroMemory(Buf, sizeof(Buf));
//	// 사용자로부터 데이타 입력...
//	printf("서버에 sin() 데이터 요청] 1:요청, 0:거절\n ");
//	scanf("%c", &c);
//	retval = send(clientSocket, &c, 1, 0);
//	if (retval == SOCKET_ERROR)
//	{
//		printf("<ERROR> send()(SOCKET_ERROR)!!!\n");
//	}
//	printf("[TCP 클라이언트] %d 바이트를 보냈습니다.\n", retval);
//
//
//
//	int stopFlag = 0, returnValue = 0, rcvTotalLen = 0;
//
//	while (stopFlag == 0) 
//	{
//		int rcvSize;
//		int strLen = 0;
//		strLen=recv(clientSocket, &count, 1, 0);
//		temp = (int*)count;
//		rcvSize = recv(clientSocket, Buf, temp, 0);
//		rcvTotalLen += rcvSize;
//		//printf("temp:%d, strLen=%d \n", temp,strLen);
//		printf("%s\n", Buf);
//		stack++;
//
//
//		/*if (rcvSize == 0)  ///  *********이 데이터 처리하는 부분 잘못 만듬!!  TCP 데이터 처리하는 거 다시 확인하기 바람
//		{
//			printf("클라이언트가 소켓을 종료\n");
//			stopFlag = 1;
//		}
//		else if (rcvSize == 0)
//		{
//			printf("소켓 오류\n");
//			stopFlag = 1;
//		}*/
//		memset(Buf, 0, sizeof(Buf));
//	}
//	printf("> %d\n", stack);
//	printf("> 클라이언트가 서버와 TCP 연결을 종료합니다.\n");
//
//	// 소켓 종료
//	errorNum = closesocket(clientSocket);
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	// 소켓 사용 종료...
//	errorNum = WSACleanup();
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//}