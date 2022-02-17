//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include "Console.h"
//#include<tchar.h>
//#define MAX 30
//#define START_X 14
//#define START_Y 28
//void cursor(int n) // 커서 보이기 & 숨기기
//{
//	HANDLE hConsole;
//	CONSOLE_CURSOR_INFO ConsoleCursor;
//
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	ConsoleCursor.bVisible = n;
//	ConsoleCursor.dwSize = 1;
//
//	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
//}
//typedef struct ST_OBJECT
//{
//	int x = 0;
//	int y = 0;
//	bool bActive = false;
//}OBJECT;
//
//OBJECT ST_OBJECT[MAX];
//OBJECT PLAYER;
//OBJECT BULLET[MAX];
//OBJECT bt[20];
//int bt_cnt = 0;
////별을 생성
//void Spawn()
//{
//	int i;
//	for (i = 0; i < MAX; i++)
//	{
//		if (!ST_OBJECT[i].bActive)
//		{
//			ST_OBJECT[i].x = (rand() % 15) * 2;
//			ST_OBJECT[i].y = 0;
//			ST_OBJECT[i].bActive = true;
//			break;
//		}
//	}
//}
//int EnemyProcess()
//{
//	int count = 0;
//	int i;
//	for (i = 0; i < MAX; i++)
//	{
//		if (ST_OBJECT[i].bActive)
//		{
//			count++;
//			GotoXY(ST_OBJECT[i].x, ST_OBJECT[i].y);
//			printf("☆");
//			ST_OBJECT[i].y++;
//
//			if (ST_OBJECT[i].y == PLAYER.y)
//			{
//				if (ST_OBJECT[i].x == PLAYER.x)//충돌
//					PLAYER.bActive = false;
//			}
//
//			if (ST_OBJECT[i].y > PLAYER.y)
//			{
//				ST_OBJECT[i].bActive = false;
//			}
//		}
//	}
//	return count;
//
//}
//void InputProcess()
//{
//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)//특정한 키가 상태가 어떠한지 값을 받아옴
//	{
//		PLAYER.x -= 2;
//		if (PLAYER.x < 0)
//			PLAYER.x = 0;
//	}
//	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)//https://3dmpengines.tistory.com/1246
//	{
//		PLAYER.x += 2;
//		if (PLAYER.x > 28)
//			PLAYER.x = 28;
//	}
//}
//
//void Init(void)
//{
//	PLAYER.x = START_X;
//	PLAYER.y = START_Y;
//	PLAYER.bActive = true;
//
//}
//void Update()
//{
//	if (PLAYER.bActive)
//	{
//		GotoXY(PLAYER.x, PLAYER.y);
//		printf("▲");
//	}
//	else
//	{
//		GotoXY(PLAYER.x, PLAYER.y);
//		printf("※");
//	}
//}
//int score = 0;
//void Score(void)
//{
//	if(PLAYER.bActive)
//		score++;
//	GotoXY(0, 0);
//	printf("Score : %d", score);
//}
//int main(void)
//{
//	bool flag = 0;
//	int state = 0;
//	Init();
//	srand(time(NULL));
//	cursor(0);
//	SetConsoleSize(30, 30);
//	int bx = 0, by = 0;
//	bool bullet = false;
//	while (1)
//	{
//		Clear();
//
// 		if (PLAYER.bActive)
//		{
//			Spawn();
//
//			InputProcess();
//		}
//  		if (GetAsyncKeyState(VK_SPACE) & 0x8000!=1)
//		{
//
//			bt[bt_cnt].x = PLAYER.x;
//			bt[bt_cnt].y = PLAYER.y - 1;
//			bt[bt_cnt].bActive = true;
//			bt_cnt++;
//
//		}
//		if (PLAYER.bActive)
//		{
//				for (int j = 0; j <= bt_cnt; j++)
//				{
//					if (bt[j].bActive)
//					{
//						GotoXY(bt[j].x, bt[j].y);
//						printf("＊");
//						bt[j].y--;
//						if (bt[j].y < 0)//다시 초기화 해주기 총알이 화면 끝에 다달으면
//						{
//							bt[j].x = PLAYER.x;
//							bt[j].y = PLAYER.y - 1;
//							bt[j].bActive = false;
//						}
//					}
//				}
//		}
//
//
//
//		//별 처리
//		state=EnemyProcess();
//
//		//player 출력
// 		Update();
//		Score();
//		Sleep(50);
//		if (state == 0)
//			break;
//	}
//
//
//	system("pause");
//	return 0;
//}
//
//
//
