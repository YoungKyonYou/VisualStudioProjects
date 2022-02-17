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
////내가 입력한 숫자와 상대방(컴퓨터)이 랜덤하게 예측한 번호와 
////비교하여 아웃인지, 아웃이 아니라면 볼과 스트라이크의 개수를 출력하는 함수
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
//		cout << "아웃!" << endl;
//		return;
//	}
//	if (arr1[0] == arr2[0] && arr1[1]== arr2[1] && arr1[2] == arr2[2])
//	{
//		cout << "스트라이크 3회 이겼습니다.!" << endl;
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
//		cout << "스트라이크 : " << strike << "회" << endl;
//	}
//	else if(strike==0 && ball!=0)
//	{
//		cout << "볼 : " << ball << "회" << endl;
//	}
//	else
//	{
//		cout << "스트라이크 : " << strike << " " << "볼: " << ball << endl;
//	}
//}
//
////상대방이 예측한 3자리 번호, 중복숫자가 있으면 안됨
//
////입력된 숫자가 3자리수인지, 중복숫자는 없는지 확인하는 함수
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
//	//상대방(컴퓨터)이 랜덤하게 생성한 중복숫자없는 3자리 번호
//	string predictNumber = GeneratePreNumbers();
//	//내가 입력할 번호
//	string numbers;
//
//	cout << "예상번호를 입력하세요(3자리수):";
//	cin >> numbers;
//
//	if (CheckValid(numbers)) {
//		NumberBaseBall(numbers);
//	}
//	else {
//		cout << "입력된 숫자가 유효하지 않습니다." << endl;
//	}
//
//	return 0;
//}