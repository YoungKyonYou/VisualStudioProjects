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
//	printf("> IO ��Ƽ�÷���(select) ���� ���α׷� ����.\n");
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//
//	// 2. ������ ���� �ϱ�...
//	SOCKET serverSocket;
//	SOCKADDR_IN   serverAddr;
//
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	// 3. bind() �Լ� ȣ��...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//
//	// 5. accept �Լ� ȣ��...
//	SOCKET         clientSocket;
//	SOCKADDR_IN      clientAddr;
//	int            addrLen;
//	int            fdNum, retval, i, tmp;
//	char         Buf[MAX_BUF_SIZE + 1];
//
//	// select �Լ� �ۼ�...
//	fd_set   reads;      // ����
//	fd_set   cpyReads;   // ���纻
//	TIMEVAL   timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket, &reads);
//
//	while (1) {
//		// 1. select( , cpyReads, ) -> �Լ� ȣ��, �̺�Ʈ ���� Ȯ��
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
//		// Ư�� ���Ͽ� �̺�Ʈ�� �߻��� ���
//		// 2. select() ��ȯ -> �̺�Ʈ �߻�, Ÿ�Ӿƿ� ���(�ٽ� select ȣ��)
//		//    - �̺�Ʈ �߻� Ȯ��. reads�� ���Ե� ��� ���Ͽ� ���ؼ� ��� ó��
//		//       1) ���� ����: ���� ��û, accept() - ���� ���� S1, S2... -> reads�� ���Խ�Ű��
//		//       2) ������ ���� ����: recv(), sends(), close Ȯ��(reads �ش� ���� ����)
//		for (i = 0; i < reads.fd_count; i++) {
//			if (FD_ISSET(reads.fd_array[i], &cpyReads)) {
//				if (reads.fd_array[i] == serverSocket) {
//					// ���� ���Ͽ� ���� �̺�Ʈ �߻�
//					// accept() - ���� ���� S1, S2... -> reads�� ���Խ�Ű��
//					printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//					addrLen = sizeof(clientAddr);
//					clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//					printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//					FD_SET(clientSocket, &reads);
//				}
//				else {
//					// Ŭ���̾�Ʈ ���Ͽ� ���� �̺�Ʈ �߻�
//					// data�� ������ ���: recv() -> ȭ�� ��� -> send()
//					// recv() ==0(socket closed) -> reads���� �ش� ���� ����
//					retval = recv(reads.fd_array[i], Buf, MAX_BUF_SIZE, 0);
//					if (retval == 0) {
//						// connection close ����
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("> Ŭ���̾�Ʈ ���� ����.\n");
//					//}a
//					else {
//						// ������ �����Ͱ� 1���� Ȯ��
//						if (Buf[0] == '1') {
//							printf("[���� ���� data]: R\n");
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
//							printf("���۳�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//							char b[4];
//							int temp = -1;
//							b[0] = (char)temp;
//							send(reads.fd_array[i], b, 1, 0);
//						}
//						else {
//							Buf[retval - 1] = '\0';
//							printf("[���� ���� data]: %s\n", Buf);
//							char *tmp = "�� ���� �����Ͱ� �ƴմϴ�. �ٽ� �������ּ���.\n";
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
//	// ������ ���� ��� ����...
//	closesocket(serverSocket);
//	// ���� ��� ����..
//	WSACleanup();
//	return 0;
//}