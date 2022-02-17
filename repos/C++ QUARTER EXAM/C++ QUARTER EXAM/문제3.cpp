//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Circle {
//	int radius;
//public:
//	Circle(int radius) {
//		this->radius = radius;
//	}
//	int GetRadius()
//	{
//		return radius;
//	}
//};
//
//class Pizza : public Circle//
//{
//public:
//	Pizza():Circle(0)
//	{
//
//	}
//	int GetWidth()
//	{
//		return GetRadius() * GetRadius() * 3.14;
//	}
//};
//
//
//////////////////////////////////////////////////////이부분은 수정하지 마시오
//class DominoPizza : public Pizza
//{
//public:
//	int GetWidth()
//	{
//		//이 부분에서 에러가 나는 이유를 주석으로 설명하고 
//		//에러가 발생하지 않도록 수정하라
//		return GetRadius() * GetRadius() * 3.14;//에러가 나는 이유는 Pizza가 Circle를 상속할 때 private으로 상속하고
//		//있기 때문에 GetRadius는 Pizza의 private함수가 되어버려서다.
//	}
//};
//
//int main()
//{
//	//Pizza객체가 생성되지 않는 이유를 주석으로 설명하고
//	//에러가 발생하지 않도록 수정하라
//	Pizza pizza;//자식 클래스가 객체를 생성할 때 부모 객체의 생성자까지 초기화를 담당해야 되는데 지금
//	//부모 클래스에는 매개변수를 하나 받는 생성자가 있는데 이것을 초기화 시켜주기 위한 인자를 보내주고 있지
//	//않고 pizza 객체 스스로도 인자를 받고 있지 않아서이다. 오류 해결을 위해서는 pizza 객체에 인자를 넣어주고
//	//부모 클래스까지 초기화를 해야된다.
//}
/////////////////////////////////////////////////////////////////////////이부분은 수정하지 마시오