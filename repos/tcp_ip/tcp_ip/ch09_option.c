//#include<stdio.h>
//#include<WinSock2.h>
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//int main()
//{
//	WSADATA wsaData;
//	SOCKET hSocket01, hSocket02;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup error");
//
//	printf("- SOCK_STREAM : %d\n", SOCK_STREAM);
//	printf("- SOCK_DGARM : %d\n", SOCK_DGRAM);
//	
//	hSocket01 = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	hSocket02 = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
//
//	int sockType;
//	int len;
//
//	len = sizeof(sockType);
//	getsockopt(hSocket01, SOL_SOCKET, SO_TYPE, (char*)&sockType, &len);
//	printf("> socket type (socket01) = %d \n", sockType);
//	printf("size:%d\n", sizeof(char*));
//	//getsockopt(hSocket02, SOL_SOCKET, SO_TYPE, (char*)&sockType, &len);
//	//printf("> socket type (socket02) = %d \n", sockType);
//	//���� �ּҴ� �Ȱ����� �� �ּҷ� ���� ���� ĳ���� ������ ���� �аڴ�.(char* ��� ����)
//	//int*��� ���� �� ���� �ּҷ� ���� 4����Ʈ ������ �аڴ� �̷� ���̴�.
//	//�аڴٴ� ���� ��ü�� CPU�̴� 
//
//
//	closesocket(hSocket01);
//	closesocket(hSocket02);
//	WSACleanup();
//	return 0;
//}