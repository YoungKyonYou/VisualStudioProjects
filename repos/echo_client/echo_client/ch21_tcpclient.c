//
//#include <stdio.h>
//#include <WinSock2.h>
//#define MAX_BUF_SIZE 100
//int main(void)
//{
//	WSADATA		winsockData;
//	int			errorNum, errorCode;
//
//	printf("> 클라이언트 실행. \n");
//
//	// 1. 소켓 라이브러리 초기화
//	errorNum = WSAStartup(MAKEWORD(2, 2), &winsockData);
//	if (errorNum == 0) { // 함수 실행 성공..
//		printf("> 소켓 초기화 성공.\n");
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
//	errorNum = connect(clientSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	printf("> 클라이언트가 서버와 TCP 연결 되었습니다.\n");
//
//	// 클라이언트 기능:
//	// 1.- 사용자로부터 메시지 입력받고, 입력 받은 메시지를 서버로 전달..
//	// 2.- 서버는 클라이언트 보낸 메시지를 그대로 돌려보냄. echo..
//	// 3.- 서버가 echo한 메시지를 받아서 화면에 출력...
//	char Buffer[MAX_BUF_SIZE + 1];
//	int  receivedBytes = 0, returnValue; // 수신한 메시지 크기 누적치...
//	int  stopFlag = 0, msglen;
//
//	while (stopFlag == 0) {
//
//		// 1. 동작
//		printf("> 메시지를 입력하세요: ");
//		scanf("%s", Buffer);
//		msglen = strlen(Buffer);
//		// 입력한 str "q" 멈춤.
//		if (strcmp(Buffer, "q") == 0) {
//			stopFlag = 1;
//		}
//
//		send(clientSocket, Buffer, msglen, 0);
//		printf("> 입력한 메시지(%d바이트)를 서버로 전송함: %s\n", msglen, Buffer);
//		// 2. 서버가 echo back.
//
//		// 3. msglen만큼 수신.
//
//		// 정해진 바이트만큼 수신...
//		receivedBytes = 0;
//		while (receivedBytes < msglen) {
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			receivedBytes += returnValue;
//
//			if (returnValue > 0) {
//				// 정상 수신...
//				printf("> %d 바이트 데이타 수신.(누적치:%d)\n",
//					returnValue, receivedBytes);
//			}
//			else if (returnValue == SOCKET_ERROR) {
//				printf("<error> recv() 함수 실행 중 오류 발생, code(%d)\n",
//					WSAGetLastError());
//				stopFlag = 1;
//				break;
//			}
//			else if (returnValue == 0) {
//				// 상대방이 connection close
//				printf("> 서버가 연결 종료.\n");
//				stopFlag = 1;
//				break;
//			}
//		}
//
//		Buffer[msglen] = 0;
//		printf("> 서버로부터 수신한 메시지: %s\n", Buffer);
//	}
//
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
//
