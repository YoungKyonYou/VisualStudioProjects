//// ���� ���α׷�.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> ���� ���α׷� ����.\n");
//
//	int ret, errorCode, len, option, state;
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup( MAKEWORD(2,2), &winsockData );
//
//	// 2. ������ ���� �ϱ�...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (serverSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> socket() ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	//-------------------------------------------------
//
//
//	
//	//-------------------------------------------------
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family		= AF_INET;
//	serverAddr.sin_port			= htons(20000); 
//	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1");
//	
//	int option1;
//	len = sizeof(option1);
//	getsockopt(serverSocket,SOL_SOCKET,SO_REUSEADDR,(char*)&option1,&len);
//	printf("> REUSEADDR : %d\n", option1);
//	
//	//option1 = TRUE;
//	//getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&option1, len);//���� ���� ���� len��
//
//	printf("> REUSEADDR : %d\n", option1);
//
//
//	// 3. bind() �Լ� ȣ��...
//	// - ������ ���� IP, port ����...
//	ret = bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (ret == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> bind() ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 0; 
//	ret = listen(serverSocket, backLog );
//	if (ret == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> listen() ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	// 5. accept �Լ� ȣ��...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	addrLen = sizeof(clientAddr);
//
//	char Buffer[MAX_BUF_SIZE]; // 100����Ʈ
//	int Count=0, stopFlag=0, returnValue;
//
//	while (Count < 1) {
//		printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//		if (clientSocket == INVALID_SOCKET) {
//			errorCode = WSAGetLastError();
//			printf("<error> accept() ���� �߻�, �ڵ�(%d).\n", errorCode);
//		}
//
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// ����� Ŭ���̾�Ʈ���� ȯ�� �޽��� ����...
//		// ������ ����:
//		// 1. loop (Ŭ���̾�Ʈ�� ���� close�� ������ �޽��� ���� �� echo back.
//		stopFlag = 0;
//		while (stopFlag == 0) {
//
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			if (returnValue > 0) {
//				Buffer[returnValue] = 0;
//				printf("> Ŭ���̾�Ʈ�κ��� %d����Ʈ ����(%s).\n", returnValue, Buffer);
//				send(clientSocket, Buffer, returnValue, 0);
//				printf("> Ŭ���̾�Ʈ���� %d����Ʈ �۽�.\n", returnValue);
//				if (strcmp(Buffer, "a") == 0) {
//					stopFlag = 1;//���� close�Ϸ� ��
//				}
//			}
//			else if (returnValue == SOCKET_ERROR) {
//				printf("<error> recv() �Լ� ���� �� ���� �߻�. code(%d)\n", WSAGetLastError());
//				stopFlag = 1;
//			}
//			else if (returnValue == 0) {
//				printf("> Ŭ���̾�Ʈ�� ������ close��.\n");
//				stopFlag = 1;
//			}
//		}
//
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ������ �����մϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//		// Ŭ���̾�Ʈ ������ ���� ��� ����...
//		closesocket(clientSocket);
//		Count++;
//	}
//	// ������ ���� ��� ����...
//	closesocket(serverSocket);
//
//	// ���� ��� ����..
//	WSACleanup();
//
//	return 0;
//}
//
//
//
///*
//	// recv() �Լ��� ���� ��� tcp client�κ��� ������ ����
//	// send(100B), send(100B), send(100B), send(100B), send(100B)
//	char Buffer[MAX_BUF_SIZE];
//	int  returnValue, stopFlag=0, index=1;
//
//	while (stopFlag == 0) {
//
//		returnValue = recv(clientSocket, Buffer, MAX_BUF_SIZE, 0);
//
//		if (returnValue > 0) // ������ �����͸� ������ ���...
//		{
//			printf("%d> %d ����Ʈ �����͸� ����.\n", index, returnValue);
//			index++;
//		}
//		else if (returnValue == SOCKET_ERROR) {
//			printf("<error> recv() �Լ� ���� �� ���� �߻�, code(%d)\n", WSAGetLastError());
//		}
//		else if (returnValue == 0) {
//			// ���� ���� ����...
//			printf("> client�� socket�� ����\n");
//			stopFlag = 1;
//		}
//
//		//Sleep(1000);
//	}
//*/