//#include<stdio.h>
//#include<string.h>
//#include<WinSock2.h>
//#define MAX_BUF 100
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	SOCKET sock;
//	char message[MAX_BUF];
//	int strLen;
//	SOCKADDR_IN sockAddr1,servAdr;
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//
//	//소켓을 생성
//	//Loop: q or Q 입력 시 종료
//	//사용자로부터 메시지를 입력
//	//서버로 송신 echo 반환
//	//서버로부터 수신
//	if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
//		ErrorHandling("Socket Error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
//	servAdr.sin_port = htons(atoi(argv[2]));
//	servAdr.sin_family = AF_INET;
//
//
//	if (connect(sock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("Connect Error");
//	//int sockAdrSz;
//	//sockAdrSz = sizeof(sockAddr);
//	while (1)
//	{
//		fputs("Input Message:", stdout);
//		fgets(message, sizeof(message), stdin);
//		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
//			break;
//		send(sock, message,strlen(message), 0);
//	//	sendto(sock, message, strlen(message), 0, (SOCKADDR*)&sockAddr, sizeof(sockAddr));
//		//strLen=recvfrom(sock, message, MAX_BUF, 0, (SOCKADDR*)&sockAddr, &sockAdrSz);
//		strLen = recv(sock, message, sizeof(message) - 1, 0);
//		message[strLen] = 0;
//		printf("message from server:%s\n", message);
//	}
//	closesocket(sock);
//	WSACleanup();
//	return 0;
//}