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
//char message[BUF_SIZE],m[10];
//int strLen;
//SOCKADDR_IN servAdr;
//int flag = 1, t = 0, cnt = 1, pcnt = 1, thresh = 0x7fffffff, status = 5,run=1;
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void packet();
//int main(int argc, char* argv[])
//{
//	conn();
//	Sleep(1500);
//	send(sock, m, 1, 0);
//	while (run)
//	{
//		message[0] = (int)cnt;
//		send(sock, message, 1, 0);
//		textcolor(GREEN);
//		for (int i = 0; i < cnt; i++)
//			printf("----------->패킷 %d\n", pcnt);
//		textcolor(ORI);
//		strLen = recv(sock, &status, 1, 0);
//		packet();
//		pcnt++;
//	}
//	printf("클라이언트 종료\n");
//	closesocket(sock);
//	WSACleanup();
//	return 0;
//}
//void packet()
//{
//	if (status == 1 && cnt < thresh)
//	{
//		textcolor(YEL);
//		printf("<--- ACK 수신\n");
//		textcolor(ORI);
//		cnt *= 2;
//		if (cnt > thresh)
//			cnt = thresh;
//	}
//	else if (status == 1 && cnt >= thresh)
//	{
//		textcolor(YEL);
//		printf("<--- ACK 수신\n");
//		textcolor(ORI);
//		cnt++;
//	}
//	else if (status == 2)//중복 ack
//	{
//		textcolor(RED);
//		printf("<--- ACK 수신(3 dup ACK 사건 수신)\n");
//		thresh = cnt / 2;
//		cnt = thresh;
//		printf("#Threshold=%d로 재설정.\n", thresh);
//		textcolor(ORI);
//	}
//	else if (status == 3)
//	{
//		textcolor(RED);
//		printf("Time-out 발생!\n");
//		thresh = cnt / 2;
//		cnt = 1;
//		printf("#Threshold=%d로 재설정.\n", thresh);
//		textcolor(ORI);
//	}
//	else if (status == 4)
//	{
//		run = 0;
//	}
//}
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
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
