//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//	shared_ptr<double> pdata{ new double{999.0} };
//	*pdata = 8888.0;
//	cout << *pdata << endl;
//
//	auto pdata2 = make_shared<double>(999.0);//���� ������ �ʱ�ȭ �ϴ� �� ���� make_shared�� �Ἥ �ʱ�ȭ �ϴ°� �� ������.
//	//���� double ������ ���� �� �Ҵ�� ����Ʈ ������ ���� �� �Ҵ��� �ϱ� �����̴�
//	cout << *pdata2 << endl;
//
//	shared_ptr<double> pd{ pdata };//shared_ptr<T>�� ������ �� �ٸ� shared_ptr<T>�� �ʱ�ȭ�� �� �ִ�.
//	
//	shared_ptr<double> pdata3{ new double{999.0} };
//	shared_ptr<double> pdata4;
//	pdata4 = pdata3;
//	cout << *pdata4 << endl;
//}