//http://poj.org/problem?id=1573
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char map[1005][1005];
int n, m, s;
int vis[1005][1005];
bool flag = true;

int solve(int x, int y,int step)
{
	//printf("solve %d %d %c\n", x, y,map[x][y]);
	if (vis[x][y]!=0)
	{
		flag = false;
		printf("%d step(s) before a loop of %d step(s)\n", vis[x][y] - 1, step - vis[x][y]);
		return step;
	}
	vis[x][y] = step;
	if (x < 0 || x >= n || y < 0 || y >= m)
	{
		flag = false;
		printf("%d step(s) to exit\n", step-1);
		return 0;
	}
	
	
	if (map[x][y]=='E')
	{
		solve(x, y + 1, step + 1);
		
	}
	if (map[x][y] == 'W')
	{
		solve(x, y - 1, step + 1);
		
	}
	if (map[x][y] == 'N')
	{
		solve(x-1, y, step + 1);

	}
	if (map[x][y] == 'S')
	{
		solve(x + 1, y, step + 1);
		
	}
}
int main()
{
	int i, j, k;
	
	while (cin >> n >> m >> s)
	{
		if (!n && !m && !s)
			break;
		flag = true;
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		
		
		solve(0, s-1,1);
		
	}
}