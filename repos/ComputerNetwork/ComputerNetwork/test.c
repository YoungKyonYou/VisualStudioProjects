//#include <stdio.h>
////#include "windows.h"
////#include "mmsystem.h"
//#include <stdlib.h>
//#include<Windows.h>
//
//
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	printf("1�ʿ� �ѹ��� �߻�\n");
//}
//void main()
//{
//	//Ÿ�̸� ����
//
//	UINT m_nTimerID;
//
//
//	//TIME_ONESHOT�� �ѹ��� ����
//	//TIME_PERIODIC��  1�ʸ��� �ֱ������� ����
//	m_nTimerID = timeSetEvent(1000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//	Sleep(10000);
//
//	//Ÿ�̸� ����
//	//timeKillEvent(m_nTimerID);
//}