//#include<stdio.h>
//#include<stdlib.h>
//#include<WinSock2.h>
//#define MAX_BUF_SIZE 100
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET servSock, clntSock;
//	SOCKADDR_IN servAdr, clntAdr;
//	int clntAdrSz;
//
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//
//	servSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("socket error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_port = htons(atoi(argv[1]));
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind error");
//
//	if (listen(servSock, 5) == SOCKET_ERROR)
//		ErrorHandling("listen error");
//
//
//	clntAdrSz = sizeof(clntAdr);
//	clntSock = accept(servSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
//	if (clntSock == INVALID_SOCKET)
//		ErrorHandling("client socket error");
//
//	printf("> Ŭ���̾�Ʈ(IP:%s, Port:%d)�� ����Ǿ����ϴ�.\n", inet_ntoa(clntAdr.sin_addr), ntohs(clntAdr.sin_port));
//
//	//���� ����
//	//����...Ŭ���̾�Ʈ...��ȣ����...�޽��� ��ȯ...��������...
//	//1. ����...���� open...
//	FILE* fp;
//	int readCnt, TargetSize, rcvedTotalBytes, recvCnt;
//	char buf[MAX_BUF_SIZE];
//
//	fp=fopen("addr_test.c", "rb");
//	if (fp == NULL) {
//		printf("<error> ���� ���� ����..\n");
//		return 1;
//	}
//	//2. while(1){ ������ �а�, send() to client... until(���� �� ���� ������)}
//	while (1)
//	{
//		//�д� ũ��:1*MAX_BUF_SIZE
//		//256B, 100, 100, 56
//		readCnt=fread(buf,1,MAX_BUF_SIZE,fp);
//		send(clntSock, buf, readCnt, 0);
//		if (readCnt < MAX_BUF_SIZE)
//		{
//			break;
//		}
//	}
//	//3. shutdown(,��� ��Ʈ�� shutdown) ... client recv()=0 ���� ���� �Ϸ�� �ؼ�...
//	shutdown(clntSock, SD_SEND);//��� ��Ʈ���� shutdown...
//	//4. recv() "Thank you...9 ���� ����"
//	TargetSize = strlen("Thank you");
//	rcvedTotalBytes = 0;
//	while (rcvedTotalBytes < TargetSize)
//	{
//		rcvedTotalBytes+=recv(clntSock, &buf[rcvedTotalBytes], MAX_BUF_SIZE, 0);
//	}
//	buf[rcvedTotalBytes] = 0;
//	printf("> Ŭ���̾�Ʈ ���� : %s\n", buf);
//	//5. ���� ����...
//	
//	fclose(fp);
//	//E---------------------------
//	closesocket(clntSock);
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}