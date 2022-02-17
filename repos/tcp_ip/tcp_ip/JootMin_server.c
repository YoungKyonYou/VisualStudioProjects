//#include   <stdio.h>
//#include   <WinSock2.h>
//#include   <math.h>
//#define      MAX_BUF_SIZE   100
//#define      PI            3.1415926535
//
//void sin_degree(int deg, double si);
//
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> IO 멀티플랙싱(select) 서버 프로그램 실행.\n");
//
//	// 1. 소켓 초기화...소켓 라이브러리를 연결...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//
//	// 2. 소켓을 생성 하기...
//	SOCKET serverSocket;
//	SOCKADDR_IN   serverAddr;
//
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
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
//	SOCKET         clientSocket;
//	SOCKADDR_IN      clientAddr;
//	int            addrLen;
//	int            fdNum, retval, i, tmp;
//	char         Buf[MAX_BUF_SIZE + 1];
//
//	// select 함수 작성...
//	fd_set   reads;      // 원본
//	fd_set   cpyReads;   // 복사본
//	TIMEVAL   timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket, &reads);
//
//	while (1) {
//		// 1. select( , cpyReads, ) -> 함수 호출, 이벤트 생성 확인
//		cpyReads = reads;
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 5000;
//
//		fdNum = select(0, &cpyReads, 0, 0, &timeout);
//		if (fdNum == SOCKET_ERROR) {
//			printf("<thread> SOCKET_ERROR");
//			break;
//		}
//		if (fdNum == 0) {
//			continue;
//		}
//
//		// 특정 소켓에 이벤트가 발생한 경우
//		// 2. select() 반환 -> 이벤트 발생, 타임아웃 경우(다시 select 호출)
//		//    - 이벤트 발생 확인. reads에 포함된 모든 소켓에 대해서 모두 처리
//		//       1) 서버 소켓: 연결 요청, accept() - 소켓 생성 S1, S2... -> reads에 포함시키기
//		//       2) 데이터 전송 소켓: recv(), sends(), close 확인(reads 해당 소켓 제외)
//		for (i = 0; i < reads.fd_count; i++) {
//			if (FD_ISSET(reads.fd_array[i], &cpyReads)) {
//				if (reads.fd_array[i] == serverSocket) {
//					// 서버 소켓에 대한 이벤트 발생
//					// accept() - 소켓 생성 S1, S2... -> reads에 포함시키기
//					printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//					addrLen = sizeof(clientAddr);
//					clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//					printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//					FD_SET(clientSocket, &reads);
//				}
//				else {
//					// 클라이언트 소켓에 대한 이벤트 발생
//					// data를 수신한 경우: recv() -> 화면 출력 -> send()
//					// recv() ==0(socket closed) -> reads에서 해당 소켓 제외
//					retval = recv(reads.fd_array[i], Buf, MAX_BUF_SIZE, 0);
//					if (retval == 0) {
//						// connection close 상태
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("> 클라이언트 연결 종료.\n");
//					//}a
//					else {
//						// 수신한 데이터가 1인지 확인
//						if (Buf[0] == '1') {
//							printf("[서버 수신 data]: R\n");
//							for (int deg = 0; deg < 361; deg += 15) {
//								retval = 0;
//								ZeroMemory(Buf, sizeof(Buf));
//								double si = sin((PI*deg) / 180.0);
//								for (tmp = -10; tmp < si * 10; tmp++) {
//									printf("-");
//									Buf[retval++] = '-';
//								}
//								printf("0\n");
//								Buf[retval++] = '0';
//								Buf[retval++] = '\n';
//								if (deg == 360) {
//									Buf[retval++] = '*';
//									Buf[retval++] = '\0';
//								}
//								retval = send(reads.fd_array[i], Buf, retval, 0);
//							}
//							printf("전송끝~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//							char b[4];
//							int temp = -1;
//							b[0] = (char)temp;
//							send(reads.fd_array[i], b, 1, 0);
//						}
//						else {
//							Buf[retval - 1] = '\0';
//							printf("[서버 수신 data]: %s\n", Buf);
//							char *tmp = "는 허용된 데이터가 아닙니다. 다시 선택해주세요.\n";
//							retval += (strlen(tmp) - 1);
//							strcat(Buf, tmp);
//							Buf[retval] = '\0';
//							//printf("%s\n", Buf);
//							retval = send(reads.fd_array[i], Buf, retval, 0);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	// 소켓을 통한 통신 종료...
//	closesocket(serverSocket);
//	// 소켓 사용 종료..
//	WSACleanup();
//	return 0;
//}