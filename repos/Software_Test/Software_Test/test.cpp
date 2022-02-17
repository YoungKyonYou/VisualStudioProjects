//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> v;
//int arr2[100001];
//int arr[100001];
//vector<int> v2;
//int flag = 0;
//int cnt;
//void permute(int n, int k)
//{
//	do {
//		if (flag)
//		{
//			for (int i = 0; i < n; i++)
//				cout << v2[i] << " ";
//			cout << endl;
//			flag = 0;
//			cnt = 0;
//			break;
//		}
//		for (int i = 0; i < v2.size(); i++)
//		{
//			arr[i] = v2.at(i);
//		}
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[j] == v[j])
//			{
//				cnt++;
//			}
//			else
//				continue;
//		}
//		if (cnt == n)
//			flag = 1;
//		cnt = 0;
//	} while (next_permutation(v.begin(), v.end()));
//}
//
//int main(void)
//{
//	int N, K;
//	cin >> N >> K;;
//
//	for (int i = 0; i < K; i++)
//	{
//		sort(v2.begin(), v2.end());
//		for (int j = 0; j < N; j++)
//		{
//			cin >> arr[j];
//			v.push_back(arr[j]);
//		}
//		permute(N, K);
//		v.clear();
//	}
//}