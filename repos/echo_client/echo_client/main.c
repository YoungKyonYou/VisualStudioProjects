//#include "func.h"
//
//
//
//extern int exit_flag;
//extern int stage_clear_flag;
//extern int stage;
//
//int main(void) {
//
//	stage_clear_flag = 1;
//	stage = StageClearFileLoad();
//
//	for (;;) {
//		if (stage_clear_flag != 0) {
//			system("cls"); //ȭ���������
//			GameStageInit();
//			GameStateDraw();
//		}
//
//		PlayerMoveAction();
//
//		if (exit_flag != 0)break;
//	}
//	return 0;
//}