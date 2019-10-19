//http://poj.org/problem?id=1020
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int map[45];
int n,m;
short a[20];
bool cmp(short a1, short a2)
{
	if (a1 > a2)
		return true;
	else
		return false;
}
bool res;

void dfs(int d)
{
	//cout << "d  " << d << endl;
	if (res)
		return;
	if (d == m)
	{
		res = 1;
		return;
	}
	int i, j, k;
	bool flag = true;
	int maxn = 0,maxi=0;
	for (i = 0; i <= n - a[d]; i++)
	{
		//cout << "i" << i << endl;
		if (map[i] > maxn)
		{
			maxn = map[i];
			maxi = i;
		}
	}
	i = maxi;
	if (maxn >= a[d])
	{
		flag = true;
		for (j = i; j - i + 1 <= a[d]; j++)
		{
			if (map[j] < a[d])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			//cout << "xuan " << i << endl;
			for (j = i; j - i + 1 <= a[d]; j++)
			{
				map[j] -= a[d];
			}
			dfs(d + 1);
			if (res)
				return;
			for (j = i; j - i + 1 <= a[d]; j++)
			{
				map[j] += a[d];
			}
		}
	}
}
int main()
{
	int i, j, k,t;
	cin >> t;
	int sum;
	while (t--)
	{
		sum = 0;
		cin >> n >> m;
		for (i = 0; i < n; i++)
			map[i] = n;
		for (i = 0; i < m; i++)
		{
			cin >> a[i];
			sum += a[i] * a[i];
		}
		
		if (sum != n * n)
		{
			printf("HUTUTU!\n");
			continue;
		}
		res = 0;
		sort(a, a + m,cmp);
		dfs(0);
		if (res)
			printf("KHOOOOB!\n");
		else
			printf("HUTUTU!\n");
	}
}