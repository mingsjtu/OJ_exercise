//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[31][31][31];
int l, r, c;
int sta1, sta2, sta3;
int dx[6] = { 1,-1,0,0,0,0};
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int res;
int minv = 100000;
bool flag = false;
void dfs(int z, int y, int x,int step)
{
	if (step > minv)
		return;
	//cout << "con" << x << y << z<<endl;
	step++;
	int i, j,res;
	int nx, ny, nz;

	for (i = 0; i < 6; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		nz = z + dz[i];
		if (nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l)
		{
			continue;
		}
		if (map[nz][ny][nx] == 'E')
		{

			flag = 1;
			if (step< minv)
			{
				minv = step;
			}
			return;
		}
		if (map[nz][ny][nx] == '.')
		{
			map[nz][ny][nx] = '#';
			dfs(nz,ny,nx,step);
			/*if (res< minv)
			{
				minv = step;
			}*/
			map[nz][ny][nx] = '.';
		}
	}

}
int main()
{
	int i, j, k;
	while (cin >> l >> r >> c) {
		if (!(l + r + c))
			break;
		minv = 100000;
		flag = false;
		for (i = 0; i < l; i++)//z
		{
			for (j = 0; j < r; j++)//y
			{
				for (k = 0; k < c; k++)//x
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						sta1 = i; sta2 = j; sta3 = k;
					}
				}
			}
		}
		dfs(sta1, sta2, sta3, 0);
		if (flag)
		{
			printf("Escaped in %d minute(s).\n", minv);
		}
		else
		{
			printf("Trapped!\n");
		}

	}
}
