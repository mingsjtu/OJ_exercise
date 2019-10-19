//https://blog.csdn.net/da_kao_la/article/details/82425671
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;
int n=0;//dian

map<int,int> duiying;//mingzi->biaohao
struct edge
{
	int en, leng;
};
vector<edge> head[50];

bool vis[50];
int dis[50];
int dij(int s,int t)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	vis[s] = 1;
	dis[s] = 0;
	int newp = s;
	int ok = 1;
	int i, j, k;
	edge tmp;
	while (ok < n)
	{
		int minv = 100000;
		for (i = 0; i < head[newp].size(); i++)
		{
			tmp = head[newp][i];
			if (vis[tmp.en] == 1)
				continue;
			if (dis[tmp.en] == -1 || dis[tmp.en] > dis[newp] + tmp.leng)
			{
				dis[tmp.en] = dis[newp] + tmp.leng;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (vis[i] == true)
				continue;
			if (dis[i] != -1 && dis[i] < minv)
			{
				minv = dis[i];
				newp = i;
			}
		}
		vis[newp] = true;
		ok++;
	}
	return dis[t];
}
int main()
{
	int a, b, len;
	char rub;
	len = 0;
	int index = 0;
	int i, j, k;
	while (scanf("%d%d%c", &a, &b,&rub)!=EOF)
	{
		if (rub == '\n')
			break;
		scanf("%d", &len);
		n++;
		if (duiying.find(a) == duiying.end())
			duiying[a] = index++;
		if (duiying.find(b) == duiying.end())
			duiying[b] = index++;
		int ta = duiying[a], tb = duiying[b];
		edge tmp;
		tmp.en = tb;
		tmp.leng = len;
		head[ta].push_back(tmp);
		tmp.en = ta;
		head[tb].push_back(tmp);
		//printf("%d %d %d\n", a, b, len);
	}
	cout<<dij(duiying[a],duiying[b]);
}
