//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<queue>
//using namespace std;
//int N,M;
//queue<pair<int, int>> q;
//int p;
//int arr[101][101];
//int visited[101][101];
//int px, py;
//int cnt;
//void show()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			cout << visited[i][j]<<" ";
//		cout << endl;
//	}
//	cout << endl << endl;
//}
//void BFS(int sx, int sy)
//{
//	while (!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		show();
//		if (x == N - 1 && y == M - 1)
//		{
//			cnt++;
//		}
//		int xx[4] = { x+1,x-1,x,x };
//		int yy[4] = { y,y,y+1,y-1 };
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			x = xx[i];
//			y = yy[i];
//			if (x >= 0 && y >= 0 && visited[x][y]==0 && x<M && y<N)
//			{
//				visited[x][y] = 1;
//				q.push({ x,y });
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> N >> M>>p;
//	for (int i = 0; i < p; i++)
//	{
//		cin >> px >> py;
//		arr[px-1][py-1] = -1;
//		visited[px-1][py-1]=-1;
//	}
//	q.push({ 0, 0 });
//	visited[0][0] = 1;
//	BFS(0, 0);
//	cout << cnt << endl;
//}