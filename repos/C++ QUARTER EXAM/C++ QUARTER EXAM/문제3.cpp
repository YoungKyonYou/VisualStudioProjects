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
//////////////////////////////////////////////////////�̺κ��� �������� ���ÿ�
//class DominoPizza : public Pizza
//{
//public:
//	int GetWidth()
//	{
//		//�� �κп��� ������ ���� ������ �ּ����� �����ϰ� 
//		//������ �߻����� �ʵ��� �����϶�
//		return GetRadius() * GetRadius() * 3.14;//������ ���� ������ Pizza�� Circle�� ����� �� private���� ����ϰ�
//		//�ֱ� ������ GetRadius�� Pizza�� private�Լ��� �Ǿ��������.
//	}
//};
//
//int main()
//{
//	//Pizza��ü�� �������� �ʴ� ������ �ּ����� �����ϰ�
//	//������ �߻����� �ʵ��� �����϶�
//	Pizza pizza;//�ڽ� Ŭ������ ��ü�� ������ �� �θ� ��ü�� �����ڱ��� �ʱ�ȭ�� ����ؾ� �Ǵµ� ����
//	//�θ� Ŭ�������� �Ű������� �ϳ� �޴� �����ڰ� �ִµ� �̰��� �ʱ�ȭ �����ֱ� ���� ���ڸ� �����ְ� ����
//	//�ʰ� pizza ��ü �����ε� ���ڸ� �ް� ���� �ʾƼ��̴�. ���� �ذ��� ���ؼ��� pizza ��ü�� ���ڸ� �־��ְ�
//	//�θ� Ŭ�������� �ʱ�ȭ�� �ؾߵȴ�.
//}
/////////////////////////////////////////////////////////////////////////�̺κ��� �������� ���ÿ�