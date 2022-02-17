//// 서버 프로그램.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> 서버 프로그램 실행.\n");
//
//	// 1. 소켓 초기화...소켓 라이브러리를 연결...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//
//	// 2. 소켓을 생성 하기...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	int option, len;
//	len = sizeof(option);
//	getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, &len);
//	printf("1 > REUSEADDR : %d\n", option);
//
//	option = TRUE;
//	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, len);// 마지막 인수가 다름
//
//	getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, &len);
//	printf("2 > REUSEADDR : %d\n", option);
//
//	// 3. bind() 함수 호출...
//	// - 생성된 소켓 IP, port 설정...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() 함수 호출...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//
//	// 5. accept 함수 호출...
//	SOCKET         clientSocket;
//	SOCKADDR_IN      clientAddr;
//	int            addrLen;
//	addrLen = sizeof(clientAddr);
//
//	char Buffer[MAX_BUF_SIZE];
//	int Count = 0, stopFlag = 0, returnValue;//returnValue  받은 데이터
//
//	while (Count < 5)
//	{
//		printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// 연결된 클라리언트에게 환영 메시지 전달...
//		// 서버의 동작 :
//		// 1. loop (클라이언트가 소켓 close할 때까지 메시지 수신 후 echo back.
//		while (stopFlag == 0)
//		{
//
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			if (returnValue > 0)
//			{
//				printf("> 클라이언트로부터 %d바이트 수신.\n", returnValue);
//				send(clientSocket, Buffer, returnValue, 0);
//				if (strcmp(Buffer, 'a') == 0)
//					stopFlag = 1;
//			}
//			else if (returnValue == SOCKET_ERROR)
//			{
//				printf("<error> recv()함수 수행 중 오류 발생, code(%d)\n", WSAGetLastError);
//				stopFlag = 1;
//			}
//			else if (returnValue == 0)
//			{
//				printf("> 클라이언트가 소켓을 close함\n");
//				stopFlag = 1;
//			}
//		}
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결을 종료합니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
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
