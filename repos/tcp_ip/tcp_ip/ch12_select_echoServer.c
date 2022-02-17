//// ���� ���α׷�.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
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
//	if (serverSocket == INVALID_SOCKET)
//	{
//		printf("socket error\n");
//	}
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	// 3. bind() �Լ� ȣ��...
//	if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == INVALID_SOCKET)
//		printf("bind error\n");
//
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 3;
//	if (listen(serverSocket, backLog) == SOCKET_ERROR)
//		printf("listen error\n");
//	// 5. accept �Լ� ȣ��...
//	SOCKET			clientSocket;
//	SOCKADDR_IN	clientAddr;
//	int				addrLen;
//	int				fdNum, retval, i;
//	char				Buf[MAX_BUF_SIZE + 1];
//
//	// select �Լ� �ۼ�...
//	fd_set reads;//����
//	fd_set cpyReads;//���纻
//	TIMEVAL timeout;
//
//	FD_ZERO(&reads);
//	FD_SET(serverSocket,&reads);
//
//	while (1)
//	{
//		//1.select(, cpy_reads,) �Լ� ȣ��, �̺�Ʈ ���� Ȯ��...
//		cpyReads = reads;//����ü�� �̷� ������ ���� ����
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
//		//Ư�� ���Ͽ� �̺�Ʈ�� �߻��� ���...
//		//2. select() ��ȯ -> �̺�Ʈ �߻�, Ÿ�Ӿƿ� ���(�ٽ� selectȣ��)
//		// -�̺�Ʈ �߻� Ȯ��... reads ���Ե� ��� ���Ͽ� ���ؼ� ��� ó��...
//		//   1. ���� ���� : ���� ��û, accept() - ���ϻ��� S1, S2, ... -> reads ����
//		//   2. ������ ���� ���� : recv(), send(), close Ȯ�� -> reads �ش� ���� ����
//		for (i = 0; reads.fd_count; i++)
//		{
//			if (FD_ISSET(reads.fd_array[i], &cpyReads))
//			{
//				if (reads.fd_array[i] == serverSocket)
//				{
//					//���� ���Ͽ� ���ؼ� �̺�Ʈ �߻�...
//					//-accept() - ���ϻ��� S1. S2 ... -> reads ����
//					addrLen = sizeof(clientAddr);
//					clientSocket=accept(serverSocket, (SOCKADDR*)&clientAddr,&addrLen);
//					printf("> Ŭ���̾�Ʈ ���� ����\n");
//					FD_SET(clientSocket, &reads);
//				}
//				else
//				{
//					//Ŭ���̾�Ʈ ���Ͽ� ���� �̺�Ʈ �߻�...
//					// - data ���� ���:recv(), ȭ�� ���, send()
//					// -recv()==0, socket close -> reads���� �ش� ���� ����...
//					retval=recv(reads.fd_array[i], Buf, MAX_BUF_SIZE, 0);
//					if (retval == 0)
//					{
//						//connection close ����...
//						FD_CLR(reads.fd_array[i], &reads);
//						closesocket(reads.fd_array[i]);
//						printf(">Ŭ���̾�Ʈ ���� ����.\n");
//					}
//					else
//					{
//						//������ �����͸� echo back...
//						Buf[retval] = '\0';
//						printf("> ���� ������ : %s\n",Buf);
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
//	// ������ ���� ��� ����...
//	closesocket(serverSocket);
//	// ���� ��� ����..
//	WSACleanup();
//	return 0;
//}
