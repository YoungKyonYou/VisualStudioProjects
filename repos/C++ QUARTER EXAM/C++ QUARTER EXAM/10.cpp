#include<iostream>
#include<string>
using namespace std;
int fibo(int num)
{
	if (num == 1)
		return 0;
	else if (num == 2)
		return 1;
	else
		return fibo(num - 1) + fibo(num - 2);

}
int main(void)
{
	int i;
	for (i = 1; i < 15; i++)
		cout << fibo(i) << " ";
	cout << endl;
	return 0;
}