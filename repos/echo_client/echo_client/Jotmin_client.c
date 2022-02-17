//#include <stdio.h>
//#include <WinSock2.h>
//#include <math.h>
//
//#define MAX_BUF_SIZE 100
//int recvn(SOCKET s, char* buf, int len, int flags);
//
//int main(int argc, int* argv[])
//{
//	WSADATA      winsockData;
//	int         errorNum, errorCode;
//
//	printf("> Ŭ���̾�Ʈ ����. \n");
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
//		return 1;
//	}
//
//		SOCKADDR_IN  serverAddr;
//		memset(&serverAddr, 0, sizeof(serverAddr));
//		serverAddr.sin_family = AF_INET;
//		serverAddr.sin_port = htons(9000);
//		serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	// ������ �����ϱ�...
//	errorNum = connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//		return 1;
//	}
//
//	printf("> Ŭ���̾�Ʈ�� ������ TCP ���� �Ǿ����ϴ�.\n");
//
//	char  Buf[MAX_BUF_SIZE + 1];
//	int     retval;
//
//	while (1)
//	{
//		// ����Ÿ�� �Է��ϰ�, �� ����Ÿ�� ������ �����ϱ�...
//		// ���� û��...
//		ZeroMemory(Buf, sizeof(Buf));
//		// ����ڷκ��� ����Ÿ �Է�...
//		printf("[������ sin() ������ ��û] 1: ��û, 0: ����\n");
//		if (fgets(Buf, MAX_BUF_SIZE + 1, stdin) == NULL) {
//			break;
//		}
//		if (Buf[0] == '0') {
//			break;
//		}
//		printf("> ������ sin �����͸� ��û�մϴ�.\n");
//		retval = send(clientSocket, Buf, strlen(Buf), 0);
//		if (retval == SOCKET_ERROR) {
//			printf("<ERROR> send()(SOCKET_ERROR)!!!\n");
//			break;
//		}
//		printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� ���½��ϴ�.\n", retval);
//
//		// �����κ��� ����Ÿ�� �����ϱ�...
//		while (1) {
//			retval = recv(clientSocket, Buf, MAX_BUF_SIZE, 0);
//			/*int temp = (int*)Buf[0];
//			printf("temp:%d\n", temp);
//			if (temp == -1)
//			{
//				printf("���� �Ϸ�\n");
//				break;
//			}*/
//			if (retval == SOCKET_ERROR) {
//				printf("<ERROR> recvn()(SOCKET_ERROR)!!!\n");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}
//			// ���� �����͸� ����ϱ�...
//			Buf[retval] = '\0';
//			//printf("[TCP Ŭ���̾�Ʈ] %d ���� sin �����͸� �޾ҽ��ϴ�.\n", retval);
//			printf("%s", Buf);
//		}
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
//
//int recvn(SOCKET s, char* buf, int len, int flags)
//{
//	int       received;
//	char* ptr = buf;
//	int       left = len;
//
//	while (left > 0)
//	{
//		received = recv(s, ptr, left, flags);
//		if (received == SOCKET_ERROR)
//			return SOCKET_ERROR;
//		else if (received == 0)
//			break;
//		left -= received;
//		ptr += received;
//	}
//
//
//	return (len - left);
//}
