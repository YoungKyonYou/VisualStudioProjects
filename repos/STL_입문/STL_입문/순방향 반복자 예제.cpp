//#include<iostream>
//#include<vector>
//using namespace std;
//
//template <class ForwardIterator, class T> 
//void replace_example(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value) 
//{ 
//	while (first != last) 
//	{
//		if (*first == old_value)
//			*first = new_value;  
//		++first;
//	} 
//}
//
//int main(void)
//{
//	vector<int> vec1;
//
//	vec1.push_back(5);
//	vec1.push_back(6);
//	vec1.push_back(6);
//	vec1.push_back(6);
//	vec1.push_back(7);
//	vec1.push_back(8);
//
//	vector<int>::iterator it = vec1.begin();
//
//	replace_example(vec1.begin(),vec1.end(),6,11);
//
//	for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
//		std::cout << ' ' << *it;
//	cout << endl;
//	return 0;
//}
