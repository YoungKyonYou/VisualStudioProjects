//#include<iostream>
//#include<vector>
//#include<fstream>
//#define MAX 100000
//using namespace std;
//int frameNum;
//int numOfData;
//int ptr;
//int i;
//int cnt;
//vector<int> Data;
//vector<pair<int, int>> Frame(MAX);//first 개수 second 데이터
//void input()
//{
//	cout << "데이터 개수:";
//	cin >> numOfData;
//	cout << "프레임의 개수:";
//	cin >> frameNum;
//	cout << "데이터 입력:";
//	for (int i = 0; i < numOfData; i++)
//	{
//		int value;
//		cin >> value;
//		Data.push_back(value);
//	}
//	for (int i = 0; i < frameNum; i++)
//		Frame[i].first = -1;
//	cout << endl << endl;
//}
//void input_stream()
//{
//	int count_data = 0;
//	ifstream in("input-txt.txt");
//	int num = -1;
//	frameNum = 4;
//	while (in.is_open() && num != 99)
//	{
//		in >> num;
//		Data.push_back(num);
//		count_data++;
//	}
//	for (int i = 0; i < frameNum; i++)
//	{
//		Frame[i].first = -1;
//		Frame[i].second = -1;
//	}
//	//cout << "데이터 개수" << count_data<<endl;
//	numOfData = count_data;
//}
//void Show()
//{
//	//cout << "데이터>> " << Data[i] << endl;
//	for (int i = 0; i < frameNum; i++)
//	{
//		if (Frame[i].first == -1)
//			break;
//		if (i == ptr%frameNum)
//		{
//			printf("|블록번호 %d|  %2d  |\n", i, Frame[i].second);
//			continue;
//		}
//		printf("|블록번호 %d|  %2d  |\n", i, Frame[i].second);
//	}
//	cout << endl << endl;
//	cout << "적중률 = " << cnt << "/" << numOfData << endl;
//}
//void Increase(int data)
//{
//	for (int i = 0; i < frameNum; i++)
//	{
//		if (Frame[i%frameNum].second != data && Frame[i%frameNum].first != -1)
//			Frame[i%frameNum].first++;
//	}
//}
//int Overlap(int data)
//{
//	for (int j = 0; j < frameNum; j++)
//		if (data == Frame[j].second)
//		{
//			Frame[j].first = 0;
//			cnt++;
//			Increase(data);
//			return 1;
//		}
//	return 0;
//}
//void LRU()
//{
//	int idx = 0,flag=0, data=0;
//	for (i = 0; data != 99; i++)
//	{
//		data = Data[i];
//		if (data == 99)//99면 멈춘다
//			break;
//		if (Overlap(data))//프레임에 데이터가 있는지 중복 검사
//			continue;
//		if (Frame[idx%frameNum].first != -1)//데이터가 프레임에 꽉 찼다면
//		{
//			int temp = -10000;
//			idx = 0;
//			for (int i = 0; i < frameNum; i++)//횟수 검사해서 제일 안 쓰인 데이터를 찾아낸다.
//				if (temp < Frame[i%frameNum].first)
//				{
//					temp = Frame[i%frameNum].first;
//					idx = i;
//				}
//			flag = 1;
//		}
//		Frame[idx%frameNum].first = 0;
//		Frame[idx%frameNum].second = data;
//		Increase(data);
//		if (flag)
//			continue;
//		flag = 0;
//		idx++;
//	}
//}
//int main()
//{
//	input_stream();
//	LRU();
//	Show();
//}