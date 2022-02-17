//#include <stdio.h>
//#include <WinSock2.h>kl
//#include<math.h>
//#define  MAX_BUF_SIZE  100
//#define PH 3.1415926535
//
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> IO ��Ƽ�÷���(select) ���� ���α׷� ����.\n");
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//	// 2. ������ ���� �ϱ�...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	// 3. bind() �Լ� ȣ��...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//	// 5. accept �Լ� ȣ��...
//	SOCKET         clientSocket;
//	SOCKADDR_IN   clientAddr;
//	int            addrLen;
//	int            fdNum, retval, i;
//	char         Buf[MAX_BUF_SIZE + 1];
//	char         B[MAX_BUF_SIZE + 1];
//	// select �Լ� �ۼ�...
//	fd_set reads;// ����
//	fd_set cpyReads; // ���纻
//	TIMEVAL timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket, &reads);
//	while (1)
//	{
//		// 1. select(,cpy_reads,) �Լ� ȣ��, �̺�Ʈ ���� Ȯ��
//		cpyReads = reads;
//		timeout.tv_sec = 5;
//		timeout.tv_usec = 5000;
//		printf("> accept �Լ��� ȣ���Ͽ� Ŭ�󸮾�Ʈ ���� ��û�� ����մϴ�.\n");
//		fdNum = select(0, &cpyReads, 0, 0, &timeout); // ���� ������ �̺�Ʈ�� ����
//		if (fdNum == SOCKET_ERROR)
//		{
//			break;
//		}
//		if (fdNum == 0)
//		{
//			continue;
//		}
//
//		// Ư�� ���Ͽ� �̺�Ʈ�� �߻��� ���
//		// 2. select() ��ȯ-> �̺�Ʈ �߻�, Ÿ�Ӿƿ� ���(�ٽ� select ȣ��)
//		//   - �̺�Ʈ �߻� Ȯ��... reads ���Ե� ��� ���Ͽ� ���ؼ� ��� ó��
//		//      1. ���� ���� : ���� ��û, accept()- ���� ���� S1, S2... ->reads ����
//		//      2. ������ ���� ���� : recv(), send(), close Ȯ�� -> reads �ش� ���� ����
//		for (i = 0; i < reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == serverSocket)
//				{//���� ���Ͽ� ���ؼ� �̺�Ʈ �߻�...
//				 //accept()- ���� ���� S1, S2... ->reads ����
//					addrLen = sizeof(clientAddr);
//					printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//					clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//					printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n"
//						, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//					FD_SET(clientSocket, &reads);
//				}
//				else
//				{// Ŭ���̾�Ʈ ���Ͽ� ���� �̺�Ʈ �߻�
//				 // - data ���� ���: recv(), ȭ�� ���, send();
//				 // - recv()==0, socket close-> reads���� �ش� ���� ����...
//					printf("[���� ���� data] R\n");
//					retval = recv(reads.fd_array[i], B, MAX_BUF_SIZE, 0);
//					if (retval == 0)
//					{
//						// connection close ����...
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(cpyReads.fd_array[i]);
//						printf("> Ŭ���̾�Ʈ ���� ����.\n");
//					}
//					else
//					{
//						// ������ �����͸� echo back...
//						B[retval] = '\0';
//						printf("> ���� ������ : %s\n", B);
//						if (B[0] == '0') // ���� ��û�� �� ��
//						{
//							FD_CLR(reads.fd_array[i], &reads);
//							closesocket(cpyReads.fd_array[i]);
//							printf("> Ŭ���̾�Ʈ ���� ����.\n");
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
//							printf("[TCP ����] %d�� sin ������ ����\n", scnt);
//
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