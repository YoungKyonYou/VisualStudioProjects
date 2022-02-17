//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//template <class T> 
//void swap_example(T& a, T& b)
//{
//	T c(a); 
//	a = b; 
//	b = c;
//}
//template <class ForwardIterator1, class ForwardIterator2>
//void iter_swap_example(ForwardIterator1 a, ForwardIterator2 b)
//{
//	swap_example(*a, *b);
//}
//unsigned int randomInteger(unsigned int n) 
//{
//	return rand() % n;
//}
//template <class RandomAccessIterator>
//void mixup(RandomAccessIterator first, RandomAccessIterator last)
//{
//	while (first < last) {
//		iter_swap_example(first, first + randomInteger(last - first));
//		for (auto it = first; it != last; it++)
//			printf("%d ", *it);
//		printf("\n");
//		++first;
//	}
//}
//int main(void)
//{
//	vector<int> vec1;
//
//	vec1.push_back(1);
//	vec1.push_back(2);
//	vec1.push_back(3);
//	vec1.push_back(4);
//	vec1.push_back(5);
//
//	mixup(vec1.begin(), vec1.end());
//
//	for (auto it = vec1.begin(); it != vec1.end(); ++it)
//		std::cout << ' ' << *it;
//	cout << endl;
//	return 0;
//}
