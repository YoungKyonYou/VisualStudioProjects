//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//static int max=5;
//int arr[200][200];
//void Alphabet(vector<int>& v1,int data)
//{
//	int sum = 0;
//	char value;
//	for (int i = 0; i <data; i++)
//	{
//		cin >> value;
//		v1[value - 65]++;
//	}
//	for (int i = 0; i < 200; i++) {
//		if (v1[i] == 0)
//			continue;
//		printf("%c: %d \n",i + 65,v1[i]);
//		sum += v1[i];
//	}
//	cout << "total:" << sum << endl;
//}
//void Number(vector<int>& v1,int data)
//{
//	int sum = 0;
//	int value;
//	for (int i = 0; i <data; i++)
//	{
//		cin >> value;
//		v1[value]++;
//	}
//	for (int i = 0; i < 200; i++) {
//		if (v1[i] == 0)
//			continue;
//		cout << i << ": " << v1[i] << endl;
//		sum += v1[i];
//	}
//	cout << "total:" << sum << endl;
//}
//void Double(int data)
//{
//	int num1;
//	int flag = 0;
//	int num2;
//	for (int i = 0; i < data; i++)
//	{
//		int d1;
//		cin >> d1;
//		num1 = d1/10;
//		num2 = d1 % 10;
//		arr[num1][num2]++;
//	}
//	cout << endl << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		for (int j = 0; j < 200; j++)
//		{
//			if (arr[i][j] == 0)
//				continue;
//			if (flag == 0) {
//				printf("%d:", i);
//				flag = 1;
//			}
//				for (int k = 0; k < arr[i][j]; k++)
//					printf("%d ", j);
//		}
//		if (flag == 0)
//			continue;
//		flag = 0;
//		cout << endl;
//	}
//}
//void Sort(int data)
//{
//	vector<int> v1;
//	int sum = 0;
//	int value;
//	for (int i = 0; i < data; i++)
//	{
//		cin >> value;
//		v1.push_back(value);
//	}
//	sort(v1.begin(), v1.end());
//	for (int i=0;i<data;i++)
//	{
//		if (i %10==0)
//			cout << endl;
//		cout << v1[i]<< " ";
//		sum ++;
//	}
//	cout << endl;
//	cout << "total:" << sum << endl;
//}
//int main(void)
//{
//	vector<int> v1(200);
//	vector<double> v2(200);
//	char value;
//	int data;
//	cout << "데이터 개수 입력: ";
//	cin >> data;
//	fill(v1.begin(),v1.end(), 0);
//
//	//Alphabet(v1,data);
//	Number(v1,data);
//	//Double(data);
//	//Sort(data);
//	return 0;
//}