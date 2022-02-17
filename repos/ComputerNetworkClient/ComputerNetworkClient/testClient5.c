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
//char message[BUF_SIZE], m[10];
//int strLen;
//static HANDLE sem;
//SOCKADDR_IN servAdr;
//int flag = 1, t = 0, cnt = 1, pcnt = 1, thresh = 0x7fffffff, status = 5, run = 1;
//int flag2 = 1, dloss=0, tloss=0;
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void packet();
//void recvACK(int c)
//{
//	textcolor(YEL);
//	printf("<--- ACK %d 수신\n",c);
//	textcolor(ORI);
//}
//void print()
//{
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", pcnt);
//		textcolor(ORI);
//		send(sock, message, 8, 0);
//		Sleep(1000);
//		strLen = recv(sock, &status, 1, 0);
//		recvACK(pcnt++);
//	}
//	printf("\n\n");
//}
//void dup_print()
//{
//	int temp = pcnt;
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", temp++);
//		textcolor(ORI);
//		if (i < cnt - 1)
//			send(sock, message, 8, 0);
//		Sleep(1000);
//		if (i < cnt - 1)
//		{
//			strLen = recv(sock, &status, 1, 0);
//			if (pcnt + 1 != dloss)
//				recvACK(pcnt++);
//			else
//				recvACK(pcnt);
//		}
//	}
//	thresh = cnt / 2;
//	pcnt = dloss;
//	printf("\n\n");
//}
//void timeout()
//{
//	int temp = pcnt;
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", temp++);
//		textcolor(ORI);
//		if (i < cnt - 1)
//			send(sock, message, 8, 0);
//		Sleep(1000);
//		if (i < cnt - 1)
//		{
//			strLen = recv(sock, &status, 1, 0);
//			if (pcnt + 1 != tloss)
//				recvACK(pcnt++);
//			else
//				recvACK(pcnt);
//		}
//	}
//	thresh = cnt / 2;
//	pcnt = tloss;
//	printf("\n\n");
//}
//char scan()
//{
//	char in;
//	in = _getch();
//	fflush(stdin);
//	return in;
//
//}
////unsigned WINAPI subMain(void* arg)
////{
////	while (1)
////	{
////		strLen = recv(sock, &status, 1, 0);
////		if (status == 1 && cnt < thresh)
////		{
////			//recvACK();
////			cnt *= 2;
////			if (cnt > thresh)
////				cnt = thresh;
////		}
////		else if (status == 1 && cnt >= thresh)
////		{
////			//recvACK();
////			cnt++;
////		}
////		else if (status == 3)//서버로부터의 timeout이므로 그냥 ack만 받음
////		{
////			message[0] = (int)1;
////			message[4] = (int)9;
////			if (thresh > cnt)
////				cnt *= 2;
////			else
////				cnt++;
////			send(sock, message, 8, 0); //의미 없는 send
////		//	recvACK();
////		}
////		else if (status == 4)
////		{
////			pcnt -= cnt;
////			thresh = cnt / 2;
////			cnt = thresh;
////			textcolor(RED);
////			printf("<--- ACK 수신\n");
////			printf("#Threshold:%d\n", thresh);
////			textcolor(ORI);
////		}
////		else if (status == 5)//송신자 timeout
////		{
////			printf("<---ACK 수신(타임아웃 발생)\n");
////			pcnt -= cnt;
////			thresh = cnt / 2;
////			cnt = 1;
////			textcolor(RED);
////			printf("# Threshhold=%d\n", thresh);
////			textcolor(ORI);
////		}
////	}
////}
//int main(int argc, char* argv[])
//{
//	//int flag3 = 0;
//	conn();
//	sem = CreateSemaphore(NULL, 1, 1, NULL);
//	//hThread = (HANDLE)_beginthreadex(NULL, 0, subMain, NULL, 0, &threadID);
//	while (1)
//	{
//		char in = scan();
//		if (in == '1')
//		{
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			send(sock, message, 8, 0);
//			print();
//			if (thresh > cnt)
//				cnt *= 2;
//			else
//				cnt++;
//		}
//		else if (in == '2')//3dup
//		{
//			scanf("%d", &dloss);
//			flag = 2;
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			message[8] = (int)dloss;
//			send(sock, message, 12, 0);
//			dup_print();
//			thresh /= 2;
//			cnt /= 2;
//		//	send(sock, message, 12, 0);
//			flag = 1;
//		}
//		else if (in == '3')//timeout 발생시킴
//		{
//
//			scanf("%d", &dloss);
//			flag = 3;
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			message[8] = (int)dloss;
//			printf("<---ACK 수신(타임아웃 발생)\n");
//			send(sock, message, 12, 0);
//			dup_print();
//			thresh /= 2;
//			cnt /= 2;
//			//	send(sock, message, 12, 0);
//			//textcolor(RED);
//			//printf("# Threshhold=%d\n", thresh);
//			//textcolor(ORI);
//		}
//		else if (in == '4')//종료
//		{
//			flag = 4;
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			send(sock, message, 8, 0);
//			break;
//		}
//
//	}
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
