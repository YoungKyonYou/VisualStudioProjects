//#include <iostream>
//using namespace std;
//
//class SelfRef
//{
//private:
//	int num;
//public:
//	SelfRef(int n) : num(n)
//	{
//		cout << "n=" << n << endl;
//		cout << "°´Ã¼»ý¼º" << endl;
//	}
//	SelfRef& Adder1(int n)
//	{
//		num += n;
//		return *this;
//	}
//	SelfRef& Adder2()
//	{
//		return *this;
//	}
//	SelfRef& ShowTwoNumber()
//	{
//		cout << num << endl;
//		return *this;
//	}
//	/*SelfRef& operator=(const int num)
//	{
//		this->num = num;
//		return *this;
//	}*/
//};
//
//int main(void)
//{
//	SelfRef obj1(3);
//	SelfRef obj2 = 10;
//
//	obj1.ShowTwoNumber();
//	obj2.ShowTwoNumber();
////	SelfRef &ref = obj.Adder1(2);
//	//obj.Adder2() = 20;//(obj.Adder2())
//
//	//obj.ShowTwoNumber();
//	//obj.ShowTwoNumber();
//	//ref.ShowTwoNumber();
//
//	//ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
//	return 0;
//}