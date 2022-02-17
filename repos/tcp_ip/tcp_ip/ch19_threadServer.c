//// ���� ���α׷�.
//#include <stdio.h>
//#include <WinSock2.h>
//#define  MAX_BUF_SIZE  100
//
//DWORD WINAPI ProcessClient(LPVOID arg);
//int main(void)
//{
//	WSADATA   winsockData;
//	printf("> ��Ƽ������ ���� ���α׷� ����.\n");
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
//	// 3. bind() �Լ� ȣ��...
//	bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
//
//	// 4. listen() �Լ� ȣ��...
//	int backLog = 3;
//	listen(serverSocket, backLog);
//
//	// 5. accept �Լ� ȣ��...
//	SOCKET			clientSocket;
//	SOCKADDR_IN		clientAddr;
//	int				addrLen;
//	HANDLE			hThread;
//	DWORD			ThreadId;
//	addrLen = sizeof(clientAddr);
//
//	while (1) {
//		addrLen = sizeof(clientAddr);
//
//		printf("> accept �Լ��� ȣ���Ͽ� Ŭ���̾�Ʈ ���� ��û�� ����մϴ�.\n");
//		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &addrLen);
//		if (clientSocket == INVALID_SOCKET) {
//			printf("<ERROR> accept() ����...\n");
//			continue;
//		}
//		printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n",
//			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
//
//		// ������ ���� ����� client�� ������ �ۼ��� �����ϱ� ����...
//		
//		hThread = CreateThread(
//			NULL,//����
//			0, //stack size
//			ProcessClient,//������ �Լ�
//			(LPVOID)clientSocket,
//			0,
//			&ThreadId//������ ���̵�
//		);
//
//
//
//
//
//
//
//		if (hThread == NULL) {
//			printf("<ERROR> ������ ���� ����!\n");
//		}
//		else {
//			CloseHandle(hThread);
//		}
//	}
//
//	// ������ ���� ��� ����...
//	closesocket(serverSocket);
//
//	// ���� ��� ����..
//	WSACleanup();
//	return 0;
//}
//DWORD WINAPI ProcessClient(LPVOID arg)//clientSocket
//{
//	SOCKET clientSocket = (SOCKET)arg;
//	char Buf[MAX_BUF_SIZE + 1];
//	SOCKADDR_IN clientAddr;
//	int addrLen, retval;
//	
//	addrLen = sizeof(clientAddr);
//	getpeername(clientSocket, (SOCKADDR*)&clientAddr,&addrLen);
//
//	while (1)
//	{
//		//Ŭ���̾�Ʈ�� ������ �ۼ���...echo...
//		retval=recv(clientSocket,Buf,MAX_BUF_SIZE,0);
//		if (retval == SOCKET_ERROR) {
//			printf("<thread> ERROR - recv() ����.\n");
//			break;
//		}
//		else if (retval == 0)//connection close...
//		{
//			printf("<thread> TCP connection close.\n");
//			break;
//		}
//		Buf[retval] = '\0';
//		printf("<thread> client[%s:%d] ���ŵ� ������: %s\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port),Buf);
//		send(clientSocket, Buf, retval, 0);
//		if (retval == SOCKET_ERROR)
//		{
//			printf("<thread> ERROR-send().\n");
//			break;
//		}
//
//
//	}
//
//	closesocket(clientSocket);
//	printf("<thread> Ŭ���̾�Ʈ ����: IP�ּ�=%s Port=%d\n",inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
//	return 0;
//
//
//}
//
//
