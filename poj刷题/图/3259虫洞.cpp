#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;//test cases
int N, M, W;
struct edge
{
	int sta, en, leng;//qidian zhongdian changdu ,leng<0
}e1[6000];
int d[505];
int all = 0;
int main()
{
	int i, j, k;
	cin >> t;
	int tsta, ten, tleng;
	while (t-- > 0)
	{
		all = 0;
		scanf("%d %d %d", &N,&M, &W);
		for (i = 0; i < M; i++)
		{
			scanf("%d %d %d", &tsta, &ten, &tleng);
			e1[all].sta = tsta;
			e1[all].en = ten;
			e1[all].leng = tleng;
			all++;
			e1[all].sta = ten;
			e1[all].en = tsta;
			e1[all].leng = tleng;
			all++;
		}
		for (i = 0; i < W; i++)
		{
			scanf("%d %d %d", &tsta, &ten, &tleng);
			e1[all].sta = tsta;
			e1[all].en = ten;
			e1[all].leng = -tleng;
			all++;
		}
		//cout << "all"<<all << endl;
		for (i = 0; i < N; i++)
			d[i] = 10005;
		d[0] = 0;
		bool flag = false;
		for (i = 0; i < N - 1; i++)
		{
			flag = false;
			for (j = 0; j < all; j++)
			{
				if (d[e1[j].en] > d[e1[j].sta] + e1[j].leng)
				{
					d[e1[j].en] = d[e1[j].sta] + e1[j].leng;
					flag = true;
				}
			}
			if (!flag)
				break;
		}
		bool res = true;
		for (j = 0; j < all; j++)
		{
			if (d[e1[j].en] > d[e1[j].sta] + e1[j].leng)
			{
				d[e1[j].en] = d[e1[j].sta] + e1[j].leng;
				res=false;
			}
		}
		if (!res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}