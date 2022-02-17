//#include<stdio.h>
//#include<WinSock2.h>
//void ErrorHandling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
//void printSocketOption_Buf(SOCKET hSocket, int* sndBufSize, int* rcvBufSize, int* len);
//int main()
//{
//	WSADATA wsaData;
//	SOCKET hSocket01, hSocket02;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup error");
//	int sndBufSize, rcvBufSize;
//	int len;
//	hSocket01 = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//	hSocket02 = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	printSocketOption_Buf(hSocket01,&sndBufSize,&rcvBufSize,&len);
//
//	printf("- sndBufSize = %d, rcvBufSize = %d, len = %d \n", sndBufSize, rcvBufSize, len);
//	//새롭게 각 버퍼 크기 재설정
//	sndBufSize = sndBufSize * 3;
//	rcvBufSize = rcvBufSize * 3;
//	len = sizeof(sndBufSize);
//	setsockopt(hSocket01, SOL_SOCKET, SO_SNDBUF, (char*)&sndBufSize, len);
//	setsockopt(hSocket01, SOL_SOCKET, SO_RCVBUF, (char*)&rcvBufSize, len);
//	printSocketOption_Buf(hSocket01, &sndBufSize, &rcvBufSize, &len);
//	closesocket(hSocket01);
//	closesocket(hSocket02);
//	WSACleanup();
//	return 0;
//}
//void printSocketOption_Buf(SOCKET hSocket,int* sndBufSize,int* rcvBufSize, int* len)
//{
//	*len = sizeof(*sndBufSize);
//	getsockopt(hSocket, SOL_SOCKET, SO_SNDBUF, (char*)sndBufSize, len);
//	printf("- snd buffer size = %d\n", *sndBufSize);
//
//	getsockopt(hSocket, SOL_SOCKET, SO_RCVBUF, (char*)rcvBufSize, len);
//	printf("- rcv buffer size = %d\n", *rcvBufSize);
//
//}