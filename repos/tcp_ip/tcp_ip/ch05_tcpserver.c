//// ���� ���α׷�.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//#define MAX_MSG_SIZE 100
//int calculation(int opCnt, int operands[], char op);
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> ���� ���α׷� ����.\n");
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup( MAKEWORD(2,2), &winsockData );
//
//	// 2. ������ ���� �ϱ�...
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN   serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family		= AF_INET;
//	serverAddr.sin_port			= htons(9000); 
//	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1");
//
//	// 3. bind() �Լ� ȣ��...
//	// - ������ ���� IP, port ����...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 3; 
//	listen(serverSocket, backLog );
//
//	// 5. accept �Լ� ȣ��...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	addrLen = sizeof(clientAddr);
//
//	int index;
//	int msgSize, opSize, rcvTotalLen, rcvSize,result;
//	opSize = sizeof(int);
//	char opCnt, opmsg[MAX_MSG_SIZE];
//	for (index=0;index<5;index++)
//	{
//		printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		//���� ���� �������� ����
//		//TCP ���� ���� �κ�....
//		//1. Ŭ���̾�Ʈ �۽��� �޼����� ����...
//		// ����: 1����Ʈ ���� (�ǿ����� ��)
//		// ����: count*sizeof(int)+1(������)
//
//		recv(clientSocket, &opCnt,1,0);
//		printf("> �ǿ����� ������ %d �Դϴ�.\n", (int)opCnt);
//
//		msgSize = opCnt * opSize + 1;
//		rcvTotalLen = 0;
//		while (rcvTotalLen<msgSize)
//		{
//			rcvSize = recv(clientSocket, &opmsg[rcvTotalLen], MAX_MSG_SIZE, 0);
//			rcvTotalLen += rcvSize;
//		}
//		printf("������ Ȯ��: %c\n", opmsg[rcvTotalLen -1]);
//		//client ������ opmsg�� ��� ����... opmsg[] �ǿ����ڵ�... ������ ������
//		result=calculation((int)opCnt,(int*)opmsg,opmsg[rcvTotalLen-1]);
//		
//		//������ ���� ���(result) client ���� ����...
//		send(clientSocket, (char*)&result, opSize, 0);
//		printf("> ������ ���� ���(%d)�� Ŭ���̾�Ʈ���� �����մϴ�.\n", result);
//
//
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ������ �����մϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
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
//
//int calculation(int opCnt, int operands[], char op)
//{
//	int result=0;
//	int index;
//	switch (op)
//	{
//	case '+':
//		for (index=1;index<opCnt;index++)
//		{
//			result += operands[index];
//		}
//		break;
//	case '-':
//		for (index = 1; index<opCnt; index++)
//		{
//			result -= operands[index];
//		}
//		break;
//	case '*':
//		for (index = 1; index<opCnt; index++)
//		{
//			result *= operands[index];
//		}
//		break;
//	case '/':
//		for (index = 1; index<opCnt; index++)
//		{
//			result /= operands[index];
//		}
//		break;
//	}
//
//	return result;
//}
