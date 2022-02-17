//#include <stdio.h>
//#include <WinSock2.h>
//
//#define MAX_BUF_SIZE 100
//int recvn(SOCKET s, char* buf, int len, int flags);
//
//int main(void)
//{
//	WSADATA      winsockData;
//	int         errorNum, errorCode;
//
//	// 1. ���� ���̺귯�� �ʱ�ȭ
//	errorNum = WSAStartup(MAKEWORD(2, 2), &winsockData);
//	if (errorNum == 0) { // �Լ� ���� ����..
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
//	char  Buf[MAX_BUF_SIZE + 1];
//	int     retval;
//	char count;
//	int temp, stack = 0;
//	int index = 0;
//	char c;
//	// ����Ÿ�� �Է��ϰ�, �� ����Ÿ�� ������ �����ϱ�...
//	// ���� û��...
//	ZeroMemory(Buf, sizeof(Buf));
//	// ����ڷκ��� ����Ÿ �Է�...
//	printf("������ sin() ������ ��û] 1:��û, 0:����\n ");
//	scanf("%c", &c);
//	retval = send(clientSocket, &c, 1, 0);
//	if (retval == SOCKET_ERROR)
//	{
//		printf("<ERROR> send()(SOCKET_ERROR)!!!\n");
//	}
//	printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� ���½��ϴ�.\n", retval);
//
//
//
//	int stopFlag = 0, returnValue = 0, rcvTotalLen = 0;
//
//	while (stopFlag == 0) 
//	{
//		int rcvSize;
//		int strLen = 0;
//		strLen=recv(clientSocket, &count, 1, 0);
//		temp = (int*)count;
//		rcvSize = recv(clientSocket, Buf, temp, 0);
//		rcvTotalLen += rcvSize;
//		//printf("temp:%d, strLen=%d \n", temp,strLen);
//		printf("%s\n", Buf);
//		stack++;
//
//
//		/*if (rcvSize == 0)  ///  *********�� ������ ó���ϴ� �κ� �߸� ����!!  TCP ������ ó���ϴ� �� �ٽ� Ȯ���ϱ� �ٶ�
//		{
//			printf("Ŭ���̾�Ʈ�� ������ ����\n");
//			stopFlag = 1;
//		}
//		else if (rcvSize == 0)
//		{
//			printf("���� ����\n");
//			stopFlag = 1;
//		}*/
//		memset(Buf, 0, sizeof(Buf));
//	}
//	printf("> %d\n", stack);
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