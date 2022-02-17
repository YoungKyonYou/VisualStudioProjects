//#include<stdio.h>
//#include<WinSock2.h>
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup error");
//	char* addr1 = "1.5.7.9";
//	char* addr2 = "1.2.17.255";
//	SOCKADDR_IN		addr32;//IPv4 林家 备炼眉, IP林家, port 
//	SOCKADDR*		addrCom;//傍侩狼 林家 备炼眉
//	addr32.sin_addr.s_addr = htonl(0x1020304);
//	unsigned long conv_addr1 = inet_addr(addr1);
//	unsigned long conv_addr2 = inet_addr(addr2);
//	printf("test1 :%#lx\n", htonl(0x1020304));
//	printf("test3 :%#lx\n", htonl(htonl(0x1020304)));
//	printf("test2 :%s\n", inet_ntoa(addr32.sin_addr));
//	printf("Network ordered integer addr:%#lx \n", conv_addr1);
//	printf("Network ordered integer addr:%#lx \n", conv_addr2);
//	memset(&addr32, 0, sizeof(addr32));// 林家备炼眉 檬扁拳 by 0
//	addr32.sin_family = AF_INET;
//	//addr32.sin_addr.S_un.S_addr=inet_addr("1,2,3,4");
//	addr32.sin_addr.s_addr = inet_addr("1.2.3.4");
//	addr32.sin_port = htons(atoi(argv[1]));
//
//	
//
//
//
//
//	WSACleanup();
//}