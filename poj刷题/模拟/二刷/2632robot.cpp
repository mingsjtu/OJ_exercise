//http://poj.org/problem?id=2632
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
int a, b;
int x[105], y[105], ori[105];
char name[4] = { 'E','N','W','N' };
int map[105][105];
bool solve(int index, char com, int rep)
{
	//printf("biao %d\n", index);
	int i, j, k;
	switch (com)
	{
	case 'R':
		ori[index] += rep;
		ori[index] %= 4;
		break;
	case 'L':
		ori[index] -= rep;
		ori[index]+=800;
		ori[index] %= 4;
		break;
	case 'F':
		int nx=x[index], ny=y[index];
		switch (ori[index])
		{
		case 0:
			for (i = 0; i < rep; i++)
			{
				ny++;
				//printf("index %d,nx %d,ny %d\n", index, nx, ny);

				if (ny <= 0 || ny > a)
				{
					printf("Robot %d crashes into the wall\n",index);
					return false;
				}
				if (map[nx][ny] != 0)
				{
					printf("Robot %d crashes into robot %d\n", index, map[nx][ny]);
					return false;
				}
			}
			map[nx][ny] = index;
			x[index] = nx;
			y[index] = ny;
			break;
		case 1:
			for (i = 0; i < rep; i++)
			{
				nx--;
				//printf("index %d,nx %d,ny %d\n", index, nx, ny);

				if (nx <= 0 || nx > b)
				{
					printf("Robot %d crashes into the wall\n", index);

					return false;
				}
				if (map[nx][ny] != 0)
				{
					printf("Robot %d crashes into robot %d\n", index, map[nx][ny]);
					return false;
				}
			}
			map[nx][ny] = index;
			x[index] = nx;
			y[index] = ny;
			break;
		case 2:
			for (i = 0; i < rep; i++)
			{
				ny--;
				//printf("index %d,nx %d,ny %d\n", index, nx, ny);

				if (ny <= 0 || ny > a)
				{
					printf("Robot %d crashes into the wall\n", index);

					return false;
				}
				if (map[nx][ny] != 0)
				{
					printf("Robot %d crashes into robot %d\n", index, map[nx][ny]);
					return false;
				}
			}
			map[nx][ny] = index;
			x[index] = nx;
			y[index] = ny;
			break;
		case 3:
			for (i = 0; i < rep; i++)
			{
				nx++;
				//printf("index %d,nx %d,ny %d\n", index, nx, ny);

				if (nx <= 0 || nx > b)
				{
					printf("Robot %d crashes into the wall\n", index);

					return false;
				}
				if (map[nx][ny] != 0)
				{
					printf("Robot %d crashes into robot %d\n", index, map[nx][ny]);
					return false;
				}
			}
			map[x[index]][y[index]] = 0;
			map[nx][ny] = index;
			x[index] = nx;
			y[index] = ny;
			break;
		}
	}
	//printf("ori %d is %d\n", index, ori[index]);

	return true;

}
int main()
{
	int t;
	int i, j, k;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cin >> n >> m;
		char tmpo;
		memset(map, 0, sizeof(map));
		for (i = 1; i <=n; i++)
		{
			cin >> y[i] >> x[i] >> tmpo;
			for (j = 0; j < 4; j++)
			{
				if (tmpo == name[j])
				{
					ori[i] = j;
				}
				
			}
			map[x[i]][y[i]] = i;
		}
		bool flag = true;
		int biao, chong;
		char com;
		for (i = 0; i < m; i++)
		{
			cin >> biao >> com >> chong;
			if(flag)
				flag=solve(biao, com, chong);

		}
		if (flag)
			printf("OK\n");
	}
}