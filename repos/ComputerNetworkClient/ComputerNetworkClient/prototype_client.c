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
//int flag = 1, t = 0, cnt = 1, pcnt = 1, acnt = 1, thresh = 0x7fffffff, status = 5, run = 1;
//int flag2 = 1, dloss = 0, tloss = 0, tflag=1, ttflag=1, rsflag=1;
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void packet();
//void recvACK(int c)
//{
//	textcolor(YEL);
//	printf("<--- ACK %d 수신\n", c);
//	textcolor(ORI);
//}
//void print()
//{
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		if (!tflag && i == cnt - 1)
//			break;
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", pcnt++);
//		textcolor(ORI);
//		//send(sock, message, 8, 0);
//	}
//	send(sock, message, 8, 0);
//	if (!tflag)
//	{
//		textcolor(RED);
//		printf("timeout packet : %d\n", tloss);
//		printf("------------->resend packet:%d\n", tloss);
//		textcolor(ORI);
//		send(sock, message, 8, 0);
//	}
//	Sleep(1000);
//	for (int i = 0; i < cnt; i++)
//	{
//		if (!tflag && i == cnt - 1)
//		{	
//			thresh = cnt / 2;
//			printf("threshold:%d\n", thresh);
//			break;
//		}
//		if (!rsflag)
//		{
//			printf("<---------re-receive ACK %d\n", pcnt - 2);
//			rsflag = 1;
//		}
//		recvACK(acnt++);
//	}
//	//thresh = cnt / 2;
//	//printf("threshold: %d\n", thresh);
//	printf("\n\n");
//}
//void dup_print()
//{
//	int temp = pcnt;
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", pcnt++);
//		textcolor(ORI);
//		//send(sock, message, 8, 0);
//	}
//	textcolor(RED);
//	printf("%d packet loss\n", dloss);
//	textcolor(ORI);
//	send(sock, message, 8, 0);
//
//	Sleep(2000);
//	int tmp=cnt;
//	//printf("test dloss:%d  test acnt:%d \n", dloss, acnt);
//	while (1)
//	{
//		if (acnt + 1 == dloss)
//		{
//
//			//
//
//			//
//
//			for (int i = 0; i < 3; i++)
//				recvACK(acnt);
//			tmp -= 3;
//			for (int i = 0; i < tmp - 1; i++)
//				printf("trash!!\n");
//			thresh = cnt / 2;
//			pcnt = dloss;
//			acnt = dloss;
//			printf("threshold:%d\n", thresh);
//			printf("\n\n");
//			return;
//		}
//		else
//		{
//			recvACK(acnt);
//			if (acnt + 1 != dloss)
//			{
//				acnt++;
//				tmp--;
//				pcnt++;
//			}
//		}
//	}
//}
//void timeout()
//{
//	int temp = pcnt;
//	printf("window: %d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		textcolor(GREEN);
//		printf("----------->패킷 %d\n", pcnt++);
//		textcolor(ORI);
//		//send(sock, message, 8, 0);
//	}
//	send(sock, message, 8, 0);
//	Sleep(1000);
//	for (int i = 0; i < cnt; i++)
//	{
//		if (acnt == tloss)
//		{
//			acnt++;
//			continue;
//		}
//		recvACK(acnt++);
//	}
//	//thresh = cnt / 2;
//	printf("\n\n");
//	tflag = 0;
//}
//char scan()
//{
//	char in;
//	in = _getch();
//	fflush(stdin);
//	return in;
//
//}
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
//			message[8] = (int)tflag;
//			send(sock, message, 12, 0);
//			print();
//			if (thresh > cnt)
//				cnt *= 2;
//			else
//				cnt++;
//			strLen = recv(sock, &status, 1, 0);
//			if (!tflag)
//			{
//				//pcnt -= 1;
//				//acnt -= 1;
//				cnt = 1;
//				tflag = 1;
//				rsflag = 0;
//			}
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
//			//	send(sock, message, 12, 0);
//			flag = 1;
//		}
//		else if (in == '3')//timeout 발생시킴
//		{
//
//			scanf("%d", &tloss);
//			flag = 3;
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			message[8] = (int)tloss;
//			textcolor(RED);
//			printf("packet %d (타임아웃 발생)\n",tloss);
//			textcolor(ORI);
//			send(sock, message, 12, 0);
//			timeout();
//			if (thresh > cnt)
//				cnt *= 2;
//			else
//				cnt++;
//			flag = 1;
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
