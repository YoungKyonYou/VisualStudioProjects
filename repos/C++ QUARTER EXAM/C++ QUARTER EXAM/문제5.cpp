//#include <iostream>
//#include <list>
//#include <string>
//#include<algorithm>
//#include <conio.h>
//
//using namespace std;
//
//struct PhoneNumber {
//	int phonenum;
//	string name;
//	PhoneNumber(int phonenum, string name) {
//	   this->phonenum = phonenum;
//	   this->name = name;
//	}
//};
//bool operator==(const PhoneNumber& s1, const PhoneNumber& s2) {
//	return s1.phonenum == s2.phonenum;
//}
////bool equal(const PhoneNumber* ph,string name)
////{
////	if (ph->name == name)
////		return true;
////	else
////		return false;
////}
//int main()
//{
//	string f_name;
//	list<PhoneNumber> numberList;
//	list<PhoneNumber>::iterator it2;
//	int num;
//	string name;
//	while (true)
//	{
//		int sel = 0;
//		cout << "1.��ȭ��ȣ ���" << endl;
//		cout << "2.��ȭ��ȣ �̸����� �˻�" << endl;
//		cout << "3.��� ��ȭ��ȣ ���(��������)" << endl;
//		cout << "4.���α׷� ����" << endl;
//		cin >> sel;
//		switch (sel)
//		{
//		case 1:
//			cout << "�̸��� �Է����ּ���:";
//			cin >> name;
//			cout << "��ȣ�� �Է����ּ���:";
//			cin >> num;
//			if (find(numberList.begin(), numberList.end(), PhoneNumber(num, "")) == numberList.end())
//			{
//				if (numberList.size() == 0)
//					numberList.push_front((PhoneNumber(num, name)));
//				else
//				{
//					auto it = numberList.begin();
//					numberList.insert(it, PhoneNumber(num, name));
//				}
//			}
//			else
//			{
//				cout << "�ߺ��� ���Դϴ�" << endl;
//			}
//			break;
//		case 2:
//			cout << "ã�� �̸��� �Է����ּ���>> ";
//			cin >> f_name;
//			for (it2 = numberList.begin(); it2 != numberList.end(); it2++)
//			{
//				if (it2->name == f_name)
//				{
//					cout << "�̸�: " << it2->name << endl;
//				    cout<< "��ȭ��ȣ: " << it2->phonenum << endl;
//					cout << endl;
//				}
//			}
//			break;
//		case 3:
//			numberList.sort([](PhoneNumber a, PhoneNumber b) {
//				return a.phonenum > b.phonenum;
//			});
//			for (it2 = numberList.begin(); it2 != numberList.end(); it2++)
//			{
//				cout << "��ȭ��ȣ:" << it2->phonenum << endl;
//			}
//			break;
//		case 4:
//			return 0;
//			break;
//		default:
//			cout << "�߸������ϼ̽��ϴ�." << endl;
//			break;
//		}
//	}
//		cout << "��� �����Ͻ÷��� �ƹ�Ű�� ��������";
//		_getch();
//		system("cls");
//	}
