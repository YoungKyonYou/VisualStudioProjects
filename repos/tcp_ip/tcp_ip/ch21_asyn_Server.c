//#include <stdio.h>
//#include <WinSock2.h>
//#include <math.h>
//#define  MAX_BUF_SIZE  100
//void CompactSocketArray(SOCKET aSocket[], int index, int count);
//void CompactEventArray(WSAEVENT aEvent[], int index, int count);
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(void)
//{
//	WSADATA			winsockData;
//	SOCKET			serverSocket, clientSocket;
//	SOCKADDR_IN		serverAddr, clientAddr;
//	WSAEVENT		event;
//	SOCKET			aSocket[WSA_MAXIMUM_WAIT_EVENTS];
//	WSAEVENT		aEvent[WSA_MAXIMUM_WAIT_EVENTS];
//	WSANETWORKEVENTS enumEvents;
//	int				numSock = 0, position, startIndex, i, eventIndex;
//	int				retval, lenClientAddr, rcvLen;
//	char			Buf[MAX_BUF_SIZE+1];
//
//	// 1. ���� �ʱ�ȭ...���� ���̺귯���� ����...
//	WSAStartup(MAKEWORD(2, 2), &winsockData);
//
//	printf("> Async Event Select ��� ���� ���α׷� ����.\n");
//
//	// 2. ������ ���� �ϱ�...
//	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
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
//
//
//	// EX-01. WSAEventSelect() �Լ� ����.
//	event = WSACreateEvent();
//
//	if (WSAEventSelect(serverSocket, event, FD_ACCEPT) == SOCKET_ERROR)
//		ErrorHandling("<ERROR> WSAEventSelect() ���� ����");
//	else
//	{
//		aSocket[numSock] = serverSocket;
//		aEvent[numSock] = event;
//		numSock++;
//	}
//
//	while (1) {
//		// EX-02. WSAWaitForMultipleEvents() �Լ� ����.
//		position=WSAWaitForMultipleEvents(numSock, aEvent, FALSE, WSA_INFINITE, FALSE);
//		startIndex = position - WSA_WAIT_EVENT_0;
//
//
//		for (i = startIndex; i < numSock; i++) {
//			retval = WSAWaitForMultipleEvents(1, &aEvent[i], TRUE, 0, FALSE);
//
//			if (retval == WSA_WAIT_FAILED || retval == WSA_WAIT_TIMEOUT)
//			{
//				continue;
//			}
//			else
//			{
//				// EX-03. Event�� ó��...
//				eventIndex = i;
//				WSAEnumNetworkEvents(aSocket[eventIndex], aEvent[eventIndex], &enumEvents);
//
//				if (enumEvents.lNetworkEvents & FD_ACCEPT)
//				{
//					//�ش� ���� ���� �����̴�...
//					// Ŭ���̾�Ʈ ���� ��û�� accept ��... ���� ���� ����...
//					//- ���� ���Ͽ� ���ؼ� �̺�Ʈ ���
//					lenClientAddr = sizeof(clientAddr);
//					clientSocket = accept(aSocket[eventIndex], (SOCKADDR*)&clientAddr, &lenClientAddr);
//					if (clientSocket == INVALID_SOCKET)
//						ErrorHandling("Client Socket Error");
//					event = WSACreateEvent();
//					WSAEventSelect(clientSocket, event, FD_READ | FD_CLOSE);
//
//					aEvent[numSock] = event;
//					aSocket[numSock] = clientSocket;
//					numSock++;
//
//					printf("> ���ο� Ŭ���̾�Ʈ ���� �Ϸ�. �̺�Ʈ ��� �Ϸ�. (�̺�Ʈ��:%d)\n", numSock);
//				}
//				if (enumEvents.lNetworkEvents & FD_READ)
//				{
//					if (enumEvents.iErrorCode[FD_READ_BIT] != 0)
//						ErrorHandling("<ERROR> Data ���� ����.\n");
//					rcvLen = recv(aSocket[eventIndex], Buf, MAX_BUF_SIZE, 0);
//					Buf[rcvLen] = 0;
//					printf("> ���� ������: %s\n", Buf);
//					send(aSocket[eventIndex], Buf, rcvLen, 0);
//				}
//			}
//			if (enumEvents.lNetworkEvents & FD_CLOSE)
//			{
//				if (enumEvents.iErrorCode[FD_CLOSE_BIT] != 0)
//					ErrorHandling("<ERROR> Socket close ����.\n");
//				WSACloseEvent(aEvent[eventIndex]);
//				closesocket(aSocket[eventIndex]);
//				numSock--;
//				CompactSocketArray(aSocket, eventIndex, numSock);
//				CompactEventArray(aEvent, eventIndex, numSock);
//			}
//		
//		}//end of for
//
//	} // end of while
//
//
//	  // ������ ���� ��� ����...
//	closesocket(serverSocket);
//	// ���� ��� ����..
//	WSACleanup();
//	return 0;
//}
//
//void CompactSocketArray(SOCKET aSocket[], int index, int count)
//{
//	for (int i = index; i < count; i++) {
//		aSocket[i] = aSocket[i + 1];
//	}
//}
//
//void CompactEventArray(WSAEVENT aEvent[], int index, int count)
//{
//	for (int i = index; i < count; i++) {
//		aEvent[i] = aEvent[i + 1];
//	}
//}
