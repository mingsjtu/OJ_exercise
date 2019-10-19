//http://poj.org/problem?id=3020
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char map[45][15];
bool line[810][810];
int girl[810];
bool used[810];
int h, w;
int t;
int cnt;
int hao[45][15];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void lashou(int x, int y)
{
	int i, nx, ny;
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < h&&ny < w&&map[nx][ny] == '*'&&line[hao[x][y]][hao[nx][ny]] == 0)
		{
			line[hao[x][y]][hao[nx][ny]] = 1;
			line[hao[nx][ny]][hao[x][y]] = 1;

		}
	}
}
bool peidui(int x)
{
	int i, j, k;
	for (i = 0; i < cnt; i++)
	{
		if (line[x][i] && used[i] == 0)
		{
			used[i] = 1;
			if (girl[i] == -1 || peidui(girl[i]))
			{
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int i, j, k;
	cin >> t;
	while (t--)
	{
		int res = 0;
		memset(map, 0, sizeof(map));
		memset(girl, -1, sizeof(girl));
		memset(line, 0, sizeof(line));
		memset(used, 0, sizeof(used));
		cnt = 0;
		cin >> h >> w;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '*')
				{
					hao[i][j] = cnt;
					//line[cnt][cnt] = 1;
					lashou(i, j);
					cnt++;
				}
			}
		}
		for (i = 0; i < cnt; i++)
		{
			memset(used, 0, sizeof(used));
			if (peidui(i))
				res++;
		}
		printf("%d\n", cnt - res / 2);

	}


}