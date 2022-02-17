#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<string.h>
using namespace std;
char* arr[1000000];
string title[1000000];
string Pro[1000];
int salary[1000000];
int salary_info[] = { 1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000 };
int idx = 0;
int cnt = 0;
int compare(const void * a, const void * b);

string title_return(int num)
{
	//switch (num)
	//{
	//case 0:
	//	return "사원";
	//case 1:
	//	return "대리";
	//case 2:
	//	return "과장";
	//case 3:
	//	return "매니저";
	//case 4:
	//	return "부장";
	//case 5:
	//	return "주임";
	//case 6:
	//	return "차장";
	//case 7:
	//	return "반장";
	//case 8:
	//	return "이사";
	//case 9:
	//	return "상무";

	//}
	switch (num)
	{
	case 0:
		return "CEO";
	case 1:
		return "COO";
	case 2:
		return "CFO";
	case 3:
		return "CIO";
	case 4:
		return "CTO";
	case 5:
		return "CMO";
	case 6:
		return "CHRO";
	case 7:
		return "CDO";
	case 8:
		return "CPO";
	case 9:
		return "CCO";

	}
}
string project_return(int num)
{

	switch (num)
	{
	case 0:
		return "Project1";
	case 1:
		return "Project2";
	case 2:
		return "Project3";
	case 3:
		return "Project4";
	case 4:
		return "Project5";
	case 5:
		return "Project6";
	case 6:
		return "Project7";
	case 7:
		return "Project8";
	case 8:
		return "Project9";
	case 9:
		return "Project10";

	}
}
void random_title()
{
	int num;
	for (int i = 0; i < 10000; i++)
	{
		num = rand() % 10;
		title[i] = title_return(num);
		salary[idx++] = salary_info[num];
	}
}
void Project_gen()
{
	int num;
	string pro = "Project";
	for (int i = 0; i < 1000; i++)
	{
		Pro[i] = pro + to_string(i+1);
	}
}
void allLexicographicRecur(char *str, char* data, int last, int index)
{
	int len = strlen(str);
	int i = strlen(str);
	for (i = 0; i < len; i++)
	{
		data[index] = str[i];
		if (index == last)
		{
			arr[idx] = new char[10];
			strcpy(arr[idx], data);
			cnt++;
			idx++;
		}
		else
		{
			allLexicographicRecur(str, data, last, index + 1);
		}
	}
}
void allLexicographic(char *str)
{
	int len = strlen(str);
	char *data = (char *)malloc(sizeof(char) * (len + 1));
	data[len] = '\0';
	qsort(str, len, sizeof(char), compare);
	allLexicographicRecur(str, data, len - 1, 0);
	free(data);
}
int compare(const void * a, const void * b)
{
	return (*(char *)a - *(char *)b);
}
void name()
{

	char str[] = "ABCDEF";
	allLexicographic(str);
	random_title();
	/*char str2[] = "FGHIJ";
	char str3[] = "KLMNO";
	char str4[] = "PRSTU";
	allLexicographic(str);
	allLexicographic(str2);
	allLexicographic(str3);
	allLexicographic(str4);*/
}
void show()
{
	for (int i = 0; i < 100000; i++)
	{
		cout << "이름:" << arr[i] << endl;
		//cout << "직급:" << title[i] << endl;
		//cout << "salary:" << salary[i] << endl;
	}
}
int main()
{
	Project_gen();
	int len;
	/*name();
	int len;
	fstream fs;
	fs.open("test.csv", ios::out);
	for (int i = 0; i < 10000; i++)
	{
		char str[1000];
		strcpy(str, to_string(i+1).c_str());
		strcat(str, ",");
		strcat(str, arr[i]);
		strcat(str, ",");
		strcat(str, title[i].c_str());
		strcat(str, ",");
		strcat(str, to_string(salary[i]).c_str());
		strcat(str, "\n");
		len = strlen(str);
		fs.write(str, len);
	}*/
	fstream fs;
	fs.open("project.csv", ios::out);
	for (int i = 0; i < 1000; i++)
	{
		char str[1000];
		strcpy(str, to_string(i + 1).c_str());
		strcat(str, ",");
		strcat(str, Pro[i].c_str());
		strcat(str, "\n");
		len = strlen(str);
		fs.write(str, len);
	}
}