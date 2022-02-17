//#include <iostream>
//#include<string> 
//#include<time.h>
//#include<cstdlib>
//#include<vector>
//#include<fstream>
//using namespace std;
//char* arr[1000000];
//string title[1000000];
//int salary[1000000];
//int salary_info[] = { 1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,900000,10000000 };
//int idx = 0;
//int cnt = 0;
//int compare(const void * a, const void * b);
//
//int check[10000];
//vector<int> v[1000];
//vector<int> v2;
//string title_return(int num)
//{
//	switch (num)
//	{
//	case 0:
//		return "사원";
//	case 1:
//		return "대리";
//	case 2:
//		return "과장";
//	case 3:
//		return "매니저";
//	case 4:
//		return "부장";
//	case 5:
//		return "주임";
//	case 6:
//		return "차장";
//	case 7:
//		return "반장";
//	case 8:
//		return "이사";
//	case 9:
//		return "상무";
//
//	}
//}
//void random_title()
//{
//	int num;
//	int idx = 0;
//	srand((int)time(NULL));
//		for (int i = 0; i < 1000; i++)
//		{
//			num = rand() % 10;
//			title[i]=title_return(num);
//			salary[idx++] = salary_info[num];
//		}
//}
//void allLexicographicRecur(char *str, char* data, int last, int index)
//{
//	int i, len = strlen(str);
//	for (i = 0; i < len; i++)
//	{
//		data[index] = str[i];
//		if (index == last)
//		{
//			arr[idx] = new char[10];
//			strcpy(arr[idx], data);
//			cnt++;
//			idx++;
//		}
//		else
//		{
//			allLexicographicRecur(str, data, last, index + 1);
//		}
//	}
//}
//void allLexicographic(char *str)
//{
//	int len = strlen(str);
//	char *data = (char *)malloc(sizeof(char) * (len + 1));
//	data[len] = '\0';
//	qsort(str, len, sizeof(char), compare);
//	allLexicographicRecur(str, data, len - 1, 0);
//	free(data);
//}
//int compare(const void * a, const void * b)
//{
//	return (*(char *)a - *(char *)b);
//}
//void show()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		cout << "이름:" << arr[i] << endl;
//		//cout << "직급:" << title[i] << endl;
//		//cout << "salary:" << salary[i] << endl;
//	}
//}
//void name()
//{
//
//	char str[] = "ABCDEF";
//	allLexicographic(str);
//	/*char str2[] = "FGHIJ";
//	char str3[] = "KLMNO";
//	char str4[] = "PRSTU";
//	allLexicographic(str);
//	allLexicographic(str2);
//	allLexicographic(str3);
//	allLexicographic(str4);*/
//}
//int random_workers()
//{
//	srand(clock());
//	int num = rand() % 11;
//	return num;
//}
//int checking2()
//{
//	for (int i=0; i<10000; i++)//employee 수 10000명
//	{
//		if (check[i] == -1)
//		{
//			//cout << "정체:" << i << endl;
//			return 1;
//		}
//	}
//	return 0;
//}
//void work_init()
//{
//	int okay = 0;
//	fill(check + 0, check + 10000, -1);
//	srand((int)time(NULL));
//	int i = 0;
//	int cnt = 0;
//	int employee_num = 0;
//	int flag = 0;
//	int flag2 = 0;
//	while (1)
//	{
//		int pro_num = i;
//		int n_workers = random_workers()+1;
//		while (cnt<=n_workers)
//		{
//			employee_num = rand() % 10000;
//			if (check[employee_num] == -1)
//			{
//				//cout << "employee_num: " << employee_num << endl;
//				//cout << "pro_num:" << i << endl;
//				check[employee_num] = 1;
//				if (employee_num == 0)
//					cout << "here" << endl;
//				v[i].push_back(employee_num+1);
//				cnt++;
//			}
//			if(cnt==n_workers)
//			  flag = 1;
//			int n = checking2();
//			if(n == 0)
//				break;
//		}
//		if (flag == 1)
//		{
//			i++;
//			flag = 0;
//			cnt = 0;
//		}
//		if (i == 1000)//project 수 1000
//			i = 1;
//		for (int i = 0; i < 10000; i++)//employee 수 10000명
//		{
//			if (check[i] == -1)
//			{
//				flag2 = 1;
//			}
//		}
//		if (flag2 == 0)
//			okay = 1;
//		if (okay == 1)
//		{
//			break;
//		}
//		flag2 = 0;
//	}
//	cout << endl << endl;
//	for (int i = 0; i < 10000; i++)//employee 수 10000명
//	{
//		if (check[i] == -1)
//		{
//			int value = i;
//			v2.push_back(value);
//		}
//	}
//}
//void show2()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		if (check[i] == 1)
//			cout << i << endl;
//	}
//}
//void works_for_data()
//{
//	fstream fs;
//	fs.open("works_for.csv", ios::out);
//	for (int i = 0; i < 1000; i++)
//	{
//		for (int x : v[i])
//		{
//				char str[1000];
//				strcpy(str,to_string(x).c_str());
//				strcat(str, ",");
//				strcat(str, to_string(i + 1).c_str());
//				strcat(str, "\n");
//				//cout << "test:" << str << endl;
//				int len = strlen(str);
//				fs.write(str, len);
//		}
//	}
//}
//void test() 
//{
//	for (int i = 0; i < 1000; i++)
//	{
//		for (int x : v[i])
//		{
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	work_init();
//	//random_title();
//	//name();
//	//cout << "cnt:" << cnt;
//	//show();
//	//show2();
//	//test();
//	works_for_data();
//	return 0;
//}