//http://poj.org/problem?id=1321
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char map[10][10];
char map1[2][10];
int n, k;
int ans = 0;
bool hang[10];
bool lie[10];
bool vis[10][10];
void dfs(int deep)
{
	if (deep == k)
	{
		//printf("find 1\n");
		ans++;
		return;
	}
	int i, j, r;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (map[i][j] == '#'&&vis[i][j]==0&&hang[i]==0&&lie[j]==0)
			{
				//printf("map%c ,i%d , j%d ,dfs\n",map[i][j],i,j);
				hang[i] = 1; lie[j] = 1;
				//map[i][j] = '.';
				vis[i][j] = 1;
				dfs(deep + 1);
				vis[i][j] = 0;
				//map[i][j] = '#';
				hang[i] = 0; lie[j] = 0;
			}
				
		}
	}
	return;
}
int main()
{
	int i, j, r;
	while (cin >> n >> k)
	{
		ans = 0;
		memset(map, '.', sizeof(map));
		memset(vis, 0, sizeof(vis));
		if (n == -1 && k == -1)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cin >> map[i][j];
		}
		memset(hang, 0, sizeof(hang));
		memset(lie, 0, sizeof(lie));

		dfs(0);
		cout << ans << endl;
	}
	
}