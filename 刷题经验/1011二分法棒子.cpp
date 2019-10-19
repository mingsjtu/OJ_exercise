//http://poj.org/problem?id=1011
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
int a[1005];
long long sum = 0;
bool vis[1005];
//int stick[1005];
bool cmp(int x, int y)
{
	return x > y;
}
bool dfs(int s,int x,int num,int cur,int curn)
{
	//printf("s %d,x %d,num %d ,curn %d\n", s, x, num, curn);
	if (curn > sum / x+1)
		return false;
	if (num == n)
	{
		return true;
	}
	int i,j,k,sample=-1;
	for (i = s; i < n; i++)
	{
		if (vis[i] || sample == a[i])
			continue;
		vis[i] = true;
		if (a[i] + cur < x)
		{
			if ((dfs(i + 1, x, num + 1, cur + a[i],curn)))
				return true;
			else
				sample = a[i];
		}
		if (a[i] + cur == x)
		{
			vis[i] = true;
			//curn++;
			if (dfs(0, x, num + 1, 0,curn+1))
				return true;
			else
			{
				curn--;
				sample = a[i];
			}
		}
		vis[i] = false;
		if (cur == x)
			return false;
	}
	return false;
}
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		
		memset(vis, 0, sizeof(vis));
		if (!n)
			return 0;
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		qsort(a,a+n,cmp);
		
		int low=a[0],high=sum;
		int res = sum;
		for (i = low; i <= sum / 2; i++)
		{
			
			if (sum%i != 0)
				continue;
			if (dfs(0,i,0,0,1))
			{
				
				res = i;
				break;
			}
		}
		cout << res << endl;
	}
	
}