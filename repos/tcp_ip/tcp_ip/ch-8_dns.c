//#include<stdio.h>
//#include<stdlib.h>
//#include<WinSock2.h>
//#define MAX_BUF_SIZE 100
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main(int argc, char* argv[])
//{
//	WSADATA wsaData;
//	int ret, index;
//	struct hostent *domainInfo;
//
//
//	if (argc != 2)
//	{
//		printf("> Usage : %s <domain name>", argv[0]);
//		return 0;
//	}
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup Error");
//
//	//struct hostent=gethostbyname("www.kpu.ac.kr")
//
//	domainInfo = gethostbyname(argv[1]);
//	if (domainInfo == NULL) {
//		printf("error DNS query ����\n");
//		return 1;
//	}
//
//	//hostent ����ü ������� ���...
//	printf("> ���� ������ �̸� = %s\n", domainInfo->h_name);
//
//	printf("> ������ aliases.\n");
//	for (index = 0; domainInfo->h_aliases[index]; index++)
//	{
//		printf("- ������ alise[%d] = %s\n", index + 1, domainInfo->h_aliases[index]);
//	}
//
//	printf("> �ּ� Ÿ�� = ");
//	if (domainInfo->h_addrtype == AF_INET)
//	{
//		printf("IPv4/AF_INET\n");
//	}
//	else
//	{
//		printf("IPv6/AF_INET6\n");
//	}
//
//	printf("> �ּ� ���� = %d\n", domainInfo->h_length);
//
//	printf("> IP �ּ�");
//	for (index = 0; domainInfo->h_addr_list[index]; index++)
//	{
//		printf("- IP�ּ�[%d] = %s\n", index + 1, inet_ntoa(*((struct in_addr*)domainInfo->h_addr_list[index])));
//		//IN_ADDR->"1.2.3.4", inet_ntoa())
//	}
//
//
//	WSACleanup();
//	return 0;
//}