//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//
//template <class BidirectionalIterator, class OutputIterator>
//OutputIterator reverse_copy_example(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result) 
//{ 
//	while (first != last)   
//		*result++ = *--last;   
//	return result; 
//}
//int main(void)
//{
//	vector<int> vec1(5);
//	vector<int> vec2;
//	list<int> lst;
//	vec2.push_back(1);
//	vec2.push_back(2);
//	vec2.push_back(3);
//	vec2.push_back(4);
//	vec2.push_back(5);
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);
//	lst.push_back(4);
//	lst.push_back(5);
//
//	//reverse_copy_example(lst.begin(), lst.end(), vec1.begin());
//	reverse_copy_example(vec2.begin(),vec2.end(),vec1.begin());
//
//	for (auto it = vec1.begin(); it != vec1.end(); ++it)
//		std::cout << ' ' << *it;
//	cout << endl;
//	return 0;
//}
