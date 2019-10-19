//《王道》180页 小狗在第T秒逃出
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[8][8];
int n, m, t;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool flag;
void dfs(int x, int y, int ct)
{
	printf("x %d,y %d, t%d ,current %c", x, y, ct, map[x][y]);
	int nx, ny, i, j;
	if (ct == t)
	{
		if (map[x][y] == 'D')
		{
			flag = true;
		}
		return;
	}
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		cout << "nx" << nx << "ny" << ny << map[nx][ny] << endl;;
		if (nx > n || nx<0 || ny>m || ny < 0)
			continue;
		if (map[nx][ny] == 'X' || map[nx][ny] == 'S')
			continue;
		if (map[nx][ny] == 'D'&&ct!=t-1)
			continue;
		if (map[nx][ny] == '.')
		{

			map[nx][ny] = 'X';
			dfs(nx, ny, ct + 1);
			map[nx][ny] = '.';
		}
		if (map[nx][ny] == 'D')
			dfs(nx, ny, ct + 1);
	}
}

int main()
{
	int i, j, r, stax, stay;
	while (1)
	{
		flag = false;
		cin >> n >> m >> t;
		if (!(n || m || t))
			return 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					stax = i;
					stay = j;
				}
			}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		dfs(stax, stay, 0);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

}