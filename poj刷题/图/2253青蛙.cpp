//http://poj.org/problem?id=2253
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>;
using namespace std;
struct dian
{
	int x, y;
}dian1[300];
int d[300];
int n;
int max(int a, int b)
{
	return a > b ? a : b;
}
struct edge
{
	int en;
	int  w;
};
vector<edge> head[300];
bool visited[300];
int ok = 0;
void spfa()
{
	queue<int> q;
	while (!q.empty())
		q.pop();
	int i;
	
	q.push(1);
	int newp=1;
	edge tmp;
	memset(visited, 0, sizeof(visited));
	visited[newp] = true;
	memset(d, -1, sizeof(d));
	while (!q.empty())
	{
		newp = q.front();
		visited[newp] = false;
		q.pop();
		for (i = 0; i < head[newp].size(); i++)
		{
			tmp = head[newp][i];
			if (d[tmp.en] == -1 || d[tmp.en] > max(d[newp], tmp.w))
			{
				d[tmp.en] = max(d[newp], tmp.w);
				if (!visited[tmp.en])
				{
					q.push(tmp.en);
					visited[tmp.en] = true;
				}
			}
		}
	}
}
int main()
{
	int i, j, k;
	int t = 0;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			while (!head[i].empty())
				head[i].pop_back();
		}
		t++;
		if (!n)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &dian1[i].x, &dian1[i].y);
		}
		int maxv = (dian1[0].x - dian1[1].x)*(dian1[0].x - dian1[1].x) + (dian1[0].y - dian1[1].y)*(dian1[0].y - dian1[1].y);
		int tmp;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				tmp = (dian1[i].x - dian1[j].x)*(dian1[i].x - dian1[j].x) + (dian1[i].y - dian1[j].y)*(dian1[i].y - dian1[j].y);
				if (tmp <= maxv)
				{
					edge e;
					e.en = j;
					e.w = tmp;
					head[i].push_back(e);
					e.en = i;
					head[j].push_back(e);
					//printf("add tmp%d\n", tmp);
				}
			}
			
		}
		d[0] = maxv;
		//printf("Scenario #%d\nFrog Distance = %.3f\n", t, sqrt(double(d[0])));
	
		spfa();
		//cout << sqrt(double(d[0])) << endl;
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",t,sqrt(double(d[0])));
	}
}
