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
//		cout << "1.전화번호 등록" << endl;
//		cout << "2.전화번호 이름으로 검색" << endl;
//		cout << "3.모든 전화번호 출력(내림차순)" << endl;
//		cout << "4.프로그램 종료" << endl;
//		cin >> sel;
//		switch (sel)
//		{
//		case 1:
//			cout << "이름을 입력해주세요:";
//			cin >> name;
//			cout << "번호를 입력해주세요:";
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
//				cout << "중복된 값입니다" << endl;
//			}
//			break;
//		case 2:
//			cout << "찾을 이름을 입력해주세요>> ";
//			cin >> f_name;
//			for (it2 = numberList.begin(); it2 != numberList.end(); it2++)
//			{
//				if (it2->name == f_name)
//				{
//					cout << "이름: " << it2->name << endl;
//				    cout<< "전화번호: " << it2->phonenum << endl;
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
//				cout << "전화번호:" << it2->phonenum << endl;
//			}
//			break;
//		case 4:
//			return 0;
//			break;
//		default:
//			cout << "잘못선택하셨습니다." << endl;
//			break;
//		}
//	}
//		cout << "계속 진행하시려면 아무키나 누르세요";
//		_getch();
//		system("cls");
//	}
