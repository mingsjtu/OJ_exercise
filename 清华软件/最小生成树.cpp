//ÍõµÀ133
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int tree[1000];
int findroot(int x)
{
	if (tree[x] == -1)
		return x;
	else
	{
		int tmp = findroot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}
struct edge
{
	int s,e,l;
	bool operator<(edge e1)
	{
		if (l < e1.l)return true;
		else return false;
	}
}e[1000];
int n;
int sta, en, len;
int main()
{
	int i, j, k;
	while(cin>>n)
		{
		if (!n)break;
		else
		{
			for (i = 0; i < n*(n-1)/2; i++)
			{
				cin >> sta >> en >> len;
				edge tmp;
				tmp.s = sta-1; tmp.e = en-1; tmp.l = len;
				e[i] = tmp;
			}
			sort(e, e + n);
			memset(tree, -1, sizeof(tree));
			int cnt = 0;
			int root = e[0].s;
			tree[e[0].s] = e[0].s;
			tree[e[0].e] = e[0].s;
			int zongchang=e[0].l;
			cnt++;
			int sea = 1;
			while(cnt<n)
			{
				cout << cnt<<endl;
				if (findroot(e[sea].s) !=findroot(e[sea].e))
				{
					zongchang+=e[sea].l;
					cnt++;
					tree[e[sea].s] = findroot(e[sea].e);

				}
				sea++;
			}

		}
		}
}