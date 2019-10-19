//http://noi.openjudge.cn/ch0206/1996/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp1[1005]; 
int dp2[1005];
int a[1005];
int n;
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] < a[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
		//printf("%d  ", dp1[i]);
	}

	for (i = n-1; i >=0; i--)
	{
		for (j = n-1; j > i; j--)
		{
			if (a[j] < a[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
		//printf("%d  ", dp2[i]);
	}
	int res = 0;
	for (i = 0; i < n; i++)
	{
		res=max(dp1[i] + dp2[i]+1,res);
	}
	printf("%d\n", res);
	
}