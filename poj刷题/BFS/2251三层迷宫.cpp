//http://poj.org/problem?id=2251
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char map[35][35][35];
int h, x, y;
int sdian[3], edian[3];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
bool vis[35][35][35];
struct sta
{
	int x, y, z, s;
};
int res = 100000;
void bfs()
{
	queue<sta> q1;
	sta s1;
	int i, j, k;
	s1.x = sdian[0];
	s1.y = sdian[1];
	s1.z = sdian[2];
	s1.s = 0;
	map[s1.x][s1.y][s1.z] = '#';
	int nx, ny, nz;
	q1.push(s1);
	while (!q1.empty())
	{
		s1=q1.front();
		q1.pop();

		for (i = 0; i < 6; i++)
		{
			nx = s1.x + dx[i];
			ny = s1.y + dy[i];
			nz = s1.z + dz[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= x || nz < 0 || nz >= y || map[nx][ny][nz] == '#')
				continue;
			//printf("check i%d,j%d,k%d is map%c\n", nx, ny, nz, map[nx][ny][nz]);

			if (map[nx][ny][nz] == 'E')
			{
				res = min(res, s1.s + 1);
				return;
			}
			map[nx][ny][nz] = '#';
			sta s2;
			s2.x = nx;
			s2.y = ny;
			s2.z = nz;
			s2.s = s1.s + 1;
			q1.push(s2);
		}
	}
	

}
int main()
{
	int i, j, k;
	while (scanf("%d %d %d", &h, &x, &y) != EOF)
	{
		res = 100000;
		memset(map, 0, sizeof(map));
		//printf("get h%d,x%d,y%d\n", h, x, y);
		if (h == 0 && x == 0 && y == 0)
			break;
		//getchar();
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < x; j++)
			{
				for (k = 0; k < y; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						sdian[0] = i;
						sdian[1] = j;
						sdian[2] = k;
					}
					//scanf("%c", &map[i][j][k]);
					if (map[i][j][k] == 'E')
					{
						edian[0] = i;
						edian[1] = j;
						edian[2] = k;
					}
				}


			}
		}
		//cout << "get" << endl;
		bfs();
		if (res != 100000)
		{
			printf("Escaped in %d minute(s).\n", res);
		}
		else
			printf("Trapped!\n");


	}
}