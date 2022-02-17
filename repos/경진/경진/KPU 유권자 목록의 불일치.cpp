//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> v2(2000000);
//int visited[2000000];
//int main(void)
//{
//	int num1 = 0;
//	int sum = 0;
//	int count = 0;
//	int value;
//	int idx = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> num1;
//		sum += num1;
//	}
//	for (int i = 0; i < sum; i++)
//	{
//		cin >> value;
//		visited[value]++;
//		if (visited[value] == 2)
//		{
//			v2[idx++] = value;
//			count++;
//		}
//	}
//	sort(v2.begin(), v2.begin()+count);
//	cout << count << endl;
//	for (int i = 0; i < count; i++)
//		cout << v2[i] << endl;
//}