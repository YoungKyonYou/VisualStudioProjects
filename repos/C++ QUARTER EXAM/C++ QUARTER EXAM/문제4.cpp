//#include <iostream>
//#include <vector>
//#include <string>
//
//
//using namespace std;
//string GeneratePreNumbers()
//{
//	string prenumbers = "254";
//	return prenumbers;
//}
////���� �Է��� ���ڿ� ����(��ǻ��)�� �����ϰ� ������ ��ȣ�� 
////���Ͽ� �ƿ�����, �ƿ��� �ƴ϶�� ���� ��Ʈ����ũ�� ������ ����ϴ� �Լ�
//void NumberBaseBall(string numbers) 
//{
//	string pn = GeneratePreNumbers();
//	int strike = 0;
//	int ball = 0;
//	int arr1[3];
//	int arr2[3];
//	for (int i = 0; i < 3; i++)
//	{
//		arr1[i] = (int)pn[i] - '0';
//		arr2[i] = (int)numbers[i] - '0';
//	}
//	if (arr1[0] != arr2[0] && arr1[1] != arr2[1] && arr1[2] != arr2[2])
//	{
//		cout << "�ƿ�!" << endl;
//		return;
//	}
//	if (arr1[0] == arr2[0] && arr1[1]== arr2[1] && arr1[2] == arr2[2])
//	{
//		cout << "��Ʈ����ũ 3ȸ �̰���ϴ�.!" << endl;
//		return;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		if (arr1[i] == arr2[i])
//			strike++;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (arr1[i] == arr2[j] && arr1[j]!=arr2[j])
//				ball++;
//		}
//	}
//	if (ball == 0 && strike != 0)
//	{
//		cout << "��Ʈ����ũ : " << strike << "ȸ" << endl;
//	}
//	else if(strike==0 && ball!=0)
//	{
//		cout << "�� : " << ball << "ȸ" << endl;
//	}
//	else
//	{
//		cout << "��Ʈ����ũ : " << strike << " " << "��: " << ball << endl;
//	}
//}
//
////������ ������ 3�ڸ� ��ȣ, �ߺ����ڰ� ������ �ȵ�
//
////�Էµ� ���ڰ� 3�ڸ�������, �ߺ����ڴ� ������ Ȯ���ϴ� �Լ�
//bool CheckValid(string numbers)
//{
//	string pnum = numbers;
//	int arr1[3];
//	for (int i = 0; i < 3; i++)
//	{
//		arr1[i] = (int)pnum[i] - '0';
//	}
//	if (arr1[0] != arr1[1] && arr1[0] != arr1[2] && arr1[1] != arr1[2])
//		return true;
//	return false;
//}
//
//
//int main()
//{
//	//����(��ǻ��)�� �����ϰ� ������ �ߺ����ھ��� 3�ڸ� ��ȣ
//	string predictNumber = GeneratePreNumbers();
//	//���� �Է��� ��ȣ
//	string numbers;
//
//	cout << "�����ȣ�� �Է��ϼ���(3�ڸ���):";
//	cin >> numbers;
//
//	if (CheckValid(numbers)) {
//		NumberBaseBall(numbers);
//	}
//	else {
//		cout << "�Էµ� ���ڰ� ��ȿ���� �ʽ��ϴ�." << endl;
//	}
//
//	return 0;
//}