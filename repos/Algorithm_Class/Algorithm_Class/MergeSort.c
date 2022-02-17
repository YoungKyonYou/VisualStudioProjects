//#include<stdio.h>
////int arr[20] = { 5,1,2,3,10,14,256,5,213,72,14,36,5,23,6,34,23,61,26,46 };
////int arr2[20];
////int arr[4] = { 4,2,1,3 };
////int arr2[4];
//int arr[7] = { 6,2,5,1,7,4,3 };
//int arr2[7];
//int len = sizeof(arr) / sizeof(int);
//void merge(int l, int m, int r)
//{
//	int i = m;
//	int fIdx = l;
//	int j = m + 1;
//	int idx = l;
//	while (fIdx <= m && j <= r)
//	{
//		if (arr[fIdx] <= arr[j])
//			arr2[idx++] = arr[fIdx++];
//		else
//			arr2[idx++] = arr[j++];
//	}
//	if (j > r)
//	{
//		for (int k = fIdx; k <=m; k++)
//			arr2[idx++] = arr[k];
//	}
//	else
//	{
//		for (int k = j; k <=r; k++)
//			arr2[idx++] = arr[k];
//	}
//	for(int i=l;i<=r;i++)
//		arr[i]=arr2[i];
//}
//void mergeSort(int left, int right)
//{
//	if (left < right)
//	{
//		int mid = (left + right) / 2;
//		mergeSort(left, mid);
//		mergeSort(mid + 1, right);
//		merge(left, mid, right);
//	}
//}
//int main()
//{
//	int i;
//	mergeSort(0, len-1);
//	for (i = 0; i < len; i++)
//		printf("%d ", arr2[i]);
//}