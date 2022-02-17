//#include<iostream>
//#include<memory>
//#include<string>
//using namespace std;
//int main(void)
//{
//	unique_ptr<std::string> pname1{ new std::string{"Algernon"} };
//
//	auto pname2 = std::make_unique<std::string>("Algernon");//unique_ptr<T> 객체를 생성하는 훨씬 더 좋은 방법 make_unique<T>() 함수 템플릿
//
//	auto pstr = std::make_unique<std::string>(6, '*');
//
//	unique_ptr<string> a(new string("sdfsf"));
//
//	unique_ptr<int> p1(new int(10));
//
//	unique_ptr<int[]> pnumber{ new int[10] };
//	pnumber[0] = 1;
//	pnumber[1] = 2;
//	pnumber[2] = 3;
//	for (int i = 0; i < 3; i++)
//	{
//		cout << pnumber[i] << " " << endl;
//	}
//
//	cout << *pname1 << endl;
//	
//	cout << *pname2 << endl;
//	
//	cout << *pstr << endl;
//
//	cout << *a << endl;
//
//	cout << *p1 << endl;
//}