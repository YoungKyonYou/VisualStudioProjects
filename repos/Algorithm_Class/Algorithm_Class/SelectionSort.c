//#include<stdio.h>
//void SelectionSort(int arr[], int len)
//{
//	int i, j;
//	int minIdx;
//	int temp;
//	for (int i = 0; i < len - 1; i++)
//	{
//		minIdx = i;
//		for (int j = i+1; j < len; j++)
//		{
//			if (arr[minIdx] > arr[j])
//				minIdx=j;
//		}
//		temp = arr[i];
//		arr[i] = arr[minIdx];
//		arr[minIdx] = temp;
//	}
//}
//int main()
//{
//	int arr[10] = { 4,2,6,1,10,3,5,7,9,8 };
//	int len = sizeof(arr) / sizeof(int);
//	int i;
//	SelectionSort(arr,len);
//	for (i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}