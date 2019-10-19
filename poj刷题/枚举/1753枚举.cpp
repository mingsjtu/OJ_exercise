//http://poj.org/problem?id=1753
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool map[4][4];
int ans = 10000;
int linx[5] = { 0,1,0,-1,0 };
int liny[5] = { 0,0,1,0,-1 };
bool ok()
{
	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (map[i][j] != map[0][0])
				return false;
		}
	}
	return true;
}
void fan(int x, int y)
{
	int i, j, k, nx, ny;
	for (i = 0; i < 5; i++)
	{
		nx = x + linx[i];
		ny = y + liny[i];
		if (nx < 0 || nx>3 || ny < 0 || ny>3)
			continue;
		map[nx][ny] = !map[nx][ny];
	}
}
void dfs(int x, int y, int bu)
{
	if (bu >= ans)
		return;
	//printf("test x%d y %d bu%d\n", x, y, bu);
	if (ok())
	{
		ans = min(ans, bu);
		return;
	}
	if (x == 0 && y == 4)
		return;
	int nx = (x + 1) % 4;
	int ny = y + (x + 1) / 4;
	dfs(nx, ny, bu);
	fan(x, y);
	dfs(nx, ny, bu+1);
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
			if (tmp == 'b')
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
			//cout << map[i][j];
		}
		//cout << endl;
	}
	
	dfs(0, 0, 0);
	//fan(0, 1);
	if (ans == 10000)
		printf("Impossible\n");
	else
		cout << ans << endl;
}