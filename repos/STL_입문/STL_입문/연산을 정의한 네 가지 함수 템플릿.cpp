//#include<iostream>
//#include<iterator>
//using namespace std;
//int main()
//{
//	int data[] = { 1,2,3,4,5,6 };
//	auto iter1 = begin(data);
//	//advance()
//	advance(iter1, 3);
//	cout << "네 번째 원소: " << *iter1 << endl << endl;
//	//distance()
//	cout << "data에 있는 원소의 개수: " << distance(begin(data), end(data)) << endl<<endl;
//	//next()
//	iter1 = begin(data);
//	auto fourth = next(iter1, 3);
//	cout << "첫 번째 원소: " << *iter1 << " 그리고 네 번째 원소: " << *fourth << endl<<endl;
//	//prev()
//	auto iter2 = end(data);
//	cout << "네 번째 원소: " << *prev(iter2, 3) << endl<<endl;
//	return 0;
//}