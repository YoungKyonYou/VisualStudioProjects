#include<stdio.h>
int arr[20] = { 5,1,2,3,10,14,256,5,213,72,14,36,5,23,6,34,23,61,26,46 };
//int arr[4] = { 4,2,1,3 };
//int arr2[4];
//int arr[7] = { 6,2,5,1,7,4,3 };
//int arr2[7];
int len = sizeof(arr) / sizeof(int);
void Swap(int n1, int n2)
{
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = temp;
}
int Partition(int left, int right)
{
	int pivot = arr[left];
	int l = left + 1;
	int h = right;
	while (l <= h)
	{
		while (arr[l] <= pivot &&l<=right)
			l++;
		while (arr[h] >= pivot && h>=(left+1))
			h--;
		if(l<=h)
			Swap(l,h);
	}
	Swap(left,h);
	return h;
}
void QuickSort(int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(left, right);
		QuickSort(left, pivot-1);
		QuickSort(pivot + 1, right);
	}
}
int main()
{
	int i;
	QuickSort(0, len - 1);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}