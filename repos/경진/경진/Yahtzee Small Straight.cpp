//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> v;
//int len = 5;
//int cnt = 0;
//int flag = 0;
//int main(void)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int value;
//		cin >> value;
//		v.push_back(value);
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < len-1; i++)
//	{
//		if (cnt == 3)
//			break;
//		if (v[i + 1] - v[i] == 0)
//			continue;
//		if (v[i + 1] - v[i] == 1)
//			cnt++;
//		else 
//			cnt = 0;
//	}
//	if (cnt == 3)
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//}