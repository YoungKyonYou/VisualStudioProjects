//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <winsock2.h>
//#define BUF_SIZE 30
//void ErrorHandling(char* message);
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET sock;
//	char message[BUF_SIZE];
//	int strLen;
//
//	SOCKADDR_IN servAdr;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	sock = socket(PF_INET, SOCK_DGRAM, 0);
//	if (sock == INVALID_SOCKET)
//		ErrorHandling("socket() error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	servAdr.sin_port = htons(9190);
//
//	connect(sock, (SOCKADDR*)&servAdr, sizeof(servAdr));
//	int flag = 1;
//	int t = 0;
//	int cnt = 1;
//	int pcnt = 1;
//	int thresh = 0x7fffffff;
//	int status=5;
//	while (1)
//	{
//		message[0] = (char)flag;
//		send(sock, message, 1, 0);
//
//		for (int i = 0; i < cnt; i++)
//			printf("----------->��Ŷ %d\n", pcnt);
//
//		strLen = recv(sock, &status, 1, 0);
//		if (status == 1 && cnt<thresh)
//		{
//			printf("<--- ACK ����\n");
//			cnt *= 2;
//			if (cnt > thresh)
//				cnt = thresh;
//		}
//		else if (status == 1 && cnt >=thresh)
//		{
//			printf("<--- ACK ����\n");
//			cnt++;
//		}
//		else if (status == 2)//�ߺ� ack
//		{
//			printf("<--- ACK ����(3 dup ACK ��� ����)\n");
//			thresh = cnt / 2;
//			cnt = thresh;
//			printf("#Threshold=%d�� �缳��.\n");
//		}
//		else if (status == 3)
//		{
//			printf("Time-out �߻�!\n");
//			thresh = cnt / 2;
//			cnt = 1;
//			printf("#Threshold=%d�� �缳��.\n");
//		}
//	//printf("status:%d cnt:%d thresh:%d\n", status, cnt, thresh);
//		pcnt++;
//	}
//	closesocket(sock);
//	WSACleanup();
//	return 0;
//}
//
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
