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
//	os << "�� ���� ���̴� " << c.radius*c.radius*3.14 << "�Դϴ�." << endl;
//	return os;
//}
//int main()
//{
//	Circle c(3);
//	cout << c;
//}