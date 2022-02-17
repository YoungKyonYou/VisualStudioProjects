//#include <stdio.h>
//#include <windows.h>
//#include<conio.h>
//
//#define ON 1
//#define ONxy 2,1
//
//#define OFF 0
//#define OFFxy 6,1
//int ON_OFF_state(void);
//const int border[3][9] = {
//	{ 1,6,6,6,22,6,6,6,2 },
//	{ 5,0,0,0,5,0,0,0,5 },
//	{ 3,6,6,6,21,6,6,6,4 }
//};
//
//void gotoxy(int x, int y)
//{
//	COORD pos = { (SHORT)x, (SHORT)y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//int use_switch(void)
//{
//	int state=0;
//	int i, j;
//	for (i = 0; i<3; i++)
//	{
//		for (j = 0; j<9; j++)
//		{
//			printf("%c", border[i][j]);
//		}
//		printf("\n");
//	}
//	gotoxy(1, 3);
//	printf("ON");
//	gotoxy(5, 3);
//	printf("OFF");
//	ON_OFF_state();
//	return 0;
//}
//
//int ON_OFF_state(void)
//{
//	int state = OFF;
//	char in = 0;
//	while (1)
//	{
//		in = _getch();
//		if (in == 32)
//		{
//			if (state == OFF)
//			{
//				gotoxy(OFFxy);
//				printf(" ");
//				gotoxy(ONxy);
//				printf("O");
//				state = ON;
//			}
//
//			else if (state == ON)
//			{
//				gotoxy(ONxy);
//				printf(" ");
//				gotoxy(OFFxy);
//				printf("O");
//				state = OFF;
//			}
//			else
//				return 0;
//		}
//		else
//			break;
//	}
//	gotoxy(0, 5);
//	return state;
//}
