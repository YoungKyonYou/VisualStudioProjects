//#include <string>
//#include <vector>
//#include<iostream>
//#include<algorithm>
//#include<functional>
//using namespace std;
//
//string solution(vector<int> numbers)
//{
//	string s = "";
//	string answer;
//	int top = 1;
//	int real = 0;
//	int temp;
//	sort(numbers.begin(), numbers.end());
//	do {
//		for (int i = 0; i<numbers.size(); i++)
//		{
//			//	cout << numbers[i] << " ";
//			s.append(to_string(numbers[i]));
//		}
//		temp = atoi(s.c_str());
//		if (top < temp)
//		{
//			top = atoi(s.c_str());
//		}
//		s = "";
//
//	} while (next_permutation(numbers.begin(), numbers.end()));
//	//cout << "´ä: " << top << endl;
//	answer = to_string(top);
//	if (answer[0] == '0')
//		return 0;
//	return answer;
//}
//int main(void)
//{
//	vector<int> v;
//	v.push_back(6);
//	v.push_back(10);
//	v.push_back(2);
//	//v.push_back(5);
//	//v.push_back(9);
//	solution(v);
//	return 0;
//}