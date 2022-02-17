//#include<iostream>
//#include<set>
//#include<functional>//greater함수가 저장된 라이브러리
//using namespace std;
//template <typename T>
//void print(std::set<T>& s) {
//	// 셋의 모든 원소들을 출력하기
//	std::cout << "[ ";
//	for (const auto& elem : s) {
//		std::cout << elem << " ";
//	}
//	std::cout << " ] " << std::endl;
//}
//int main(void)
//{
//	set<int> s;
//	s.insert(10);//데이터 저장 구조:노드기반 균형 이진트리
//	s.insert(50);
//	s.insert(20);
//	s.insert(40);
//	s.insert(40);
//	s.insert(40);
//	s.insert(30);
//	for (const auto& it : s)//디폴트 오름차순
//		cout << it << " ";
//	cout << endl;
//
//	set<int, greater<int>> s2;
//	s2.insert(40);
//	s2.insert(10);
//	s2.insert(50);
//	s2.insert(60);
//	for (const auto& it : s2)//디폴트 오름차순
//		cout << it << " ";
//	cout << endl;
//}