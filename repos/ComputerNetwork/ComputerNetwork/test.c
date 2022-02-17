//#include <stdio.h>
////#include "windows.h"
////#include "mmsystem.h"
//#include <stdlib.h>
//#include<Windows.h>
//
//
//void CALLBACK TimeProc(UINT m_nTimerID, UINT uiMsg, DWORD dwUser, DWORD dw1, DWORD d2)
//{
//	printf("1초에 한번씩 발생\n");
//}
//void main()
//{
//	//타이머 실행
//
//	UINT m_nTimerID;
//
//
//	//TIME_ONESHOT은 한번만 동작
//	//TIME_PERIODIC는  1초마다 주기적으로 동작
//	m_nTimerID = timeSetEvent(1000, 0, TimeProc, (DWORD)0, TIME_PERIODIC);
//	Sleep(10000);
//
//	//타이머 종료
//	//timeKillEvent(m_nTimerID);
//}