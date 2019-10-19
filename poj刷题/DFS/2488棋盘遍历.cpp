//http://poj.org/problem?id=2488
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
bool vis[30][30];
int x[30];
int y[30];
int h, w;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
bool dfs(int step, int cx, int cy)
{
	if (step >=w*h )
	{
		return true;
	}
	int i, j, k;
	int nx, ny;
	for (i = 0; i < 8; i++)
	{
		
		nx = cx + dx[i];
		ny = cy + dy[i];
		//if (cx == 1 && cy == 3)
		//	printf("find nx%d,find ny%d\n", nx, ny);
		if (nx > 0 && nx <= w&&ny > 0 && ny <= h&&vis[nx][ny] == 0)
		{
			vis[nx][ny] = 1;
			x[step] = nx;
			y[step] = ny;
			if (dfs(step+1, nx, ny))
			{
				return true;
			}
			vis[nx][ny]=false;
		}
	}
	return false;
}
int main()
{
	int t,i,j,k;
	cin >> t;
	bool flag;
	int c=0;
	while (t--)
	{
		c++;
		scanf("%d %d", &h, &w);
		memset(vis, 0, sizeof(vis));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		x[0] = 1;
		y[0] = 1;
		vis[1][1] = 1;
		flag=dfs(1,1,1);
		printf("Scenario #%d:\n", c);
		if (flag)
		{
			for (i = 0; i < w*h; i++)
			{
				printf("%c%d", char(x[i] + 'A' - 1), y[i]);
			}
		}
		else
		{
			printf("impossible");
		}
		printf("\n\n");
	}
}