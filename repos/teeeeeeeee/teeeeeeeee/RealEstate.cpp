#include<iostream>
#include<time.h>
#include<random>
#include<cstring>
#include<conio.h>
#include<windows.h>
using namespace std;
char typeName[100][100];
int probability[100];
int num[100];
int tempNum[100];
int classify[100];
int cur_prob=0;
int type,priority,choice;
int cnt[100];
int can;
int cant;
int totalCnt;

void input()
{
	printf("---내 우선 순위---\n");
	printf("우선 순위 입력: ");
	scanf("%d",&priority);
	totalCnt = priority;
	system("cls");
	printf("종류 개수 입력: ");
	scanf("%d", &type);
	system("cls");
	printf("---각 종류 이름 입력---\n");
	for (int i = 0; i < type; i++)
	{
		printf("종류 %d 이름: ",i +1);
		scanf("%s", typeName[i]);
	}
	system("cls");
	printf("---각 종류별 세대 수---\n");
	for (int i = 0; i < type; i++)
	{
		printf("%s 세대 수 입력: ", typeName+i);
		scanf("%d", &num[i]);
		tempNum[i] = num[i];
	}
	system("cls");
	

	printf("---내가 원하는 타입 입력---\n\n");
	for (int i = 0; i < type; i++)
	{
		printf("%s ", typeName[i]);
		printf("%d번 입력\n",i+1);
	}
	printf("\n");
	printf("입력: ");
	scanf("%d", &choice);
	system("cls");
	printf("---각 종류별 선택 확률 입력(각 확률의 총 합은 100%여야함, 정수만 입력 가능)---\n\n");
	for (int i = 0; i < type; i++)
	{
		printf("종류별 확률 입력-> %s을 선택할 확률: ",typeName[i]);
		scanf("%d", &probability[i]);
		cur_prob += probability[i];
		if (cur_prob > 100)
		{
			printf("확률의 합이 100%이 넘었습니다. 다시 입력해주세요\n");
			i--;
		}
		printf("현재 확률 합: %d\n", cur_prob);
	}
	system("cls");
}
void sum()
{
	for (int i = 0; i < type; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			classify[i]+= probability[j];
		}
		classify[i]++;
	}
	//for (int i = 0; i < type; i++)
	//{
	//	printf("classify[%d]:%d\n", i, classify[i]);
	//}
}
void init()
{
	for (int i = 0; i < type; i++)
		tempNum[i] = num[i];
	totalCnt = priority;
}
void info()
{
	int total = 0;
	for (int i = 0; i < type; i++)
	{
		printf("%s:",typeName[i]);
		printf(" %d\n", tempNum[i]);
	}
	printf("total:%d\n", totalCnt);
	//printf("p:%d\n", pos);
	printf("\n\n");
}
void cal()
{
	srand((int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		while (1)
		{
			if (!totalCnt)
				break;
			int p = (rand() % 100) + 1;
			for (int j = 0; j < type; j++)
			{
				if (p < classify[j] && tempNum[j] != 0)
				{
					tempNum[j]--;
					totalCnt--;

					//info(p);
					break;
				}
				else if (p < classify[j] && tempNum[j] == 0)
					break;
			}
		}
		if (tempNum[choice-1] > 0)
			can++;
		else
			cant++;
		//info();
		init();

	}
}
int main()
{
	input();
	sum();
	cal();
	
	//printf("can:%d\n", can);
	printf("가능: %d.%d퍼센트\n",can / 1000,can%1000);
	printf("불가능: %d.%d퍼센트\n", cant/1000,cant%1000);
	_getch();
}