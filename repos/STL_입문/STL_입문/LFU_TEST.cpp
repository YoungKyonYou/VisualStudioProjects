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
//
//	cout << "데이터 개수" << count_data<<endl;
//	numOfData = count_data;
//}
//void Show()
//{
//	cout << "데이터>> " << Data[i] << endl;
//	for (int i = 0; i < frameNum; i++)
//	{
//		if (Frame[i].first == -1)
//			break;
//		if (i == ptr%frameNum)
//		{
//			cout << "Frame " << i << "   " << "| " << Frame[i].first << " | " << Frame[i].second << " | " << endl;
//			continue;
//		}
//		cout << "Frame " << i << "   " << "| " << Frame[i].first << " | " << Frame[i].second << " | " << endl;
//	}
//	cout << endl << endl << endl << endl;
//}
//int Overlap(int data)
//{
//	for (int j = 0; j < frameNum; j++)
//		if (data == Frame[j].second)
//		{
//			Frame[j].first++;
//			cnt++;
//			return j;
//		}
//	return -1;
//}
//void LFU()
//{
//	int idx = 0;
//	int idx2 = 0;
//	int data;
//	data = Data[i];
//	for (i = 0; data != 99; i++)
//	{
//		data = Data[i];
//		if (data == 99)
//			break;
//		idx2 = Overlap(data);//중복 검사
//		if (idx2 != -1)
//		{
//			Show();
//			continue;
//		}
//		if (Frame[idx%frameNum].first != -1)//데이터가 프레임에 꽉 차면
//		{
//			int temp = 1000000;
//			int idx = 0;
//			for (int i = 0; i < frameNum; i++)
//			{
//				if (temp > Frame[i%frameNum].first)
//				{
//					temp = Frame[i%frameNum].first;
//					idx = i%frameNum;
//				}
//				else if (temp == Frame[i%frameNum].first)
//					continue;
//			}
//			Frame[idx].first = 0;
//			Frame[idx].second = data;
//			Show();
//			continue;
//		}
//		if (Frame[idx%frameNum].first == -1 && (idx%frameNum) <= (numOfData - 1))//프레임에 다 안 찼을 경우
//		{
//			Frame[idx%frameNum].first = 0;
//			Frame[idx%frameNum].second = data;
//			idx++;
//			Show();
//		}
//	}
//}
//int main()
//{
//	input_stream();
//	//input();
//	LFU();
//	cout << "적중률 = " << cnt << "/" << numOfData << endl;
//}