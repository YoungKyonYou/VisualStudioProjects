//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//	weak_ptr<int> pData = make_shared<int>(10);//weak_ptr<T>는 shared_ptr<T>에서 생성하거나 다른 weak_ptr<T>에서 생성할 수 있다
//	weak_ptr<int> pwData{ pData };
//	weak_ptr<int> pwData2{ pwData };
//	//약한 포인터로는 할 수 있는 게 많지 않다.
//	//즉 약한 포인터가 가리키는 객체는 역참조해서 접근할 수 없다.
//	return 0;
//}