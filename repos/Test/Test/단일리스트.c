//#include <stdio.h>
//#include <time.h>
//#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
//#define MAX 80000
//int arr[MAX];
//int array1[MAX];
//int array2[MAX];
//int array3[MAX];
//int array4[MAX];
//int cnt = 0;
//
//// ���� �����
//void count()
//{
//	FILE* stream;
//	stream = fopen("Data3.txt", "r");
//	int i = 0;
//	while (!feof(stream))
//	{
//		int num;
//		fscanf(stream, "%d", &num);
//		array1[i] = num;
//		array2[i] = num;
//		array3[i] = num;
//		array4[i++] = num;
//		cnt++;
//	}
//	fclose(stream);
//}
//
//// ���� ���� �˰���
//void insertion_sort(int array[], int n)
//{
//	int i, j, key;
//	for (i = 1; i < n; i++) {
//		key = array[i];
//		for (j = i - 1; j >= 0 && array[j] > key; j--) {
//			// ��������
//			// for (j = i - 1; j >= 0 && array[j] < key; j--)
//			array[j + 1] = array[j];
//		}
//		array[j + 1] = key;
//	}
//}
//
//// ���� ���� �˰���
//void selection_sort(int list[], int n)
//{
//	int i, j, least, temp;
//
//
//	for (i = 0; i<n - 1; i++) {
//		least = i;
//		for (j = i + 1; j<n; j++)
//			if (list[j]<list[least]) least = j;
//		SWAP(list[i], list[least], temp);
//	}
//}
//
//// ���� ���� �˰���
//void bubble_sort(int list[], int n)
//{
//	int i, j, temp;
//	for (i = n - 1; i>0; i--) {
//		for (j = 0; j<i; j++)
//			if (list[j]>list[j + 1])
//				SWAP(list[j], list[j + 1], temp);
//	}
//}
//
//// �� ���� �˰���
//inc_insertion_sort(int list[], int first, int last, int gap)
//{
//	int i, j, key;
//
//	for (i = first + gap; i <= last; i = i + gap) {
//		key = list[i];
//		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
//			list[j + gap] = list[j];
//		list[j + gap] = key;
//	}
//
//}
//void shell_sort(int list[], int n)   // n = size
//{
//	int i, gap;
//	for (gap = n / 2; gap>0; gap = gap / 2) {
//		if ((gap % 2) == 0) gap++;
//		for (i = 0; i<gap; i++)
//			inc_insertion_sort(list, i, n - 1, gap);
//	}
//}
//
////// ����Ʈ �Լ�
////void print()
////{
////   for (int i = 0; i < cnt; i++) {
////      printf("%d,\n", arr[i]);
////   }
////}
//void print()
//{
//	for (int i = 0; i < cnt; i++)
//	{
//		printf("%d %d %d %d\n", array1[i], array2[i], array3[i],array4[i]);
//	}
//}
//int main(void)
//{
//	clock_t start1, start2, start3, start4, end1, end2, end3, end4;
//	float res1, res2, res3, res4;
//	// ���� �Է�
//	count();
//
//	//��������
//	start1 = clock();
//	insertion_sort(array1, cnt);
//	end1 = clock();
//	res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
//
//	//��������
//	start2 = clock();
//	selection_sort(array2, cnt);
//	end2 = clock();
//	res2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
//
//	// ���� ����
//	start3 = clock();
//	bubble_sort(array3, cnt);
//	end3 = clock();
//	res3 = (float)(end3 - start3) / CLOCKS_PER_SEC;
//
//	// �� ����
//	start4 = clock();
//	shell_sort(array4, cnt);
//	end4 = clock();
//	res4 = (float)(end4 - start4) / CLOCKS_PER_SEC;
//	print();
//	// ���� �ð�
//	printf("�������� �� ����Ǵ� �ð� : %.3f\n", res1);
//	printf("�������� �� ����Ǵ� �ð� : %.3f\n", res2);
//	printf("�������� �� ����Ǵ� �ð� : %.3f\n", res3);
//	printf("������ �� ����Ǵ� �ð� : %.3f\n", res4);
//	return 0;
//}