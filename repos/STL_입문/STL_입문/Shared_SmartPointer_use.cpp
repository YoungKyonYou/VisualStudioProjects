//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//	shared_ptr<double> pdata{ new double{999.0} };
//	*pdata = 8888.0;
//	cout << *pdata << endl;
//
//	auto pdata2 = make_shared<double>(999.0);//위에 식으로 초기화 하는 것 보단 make_shared를 써서 초기화 하는게 더 빠르다.
//	//위는 double 변수를 위한 힙 할당과 스마트 포인터 관련 힙 할당을 하기 때문이다
//	cout << *pdata2 << endl;
//
//	shared_ptr<double> pd{ pdata };//shared_ptr<T>는 정의할 때 다른 shared_ptr<T>로 초기화할 수 있다.
//	
//	shared_ptr<double> pdata3{ new double{999.0} };
//	shared_ptr<double> pdata4;
//	pdata4 = pdata3;
//	cout << *pdata4 << endl;
//}