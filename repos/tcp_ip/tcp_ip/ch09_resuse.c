//// ���� ���α׷�.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> ���� ���α׷� ����.\n");
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//
//	// 2. ������ ���� �ϱ�...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	int option, len;
//	len = sizeof(option);
//	getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, &len);
//	printf("1 > REUSEADDR : %d\n", option);
//
//	option = TRUE;
//	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, len);// ������ �μ��� �ٸ�
//
//	getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,(char*)&option, &len);
//	printf("2 > REUSEADDR : %d\n", option);
//
//	// 3. bind() �Լ� ȣ��...
//	// - ������ ���� IP, port ����...
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
//	addrLen = sizeof(clientAddr);
//
//	char Buffer[MAX_BUF_SIZE];
//	int Count = 0, stopFlag = 0, returnValue;//returnValue  ���� ������
//
//	while (Count < 5)
//	{
//		printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// ����� Ŭ�󸮾�Ʈ���� ȯ�� �޽��� ����...
//		// ������ ���� :
//		// 1. loop (Ŭ���̾�Ʈ�� ���� close�� ������ �޽��� ���� �� echo back.
//		while (stopFlag == 0)
//		{
//
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			if (returnValue > 0)
//			{
//				printf("> Ŭ���̾�Ʈ�κ��� %d����Ʈ ����.\n", returnValue);
//				send(clientSocket, Buffer, returnValue, 0);
//				if (strcmp(Buffer, 'a') == 0)
//					stopFlag = 1;
//			}
//			else if (returnValue == SOCKET_ERROR)
//			{
//				printf("<error> recv()�Լ� ���� �� ���� �߻�, code(%d)\n", WSAGetLastError);
//				stopFlag = 1;
//			}
//			else if (returnValue == 0)
//			{
//				printf("> Ŭ���̾�Ʈ�� ������ close��\n");
//				stopFlag = 1;
//			}
//		}
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ������ �����մϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//		// Ŭ���̾�Ʈ ������ ���� ��� ����...
//		closesocket(clientSocket);
//	}
//	// ������ ���� ��� ����...
//	closesocket(serverSocket);
//
//	// ���� ��� ����..
//	WSACleanup();
//
//	return 0;
//}
