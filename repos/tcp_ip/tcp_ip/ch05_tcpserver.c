//// 서버 프로그램.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//#define MAX_MSG_SIZE 100
//int calculation(int opCnt, int operands[], char op);
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> 서버 프로그램 실행.\n");
//
//	// 1. 소켓 초기화...소켓 라이브러리를 연결...
//	WSAStartup( MAKEWORD(2,2), &winsockData );
//
//	// 2. 소켓을 생성 하기...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family		= AF_INET;
//	serverAddr.sin_port			= htons(9000); 
//	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1");
//
//	// 3. bind() 함수 호출...
//	// - 생성된 소켓 IP, port 설정...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() 함수 호출...
//	int backLog = 3; 
//	listen(serverSocket, backLog );
//
//	// 5. accept 함수 호출...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	addrLen = sizeof(clientAddr);
//
//	int index;
//	int msgSize, opSize, rcvTotalLen, rcvSize,result;
//	opSize = sizeof(int);
//	char opCnt, opmsg[MAX_MSG_SIZE];
//	for (index=0;index<5;index++)
//	{
//		printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		//응용 계층 프로토콜 구현
//		//TCP 계산기 서버 부분....
//		//1. 클라이언트 송신한 메세지를 수신...
//		// 수신: 1바이트 수신 (피연산자 수)
//		// 수신: count*sizeof(int)+1(연산자)
//
//		recv(clientSocket, &opCnt,1,0);
//		printf("> 피연산자 개수는 %d 입니다.\n", (int)opCnt);
//
//		msgSize = opCnt * opSize + 1;
//		rcvTotalLen = 0;
//		while (rcvTotalLen<msgSize)
//		{
//			rcvSize = recv(clientSocket, &opmsg[rcvTotalLen], MAX_MSG_SIZE, 0);
//			rcvTotalLen += rcvSize;
//		}
//		printf("연산자 확인: %c\n", opmsg[rcvTotalLen -1]);
//		//client 전송한 opmsg를 모두 수신... opmsg[] 피연산자들... 마지막 연산자
//		result=calculation((int)opCnt,(int*)opmsg,opmsg[rcvTotalLen-1]);
//		
//		//서버는 계산된 결과(result) client 에게 전송...
//		send(clientSocket, (char*)&result, opSize, 0);
//		printf("> 서버가 계산된 결과(%d)을 클라이언트에게 전송합니다.\n", result);
//
//
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결을 종료합니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// 클라이언트 소켓을 통한 통신 종료...
//		closesocket(clientSocket);
//	}
//	// 소켓을 통한 통신 종료...
//	closesocket(serverSocket);
//
//	// 소켓 사용 종료..
//	WSACleanup();
//
//	return 0;
//}
//
//int calculation(int opCnt, int operands[], char op)
//{
//	int result=0;
//	int index;
//	switch (op)
//	{
//	case '+':
//		for (index=1;index<opCnt;index++)
//		{
//			result += operands[index];
//		}
//		break;
//	case '-':
//		for (index = 1; index<opCnt; index++)
//		{
//			result -= operands[index];
//		}
//		break;
//	case '*':
//		for (index = 1; index<opCnt; index++)
//		{
//			result *= operands[index];
//		}
//		break;
//	case '/':
//		for (index = 1; index<opCnt; index++)
//		{
//			result /= operands[index];
//		}
//		break;
//	}
//
//	return result;
//}
