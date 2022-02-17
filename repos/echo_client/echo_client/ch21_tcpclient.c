//
//#include <stdio.h>
//#include <WinSock2.h>
//#define MAX_BUF_SIZE 100
//int main(void)
//{
//	WSADATA		winsockData;
//	int			errorNum, errorCode;
//
//	printf("> Ŭ���̾�Ʈ ����. \n");
//
//	// 1. ���� ���̺귯�� �ʱ�ȭ
//	errorNum = WSAStartup(MAKEWORD(2, 2), &winsockData);
//	if (errorNum == 0) { // �Լ� ���� ����..
//		printf("> ���� �ʱ�ȭ ����.\n");
//	}
//	else {
//		printf("> ���� �ʱ�ȭ ����. �����ڵ�(%d)\n", errorNum);
//		return 1;
//	}
//
//	// 2. ���� ����, param  �������� ����, TCP
//	SOCKET clientSocket;
//	clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (clientSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	SOCKADDR_IN  serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	// ������ �����ϱ�...
//	errorNum = connect(clientSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	printf("> Ŭ���̾�Ʈ�� ������ TCP ���� �Ǿ����ϴ�.\n");
//
//	// Ŭ���̾�Ʈ ���:
//	// 1.- ����ڷκ��� �޽��� �Է¹ް�, �Է� ���� �޽����� ������ ����..
//	// 2.- ������ Ŭ���̾�Ʈ ���� �޽����� �״�� ��������. echo..
//	// 3.- ������ echo�� �޽����� �޾Ƽ� ȭ�鿡 ���...
//	char Buffer[MAX_BUF_SIZE + 1];
//	int  receivedBytes = 0, returnValue; // ������ �޽��� ũ�� ����ġ...
//	int  stopFlag = 0, msglen;
//
//	while (stopFlag == 0) {
//
//		// 1. ����
//		printf("> �޽����� �Է��ϼ���: ");
//		scanf("%s", Buffer);
//		msglen = strlen(Buffer);
//		// �Է��� str "q" ����.
//		if (strcmp(Buffer, "q") == 0) {
//			stopFlag = 1;
//		}
//
//		send(clientSocket, Buffer, msglen, 0);
//		printf("> �Է��� �޽���(%d����Ʈ)�� ������ ������: %s\n", msglen, Buffer);
//		// 2. ������ echo back.
//
//		// 3. msglen��ŭ ����.
//
//		// ������ ����Ʈ��ŭ ����...
//		receivedBytes = 0;
//		while (receivedBytes < msglen) {
//			returnValue = recv(clientSocket, Buffer, sizeof(Buffer), 0);
//			receivedBytes += returnValue;
//
//			if (returnValue > 0) {
//				// ���� ����...
//				printf("> %d ����Ʈ ����Ÿ ����.(����ġ:%d)\n",
//					returnValue, receivedBytes);
//			}
//			else if (returnValue == SOCKET_ERROR) {
//				printf("<error> recv() �Լ� ���� �� ���� �߻�, code(%d)\n",
//					WSAGetLastError());
//				stopFlag = 1;
//				break;
//			}
//			else if (returnValue == 0) {
//				// ������ connection close
//				printf("> ������ ���� ����.\n");
//				stopFlag = 1;
//				break;
//			}
//		}
//
//		Buffer[msglen] = 0;
//		printf("> �����κ��� ������ �޽���: %s\n", Buffer);
//	}
//
//	printf("> Ŭ���̾�Ʈ�� ������ TCP ������ �����մϴ�.\n");
//
//	// ���� ����
//	errorNum = closesocket(clientSocket);
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	// ���� ��� ����...
//	errorNum = WSACleanup();
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//}
//
