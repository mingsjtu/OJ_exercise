//http://poj.org/problem?id=2253
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
int map[205][205];
int n;
int x[205],y[205];
int dis[205];
int spfa()
{
	int i, j, k;
	queue<int> q1;
	q1.push(0);
	int tmp;
	for (i = 0; i < n; i++)
	{
		dis[i] = 999999999;
	}
	dis[0] = 0;
	while (!q1.empty())
	{
		tmp = q1.front();
		q1.pop();
		for (i = 0; i < n; i++)
		{
			if (dis[i] > max(dis[tmp], map[i][tmp]))
			{
				dis[i] = max(dis[tmp], map[i][tmp]);
				q1.push(i);
			}
		}
	}
	return dis[1];
}
int main()
{
	int i, j, k,t=0;
	while (cin >> n)
	{
		if (!n)
			break;
		t++;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				map[i][j] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
				map[j][i] = map[i][j];
			}
		}
		double res=sqrt(double(spfa()));
		//double res = sqrt(double(map[1][0]));
		//printf("%f\n", res);
		cin.get();
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", t, res);
	}
	
}