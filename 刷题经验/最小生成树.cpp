//http://poj.org/problem?id=1789
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int n;
char s[2005][8];
int map[2005][2005];
int p[2005];
int dis[2005];
int cnt = 0;

struct edge
{
	int from;
	int to;
	int leng;
	
}tree[2005*2005];
bool cmp(edge e1, edge e2)
{
	if (e1.leng < e2.leng)
		return true;
	else
		return false;
}

int compute(char *a, char *b)
{
	int i;
	int res = 0;
	for (i = 0; i < 7; i++)
	{
		if (a[i] != b[i])
			res++;
	}
	return res;
}
int f[2005];
int findf(int x)
{
	if (f[x] == -1)
	{
		return x;
	}
	int res = findf(f[x]);
	f[x] = res;
	return res;
}
int kru()
{
	sort(tree, tree + cnt,cmp);
	int s, e;
	int res = 0;
	for (int i = 0; i < cnt; i++)
	{
		s =	findf(tree[i].from);
		e = findf(tree[i].to);
		if (s != e)
		{
			res += tree[i].leng;
			f[tree[i].from] = e;
			f[s] = e;
		}
	}
	return res;
}
int main()
{
	int i, j, k;
	edge tmpe;
	while (cin >> n)
	{
		memset(f, -1, sizeof(f));
		cnt = 0;
		if (!n)
			return 0;
		for (i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				tmpe.leng= compute(s[i], s[j]);
				tmpe.from = i;
				tmpe.to = j;
				tree[cnt++] = tmpe;
			}
		}
		int rr = kru();
		printf("The highest possible quality is 1/%d.\n", rr);
	}
}
