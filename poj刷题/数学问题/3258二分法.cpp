//http://poj.org/problem?id=3258
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, l[50005];
int maxl, m;
bool dfs(int x)
{
	int sta = 0, en = 1,res=0;
	int i, j, k;
	while (en < n)
	{
		if (l[en] - l[sta] < x)
		{
			res++;
			if (res > m)
				return false;
			en = en + 1;
		}
		else
		{
			sta = en;
			en = en + 1;
		}
	}
	//printf("x %d,res %d\n", x, res);
	return true;
	
}
int main()
{
	
	cin>>maxl>> n>>m;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
	}
	l[n] = 0;
	l[n + 1] = maxl;
	n += 2;
	sort(l, l + n);
	int minv=maxl;
	for (i = 0; i < n-1; i++)
	{
		if (l[i + 1] - l[i] < minv)
		{
			minv = l[i+1]-l[i];
		}
	}
	int h, l, mid;
	l = minv;
	h = maxl;
	mid = (l + h) / 2;
	while (h > l)
	{
		if (dfs(mid))
		{
			l = mid+1;
		}
		else
		{
			h = mid-1;
		}
		//printf("h%d l%d test %d\n", h, l, mid);
		mid = (h + l) / 2;
	}
	if (dfs(mid))
		cout << mid << endl;
	else
		cout << mid-1<< endl;
}