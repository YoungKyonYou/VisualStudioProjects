//#include <stdio.h>
//#include <WinSock2.h>
//#define MAX_BUF_SIZE 100
//#define MAX_MSG_SIZE 100
//int main(void)
//{
//	WSADATA		winsockData;
//	int			errorNum, errorCode;
//
//	printf("> Ŭ���̾�Ʈ ����. \n");
//
//	// 1. ���� ���̺귯�� �ʱ�ȭ
//	errorNum = WSAStartup( MAKEWORD(2,2), &winsockData );
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
//	clientSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
//	if (clientSocket == INVALID_SOCKET) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	SOCKADDR_IN  serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_family			= AF_INET;
//	serverAddr.sin_port				= htons(9000);  	
//	serverAddr.sin_addr.s_addr		= inet_addr("127.0.0.1");
//
//	// ������ �����ϱ�...
//	errorNum = connect(clientSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr) );
//	if (errorNum == SOCKET_ERROR) {
//		errorCode = WSAGetLastError();
//		printf("<error> ���� �߻�, �ڵ�(%d).\n", errorCode);
//	}
//
//	printf("> Ŭ���̾�Ʈ�� ������ TCP ���� �Ǿ����ϴ�.\n");
//
//
//	//TCP ���� client �κ� ����...
//	//1. ����ڷκ��� �ǿ����ڿ� �����ڸ� �Է�...
//	//�ǿ������� ���� ����...
//	// �޽���: 1����Ʈ:�ǿ����� ���� (n)...
//	// n*4 ����Ʈ : �ǿ����� ����...
//	// 1 ����Ʈ : ������(+/-/*//)
//	
//	char opmsg[MAX_MSG_SIZE];
//	int count;
//	int index;
//	int result, opSize=sizeof(int);
//	char operator;
//	printf("> �ǿ������� ������ �Է��ϼ��� : ");
//	scanf("%d",&count);//�ǿ������� ����
//	printf("> �ǿ������� ������ %d �Դϴ�.\n", count);
//
//	opmsg[0] = (char)count;
//
//	for (index = 0; index < count; index++)
//	{
//		printf("> %d ��° �ǿ�����(����)�� �Է��ϼ��� : ",index+1);
//		scanf("%d", (int*)&opmsg[index*opSize+1]);
//		printf("> �Էµ� �ǿ����� ���� %d �Դϴ�.\n", (int)*(int*)&opmsg[index * opSize + 1]);
//		//���� �ּҸ� ������ int��ŭ ���ڴٴ� �Ű�
//		//�ű⿡ �ִ� ���� �����;� �ϴϱ� �� �տ� (int)�� ĳ���� ���ִ°�
//	}
//	getchar();//����
//	printf("> �����ڸ� �Է��ϼ��� : ");
//	scanf("%c", &operator);
//	printf("> �Էµ� �����ڴ� %c �Դϴ�.\n", operator);
//	opmsg[opSize*count + 1] = operator;
//	//������ ������ ��Ŷ opmsg[] ���� �Ϸ�
//	
//	//�ϼ��� �޽����� ������ ����...
//	int send_byte=send(clientSocket, opmsg, count*opSize+2, 0);
//	printf("sendbytes: %d\n", send_byte);
//	//�����κ��� ��� ����...
//	recv(clientSocket, &result, opSize, 0);
//	printf("> �����κ��� ������ ����� %d �Դϴ�.\n", result);
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
