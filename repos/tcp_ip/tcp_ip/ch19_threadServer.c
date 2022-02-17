//// 서버 프로그램.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//
//DWORD WINAPI ProcessClient(LPVOID arg);
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> 멀티쓰레드 서버 프로그램 실행.\n");
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
//	// 3. bind() 함수 호출...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() 함수 호출...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//
//	// 5. accept 함수 호출...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	HANDLE			hThread;
//	DWORD			ThreadId;
//	addrLen = sizeof(clientAddr);
//
//	while (1) {
//		addrLen = sizeof(clientAddr);
//
//		printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//		if (clientSocket == INVALID_SOCKET) {
//			printf("<ERROR> accept() 오류...\n");
//			continue;
//		}
//		printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// 스레드 생성 연결된 client와 데이터 송수신 지원하기 위해...
//		
//		hThread = CreateThread(
//			NULL,//보안
//			0, //stack size
//			ProcessClient,//실행할 함수
//			(LPVOID)clientSocket,
//			0,
//			&ThreadId//쓰레드 아이디
//		);
//
//
//
//
//
//
//
//		if (hThread == NULL) {
//			printf("<ERROR> 스레드 생성 실패!\n");
//		}
//		else {
//			CloseHandle(hThread);
//		}
//	}
//
//	// 소켓을 통한 통신 종료...
//	closesocket(serverSocket);
//
//	// 소켓 사용 종료..
//	WSACleanup();
//	return 0;
//}
//DWORD WINAPI ProcessClient(LPVOID arg)//clientSocket
//{
//	SOCKET clientSocket = (SOCKET)arg;
//	char Buf[MAX_BUF_SIZE + 1];
//	SOCKADDR_IN clientAddr;
//	int addrLen, retval;
//	
//	addrLen = sizeof(clientAddr);
//	getpeername(clientSocket, (SOCKADDR*)&clientAddr,&addrLen);
//
//	while (1)
//	{
//		//클라이언트와 데이터 송수신...echo...
//		retval=recv(clientSocket,Buf,MAX_BUF_SIZE,0);
//		if (retval == SOCKET_ERROR) {
//			printf("<thread> ERROR - recv() 오류.\n");
//			break;
//		}
//		else if (retval == 0)//connection close...
//		{
//			printf("<thread> TCP connection close.\n");
//			break;
//		}
//		Buf[retval] = '\0';
//		printf("<thread> client[%s:%d] 수신된 데이터: %s\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port),Buf);
//		send(clientSocket, Buf, retval, 0);
//		if (retval == SOCKET_ERROR)
//		{
//			printf("<thread> ERROR-send().\n");
//			break;
//		}
//
//
//	}
//
//	closesocket(clientSocket);
//	printf("<thread> 클라이언트 종료: IP주소=%s Port=%d\n",inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
//	return 0;
//
//
//}
//
//
