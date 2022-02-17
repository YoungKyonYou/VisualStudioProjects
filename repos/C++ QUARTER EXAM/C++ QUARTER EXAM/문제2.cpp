//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Person {
//public:
//	virtual void WhoAmI() {
//		cout << "나는 사람 입니다." << endl;
//	}
//};
//
//class Professor : public Person {
//public:
//	virtual void WhoAmI() {
//		cout << "나는 교수 입니다." << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual void WhoAmI() {
//		cout << "나는 학생 입니다." << endl;
//	}
//};
//
//class Developer : public Person {
//public:
//	virtual void WhoAmI() {
//		cout << "나는 개발자 입니다." << endl;
//	}
//};
//
//int main()
//{
//	Person* arr[5];
//	arr[0] = new Student();
//	arr[1] = new Professor();
//	arr[2] = new Student();
//	arr[3] = new Student();
//	arr[4] = new Developer();
//
//	for (int i = 0; i < 5; i++)
//		arr[i]->WhoAmI();
//
//	for (int i = 0; i < 5; i++)
//		delete arr[i];
//}