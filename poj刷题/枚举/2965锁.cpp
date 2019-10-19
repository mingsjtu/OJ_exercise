//http://poj.org/problem?id=2965
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
bool map[4][4];
int ans = 10000,res;
bool ok()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (!map[i][j])
				return false;
		}
	}
	return true;
}
void fan(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		map[x][i] = !map[x][i];
		map[i][y] = !map[i][y];
	}
	map[x][y] = !map[x][y];
}
void dfs(int x, int y, int fang, int bu)
{
	if (bu >=ans)
		return;
	if (ok())
	{
		//printf("ok\n");
		if (ans > bu)
		{
			ans = bu;
			res = fang;
		}
	}
	int nx = (x + 1) % 4;
	int ny = y + (x + 1) / 4;
	if (x == 0&&y == 4)
		return;
	dfs(nx, ny, fang, bu);
	fan(x, y);
	int hao = x + y * 4;
	dfs(nx, ny, fang + (1 << hao), bu + 1);
	//printf("fan x%d y%d , %d\n", nx, ny, fang + (1 << hao));
	fan(x, y);
}
int main()
{
	int i, j, k;
	char tmp;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cin>>tmp;
			if (tmp == '+')
			{
				map[i][j] = 0;
			}
			if (tmp == '-')
				map[i][j] = 1;
		}
	}
	
	dfs(0, 0, 0,0);
	cout << ans << endl;
	i = 0;
	while (i != 16)
	{
		int flag=res % 2;
		if (flag == 1)
		{
			//printf("i %d\n", i);
			int x = i % 4;
			int y = i / 4;
			printf("%d %d\n", x + 1, y + 1);
		}
		res=res>>1;
		i++;
	}
}