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
	printf("---�� �켱 ����---\n");
	printf("�켱 ���� �Է�: ");
	scanf("%d",&priority);
	totalCnt = priority;
	system("cls");
	printf("���� ���� �Է�: ");
	scanf("%d", &type);
	system("cls");
	printf("---�� ���� �̸� �Է�---\n");
	for (int i = 0; i < type; i++)
	{
		printf("���� %d �̸�: ",i +1);
		scanf("%s", typeName[i]);
	}
	system("cls");
	printf("---�� ������ ���� ��---\n");
	for (int i = 0; i < type; i++)
	{
		printf("%s ���� �� �Է�: ", typeName+i);
		scanf("%d", &num[i]);
		tempNum[i] = num[i];
	}
	system("cls");
	

	printf("---���� ���ϴ� Ÿ�� �Է�---\n\n");
	for (int i = 0; i < type; i++)
	{
		printf("%s ", typeName[i]);
		printf("%d�� �Է�\n",i+1);
	}
	printf("\n");
	printf("�Է�: ");
	scanf("%d", &choice);
	system("cls");
	printf("---�� ������ ���� Ȯ�� �Է�(�� Ȯ���� �� ���� 100%������, ������ �Է� ����)---\n\n");
	for (int i = 0; i < type; i++)
	{
		printf("������ Ȯ�� �Է�-> %s�� ������ Ȯ��: ",typeName[i]);
		scanf("%d", &probability[i]);
		cur_prob += probability[i];
		if (cur_prob > 100)
		{
			printf("Ȯ���� ���� 100%�� �Ѿ����ϴ�. �ٽ� �Է����ּ���\n");
			i--;
		}
		printf("���� Ȯ�� ��: %d\n", cur_prob);
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
	printf("����: %d.%d�ۼ�Ʈ\n",can / 1000,can%1000);
	printf("�Ұ���: %d.%d�ۼ�Ʈ\n", cant/1000,cant%1000);
	_getch();
}