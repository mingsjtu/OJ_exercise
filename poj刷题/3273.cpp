//http://poj.org/problem?id=3273
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n, m;
int a[100005];
bool dfs(int x)
{
	//printf("test %d\n", x);
	int sum = 0;
	int i = 0;
	int res = 1;
	for (i = 0; i < n; i++)
	{
		if(sum+a[i]<=x)
		{
			sum = sum + a[i];
			continue;
		}
		sum = a[i];
		res++;
		if (res > m)
			return false;
	}
	//printf("res %d\n",res);

	return true;
}
int main()
{
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int h=0, l=0, mid;
	for (i = 0; i < n; i++)
	{
		h += a[i];
		if (l < a[i])
		{
			l = a[i];
		}
	}
	mid = (h + l) / 2;
	int res = 0;
	int flag = 0;
	while (l<h)
	{
		if (dfs(mid))
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
		mid = (h + l) / 2;
	}
	cout << mid << endl;
	
}