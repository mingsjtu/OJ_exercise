//http://poj.org/problem?id=2632
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int map[105][105];
int ra[105];
int ro[105][2];
int a, b;//map size
int n, m;//robot,command
bool flag;
bool solve(int hao, char com, int rep)
{
	
	int i, j, k;
	int x, y, d;
	x = ro[hao][1];
	y = ro[hao][0];
	switch (com)
	{
	case 'L':
	{
		ra[hao] = (ra[hao] - rep + 400) % 4;
		return true;
	}
	case 'R':
	{
		ra[hao] = (ra[hao] + rep) % 4;
		return true;
	}
	case 'F':
	{
		if (ra[hao] == 0)
		{
			for (i = 0; i < rep; i++)
			{
				y++;
				if (y <=0 || y > a)
				{
					flag = false;
					printf("Robot %d crashes into the wall\n", hao);
					return false;
				}
				if (map[x][y] != 0)
				{
					flag = false;
					printf("Robot %d crashes into robot %d\n", hao, map[x][y]);
					return false;
				}
			}
			map[x][y] = hao;
		}

		if (ra[hao] == 1)
		{
			for (i = 0; i < rep; i++)
			{
				x--;
				if (x <=0 || x > b)
				{
					flag = false;
					printf("Robot %d crashes into the wall\n", hao);
					return false;
				}
				if (map[x][y] != 0)
				{
					flag = false;
					printf("Robot %d crashes into robot %d\n", hao, map[x][y]);
					return false;
				}
			}
			map[x][y] = hao;
		}

		if (ra[hao] == 2)
		{
			for (i = 0; i < rep; i++)
			{
				y--;
				if (y <= 0 || y > a)
				{
					flag = false;
					printf("Robot %d crashes into the wall\n", hao);
					return false;
				}
				if (map[x][y] != 0)
				{
					flag = false;
					printf("Robot %d crashes into robot %d\n", hao, map[x][y]);
					return false;
				}
			}
			map[x][y] = hao;
		}

		if (ra[hao] == 3)
		{
			for (i = 0; i < rep; i++)
			{
				x++;
				if (x <=0 || x > b)
				{
					flag = false;
					printf("Robot %d crashes into the wall\n", hao);
					return false;
				}
				if (map[x][y] != 0)
				{
					flag = false;
					printf("Robot %d crashes into robot %d\n", hao, map[x][y]);
					return false;
				}
			}
			map[x][y] = hao;
		}
		ro[hao][1]=x;
		ro[hao][0]=y;

	}
	return true;
	}
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	while (t--)
	{
		memset(map, 0, sizeof(map));
		char com;
		flag = true;
		int hao, rep;
		cin >> a >> b;
		cin >> n >> m;
		for (i = 1; i <=n; i++)
		{
			char tmp;
			cin >> ro[i][0] >> ro[i][1] >> tmp;
			switch (tmp)
			{
			case 'E':
				ra[i] = 0;
				break;
			case 'S':
				ra[i] = 1;
				break;
			case 'W':
				ra[i] = 2;
				break;
			case 'N':
				ra[i] = 3;
				break;
			}
			map[ro[i][1]][ro[i][0]] = i;

		}
		for (i = 0; i < m; i++)
		{
			cin >> hao >> com >> rep;
			if (flag)
			{
				solve(hao, com, rep);
				//printf("hao %d at %d ,%d ,ra%d\n", hao, ro[hao][0], ro[hao][1],ra[hao]);
			}
		}
		if (flag)
			printf("OK\n");
	}
}