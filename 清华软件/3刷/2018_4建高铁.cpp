//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int dis[1000005];
bool vis[1000005];
int dis1[1000005];
struct edge
{
	int en, leng;
};
int N, M;
vector<edge> head[100005];
void dij()
{
	int s = 0;
	int ok = 0;
	int newp = 0;
	ok++;
	int i, j, k;
	edge tmp;
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	dis[0] = 0;
	while (ok <= N)
	{
		for (i = 0; i < head[newp].size(); i++)
		{
			tmp = head[newp][i];
			if (vis[tmp.en])
				continue;
			if (dis[tmp.en] == -1 || dis[tmp.en] > dis[newp] + tmp.leng)
			{
				dis[tmp.en] = dis[newp] + tmp.leng;
				printf("update en%d, dis %d\n", tmp.en, dis[tmp.en]);
			}
		}
		int minv = 1000000;
		for (i = 0; i < N; i++)
		{
			if (vis[i] == true || dis[i] == -1)
				continue;
			if (dis[i] < minv)
			{
				minv = dis[i];
				newp = i;
			}

		}
		vis[newp] = true;
		printf("dij newp %d , dis %d\n", newp, dis[newp]);

		ok++;
	}
}
void dij1()
{
	int s = 0;
	int ok = 0;
	int newp = N - 1;
	ok++;
	int i, j, k;
	edge tmp;
	memset(vis, 0, sizeof(vis));
	memset(dis1, -1, sizeof(dis1));
	vis[N - 1] = 1;
	dis1[N - 1] = 0;
	while (ok <= N)
	{
		for (i = 0; i < head[newp].size(); i++)
		{
			tmp = head[newp][i];
			if (vis[tmp.en])
				continue;
			if (dis1[tmp.en] == -1 || dis1[tmp.en] > dis1[newp] + tmp.leng)
			{
				dis1[tmp.en] = dis1[newp] + tmp.leng;
			}
		}

		int minv = 1000000;
		for (i = 0; i < N; i++)
		{
			if (vis[i] == true || dis1[i] == -1)
				continue;
			if (dis1[i] < minv)
			{
				minv = dis1[i];
				newp = i;
			}
		}
		vis[newp] = true;
		printf("dij1 newp %d , dis %d\n", newp, dis1[newp]);

		ok++;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int i, j, k;
	int csta, cen, cleng;
	memset(dis, -1, sizeof(dis));
	edge tmp;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &csta, &cen, &cleng);
		tmp.en = cen;
		tmp.leng = cleng;
		head[csta].push_back(tmp);
		tmp.en = csta;
		head[cen].push_back(tmp);
	}
	dij();
	dij1();
	int ressta = 0, resen = 0;
	int minv = 1000000;
	for (i = 0; i < N; i++)
	{
		cout << dis[i] << " " ;
	}
	cout << endl;
	for (i = 0; i < N; i++)
	{
		cout << dis1[i] << " " ;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < head[i].size(); j++)
		{
			tmp = head[i][j];
			printf("kaocha i %d ,j%d ,tmp %d\n", i, j, dis[tmp.en] + dis1[i] + tmp.leng / 2);
			if (minv > dis[tmp.en] + dis1[i] + tmp.leng / 2)
			{
				ressta = tmp.en;
				resen = i;
				minv = dis[tmp.en] + dis1[i] + tmp.leng / 2;
			}
		}
	}
	printf("%d %d %d\n", ressta, resen, minv);
}