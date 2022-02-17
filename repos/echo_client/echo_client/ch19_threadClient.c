//#include <stdio.h>
//#include <WinSock2.h>
//
//#define MAX_BUF_SIZE 100
//int recvn(SOCKET s, char* buf, int len, int flags);
//
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
//	errorNum = connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	printf("> Ŭ���̾�Ʈ�� ������ TCP ���� �Ǿ����ϴ�.\n");
//
//	char  Buf[MAX_BUF_SIZE];
//	int	  retval;
//
//	while (1)
//	{
//		// ����Ÿ�� �Է��ϰ�, �� ����Ÿ�� ������ �����ϱ�...
//		// ���� û��...
//		ZeroMemory(Buf, sizeof(Buf));
//		// ����ڷκ��� ����Ÿ �Է�...
//		printf("\n[���� ����Ÿ] ");
//		if (fgets(Buf, MAX_BUF_SIZE + 1, stdin) == NULL)	break;
//
//		retval = send(clientSocket, Buf, strlen(Buf), 0);
//		if (retval == SOCKET_ERROR)
//		{
//			printf("<ERROR> send()(SOCKET_ERROR)!!!\n");
//			break;
//		}
//		printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� ���½��ϴ�.\n", retval);
//
//		// �����κ��� ����Ÿ�� �����ϱ�...
//		retval = recvn(clientSocket, Buf, retval, 0);
//		if (retval == SOCKET_ERROR)
//		{
//			printf("<ERROR> recvn()(SOCKET_ERROR)!!!\n");
//			break;
//		}
//		else if (retval == 0)	break;
//
//		// ���� ����Ÿ�� ����ϱ�...
//		Buf[retval] = '\0';
//		printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� �޾ҽ��ϴ�.\n", retval);
//		printf("[���� ����Ÿ] %s \n", Buf);
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
//	int 		received;
//	char* ptr = buf;
//	int 		left = len;
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
//	return (len - left);
//}