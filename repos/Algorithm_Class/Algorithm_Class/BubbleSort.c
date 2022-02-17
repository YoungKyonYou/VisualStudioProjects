//#include<stdio.h>
//void BubbleSort(int arr[], int len)
//{
//	int i, j;
//	int temp;
//	for (i = 0; i < len-1; i++)
//	{
//		for (j = 0; j < len-(i+1); j++)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//		for (int k = 0; k < len; k++)
//			printf("%d ", arr[k]);
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[10] = { 4,2,6,1,10,3,5,7,9,8 };
//	int len = sizeof(arr) / sizeof(int);
//	int i;
//	BubbleSort(arr,len);
//	for (i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}