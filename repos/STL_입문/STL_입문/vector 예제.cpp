//#include<iostream>
//#include<vector>
//using namespace std;
//int main(void)
//{
//	vector<int> v1;//빈 컨테이너
//	vector<int> v2(10);//기본값(0)으로 초기화된 10개의 원소를 갖는다
//	vector<int> v3(10, 5);//5의 값으로 초기화된 10개의 원소를 갖는다
//
//	v1.push_back(10);//push_back 함수는 지정한 원소를 뒤에다가 넣어준다
//	v1.push_back(8);
//	v1.push_back(6);
//	v1.push_back(4);
//	v1.push_back(2);
//
//	for (auto it = v1.begin(); it != v1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	vector<int>::iterator it;
//	it = v1.begin();
//
//	v1.insert(it+3, 5);
//
//	for (auto it = v1.begin(); it != v1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}