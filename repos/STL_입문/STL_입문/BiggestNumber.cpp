//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//bool cmp(string &a, string &b) {
//	return a + b < b + a ? true : false;
//}
//string solution(vector<int> numbers)
//{
//	string answer = "";
//	vector<string> v;
//	for (auto it=numbers.begin(); it!=numbers.end(); it++)
//		v.push_back(to_string(*it));
//	sort(v.begin(), v.end(), cmp);
//	while (!v.empty())
//	{
//		answer += v.back();
//		v.pop_back();
//	}
//	if (answer[0] == '0')
//		return "0";
//	return answer;
//}
//int main(void)
//{
//	vector<int> v;
//	v.push_back(3);
//	v.push_back(30);
//	v.push_back(34);
//	v.push_back(5);
//	v.push_back(9);
//	//v.push_back(5);
//	//v.push_back(9);
//	solution(v);
//	return 0;
//}