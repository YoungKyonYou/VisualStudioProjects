//#include<stdio.h>
//#include<WinSock2.h>
//#define MAX_BUF_SIZE 100
//int main(void)
//{
//	WSADATA winsockData;
//	if (WSAStartup(MAKEWORD(2, 2), &winsockData) != 0)
//		printf("WSAStartup Error\n");
//
//	SOCKET serverSocket;
//	serverSocket = socket(PF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN serverAddr;
//	memset(&serverAddr, 0, sizeof(serverAddr));
//	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	serverAddr.sin_port = htons(9000);
//	serverAddr.sin_family = AF_INET;
//
//	int option, len;
//	getsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&option, &len);
//	option = TRUE;
//	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&option, len);
//}