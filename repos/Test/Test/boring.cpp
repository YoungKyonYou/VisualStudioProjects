//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<random>
//#include<time.h>
//int main(void)
//{
//	int ran[15];
//	int flag[10] = { 0, };
//	int high, low, num;
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 15; i++) 
//	{ 
//		num = rand() % 10;
//		flag[num]++;
//		printf("%d ", num);
//	}
//
//	printf("\n\n");
//
//	high = flag[0];
//	low = flag[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (high < flag[i])
//			high = flag[i];
//		if (low > flag[i])
//			low = flag[i];
//	}
//
//	printf("���� ���� ���¼�:\n");
//	for (int i = 0; i < 10; i++)
//		if (flag[i] == high)
//			printf("���� : %d, %d��\n",i,flag[i]);
//
//	printf("\n");
//
//	printf("���� ���� ���¼�:\n");
//	for (int i = 0; i < 10; i++)
//		if (flag[i] == low)
//			printf("���� : %d, %d��\n", i, flag[i]);
//	return 0;
//}