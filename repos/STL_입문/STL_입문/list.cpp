//#include<iostream>
//#include<list>
//using namespace std;
//int main(void)
//{
//	list<int> lt1;//�� �����̳�
//	list<int> lt2(10);//�⺻��(0)���� �ʱ�ȭ�� 10���� ���Ҹ� ���´�
//	list<int> lt3(10, 5);//5�� ������ �ʱ�ȭ�� 10���� ���Ҹ� ���´�
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
//	lt1.insert(it, 10);//vector�� dequeó�� insert(it+3,10)�� �� ���� ����.
//
//	for (auto it = lt1.begin(); it != lt1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}