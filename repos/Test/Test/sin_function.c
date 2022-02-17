//#include<stdio.h>
//#include<math.h>
//#define PH 3.1415926535
//#define BUF_SIZE 1024
//void sin_degree(int i, int x, double si);
//int main(void)
//{
//	int i = 0;
//	double si = 0;
//	int x = 0;
//	sin_degree(i, x, si);
//}
//void sin_degree(int i, int x, double si)
//{
//	char buf[BUF_SIZE];
//	char buf2[255];
//	char temp[100];
//	int index = 0;
//	int strLLen;
//	int cnt = 0;
//	for (i = 0; i <= 720; i += 20)
//	{
//		si = sin((PH*i) / 180, 0);
//
//		for (x = -15; x < si * 16; x++)
//		{
//			buf[index++] = '-';
//			cnt++;
//		}
//		buf[index++] = '0';
//		buf[index++] = '\n';
//		//buf[index] = '\0';
//		//printf(buf);
//		//	strLLen = strlen(buf);
//		//	buf2[0] = (char)strlen(buf);
//		//	buf2[1] = '0';
//		////	printf("test:%d and cnt:%d\n", (int*)buf2[0],cnt);
//
//		//	send(clnt, buf2, 1, 0);
//
//
//		//	send(clnt, buf, strLLen+1, 0);
//	}
//	buf[index] = '\0';
//	printf(buf);
//	//send(clnt, EOF, 1, 0);
//}