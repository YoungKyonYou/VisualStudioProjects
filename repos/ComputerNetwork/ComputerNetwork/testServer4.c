//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<process.h>
//#include <conio.h>
//#include <winsock2.h>
//#define BLUE 9
//#define GREEN 10
//#define RED 12
//#define YEL 14
//#define ORI 15
//#define BUF_SIZE 30
//HANDLE hThread;
//char in;
//unsigned threadID;
//int param = 5, thread_param = 5, cnt = 0, pcnt = 1; status = 0, input = 1, rcvn = 1, len, s, timer = 1;;
//int ff = 1;
//WSADATA wsaData;
//int strLen;
//UINT m_nTimerID;
//SOCKET servSock;
//SOCKADDR_IN servAdr, clntAdr;
//static HANDLE sem;
//int clntAdrSz = sizeof(clntAdr);
//char message[BUF_SIZE];
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void sendACK();
//void print(int cnt);
//void conn();
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2);
//
//int main(int argc, char* argv[])
//{
//	conn();
//	//hThread = (HANDLE)_beginthreadex(NULL, 0, subMain, NULL, 0, &threadID);
//	while (1)
//	{
//		int c, f;
//		len = recvfrom(servSock, message, 8, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		c = (int)message[0];
//		f = (int)message[4];
//		if (f == 1)
//		{
//			print(c);
//			m_nTimerID = timeSetEvent(4000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//		}
//		else if (f == 2)//3dup
//		{
//
//			printf("---------------->ACK 송신(3 dup ACK 사건 전달)\n");
//			message[0] = (int)4;
//			sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//			continue;
//		}
//		else if (f == 3)//송신자로부터의 timeout
//		{
//			pcnt -= c;
//			timeKillEvent(m_nTimerID);
//			sendACK();
//			message[0] = (int)5;
//			sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//			continue;
//		}
//		else if (f == 4)//종료
//			break;
//		len = recvfrom(servSock, message, 8, 0, (SOCKADDR*)&clntAdr, &clntAdrSz);
//		c = (int)message[0];
//		f = (int)message[4];
//		if (f == 1)
//		{
//			c = (int)message[0];
//			f = (int)message[4];
//
//			timeKillEvent(m_nTimerID);
//			print(c);
//			message[0] = (int)1;
//			///////////////////////
//			sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//			////////////////////////
//			sendACK();
//
//		}
//		else if (f == 2)//3dup
//		{
//			timeKillEvent(m_nTimerID);
//			printf("---------------->ACK 송신(3 dup ACK 사건 전달)\n");
//			message[0] = (int)4;
//			sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//			continue;
//		}
//		else if (f == 3)//송신자로부터의 timeout
//		{
//			pcnt -= c;
//			timeKillEvent(m_nTimerID);
//			sendACK();
//			message[0] = (int)5;
//			sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//			continue;
//		}
//		else if (f == 4)//종료
//			break;
//
//	}
//	CloseHandle(sem);
//	closesocket(servSock);
//	WSACleanup();
//	return 0;
//}
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	ff = 2;
//	sendACK();
//	message[0] = (int)3;
//	sendto(servSock, message, 1, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr));
//	timeKillEvent(m_nTimerID);
//
//}
//void textcolor(int color_number)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
//}
//void conn()
//{
//	sem = CreateSemaphore(NULL, 1, 1, NULL);
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	servSock = socket(PF_INET, SOCK_DGRAM, 0);
//	if (servSock == INVALID_SOCKET)
//		ErrorHandling("UDP socket creation error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(9190);
//
//	if (bind(servSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//}
//void print(int cnt)
//{
//	textcolor(GREEN);
//	for (int i = 0; i < cnt; i++)
//		printf("<---패킷 %d 수신\n", pcnt++);
//	textcolor(ORI);
//	rcvn++;
//}
//void sendACK()
//{
//	textcolor(YEL);
//	printf("------------->ACK 송신\n");
//	textcolor(ORI);
//}
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}