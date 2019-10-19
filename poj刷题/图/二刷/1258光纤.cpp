//http://poj.org/problem?id=1258
//注意看题，多个case
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;
int map[105][105];
int minv = -1;
bool in[105];
int dis[105];
int ok = 0;
int all = 0;
int main()
{
	while (cin >> n) 
	{
		ok = 0;
		all = 0;
		int i, j, k;
		memset(dis, 0, sizeof(dis));
		memset(in, 0, sizeof(in));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> map[i][j];
				//scanf("%d", &map[i][j]);
			}
		}
		in[0] = 1;
		int newp = 0;
		dis[0] = 0;
		minv = 0;
		ok = 1;
		for (i = 0; i < n; i++)
		{
			dis[i] = map[0][i];
		}
		while (ok++ < n)
		{
			minv = 1000000;
			//printf("newp %d\n", newp);
			for (i = 0; i < n; i++)
			{
				if (dis[i] > map[newp][i])
				{
					dis[i] = map[newp][i];
				}
			}
			for (i = 0; i < n; i++)
			{
				if (in[i])
					continue;
				if (minv > dis[i])
				{
					minv = dis[i];
					newp = i;
				}
			}
			all += minv;
			//printf("minv %d\n", minv);
			in[newp] = 1;
		}
		printf("%d\n", all);
	}
}