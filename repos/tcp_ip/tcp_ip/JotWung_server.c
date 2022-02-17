//#include <stdio.h>
//#include <WinSock2.h>kl
//#include<math.h>
//#define  MAX_BUF_SIZE  100
//#define PH 3.1415926535
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
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	// 3. bind() 함수 호출...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	// 4. listen() 함수 호출...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//	// 5. accept 함수 호출...
//	SOCKET         clientSocket;
//	SOCKADDR_IN   clientAddr;
//	int            addrLen;
//	int            fdNum, retval, i;
//	char         Buf[MAX_BUF_SIZE + 1];
//	char         B[MAX_BUF_SIZE + 1];
//	// select 함수 작성...
//	fd_set reads;// 원본
//	fd_set cpyReads; // 복사본
//	TIMEVAL timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket, &reads);
//	while (1)
//	{
//		// 1. select(,cpy_reads,) 함수 호출, 이벤트 생성 확인
//		cpyReads = reads;
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 5000;
//		printf("> accept 함수를 호출하여 클라리언트 연결 요청을 대기합니다.\n");
//		fdNum = select(0, &cpyReads, 0, 0, &timeout); // 리턴 값으로 이벤트의 개수
//		if (fdNum == SOCKET_ERROR)
//		{
//			break;
//		}
//		if (fdNum == 0)
//		{
//			continue;
//		}
//
//		// 특정 소켓에 이벤트가 발생한 경우
//		// 2. select() 반환-> 이벤트 발생, 타임아웃 경우(다시 select 호출)
//		//   - 이벤트 발생 확인... reads 포함된 모든 소켓에 대해서 모두 처리
//		//      1. 서버 소켓 : 연결 요청, accept()- 소켓 생성 S1, S2... ->reads 포함
//		//      2. 데이터 전송 소켓 : recv(), send(), close 확인 -> reads 해당 소켓 제외
//		for (i = 0; i < reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == serverSocket)
//				{//서버 소켓에 대해서 이벤트 발생...
//				 //accept()- 소켓 생성 S1, S2... ->reads 포함
//					addrLen = sizeof(clientAddr);
//					printf("> accept 함수를 호출하여 클라이언트 연결 요청을 대기합니다.\n");
//					clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//					printf("> 클라이언트(IP:%s, Port:%d)가 연결되었습니다.\n"
//						, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//					FD_SET(clientSocket, &reads);
//				}
//				else
//				{// 클라이언트 소켓에 대한 이벤트 발생
//				 // - data 수신 경우: recv(), 화면 출력, send();
//				 // - recv()==0, socket close-> reads에서 해당 소켓 제외...
//					printf("[서버 수신 data] R\n");
//					retval = recv(reads.fd_array[i], B, MAX_BUF_SIZE, 0);
//					if (retval == 0)
//					{
//						// connection close 상태...
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("> 클라이어트 연결 종료.\n");
//					}
//					else
//					{
//						// 수신한 데이터를 echo back...
//						B[retval] = '\0';
//						printf("> 수신 데이터 : %s\n", B);
//						if (B[0] == '0') // 거절 요청이 올 때
//						{
//							FD_CLR(reads.fd_array[i], &reads);
//							closesocket(cpyReads.fd_array[i]);
//							printf("> 클라이어트 연결 종료.\n");
//						}
//						else
//						{
//							double si = 0;
//							int result, x;
//							int scnt = 0;
//							int len = 0;
//							int index = 0;
//							for (int a = 0; a <= 1080; a += 20)
//							{
//								int count = 0;
//								int index = 1;
//								si = sin((PH*a) / 180.0);
//
//								for (x = -9; x < si * 10; x++)
//								{
//									Buf[index++] = '-';
//									//printf("index:%d ", index);
//								}
//								//printf("\n");
//								Buf[index++] = '0';
//								Buf[index] = '\0';
//								Buf[0] = (char)strlen(&Buf[1]);
//								//printf("strlen:%d\n", strlen(Buf));
//								//printf("count:%d\n", count);
//							//	printf("%s\n", &Buf[1]);
//								//printf("first byte: %d  \n", (int*)Buf[0]);
//								retval = send(reads.fd_array[i], Buf, strlen(Buf)+1 , 0);
//								scnt++;
//								memset(Buf, 0, sizeof(Buf));
//							}
//							printf("[TCP 서버] %d개 sin 데이터 전송\n", scnt);
//
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