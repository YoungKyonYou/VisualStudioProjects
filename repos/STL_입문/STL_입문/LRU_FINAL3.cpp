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
//int time = 1;
//vector<int> Time;
//vector<int> refc;
//vector<int> Frame1;
//vector<int> Frame2;
//vector<int> Frame3;
//vector<int> Frame4;
//vector<bool> Occurence;
//vector<int> Data;
//vector<pair<int, int>> Frame(MAX);//first 개수 second 데이터
//void ChangeData(vector<int>& Frame)
//{
//	int temp;
//	int flag=0;
//	int idx = 0;
//	for (idx; idx < Frame.size();)
//	{
//		temp = Frame[idx];
//		idx++;
//		if (Frame.size() == idx)
//			break;
//		for(int j=idx; Frame.size()>j && Frame[j] == -1;)
//		{
//			Frame[j] = temp;
//			idx = j;
//			j++;
//			flag = 1;
//		}
//		if(flag==1)
//			idx++;
//		flag = 0;
//	}
//}
//void input_stream()
//{
//	int count_data = 0;
//	ifstream in("input-txt.txt");
//	int num = -1;
//	frameNum = 3;
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
//	numOfData = count_data-1;
//}
//void Show2()
//{
//	ChangeData(Frame1);
//	ChangeData(Frame2);
//	ChangeData(Frame3);
//	ChangeData(Frame4);
//	cout << "-------|";
//	for (int i = 0; i < numOfData; i++)
//		cout << "----|";
//	cout << endl;
//	cout << "시 간  |";
//	for (int i = 0; i < numOfData; i++)
//	{
//		printf(" %2d |",Time[i]);
//	}
//	cout << endl;
//	cout << "-------|";
//
//	for (int i = 0; i < numOfData; i++)
//		cout << "----|";
//	cout << endl;
//	cout << "데이터 |";
//	for (int i = 0; i < numOfData; i++)
//	{
//		printf(" %2d |", refc[i]);
//	}
//	cout << endl;
//	cout << "-------|";
//	for (int i = 0; i < numOfData; i++)
//		cout << "----|";
//	cout << endl;
//	cout << "Memory |";
//	for (int i = 0; i < numOfData; i++)
//	{
//		if (Frame1[i] == -1)
//		{
//			printf("        |");
//			continue;
//		}
//		printf(" %2d |", Frame1[i]);
//	}
//	cout << endl;
//	cout << "       |" ;
//	for (int i = 0; i < numOfData; i++)
//	{
//		if (Frame2[i] == -1)
//		{
//			printf("    |");
//			continue;
//		}
//		printf(" %2d |", Frame2[i]);
//	}
//	cout << endl;
//	cout << " 상태  |";
//	for (int i = 0; i < numOfData; i++)
//	{
//		if (Frame3[i] == -1)
//		{
//			printf("    |");
//			continue;
//		}
//		printf(" %2d |", Frame3[i]);
//	}
//	cout << endl;
//	cout << "       |";
//	for (int i = 0; i < numOfData; i++)
//	{
//		if (Frame4[i] == -1)
//		{
//			printf("    |");
//			continue;
//		}
//		printf(" %2d |", Frame4[i]);
//	}
//	cout << endl;
//	cout << "-------|";
//	for (int i = 0; i < numOfData; i++)
//		cout << "----|";
//	cout << endl;
//	cout << " 부재  |";
//	for (int i = 0; i < numOfData; i++)
//		cout << "    |";
//	cout << endl;
//	cout << " 여부  |";
//
//	for (int i = 0; i < numOfData; i++)
//	{
//		if (Occurence[i])
//			printf("  T |", Occurence[i]);
//		else 
//			printf("  F |", Occurence[i]);
//	}
//
//	cout << endl;
//	cout << "-------|";
//	for (int i = 0; i < numOfData; i++)
//		cout << "----|";
//	cout << endl;
//	cout << endl;
//	cout << endl;
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
//void Insert(int IDX, int data,bool occ)
//{
//	Time.push_back(time++);
//	refc.push_back(data);
//	if (IDX == 0)
//	{
//		Frame1.push_back(data);
//		Frame2.push_back(-1);
//		Frame3.push_back(-1);
//		Frame4.push_back(-1);
//	}
//	else if (IDX == 1)
//	{
//		Frame2.push_back(data);
//		Frame1.push_back(-1);
//		Frame3.push_back(-1);
//		Frame4.push_back(-1);
//
//	}
//	else if (IDX == 2)
//	{
//		Frame3.push_back(data);
//		Frame1.push_back(-1);
//		Frame2.push_back(-1);
//		Frame4.push_back(-1);
//
//	}
//	else if (IDX == 3)
//	{
//		Frame4.push_back(data);
//		Frame1.push_back(-1);
//		Frame2.push_back(-1);
//		Frame3.push_back(-1);
//
//	}
//	Occurence.push_back(occ);
//}
//int Overlap(int data)
//{
//	for (int j = 0; j < frameNum; j++)
//		if (data == Frame[j].second)
//		{
//			Frame[j].first = 0;
//			Insert(j, data, true);
//			cnt++;
//			Increase(data);
//			return 1;
//		}
//	return 0;
//}
//void LRU()
//{
//	int idx = 0, flag = 0, data = 0;
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
//		Insert(idx%frameNum, data, false);
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
//	Show2();
//}