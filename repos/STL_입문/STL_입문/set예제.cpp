//#include<iostream>
//#include<set>
//#include<functional>//greater�Լ��� ����� ���̺귯��
//using namespace std;
//template <typename T>
//void print(std::set<T>& s) {
//	// ���� ��� ���ҵ��� ����ϱ�
//	std::cout << "[ ";
//	for (const auto& elem : s) {
//		std::cout << elem << " ";
//	}
//	std::cout << " ] " << std::endl;
//}
//int main(void)
//{
//	set<int> s;
//	s.insert(10);//������ ���� ����:����� ���� ����Ʈ��
//	s.insert(50);
//	s.insert(20);
//	s.insert(40);
//	s.insert(40);
//	s.insert(40);
//	s.insert(30);
//	for (const auto& it : s)//����Ʈ ��������
//		cout << it << " ";
//	cout << endl;
//
//	set<int, greater<int>> s2;
//	s2.insert(40);
//	s2.insert(10);
//	s2.insert(50);
//	s2.insert(60);
//	for (const auto& it : s2)//����Ʈ ��������
//		cout << it << " ";
//	cout << endl;
//}