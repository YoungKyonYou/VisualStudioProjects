//#include <stdio.h>
//#include <WinSock2.h>
//#include <math.h>
//
//#define MAX_BUF_SIZE 100
//int recvn(SOCKET s, char* buf, int len, int flags);
//
//int main(int argc, int* argv[])
//{
//	WSADATA      winsockData;
//	int         errorNum, errorCode;
//
//	printf("> 클라이언트 실행. \n");
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
//		return 1;
//	}
//
//		SOCKADDR_IN  serverAddr;
//		memset(&serverAddr, 0, sizeof(serverAddr));
//		serverAddr.sin_family = AF_INET;
//		serverAddr.sin_port = htons(9000);
//		serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	// 서버와 연결하기...
//	errorNum = connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//		return 1;
//	}
//
//	printf("> 클라이언트가 서버와 TCP 연결 되었습니다.\n");
//
//	char  Buf[MAX_BUF_SIZE + 1];
//	int     retval;
//
//	while (1)
//	{
//		// 데이타를 입력하고, 그 데이타를 서버에 전송하기...
//		// 버퍼 청소...
//		ZeroMemory(Buf, sizeof(Buf));
//		// 사용자로부터 데이타 입력...
//		printf("[서버에 sin() 데이터 요청] 1: 요청, 0: 거절\n");
//		if (fgets(Buf, MAX_BUF_SIZE + 1, stdin) == NULL) {
//			break;
//		}
//		if (Buf[0] == '0') {
//			break;
//		}
//		printf("> 서버에 sin 데이터를 요청합니다.\n");
//		retval = send(clientSocket, Buf, strlen(Buf), 0);
//		if (retval == SOCKET_ERROR) {
//			printf("<ERROR> send()(SOCKET_ERROR)!!!\n");
//			break;
//		}
//		printf("[TCP 클라이언트] %d 바이트를 보냈습니다.\n", retval);
//
//		// 서버로부터 데이타를 수신하기...
//		while (1) {
//			retval = recv(clientSocket, Buf, MAX_BUF_SIZE, 0);
//			/*int temp = (int*)Buf[0];
//			printf("temp:%d\n", temp);
//			if (temp == -1)
//			{
//				printf("수신 완료\n");
//				break;
//			}*/
//			if (retval == SOCKET_ERROR) {
//				printf("<ERROR> recvn()(SOCKET_ERROR)!!!\n");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}
//			// 받은 데이터를 출력하기...
//			Buf[retval] = '\0';
//			//printf("[TCP 클라이언트] %d 개의 sin 데이터를 받았습니다.\n", retval);
//			printf("%s", Buf);
//		}
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
//
//int recvn(SOCKET s, char* buf, int len, int flags)
//{
//	int       received;
//	char* ptr = buf;
//	int       left = len;
//
//	while (left > 0)
//	{
//		received = recv(s, ptr, left, flags);
//		if (received == SOCKET_ERROR)
//			return SOCKET_ERROR;
//		else if (received == 0)
//			break;
//		left -= received;
//		ptr += received;
//	}
//
//
//	return (len - left);
//}
