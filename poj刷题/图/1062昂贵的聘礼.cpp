//http://poj.org/problem?id=1062
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int qian;
	int diwei;
}no[105];
struct edge
{
	int sta, en, w;
}e[10005];
int N, M;
int main()
{
	int i, j, k;
	cin >> M >> N;
	int c_v, c_diwei, c_n;
	int c_en, c_w;
	int all = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d", &c_v, &c_diwei, &c_n);
		no[i].qian = c_v;
		no[i].diwei = c_diwei;
		for (j = 0; j < c_n; j++)
		{
			scanf("%d %d", &c_en, &c_w);
			e[all].sta = i;
			e[all].en = c_en-1;
			e[all].w = c_w;
			all++;
		}
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < all; j++)
		{
			if (no[e[j].sta].qian > no[e[j].en].qian + e[j].w&&no[e[j].en].diwei <= no[e[j].sta].diwei + M&& no[e[j].en].diwei +M>= no[e[j].sta].diwei)

			{
				no[e[j].sta].qian = no[e[j].en].qian + e[j].w;
			}
		}
	}
	cout << no[0].qian<<endl;
	
}