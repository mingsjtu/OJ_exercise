//¡¶ÍõµÀ¡·176Ò³
#include<iostream>
#include<cstdio>

using namespace std;
char map[105][105];
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int youbao = 0;
int m, n;
void check()
{

}
void dfs(int x,int y)
{
	int i, j,nx,ny;
	for (i = 0; i < 8; i++)
	{
		nx = dx[i] + x;
		ny = dy[i] + y;
		if (nx < m&&ny < n&&map[nx][ny] == '@')
		{
			map[nx][ny] = '*';
			dfs(nx, ny);
		}
	}
	
}
int main()
{
	int i,j;
	while(1)
	{
		youbao = 0;
		cin >> m >> n;
		if (!m)return 0;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				cin >> map[i][j];
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				if (map[i][j] == '@')
				{
					youbao++;
					dfs(i,j);
					map[i][j]='*';
				}
		}
		cout << youbao << endl;
		
	}
	return 0;
	
}
