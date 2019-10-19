//http://poj.org/problem?id=1011
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, a[70],sum,fen,tar;
bool vis[70];
bool isyin(int a, int b)
{
	if (b%a == 0)
		return true;
	return false;
}
bool dfs(int sta, int fin, int left,int sample)
{

	if (fin == fen-1)
	{
		return true;
	}
	sample = -1;
	int i, j, k;
	for (i = sta; i < n; i++)
	{
		if (!vis[i]&&a[i]!=sample)
		{
			vis[i] = true;
			if (a[i] == left)
			{
				if (dfs(0, fin + 1, tar, -1))
					return true;
				else
					sample = a[i];
			}
			if (a[i] < left)
			{
				if (dfs(i + 1, fin, left - a[i],-1))
					return true;
				else
					sample = a[i];
			}
			vis[i] = false;
			if (left == tar)
				break;
		}
	}
	return false;
}
bool cmp(int a, int b)
{
	if (a < b)
		return false;
	return true;
}
int main()
{
	int i, j, k;
	bool flag;
	while (cin >> n)
	{
		flag = false;
		sum = 0;
		if (!n)
			return 0;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n,cmp);
		
		for (i = a[0]; i <= sum / 2; i++)
		{
			if (isyin(i, sum))
			{
				//printf("test %d\n", i);
				fen = sum / i;
				tar = i;
				flag=dfs(0, 0, i,-1);
				if (flag)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
		if (flag == false)
			printf("%d\n", sum);
	}
}