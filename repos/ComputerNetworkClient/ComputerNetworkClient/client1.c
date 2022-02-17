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
//
//int flag = 0, packNum = 1, packCnt = 1, packDup = -1, packTime = -1, window = 1, threshold= 0x7fffffff;
//int rcvPackNum = 0, rcvPackCnt = 0, timeFlag = 0, timeFlag2 = 0;;
//int mainFlag = 0;
//
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void print(int pn);
//
//char scan()
//{
//	char in;
//	in = _getch();
//	fflush(stdin);
//	return in;
//
//}
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	timeFlag = 1;
//	timeKillEvent(m_nTimerID);
//}
//unsigned WINAPI subMain(void* arg)
//{
//	char recvMsg[BUF_SIZE];
//	while (1)
//	{
//		/// 발생
//		if (timeFlag == 1)
//		{
//			printf("window:%d\n", window);
//			if (threshold != 0x7fffffff)
//				printf("threshold:%d\n", threshold);
//			flag = 4;
//			window = packCnt;
//			message[0] = (int)flag;
//			message[4] = (int)packNum;
//			message[8] = (int)packCnt;
//			message[12] = (int)packDup;
//			message[16] = (int)packTime;
//			message[20] = (int)timeFlag;
//			for (int i = 0; i < window-1; i++)
//			{
//				message[4] = (int)packNum;
//				send(sock, message, 24, 0);
//				print(packNum);
//				packNum++;
//			}
//			if (threshold > packCnt)
//				packCnt *= 2;
//			else
//				packCnt++;
//
//
//			message[4] = (int)packTime;
//			send(sock, message, 24, 0);
//			textcolor(RED);
//			printf("time out: %d packet\n", packTime);
//			textcolor(ORI);
//
//
//			message[4] = (int)packTime;
//			send(sock, message, 24, 0);
//			textcolor(GREEN);
//			printf("----------->패킷 %d\n", packTime);
//			textcolor(ORI);
//			mainFlag = 1;
//		}
//		if (mainFlag == 1)
//		{
//			///// ///////////////////
//
//			if (timeFlag2 == 1)
//			{
//				textcolor(RED);
//				printf("<--- ACK %d 재수신\n", packNum-2);
//				textcolor(ORI);
//				timeFlag2 = 0;
//			}
//			///////////////////////
//
//
//			recv(sock, recvMsg, 24, 0);
//			flag = (int)recvMsg[0];
//			rcvPackCnt = (int)recvMsg[8];
//			for (int i = 0; i < rcvPackCnt; i++)
//			{
//				rcvPackNum = (int)recvMsg[4];
//				textcolor(YEL);
//				printf("<--- ACK %d 수신\n", rcvPackNum);
//				textcolor(ORI);
//				if(i+1<rcvPackCnt)
//					recv(sock, recvMsg, 24, 0);
//			}
//
//
//			if (timeFlag == 1)
//			{
//				timeFlag2 = 1;
//				timeFlag = 0;
//				threshold = window;
//				threshold /= 2;
//				packCnt = 1;
//				window = 1;
//			}
//			else
//			{
//				if (threshold > packCnt)
//					packCnt *= 2;
//				else
//					packCnt++;
//			}
//			window = packCnt;
//			mainFlag = 0;
//			printf("\n\n");
//		}
//		else if (mainFlag == 2)
//		{
//			int dupCnt = 0;
//			recv(sock, recvMsg, 24, 0);
//			flag = (int)recvMsg[0];
//			rcvPackCnt = (int)recvMsg[8];
//			for (int i = 0; i < rcvPackCnt; i++)
//			{
//				rcvPackNum = (int)recvMsg[4];
//				textcolor(YEL);
//				if(rcvPackNum !=-1)
//					printf("<--- ACK %d 수신\n", rcvPackNum);
//				else if (rcvPackNum == -1 && dupCnt<2)
//				{
//					printf("<--- ACK %d 수신\n", packDup-1);
//					dupCnt++;
//				}
//				else
//					printf("trash!!\n");
//				textcolor(ORI);
//				if (i + 1 < rcvPackCnt)
//					recv(sock, recvMsg, 24, 0);
//			}
//			threshold = window;
//			threshold /= 2;
//			packCnt /= 2;
//			packNum = packDup;
//			window = packCnt;
//			printf("\n\n");
//			mainFlag = 0;
//		}
//		else if (mainFlag == 3)
//		{
//			int prePackNum = rcvPackNum;
//			recv(sock, recvMsg, 24, 0);
//			flag = (int)recvMsg[0];
//			rcvPackCnt = (int)recvMsg[8];
//			for (int i = 0; i < rcvPackCnt-1; i++)
//			{
//				rcvPackNum = (int)recvMsg[4];
//
//				/// TIME 
//				m_nTimerID = timeSetEvent(3000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//				/// 
//
//				textcolor(YEL);
//				printf("<--- ACK %d 수신\n", rcvPackNum);
//				textcolor(ORI);
//				if (rcvPackNum - prePackNum == 1)
//				{
//					timeKillEvent(m_nTimerID);
//				}
//				if (i + 1 < rcvPackCnt-1)
//				{
//					recv(sock, recvMsg, 24, 0);
//				}
//
//			}
//			if (threshold > packCnt)
//				packCnt *= 2;
//			else
//				packCnt++;
//			window = packCnt;
//			printf("\n\n");
//			mainFlag = 0;
//		}
//	}
//}
//int main(int argc, char* argv[])
//{
//
//	conn();
//	hThread = (HANDLE)_beginthreadex(NULL, 0, subMain, NULL, 0, &threadID);
//	while (1)
//	{
//		char in = scan();
//		if (in == '1')
//		{
//			printf("window:%d\n", window);
//			if (threshold != 0x7fffffff)
//				printf("threshold:%d\n", threshold);
//			flag = 1;
//			window = packCnt;
//			message[0] = (int)flag;
//			message[4] = (int)packNum;
//			message[8] = (int)packCnt;
//			message[12] = (int)packDup;
//			message[16] = (int)packTime;
//			message[20] = (int)timeFlag;
//			for (int i = 0; i < window; i++)
//			{
//				message[4] = (int)packNum;
//				send(sock, message, 24, 0);
//				print(packNum);
//				packNum++;
//			}
//			mainFlag = 1;
//		}
//		else if (in == '2')
//		{
//			scanf("%d", &packDup);
//			printf("window:%d\n", window);
//			if (threshold != 0x7fffffff)
//				printf("threshold:%d\n", threshold);
//			flag = 2;
//			window = packCnt;
//			message[0] = (int)flag;
//			message[4] = (int)packNum;
//			message[8] = (int)packCnt;
//			message[12] = (int)packDup;
//			message[16] = (int)packTime;
//			message[20] = (int)timeFlag;
//			for (int i = 0; i < window; i++)
//			{
//				message[4] = (int)packNum;
//				send(sock, message, 24, 0);
//				print(packNum);
//				packNum++;
//			}
//			printf("LOSS PACKET: %d\n", packDup);
//			mainFlag = 2;
//		}
//		else if (in == '3')
//		{
//			scanf("%d", &packTime);
//			printf("window:%d\n", window);
//			if (threshold != 0x7fffffff)
//				printf("threshold:%d\n", threshold);
//			flag = 3;
//			window = packCnt;
//			message[0] = (int)flag;
//			message[4] = (int)packNum;
//			message[8] = (int)packCnt;
//			message[12] = (int)packDup;
//			message[16] = (int)packTime;
//			message[20] = (int)timeFlag;
//			for (int i = 0; i < window; i++)
//			{
//				message[4] = (int)packNum;
//				send(sock, message, 24, 0);
//				print(packNum);
//				packNum++;
//			}
//			mainFlag = 3;
//		}
//	}
//	return 0;
//}
//
//void print(int pn)
//{
//	textcolor(GREEN);
//	printf("----------->패킷 %d\n", pn);
//	textcolor(ORI);
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
