//http://poj.org/problem?id=3009
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
short map[25][25];
int w, h;
int qidian[2];
int zhongdian[2];
int flag = 0;
int step = 11;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void dfs(int x, int y, int s)
{
	//printf("dfs x%d , y%d\n", x, y);
	if (s >= 10|| x < 0 || x >= h || y < 0 || y >= w)
		return;
	if (map[x][y] == 3)
	{
		s++;
		flag = 1;
		if (s < step)
		{
			step = s;
		}
		return;
	}
	int nx = x, ny = y;
	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		//nx = nx + dx[i];
		//ny = ny + dy[i];
		nx = x; ny = y;
		if (map[nx + dx[i]][ny + dy[i]] == 1)
			continue;
		
		while (map[nx + dx[i]][ny+dy[i]] != 1)
		{
			nx = nx + dx[i];
			ny = ny + dy[i];
			//printf("test nx%d ,ny %d\n", nx, ny);
			if (nx < 0 || nx >= h || ny<0 || ny>=w)
				break;
			//printf("test nx%d ny%d\n", nx, ny);

			if (map[nx][ny] == 3)
			{
				//printf("find s%d\n", s + 1);
				step = step < s + 1 ? step : s + 1;
				flag = 1;
				return;
			}

		}
		if (nx>=0&& nx<h&& ny>=0&&ny<w&&s<9)
		{
			map[nx+dx[i]][ny+dy[i]] = 0;
			//if (s < 9)
			dfs(nx, ny, s + 1);
			map[nx + dx[i]][ny + dy[i]] = 1;
		}
	}
}
int main()
{
	int i, j, k;
	while (cin >> h >> w)
	{
		if (h == 0 && w == 0)
			break;
		memset(map, 0, sizeof(map));
		step = 11;
		flag = false;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2)
				{
					qidian[0] = i;
					qidian[1] = j;
				}
				if (map[i][j] == 3)
				{
					zhongdian[0] = i;
					zhongdian[1] = j;
				}
			}
		}
		dfs(qidian[0], qidian[1], 0);
		if (step < 11)
			cout << step << endl;
		else
			cout << -1 << endl;
	}

}