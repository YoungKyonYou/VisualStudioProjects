//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <winsock2.h>
//#define BUF_SIZE 30
//#define BLUE 9
//#define GREEN 10
//#define RED 12
//#define YEL 14
//#define ORI 15
//WSADATA wsaData;
//SOCKET sock;
//char message[BUF_SIZE];
//int strLen;
//SOCKADDR_IN servAdr;
//int flag = 1;
//int t = 0;
//int cnt = 1;
//int pcnt = 1;
//int thresh = 0x7fffffff;
//int status = 5;
//char m[10];
//void ErrorHandling(char* message);
//void textcolor(int color_number)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
//}
//void conn()
//{
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
//	m[0] = 'c';
//}
//int main(int argc, char* argv[])
//{
//	conn();
//	send(sock, m, 1, 0);
//	while (1)
//	{
//		message[0] = (int)cnt;
//		send(sock, message, 1, 0);
//		textcolor(GREEN);
//		for (int i = 0; i < cnt; i++)
//			printf("----------->패킷 %d\n", pcnt);
//		textcolor(ORI);
//		strLen = recv(sock, &status, 1, 0);
//		if (status == 1 && cnt < thresh)
//		{
//			textcolor(YEL);
//			printf("<--- ACK 수신\n");
//			textcolor(ORI);
//			cnt *= 2;
//			if (cnt > thresh)
//				cnt = thresh;
//		}
//		else if (status == 1 && cnt >= thresh)
//		{
//			textcolor(YEL);
//			printf("<--- ACK 수신\n");
//			textcolor(ORI);
//			cnt++;
//		}
//		else if (status == 2)//중복 ack
//		{
//			textcolor(RED);
//			printf("<--- ACK 수신(3 dup ACK 사건 수신)\n");
//			thresh = cnt / 2;
//			cnt = thresh;
//			printf("#Threshold=%d로 재설정.\n",thresh);
//			textcolor(ORI);
//		}
//		else if (status == 3)
//		{
//			textcolor(RED);
//			printf("Time-out 발생!\n");
//			thresh = cnt / 2;
//			cnt = 1;
//			printf("#Threshold=%d로 재설정.\n",thresh);
//			textcolor(ORI);
//		}
//		//printf("status:%d cnt:%d thresh:%d\n", status, cnt, thresh);
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
