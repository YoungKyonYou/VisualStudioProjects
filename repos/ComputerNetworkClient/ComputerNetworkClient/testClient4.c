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
//int flag2 = 1;
//void ErrorHandling(char* message);
//void textcolor(int color_number);
//void conn();
//void packet();
//
//void print()
//{
//	textcolor(GREEN);
//	for (int i = 0; i < cnt; i++)
//		printf("----------->��Ŷ %d\n", pcnt++);
//	textcolor(ORI);
//	//printf("pack %d��\n", cnt);
//}
//void recvACK()
//{
//	textcolor(YEL);
//	printf("<--- ACK ����\n");
//	textcolor(ORI);
//}
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
//		if (status == 1 && cnt < thresh)
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
//		else if (status == 3)//�����κ����� timeout�̹Ƿ� �׳� ack�� ����
//		{
//			message[0] = (int)1;
//			message[4] = (int)9;
//			if (thresh > cnt)
//				cnt *= 2;
//			else
//				cnt++;
//			send(sock, message, 8, 0); //�ǹ� ���� send
//			recvACK();
//		}
//		else if (status == 4)
//		{
//			pcnt -= cnt;
//			thresh = cnt / 2;
//			cnt = thresh;
//			textcolor(RED);
//			printf("<--- ACK ����\n");
//			printf("#Threshold:%d\n", thresh);
//			textcolor(ORI);
//		}
//		else if (status == 5)//�۽��� timeout
//		{
//			printf("<---ACK ����(Ÿ�Ӿƿ� �߻�)\n");
//			pcnt -= cnt;
//			thresh = cnt / 2;
//			cnt = 1;
//			textcolor(RED);
//			printf("# Threshhold=%d\n", thresh);
//			textcolor(ORI);
//		}
//	}
//}
//int main(int argc, char* argv[])
//{
//	//int flag3 = 0;
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
//		//	flag3 = !flag3;
//		}
//		else if (in == '2')//3dup
//		{
//			flag = 2;
//			message[0] = (int)cnt;
//			message[4] = (int)flag;
//			print();
//			send(sock, message, 8, 0);
//			flag = 1;
//		}
//		else if (in == '3')//timeout �߻���Ŵ
//		{
//			//flag = 3;
//			//message[0] = (int)cnt;
//			//message[4] = (int)flag;
//			//send(sock, message, 8, 0);
//
//			print();
//			flag = 1;
//			Sleep(5000);
//			printf("<---ACK ����(Ÿ�Ӿƿ� �߻�)\n");
//			/**/int temp = cnt;
//		//	if (thresh > cnt)
//				//temp /= 2;
//		//	else
//			//	temp--;
//			//printf("flag3:%d\n", flag3);
//			pcnt-= temp;
//			thresh = cnt / 2;
//			cnt = 1;
//			textcolor(RED);
//			printf("# Threshhold=%d\n", thresh);
//			textcolor(ORI);
//		//	flag3 = !flag3;
//		}
//		else if (in == '4')//����
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
