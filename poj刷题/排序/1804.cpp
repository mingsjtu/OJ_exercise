//http://poj.org/problem?id=1804
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
int ori[1005];
int res;
void merge(int l, int r, int m)
{
	int i, j, k;
	i = l;
	j = m + 1;
	k = l;
	int tmp[1005];
	while (i <= m && j <= r)
	{
		if (ori[i] <=ori[j])
		{
			tmp[k++] = ori[i++];
		}
		else
		{
			tmp[k++] = ori[j++];
			res += m + 1 - i;
		}
	}
	while (i <= m)tmp[k++] = ori[i++];
	while (j <= r)tmp[k++] = ori[j++];
	for (i = l; i <=r; i++)
	{
		ori[i] = tmp[i];
	}
	
}
void solve(int l,int r)
{
	if (l < r)
	{
		int mid = (l + r)/2;
		solve(l, mid);
		solve(mid + 1, r);
		merge(l, r, mid);
	}
}
int main()
{
	int i, j, k;
	cin >> n;
	int t = 0;
	while (n--)
	{
		t++;
		memset(ori, 0, sizeof(ori));
		cin >> m;
		res = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &ori[i]);
		}
		solve(0,m-1);
		printf("Scenario #%d:\n%d\n\n", t, res);
	}
}