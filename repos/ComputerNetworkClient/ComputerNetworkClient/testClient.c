//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<process.h>
//#include <conio.h>
//#include <winsock2.h>
//#define BUF_SIZE 30
//#define BLUE 9
//#define GREEN 10
//#define RED 12
//#define YEL 14
//#define ORI 15
//WSADATA wsaData;
//unsigned threadID;
//SOCKET sock;
//HANDLE hThread;
//UINT m_nTimerID;
//char message[BUF_SIZE],m[10];
//int strLen;
//static HANDLE sem;
//SOCKADDR_IN servAdr;
//int flag = 1, t = 0, cnt = 1, pcnt = 1, thresh = 0x7fffffff, status = 5,run=1;
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void packet();
//
//void print()
//{
//	textcolor(GREEN);
//	for (int i = 0; i < cnt; i++)
//		printf("----------->패킷 %d\n", pcnt++);
//	textcolor(ORI);
//}
//void recvACK()
//{
//	textcolor(YEL);
//	printf("<--- ACK 수신\n");
//	textcolor(ORI);
//}
//
//
////unsigned WINAPI subMain(void* arg)
////{
////	while (1)
////	{
////		strLen = recv(sock, &status, 1, 0);
////
////		if (status == 1)
////		{
////			strLen = recv(sock, &status, 1, 0);
////
////		}
////		timeKillEvent(m_nTimerID);
////		
////		
////	}
////}
////void segUp()
////{
////	if (status == 0 && cnt < thresh)
////	{
////		if (cnt > thresh)
////			cnt = thresh;
////	}
////	else if (status == 1 && cnt < thresh)
////	{
////		textcolor(YEL);
////		printf("<--- ACK 수신\n");
////		textcolor(ORI);
////		cnt *= 2;
////		if (cnt > thresh)
////			cnt = thresh;
////	}
////
////	else if (status == 1 && cnt >= thresh)
////	{
////		textcolor(YEL);
////		printf("<--- ACK 수신\n");
////		textcolor(ORI);
////		cnt++;
////	}
////	else if (status == 2)//중복 ack
////	{
////		textcolor(RED);
////		printf("<--- ACK 수신(3 dup ACK 사건 수신)\n");
////		thresh = cnt / 2;
////		cnt = thresh;
////		printf("#Threshold=%d로 재설정.\n", thresh);
////		textcolor(ORI);
////	}
////	else if (status == 3)
////	{
////		timeKillEvent(m_nTimerID);
////		cnt *= 2;
////		cnt = 1;
////		message[0] = (int)cnt;
////		send(sock, message, 1, 0);
////		recvACK();
////		print();
////		strLen = recv(sock, &status, 1, 0);
////
////
////		textcolor(RED);
////		printf("Time-out 발생!\n");
////		thresh = cnt / 4;
////		cnt = 1;
////		message[0] = (int)cnt;
////		printf("#Threshold=%d로 재설정.\n", thresh);
////		textcolor(ORI);
////
////		send(sock, message, 1, 0);
////		ReleaseSemaphore(sem, 1, NULL);
////	}
////	else if (status == 4)
////	{
////		run = 0;
////	}
////}
//char scan()
//{
//	char in;
//	in = _getch();
//	fflush(stdin);
//	return in;
//
//}
//unsigned WINAPI subMain(void* arg)
//{
//	while (1)
//	{
//		strLen = recv(sock, &status, 1, 0);
//		if (status == 1 && cnt<thresh)
//		{
//			recvACK();
//			cnt *= 2;
//			if (cnt > thresh)
//				cnt = thresh;
//		}
//		else if (status == 1 && cnt >= thresh)
//		{
//			recvACK();
//			cnt++;
//		}
//		else if (status == 3)
//		{
//			message[0] = (int)1;
//			message[4] = (int)9;
//			send(sock, message, 8, 0); //의미 없는 send
//			thresh = cnt / 2;
//			cnt = 1;
//			textcolor(RED);
//			printf("<--- ACK 수신 (Time out 발생)\n");
//			printf("#Threshold:%d\n", thresh);
//			textcolor(ORI);
//		}
//	}
//}
//int main(int argc, char* argv[])
//{
//	conn();
//	sem = CreateSemaphore(NULL, 1, 1, NULL);
//	hThread = (HANDLE)_beginthreadex(NULL, 0, subMain, NULL, 0, &threadID);
//	while (1)
//	{
//		char in = scan();
//		if (in == '1')
//		{
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			print();
//			send(sock, message, 8, 0);
//		}
//
//	}
//
//	return 0;
//}
//
//
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
