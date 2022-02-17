//#include<iostream>
//#include<time.h>
//#include<random>
//#include<cstring>
//#include<cstdlib>
//#include<conio.h>
//using namespace std;
//int place[4];
//int cnt = 159;
//int limit[4] = { 37,35,74,146 };
//int can;
//int cant;
//void info()
//{
//	//È®·ü
//	printf("place[0]:%d\nplace[1]:%d\nplace[2]:%d\nplace[3]:%d\n", place[0], place[1], place[2], place[3]);
//	printf("total:%d\n", place[0] + place[1] + place[2] + place[3]);
//	printf("\n");
//}
//int main()
//{
//	srand((int)time(NULL));
//	for (int i = 0; i < 100000; i++)
//	{
//		while (1)
//		{
//			if (cnt == 0)
//				break;
//			int p = (rand() % 100) + 1;
//			//printf("rand:%d\n", p);
//			if (p >= 1 && p <= 40)
//			{
//				if (place[2] < limit[2])
//					place[2]++;
//				else
//					continue;
//			}
//			else if (p >= 41 && p <= 70)
//			{
//				if (place[1] < limit[1])
//					place[1]++;
//				else
//					continue;
//			}
//			else if (p >= 71 && p <= 90)
//			{
//				if (place[0] < limit[0])
//					place[0]++;
//				else
//					continue;
//			}
//			else if (p >= 91 && p <= 100)
//			{
//				if (place[3] < limit[3])
//					place[3]++;
//				else
//					continue;
//			}
//			cnt--;
//		}
//	//	info();
//		if (place[2] < limit[2])
//			can++;
//		else
//			cant++;
//		for (int j = 0; j < 4; j++)
//			place[j] = 0;
//		cnt = 159;
//	}
//
//	printf("can:%d\n", can);
//	printf("cant:%d\n", cant);
//	_getch();
//}