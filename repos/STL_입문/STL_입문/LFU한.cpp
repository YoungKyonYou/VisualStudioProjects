////LFU 알고리즘 2017154043 컴퓨터공학과 권한길
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#pragma warning(disable:4996)
//
//#define BLOCK_SIZE 4
////블럭을 struct 로 표현하여 count 값과 value 값을 이용함
//typedef struct {
//	int count;
//	int Frequency;
//	int value;
//}Block;
//
////int table[99] = { 0 };// 테이블에 
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
//		//블락이 꽉차지 않은 경우
//		if (!is_full())
//		{
//			if (is_hit(input[j]) == true)
//				j++;
//			//printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//
//			//false 인 경우  
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
//		//꽉찬경우
//		else {
//
//			//hit 경우
//			if (is_hit(input[j]) == true) {
//
//				j++;
//				printf("%d, %d, %d, %d", barr[0].value, barr[1].value, barr[2].value, barr[3].value);
//				printf("  hit");
//				printf("\n");
//			}
//			// 블락이 꽉 차고 hit 이 없을 때  바꾼다
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
//	printf("적중률 : %lf\n", hitrate);
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
//			//frequency 수 다른경우
//			if (smallest.Frequency != barr[k].Frequency) {
//				if (smallest.Frequency > barr[k].Frequency)// 작은것을 넣어준다 
//					smallest = barr[k];
//			}
//			//frequency 수 같을 때 
//			else {
//				if (smallest.count < barr[k].count)//카운트 큰 값이 smallest 
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
