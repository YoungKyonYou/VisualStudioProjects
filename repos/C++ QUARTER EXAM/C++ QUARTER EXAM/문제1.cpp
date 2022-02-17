//#include <iostream>
//
//using namespace std;
//
//class Circle {
//	double radius;
//public:
//	Circle(double radius) {
//		this->radius = radius;
//	}
//	friend ostream& operator<<(ostream& os, const Circle c);
//};
//ostream& operator<<(ostream& os, const Circle c)
//{
//	os << "이 원의 넓이는 " << c.radius*c.radius*3.14 << "입니다." << endl;
//	return os;
//}
//int main()
//{
//	Circle c(3);
//	cout << c;
//}