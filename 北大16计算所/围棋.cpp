//http://bailian.openjudge.cn/practice/3723/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[102][102];
bool mark[102][102];
int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cnt = 0;
void dfs(int x, int y)
{
	//cout << "dfs" << x << y << endl;
	int i, j;
	int nx, ny;
	for (i = 0; i < 4; i++)
	{
		
		nx = dx[i] + x;
		ny = dy[i] + y;
		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1)continue;
			if (mark[nx][ny] == 0 && map[nx][ny] == '.')
			{
				cnt++;
				mark[nx][ny] = 1;
				dfs(nx, ny);
			}
	}
}
int main()
{
	int i, j;
	cin >> n;
	memset(mark, 0, sizeof(mark));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> map[i][j];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (map[i][j] == 'B'&&mark[i][j] == 0)
			{
				cnt++;
				mark[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << cnt <<' '<<n*n-cnt<< endl;
}