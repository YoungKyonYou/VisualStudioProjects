////LFU �˰��� 2017154043 ��ǻ�Ͱ��а� ���ѱ�
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#pragma warning(disable:4996)
//
//#define BLOCK_SIZE 4
////���� struct �� ǥ���Ͽ� count ���� value ���� �̿���
//typedef struct {
//	int count;
//	int Frequency;
//	int value;
//}Block;
//
////int table[99] = { 0 };// ���̺� 
//Block barr[BLOCK_SIZE] = { NULL };
//double F, Hit = 0;
//
//void Plus_count();
//void best(int input);
//bool is_full();
//bool is_hit(int input);
//
//int main()
//{
//	FILE *fp;
//	fp = fopen("input-txt.txt", "r");
//	int i = 0, j = 0, k = 0;
//	double hitrate = 0;
//	int input[30];
//	do {
//		fscanf(fp, "%d", input + i);
//		printf("%d  ", input[i]);
//		i++;
//	} while (input[i - 1] != 99);
//	printf("\n");
//
//	while (input[j] != 99) {
//		Plus_count();
//
//		if (k>3)
//			k = 0;
//		//����� ������ ���� ���
//		if (!is_full())
//		{
//			if (is_hit(input[j]) == true)
//				j++;
//			//printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//
//			//false �� ���  
//			else {
//				barr[k].value = input[j];
//				barr[k].count = 0;
//				barr[k].Frequency = 1;
//				F++;
//				j++;
//				k++;
//
//				printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//				printf("  Fault");
//				printf("\n");
//			}
//		}
//
//		//�������
//		else {
//
//			//hit ���
//			if (is_hit(input[j]) == true) {
//
//				j++;
//				printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//				printf("  hit");
//				printf("\n");
//			}
//			// ����� �� ���� hit �� ���� ��  �ٲ۴�
//			else
//			{
//				best(input[j]);
//				j++;
//				printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//				printf("  Fault");
//				printf("\n");
//			}
//			/*else {
//			j++;
//
//			printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//			printf("  Fault");
//			printf("\n");
//			}*/
//		}
//
//	}
//
//	//printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//	hitrate = (Hit) / (Hit + F);
//	printf("���߷� : %lf\n", hitrate);
//
//	system("pause");
//	return 0;
//}
//bool is_full() {
//	int i;
//	int count = 0;
//	for (i = 0; i < BLOCK_SIZE; i++)
//	{
//		if (barr[i].value != NULL)
//			count++;
//	}
//
//	if (count >= BLOCK_SIZE - 1)
//		return true;
//	else
//		return false;
//}
//
//
//void best(int input) {
//	Block change;
//	Block smallest;
//	//   int oldest,oldestindex;
//	int i = 1;
//	int j = 0;
//	int k = 1;
//	int value;
//	//table compare  all same or what is best
//	//if all same,  compare count
//	if ((barr[0].Frequency == barr[1].Frequency == barr[2].Frequency == barr[3].Frequency)) {
//		change = barr[0];
//		for (i = 1; i < BLOCK_SIZE; i++) {
//			if (change.count < barr[i].count)
//				change = barr[i];
//		}
//		value = change.value;
//
//		while (value != barr[j].value) {
//			j++;
//		}
//		barr[j].value = input;
//		barr[j].count = 0;
//		barr[j].Frequency = 1;
//		F++;
//
//	}
//
//	//not all same, find  smallest , oldes 
//	else {
//		smallest = barr[0];
//		for (k = 1; k < BLOCK_SIZE; k++) {
//			//frequency �� �ٸ����
//			if (smallest.Frequency != barr[k].Frequency) {
//				if (smallest.Frequency > barr[k].Frequency)// �������� �־��ش� 
//					smallest = barr[k];
//			}
//			//frequency �� ���� �� 
//			else {
//				if (smallest.count < barr[k].count)//ī��Ʈ ū ���� smallest 
//					smallest = barr[k];
//			}
//		}
//		value = smallest.value;
//
//		while (value != barr[j].value) {
//			j++;
//		}
//
//		barr[j].value = input;
//		barr[j].count = 1;
//		barr[j].Frequency = 1;
//		F++;
//	}
//}
//
//void Plus_count() {
//	int i;
//	for (i = 0; i < BLOCK_SIZE; i++) {
//		barr[i].count++;
//	}
//}
//bool is_hit(int input) {
//	int i;
//	for (i = 0; i < BLOCK_SIZE; i++) {
//		if ((barr[i].value == input) && (barr[i].Frequency != 0)) {
//			Plus_count();
//			Hit++;
//			//   printf("hit");
//			barr[i].Frequency++;
//			return true;
//		}
//	}
//
//	return false;
//}
//
