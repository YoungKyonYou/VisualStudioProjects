//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//#include<string.h>
//#include<map>
//#include<functional>
//using namespace std;
//map<string, int> m;
//vector<pair<pair<string, int>, int>> v;
//vector<pair<pair<string, int>,int>> v3;
//vector<pair<pair<string, int>, int>> v2[1001];
//int N;
//int idx;
//bool cmp(const pair<pair<string, int>,int>& n1, pair<pair<string, int>, int>& n2)
//{
//	return n1.first.first < n2.first.first;
//}
//bool cmp2(const pair<pair<string, int>, int>& n1, pair<pair<string, int>, int>& n2)
//{
//	if(n1.first.first==n2.first.first)
//		return n1.first.second > n2.first.second;
//}
//bool cmp3(const pair<pair<string, int>, int>& n1, pair<pair<string, int>, int>& n2)
//{
//	if(n1.first.first==n2.first.first)
//		if (n1.first.second == n2.first.second)
//			return n1.second > n2.second;
//}
//
//int main(void)
//{
//	int N;
//	string s;
//	int num;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> s >> num;
//		m[s]+= num;
//		v.push_back(make_pair(make_pair(s, num), i));
//	}
//	sort(v.begin(), v.end(), cmp);
//	sort(v.begin(), v.end(), cmp2);
//	sort(v.begin(), v.end(), cmp3);
//	//for (auto it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << "first: " << it->first.first << " second: " << it->first.second << " " << it->second << endl;
//	//}
//	//for (int i = 0; i < v.size(); i++)
//	//{
//	//	v3.push_back(v[i]);
//	//}
//	for (auto it = v3.begin(); it != v3.end(); it++)
//	{
//		cout << "first: " << it->first.first << " second: " << it->first.second << " third: " << it->second << endl;
//	}
//	for (auto it = --m.end(); it!=--m.begin(); it--)
//	{
//		for (int j = 0; j < v.size(); j++)
//		{
//			if (it->first == v[j].first.first)
//			{
//				v3.push_back(v[j]);
//			}
//		}
//	}
//	cout << endl << endl;
//	for (auto it = v3.begin(); it != v3.end(); it++)
//	{
//		cout << "first: " << it->first.first << " second: " << it->first.second << " third: " << it->second << endl;
//	}
//}