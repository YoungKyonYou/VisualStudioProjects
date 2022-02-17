//#include <stdio.h>
//#include <WinSock2.h>
//#define MAX_BUF_SIZE 100
//#define MAX_MSG_SIZE 100
//int main(void)
//{
//	WSADATA		winsockData;
//	int			errorNum, errorCode;
//
//	printf("> 클라이언트 실행. \n");
//
//	// 1. 소켓 라이브러리 초기화
//	errorNum = WSAStartup( MAKEWORD(2,2), &winsockData );
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
//	clientSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
//	if (clientSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	SOCKADDR_IN  serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family			= AF_INET;
//	serverAddr.sin_port				= htons(9000);  	
//	serverAddr.sin_addr.s_addr		= inet_addr("127.0.0.1");
//
//	// 서버와 연결하기...
//	errorNum = connect(clientSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr) );
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> 오류 발생, 코드(%d).\n", errorCode);
//	}
//
//	printf("> 클라이언트가 서버와 TCP 연결 되었습니다.\n");
//
//
//	//TCP 계산기 client 부분 구현...
//	//1. 사용자로부터 피연산자와 연산자를 입력...
//	//피연산자의 개수 가변...
//	// 메시지: 1바이트:피연산자 개수 (n)...
//	// n*4 바이트 : 피연산자 저장...
//	// 1 바이트 : 연산자(+/-/*//)
//	
//	char opmsg[MAX_MSG_SIZE];
//	int count;
//	int index;
//	int result, opSize=sizeof(int);
//	char operator;
//	printf("> 피연산자의 개수를 입력하세요 : ");
//	scanf("%d",&count);//피연산자의 개수
//	printf("> 피연산자의 개수는 %d 입니다.\n", count);
//
//	opmsg[0] = (char)count;
//
//	for (index = 0; index < count; index++)
//	{
//		printf("> %d 번째 피연산자(정수)를 입력하세요 : ",index+1);
//		scanf("%d", (int*)&opmsg[index*opSize+1]);
//		printf("> 입력된 피연산자 값은 %d 입니다.\n", (int)*(int*)&opmsg[index * opSize + 1]);
//		//시작 주소를 가지로 int만큼 보겠다는 거고
//		//거기에 있는 값을 가져와야 하니까 그 앞에 (int)로 캐스팅 해주는것
//	}
//	getchar();//엔터
//	printf("> 연산자를 입력하세요 : ");
//	scanf("%c", &operator);
//	printf("> 입력된 연산자는 %c 입니다.\n", operator);
//	opmsg[opSize*count + 1] = operator;
//	//서버로 전달할 패킷 opmsg[] 설정 완료
//	
//	//완성한 메시지를 서버로 전달...
//	int send_byte=send(clientSocket, opmsg, count*opSize+2, 0);
//	printf("sendbytes: %d\n", send_byte);
//	//서버로부터 결과 수신...
//	recv(clientSocket, &result, opSize, 0);
//	printf("> 서버로부터 수신한 결과는 %d 입니다.\n", result);
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
