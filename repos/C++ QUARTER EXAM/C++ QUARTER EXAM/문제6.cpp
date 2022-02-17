//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Coffee
//{
//public:
//	virtual void print() = 0;//순수 가상함수는 객체 생성 불가
//	static Coffee* CreateInstance(int num);
//};
//
//class Americano :public Coffee
//{
//public:
//	virtual void print()
//	{
//		cout << "나는 Americano 객체입니다.";
//	}
//};
//class CaffeLatte :public Coffee
//{
//public:
//	virtual void print()
//	{
//		cout << "나는 CaffeLatte 객체입니다.";
//	}
//};
//class CaffeMocha :public Coffee
//{
//public:
//	virtual void print()
//	{
//		cout << "나는 CaffeMocha 객체입니다.";
//	}
//};
//
//Coffee* Coffee::CreateInstance(int num)
//{
//	if (num == 1)
//		return new Americano;
//	else if (num == 2)
//		return new CaffeLatte;
//	else if (num == 3)
//		return new CaffeMocha;
//}
//
//class CoffeeMachince
//{
//private:
//	vector<Coffee*> list;
//	vector<Coffee*>::iterator it;
//	static CoffeeMachince* instance;
//public:
//	static CoffeeMachince& getInstance()
//	{
//		if (!instance)
//		{
//			instance = new CoffeeMachince();
//		}
//		return *instance;
//	}
//	int Information()
//	{
//		int num;
//		while (1)
//		{
//			cout << "Americano (1), CaffeLatte (2), CaffeMocha (3), Exit (5): ";
//			cin >> num;
//			if (num == 5)
//			{
//				cout << "종료" << endl;
//				break;
//			}
//			else
//			{
//				CoffeeMachince::getInstance().Point(num)->print();
//				cout << endl;
//			}
//		}
//		return 0;
//	}
//	Coffee* Point(int num)
//	{
//		return Coffee::CreateInstance(num);
//	}
//};
//CoffeeMachince* CoffeeMachince::instance = NULL;
//int main(void)
//{
//	CoffeeMachince::getInstance().Information();
//	return 0;
//}
//
//
