//#include<iostream>
//#include<vector>
//#define MAX 100000
//using namespace std;
//int frameNum;
//int numOfData;
//int ptr;
//int i;
//int cnt;
//vector<int> Data;
//vector<pair<int, int>> Frame(MAX);//first ���� second ������
//void input()
//{
//	cout << "������ ����:";
//	cin >> numOfData;
//	cout << "�������� ����:";
//	cin >> frameNum;
//	cout << "������ �Է�:";
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
//void Show()
//{
//	cout << "������>> " << Data[i] << endl;
//	for (int i = 0; i < frameNum; i++)
//	{
//		if (Frame[i].first == -1)
//			break;
//		if (i == ptr%frameNum)
//		{
//			cout <<"Frame "<<i<<"   "<< "| " << Frame[i].first << " | " << Frame[i].second << " | " << "<---Pointer" << endl;
//			continue;
//		}
//		cout << "Frame " <<i<<"   "<< "| " << Frame[i].first << " | " << Frame[i].second <<" | "<< endl;
//	}
//	cout<<endl << endl << endl << endl;
//}
//int Overlap(int data)
//{
//	for (int j = 0; j < numOfData; j++)
//		if (data == Frame[j].second)
//		{
//			Frame[j].first++;
//			cnt++;
//			return j;
//		}
//	return -1;
//}
//void Clock_Replacement()
//{
//	int idx = 0;
//	int idx2 = 0;
//	int data;
//	for (i = 0; i < numOfData; i++)
//	{
//		data = Data[i];
//		idx2 = Overlap(data);//�ߺ� �˻�
//		if (idx2 != -1)
//		{
//			Show();
//			continue;
//		}
//		if (Frame[idx%frameNum].first != -1)//�����Ͱ� �����ӿ� �� ����
//		{
//			while (Frame[ptr%frameNum].first != 0)
//			{
//				Frame[ptr%frameNum].first--;
//				ptr++;
//			}
//			Frame[ptr%frameNum].second = data;
//			ptr++;
//			Show();
//			continue;
//		}
//		if (Frame[idx%frameNum].first == -1 && (idx%frameNum) <= (numOfData - 1)) 
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
//	input();
//	Clock_Replacement();
//	cout << "���߷� = " << cnt << "/" << numOfData << endl;
//}