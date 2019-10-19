//http://bailian.openjudge.cn/dsj2018xly/B/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
int c, m, t1;//case map time
char map[12][12];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };
bool flag;
void dfs(int i, int j, int t)//hang lie
{
	int ni, nj, r;
	if (map[i][j] == 'E')
	{
		flag = true;
		return;
	}
	if (t < t1)
	{
		for (r = 0; r < 4; r++)
		{
			ni = dx[r] + i;
			nj = dy[r] + j;
			if (ni >= 0 && ni < m&&nj >= 0 && nj <= m && map[ni][nj] != '#')
				dfs(ni, nj, t + 1);
		}
	}
}
int main()
{

	cin >> c;
	int i, j, k, si, sj;
	for (k = 0; k < c; k++)
	{
		cin >> m >> t1;
		flag = false;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
			}
		}
		dfs(si, sj, 0);
		if (flag)
				cout << "YES" << endl;
			else
			{
				cout << "NO" << endl;
			}

		
	}
}