#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int visited[10000];
vector<int> v;
vector<int> v2;
int main(void)
{
	int num;
	int cnt = 0;
	cin >> num;
	int data = 0;
	int idx = 1;
	int start = 0;
	int end = 0;
	for (int i = 0; i < num; i++)
	{
		int value;
		cin >> value;
		v.push_back(value);
	}
	while (1)
	{
		v2.push_back(idx);
		visited[idx] = 1;
		start = idx;
		while (v[idx-1]!=start)
		{
			v2.push_back(v[idx - 1]);
			visited[v[idx - 1]] = 1;
			idx = v[idx - 1];
		}
		v2.push_back(start);


		for (int i = 1; i <=num; i++)
		{
			if (visited[i] == 0)
			{
				cnt++;
				idx = i;
				break;
			}
			if(i==num)
				end = 1;
		}
		if (end == 1)
			break;
	}
	int j = 0;
	cout << cnt+1 << endl;
	int index = 0;
	int flag3 = 0;
	for (int i = 0; i < cnt+1; i++)
	{
		start = v2[j];
		while(1)
		{
			cout << v2[j];
			if (v2[j] == start && flag3 == 1)
			{
				j++;
				break;
			}
			cout << " ";
			flag3 = 1;
			j++;
		}
		flag3 = 0;
		cout << endl;
	}
}