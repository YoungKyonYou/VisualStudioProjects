//#include<stdio.h>
//int arr[10] = { 4,2,6,1,10,3,5,7,9,8 };
//int len = sizeof(arr) / sizeof(int);
//void InsertionSort()
//{
//	int i, j=0;
//	int temp;
//	for (i = 1; i < len; i++)
//	{
//		j = i;
//		temp = arr[i];
//		while (j&&arr[j-1]>temp)
//		{
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = temp;
//	}
//}
//int main()
//{
//	int i;
//	InsertionSort(arr);
//	for (i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}