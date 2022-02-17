//#include<iostream>
//#include<list>
//using namespace std;
//int main(void)
//{
//	list<int> lt1;//빈 컨테이너
//	list<int> lt2(10);//기본값(0)으로 초기화된 10개의 원소를 갖는다
//	list<int> lt3(10, 5);//5의 값으로 초기화된 10개의 원소를 갖는다
//
//	lt1.push_front(3);
//	lt1.push_front(2);
//	lt1.push_front(1);
//
//	lt1.push_back(4);
//	lt1.push_back(5);
//	lt1.push_back(6);
//
//	for (auto it = lt1.begin(); it != lt1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	list<int>::iterator it;
//	list<int>::iterator it2;
//
//	it = lt1.begin();
//	it++;
//	lt1.insert(it, 10);//vector와 deque처럼 insert(it+3,10)을 할 수가 없다.
//
//	for (auto it = lt1.begin(); it != lt1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}