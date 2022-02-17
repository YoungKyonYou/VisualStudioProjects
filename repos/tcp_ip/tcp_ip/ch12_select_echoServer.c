//// 서버 프로그램.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> IO 멀티플랙싱(select) 서버 프로그램 실행.\n");
//
//	// 1. 소켓 초기화...소켓 라이브러리를 연결...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//	// 2. 소켓을 생성 하기...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (serverSocket == INVALID_SOCKET)
//	{
//		printf("socket error\n");
//	}
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	// 3. bind() 함수 호출...
//	if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == INVALID_SOCKET)
//		printf("bind error\n");
//
//	// 4. listen() 함수 호출...
//	int backLog = 3;
//	if (listen(serverSocket, backLog) == SOCKET_ERROR)
//		printf("listen error\n");
//	// 5. accept 함수 호출...
//	SOCKET			clientSocket;
//	SOCKADDR_IN	clientAddr;
//	int				addrLen;
//	int				fdNum, retval, i;
//	char				Buf[MAX_BUF_SIZE + 1];
//
//	// select 함수 작성...
//	fd_set reads;//원본
//	fd_set cpyReads;//복사본
//	TIMEVAL timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket,&reads);
//
//	while (1)
//	{
//		//1.select(, cpy_reads,) 함수 호출, 이벤트 생성 확인...
//		cpyReads = reads;//구조체는 이런 식으로 복사 가능
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 50000;
//
//		fdNum=select(0,&cpyReads,0,0,&timeout);
//		if (fdNum == SOCKET_ERROR)
//			break;
//
//		if (fdNum == 0)
//			continue;
//
//		//특정 소켓에 이벤트가 발생한 경우...
//		//2. select() 반환 -> 이벤트 발생, 타임아웃 경우(다시 select호출)
//		// -이벤트 발생 확인... reads 포함된 모든 소켓에 대해서 모두 처리...
//		//   1. 서버 소켓 : 연결 요청, accept() - 소켓생성 S1, S2, ... -> reads 포함
//		//   2. 데이터 전송 소켓 : recv(), send(), close 확인 -> reads 해당 소켓 제외
//		for (i = 0; reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == serverSocket)
//				{
//					//서버 소켓에 대해서 이벤트 발생...
//					//-accept() - 소켓생성 S1. S2 ... -> reads 포함
//					addrLen = sizeof(clientAddr);
//					clientSocket=accept(serverSocket, (SOCKADDR*)&clientAddr,&addrLen);
//					printf("> 클라이언트 연결 수락\n");
//					FD_SET(clientSocket, &reads);
//				}
//				else
//				{
//					//클라이언트 소켓에 대한 이벤트 발생...
//					// - data 수신 경우:recv(), 화면 출력, send()
//					// -recv()==0, socket close -> reads에서 해당 소켓 제외...
//					retval=recv(reads.fd_array[i], Buf, MAX_BUF_SIZE, 0);
//					if (retval == 0)
//					{
//						//connection close 상태...
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(reads.fd_array[i]);
//						printf(">클라이언트 연결 종료.\n");
//					}
//					else
//					{
//						//수신한 데이터를 echo back...
//						Buf[retval] = '\0';
//						printf("> 수신 데이터 : %s\n",Buf);
//						retval=send(reads.fd_array[i], Buf, retval, 0);
//					}
//				}
//			}
//
//
//		}
//
//
//
//	}
//
//
//
//
//	// 소켓을 통한 통신 종료...
//	closesocket(serverSocket);
//	// 소켓 사용 종료..
//	WSACleanup();
//	return 0;
//}
