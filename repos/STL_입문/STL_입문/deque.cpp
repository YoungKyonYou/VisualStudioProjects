//#include<iostream>
//#include<deque>
//using namespace std;
//int main(void)
//{
//	deque<int> dq1;//�� �����̳�
//	deque<int> dq2(10);//�⺻��(0)���� �ʱ�ȭ�� 10���� ���Ҹ� ���´�
//	deque<int> dq3(10, 5);//5�� ������ �ʱ�ȭ�� 10���� ���Ҹ� ���´�
//
//	dq1.push_front(5);
//	dq1.push_front(4);
//	dq1.push_front(3);
//	dq1.push_front(2);
//	dq1.push_front(1);
//
//	dq1.push_back(6);
//	dq1.push_back(7);
//	dq1.push_back(8);
//	dq1.push_back(9);
//	dq1.push_back(10);
//
//	for (auto it = dq1.begin(); it != dq1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	deque<int>::iterator it;
//	it = dq1.begin();
//
//	dq1.insert(it+3, 4);
//
//	for (auto it = dq1.begin(); it != dq1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}