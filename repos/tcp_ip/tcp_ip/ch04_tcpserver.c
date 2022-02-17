//// 서버 프로그램.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> 서버 프로그램 실행.\n");
//
//	int ret, errorCode, len, option, state;
//
//	// 1. 소켓 초기화...소켓 라이브러리를 연결...
//	WSAStartup( MAKEWORD(2,2), &winsockData );
//
//	// 2. 소켓을 생성 하기...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (serverSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> socket() 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	//-------------------------------------------------
//
//
//	
//	//-------------------------------------------------
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family		= AF_INET;
//	serverAddr.sin_port			= htons(20000); 
//	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1");
//	
//	int option1;
//	len = sizeof(option1);
//	getsockopt(serverSocket,SOL_SOCKET,SO_REUSEADDR,(char*)&option1,&len);
//	printf("> REUSEADDR : %d\n", option1);
//	
//	//option1 = TRUE;
//	//getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&option1, len);//여기 차이 있음 len에
//
//	printf("> REUSEADDR : %d\n", option1);
//
//
//	// 3. bind() 함수 호출...
//	// - 생성된 소켓 IP, port 설정...
//	ret = bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (ret == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> bind() 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	// 4. listen() 함수 호출...
//	int backLog = 0; 
//	ret = listen(serverSocket, backLog );
//	if (ret == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> listen() 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	// 5. accept 함수 호출...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	addrLen = sizeof(clientAddr);
//
//	char Buffer[MAX_BUF_SIZE]; // 100바이트
//	int Count=0, stopFlag=0, returnValue;
//
//	while (Count < 1) {
//		printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//		if (clientSocket == INVALID_SOCKET) {
//			errorCode = WSAGetLastError();
//			printf("<error> accept() 오류 발생, 코드(%d).\n", errorCode);
//		}
//
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// 연결된 클라이언트에게 환영 메시지 전달...
//		// 서버의 동작:
//		// 1. loop (클라이언트가 소켓 close할 때까지 메시지 수신 후 echo back.
//		stopFlag = 0;
//		while (stopFlag == 0) {
//
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			if (returnValue > 0) {
//				Buffer[returnValue] = 0;
//				printf("> 클라이언트로부터 %d바이트 수신(%s).\n", returnValue, Buffer);
//				send(clientSocket, Buffer, returnValue, 0);
//				printf("> 클라이언트에게 %d바이트 송신.\n", returnValue);
//				if (strcmp(Buffer, "a") == 0) {
//					stopFlag = 1;//소켓 close하러 감
//				}
//			}
//			else if (returnValue == SOCKET_ERROR) {
//				printf("<error> recv() 함수 수행 중 오류 발생. code(%d)\n", WSAGetLastError());
//				stopFlag = 1;
//			}
//			else if (returnValue == 0) {
//				printf("> 클라이언트가 소켓을 close함.\n");
//				stopFlag = 1;
//			}
//		}
//
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결을 종료합니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//		// 클라이언트 소켓을 통한 통신 종료...
//		closesocket(clientSocket);
//		Count++;
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
//
//
///*
//	// recv() 함수를 통해 상대 tcp client로부터 데이터 수신
//	// send(100B), send(100B), send(100B), send(100B), send(100B)
//	char Buffer[MAX_BUF_SIZE];
//	int  returnValue, stopFlag=0, index=1;
//
//	while (stopFlag == 0) {
//
//		returnValue = recv(clientSocket, Buffer, MAX_BUF_SIZE, 0);
//
//		if (returnValue > 0) // 일정한 데이터를 수신한 경우...
//		{
//			printf("%d> %d 바이트 데이터를 수신.\n", index, returnValue);
//			index++;
//		}
//		else if (returnValue == SOCKET_ERROR) {
//			printf("<error> recv() 함수 실행 중 오류 발생, code(%d)\n", WSAGetLastError());
//		}
//		else if (returnValue == 0) {
//			// 상대방 연결 종료...
//			printf("> client가 socket을 종료\n");
//			stopFlag = 1;
//		}
//
//		//Sleep(1000);
//	}
//*/